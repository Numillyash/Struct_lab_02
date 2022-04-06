#include "LCG.h"

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
	number a, x0, c, m, sum, mod;
	generator.x0 = generator.next;
	a = ull_to_number(generator.a);
	x0 = ull_to_number(generator.x0);
	c = ull_to_number(generator.c);
	m = ull_to_number(generator.m);
	sum = multiplication(&a, &x0);
	sum = addition(&sum, &c);
	division_with_module(&sum, &m, &mod);
	generator.next = number_to_ull(&mod);
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
	ull c, m = numbers[2], s = numbers[1], c_max, c_min;
	int count = 0;
	if (m == 0 || s == 0 || s > 64)
	{
		save_text("no solution");
	}
	else
	{
		c_min = (ull)1 << (s-1);
		c_max = (ull)1 << s;
		for (c = c_min; c <= c_max; c++)
		{
			if (c >= m)
				break;
			if (_euclide_algorithm(m, c) == 1)
			{
				count++;
				save_int(c);
			}
			if (count == 10)
				break;
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

	if (numbers[5] == 0 || numbers[4] == 0 || numbers[1] == 0 || (numbers[2] == 0 && numbers[3] == 0) || numbers[1] >= numbers[4] || numbers[2] >= numbers[4] || numbers[3] >= numbers[4])
	{
		save_text("no solution");
	}
	else
	{
		rand_init(numbers[1], numbers[2], numbers[3], numbers[4]);
		for (i = 0; i < numbers[5]; i++)
		{
			save_int(rand_get_next());
		}
	}
}

void bits_wm(ull numbers[6])
{
	ull _bits[64];
	ull i;
	ull numb;
	int j;

	for (i = 0; i < 64; i++)
	{
		_bits[i] = 0;
	}

	if (numbers[5] == 0 || numbers[4] == 0 || numbers[1] == 0 || (numbers[2] == 0 && numbers[3] == 0) || numbers[1] >= numbers[4] || numbers[2] >= numbers[4] || numbers[3] >= numbers[4])
	{
		save_text("no solution");
	}
	else
	{
		rand_init(numbers[1], numbers[2], numbers[3], numbers[4]);

		for (i = 0; i < numbers[5]; i++)
		{
			numb = rand_get_next();
			j = 0;
			while (numb != 0)
			{
				if (numb % 2)
					_bits[j]++;
				numb >>= 1;
				j++;
			}
		}
		for (i = 64; i > 0; i--)
		{
			save_int(_bits[i-1]);
		}
	}
}
