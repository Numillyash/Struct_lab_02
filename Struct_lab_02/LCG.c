#include "output.h"

ull mul_mod(ull a, ull b, ull m) {
    ull d = 0, _a=a, _b=b;
    int i_a =0 , i_b = 0, zn = 1;
    
    while (_a) // подсчет битов a
    {
        i_a++;
        _a >>= 1;
    }
    while (_b) // подсчет битов b
    {
        i_b++;
        _b >>= 1;
    }
    
    if(i_a + i_b <= 64) // если сумма битов не превышает 64
        return a * b % m; // возвращаем обычным действиями
    
    // идея: a mod m = (a-m) mod m
    // так как мы храним только неотрицательные числа, 
    // будем хранить m-a и если что менять знак
    // (-a) mod m = -(a mod m) = m - (a mod m) = m - a (a < m)
    //
    // (-a * b) mod m = (-a) mod m * b mod m = -(a mod m * b mod m) =
    // = -((a * b) mod m) = m - ((a * b) mod m)
    // 
    // ((a * b) mod m) = m - (-a * b) mod m
    //
    // (-a * -b) mod m = (-a) mod m * (-b) mod m = 
    // = (a mod m * b mod m) = (a * b) mod m
    // 
    // (a * b) mod m = (-a * -b) mod m

    if(i_a > 32) 
    {
        _a = m - a;
        zn *= -1;
    }
    else
        _a = a;
    if(i_b > 32)
    {
        _b = m - b;
        zn *= -1;
    }
    else
        _b = b;    

    // считаем то, что гарантированно влезло в 64 бита
    d = _a * _b;

    d %= m;

    if(zn == -1) // если числа менялись
        d = m-d;

    return d;
}

ull sum_mod(ull a, ull b, ull m) {
    ull d = 0, _a=a, _b=b;
    int i_a =0 , i_b = 0, zn = 0;
    
    while (_a) // подсчет битов a
    {
        i_a++;
        _a >>= 1;
    }
    while (_b) // подсчет битов b
    {
        i_b++;
        _b >>= 1;
    }

    if((max(i_a, i_b)) <= 63) // если сумма битов не превышает 64
        return (a + b) % m; // возвращаем обычным действиями

    // идея: a mod m = (a-m) mod m
    // так как мы храним только неотрицательные числа, 
    // будем хранить m-a и если что менять знак
    // (-a) mod m = -(a mod m) = m - (a mod m) = m - a (a < m)
    //
    // если заменены оба числа
    // (a+b) mod m = m - (_a + _b) = m - (m - a + m - b) = (a + b - m) = (a+b) mod m
    //
    // если заменено a
    // (a+b) mod m = - _a + b = -(m - a) + b = a + b - m = (a+b) mod m
    // если _a > b (b - _a < 0)
    // - _a + b = -(_a - b) = m - (_a - b)
    //
    // если заменено b
    // (a+b) mod m = a - _b = a - (m - b) = a + b - m = (a+b) mod m
    // если _b > a (a - _b < 0)
    // a - _b = -(_b - a) = m - (_b - a)
    //

    if(i_a > 63) 
    {
        _a = m - a;
        zn = 1;
    }
    else
        _a = a;
    if(i_b > 63)
    {
        _b = m - b;
        if(zn == 1)
            zn = 3;
        else 
            zn = 2;
    }
    else
        _b = b;    

    if(zn == 3)
    {
        d = m-(_a + _b);
    }
    if(zn == 2)
    {
        if(a - _b < 0)
            d = m - (_b - a);
        else
            d = a - _b;
    }
    if(zn == 1)
    {
        if(b - _a < 0)
            d = m - (_a - b);
        else
            d = b - _a;
    }
    if(zn == 0)
    {
        d = _a + _b;
    }
    return d;
}

struct _system {
	ull a;
	ull x0;
	ull next;
	ull c;
	ull m;
};

struct _system generator;

ull _euclide_algorithm(ull a, ull b)
{
	if (abs(a) < abs(b))
	{
		ull _ = b;
		b = a;
		a = _;
	}
	//a = b * q_0 + r_1
	ull r = a % b;

	if (r != 0)
		_euclide_algorithm(b, r);
	else
		return b;
}

ull rand_get_next()
{
	generator.x0 = generator.next;
	generator.next = sum_mod(mul_mod(generator.a, generator.x0, generator.m), generator.c, generator.m);
    // = (a*x0+c)%m;
	return generator.next;
}

void rand_init(ull _a, ull _x0, ull _c, ull _m)
{
	generator.a = _a;
	generator.x0 = _x0;
	generator.c = _c;
	generator.m = _m;
	generator.next = _x0;
}

void get_c_wm(ull numbers[6]) 
{
	ull c, m = numbers[3], c_max = numbers[2], c_min = numbers[1];
	ull count = 0;
	if (m == 0 || c_max == 0 || c_min == 0 || c_max < c_min || c_max >= m)
	{
		save_text("no solution");
	}
	else
	{
		for (c = c_min; c <= c_max; c++)
		{
			if (c >= m)
				break;
			if (_euclide_algorithm(m, c) == 1)
			{
				count++;
				save_int(c);
			}
		}
	}
	if (!count)
	{
		save_text("no solution");
	}
}

void get_a_wm(ull numbers[6]) 
{
	ull b = 1, m, a;
	ull i = 3;
	
	m = numbers[1];

	if (m % 2 == 0)
	{
		b *= 2;
		m /= 2;
		if (m % 2 == 0)
		{
			b *= 2;
			m /= 2;
		}
		while (m % 2 == 0)
			m /= 2;
	}

	while (m > 1)
	{
		if (m % i == 0)
		{
			b *= i;
			while (m % i == 0)
				m /= i;
		}
		i += 2;
	}
	a = b + 1;
	m = numbers[1];
	printf("%d %d\n", a, m);
	if(a > m || a == 0 || m == 0) 
	{
		save_text("no solution");
	}
	else
	{
		save_int(a);
	}
}

void lcg_wm(ull numbers[6])
{
	ull i;

	if (numbers[5] == 0 || numbers[4] == 0 || numbers[1] < 2 || (numbers[2] == 0 && numbers[3] == 0) || numbers[1] >= numbers[4] || numbers[2] >= numbers[4] || numbers[3] >= numbers[4])
	{
		save_text("no solution");
	}
	else
	{
		rand_init(numbers[1], numbers[2], numbers[3], numbers[4]);
		for (i = 0; i < numbers[5]; i++)
		{
			save_bin(rand_get_next());
		}
	}
}

void test_wm(char* inp_file)
{
    ull count = 0;
    FILE* inp = fopen(inp_file, "r");
    if (inp == NULL)
    {
        save_text("no solution");
        exit(EXIT_SUCCESS);
    }
    
    // 64 бита
    //
    // то бишь можно разделить на 8 блоков по 8 бит и считать кол-ва единичек и нулей
    //

    char* bin_num[70];
    fscanf(inp, "%s", bin_num);

    while (strlen(bin_num) > 0)
    {
        if (strlen(bin_num) > 64)
        {
            save_text("no solution");
            exit(EXIT_SUCCESS);
        }

    }

}
