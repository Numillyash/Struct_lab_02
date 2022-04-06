//
// Created by Georgul on 02.11.2021.
//
#include "bit_LA.h"

inline uint8_t XOR(uint8_t a, uint8_t b)
{
	return a ^ b;
}

inline uint8_t NOT(uint8_t a)
{
	return (a) ? 0 : 1;
}

inline uint8_t AND(uint8_t a, uint8_t b)
{
	return a & b;
}

void additional_code(number* value)
{
	if (!is_zero(value)) {
		uint8_t addit_digit = 1;
		int iter;

		for (iter = 0; iter < value->current_count; iter++)
		{
			value->mas[iter] = NOT(value->mas[iter]);
		}

		for (iter = 0; iter < value->current_count; iter++)
		{
			value->mas[iter] = XOR(value->mas[iter], addit_digit);
			if (value->mas[iter])
				addit_digit = 0;
		}
	}
}

void nonadditional_code(number* value)
{
	if (!is_zero(value)) {
		uint8_t addit_digit = 1;
		int iter;

		for (iter = 0; iter < value->current_count; iter++)
		{
			value->mas[iter] = NOT(value->mas[iter]);
		}

		for (iter = 0; iter < value->current_count; iter++)
		{
			value->mas[iter] = XOR(value->mas[iter], addit_digit);
			if (value->mas[iter])
				addit_digit = 0;
		}
	}
}

number init() {
	number result = { 1, NUMBER_ARR_SIZE };
	int i;

	for(i = 0; i < NUMBER_ARR_SIZE; i++)
		result.mas[i] = 0;

	return result;
}

number copy(number* value) {
	number result = init();
	int i; // iterator
	for (i = 0; i < value->current_count - 1; i++)
		add_digit(&result, value->mas[i]);
	result.mas[result.current_count - 1] = value->mas[value->current_count - 1];
	return result;
}

number int_to_number(int value) {
	int ostatok;
	number result = init();
	if (value < 0)
	{
		value *= -1;
		while (value > 0) {
			ostatok = value % NUMBER_SYSTEM_BASE;
			add_digit(&result, ostatok);
			value >>= 1;
		}
		if (result.current_count == 0)
			add_digit(&result, 0);
		additional_code(&result);
	}
	else
	{
		while (value > 0) {
			ostatok = value % NUMBER_SYSTEM_BASE;
			add_digit(&result, ostatok);
			value >>= 1;
		}
		if (result.current_count == 1)
		{
			add_digit(&result, 0);
		}
	}

	return result;
}

int number_to_int(number* value)
{
	int res = 0, i, zn = 1;
	int x = 1; // ������� ������

	if (value->mas[value->current_count - 1])
	{
		zn = -1;
		nonadditional_code(value);
		for (i = 0; i < value->current_count - 1; i++)
		{
			res += value->mas[i] * x;
			x <<= 1;
		}
	}
	else
	{
		for (i = 0; i < value->current_count - 1; i++)
		{
			res += value->mas[i] * x;
			x <<= 1;
		}
	}
	res *= zn;
	return res;
}

number ull_to_number(ull value) {
	ull ostatok;
	number result = init();
	if (value < 0)
	{
		value *= -1;
		while (value > 0) {
			ostatok = value % NUMBER_SYSTEM_BASE;
			add_digit(&result, ostatok);
			value >>= 1;
		}
		if (result.current_count == 0)
			add_digit(&result, 0);
		additional_code(&result);
	}
	else
	{
		while (value > 0) {
			ostatok = value % NUMBER_SYSTEM_BASE;
			add_digit(&result, ostatok);
			value >>= 1;
		}
		if (result.current_count == 1)
		{
			add_digit(&result, 0);
		}
	}

	return result;
}

ull number_to_ull(number* value) 
{
	ull res = 0, i, zn = 1;
	ull x = 1; // ������� ������

	if (value->mas[value->current_count - 1])
	{
		zn = -1;
		nonadditional_code(value);
		for (i = 0; i < value->current_count - 1; i++)
		{
			res += value->mas[i] * x;
			x <<= 1;
		}
	}
	else
	{
		for (i = 0; i < value->current_count - 1; i++)
		{
			res += value->mas[i] * x;
			x <<= 1;
		}
	}
	res *= zn;
	return res;
}

void normalize(number* value) {
	number result = init();
	int i; //iterator
	int end = value->current_count - 2;
	if (value->mas[value->current_count - 1])
	{
		for (i = value->current_count - 2; i > 0; i--) {
			end = i;
			if (value->mas[i] == 0 || value->mas[i - 1] == 0) {
				break;
			}
		}
	}
	else
	{
		for (i = value->current_count - 2; i >= 0; i--) {
			end = i;
			if (value->mas[i] != 0) {
				break;
			}
		}
	}
	for (i = 0; i <= end; i++) {
		add_digit(&result, value->mas[i]);
	}
	result.mas[result.current_count - 1] = value->mas[value->current_count - 1];
	*value = init();
	for (i = 0; i <= end; i++) {
		add_digit(value, result.mas[i]);
	}
	value->mas[value->current_count - 1] = result.mas[result.current_count - 1];
}

void add_digit(number* object, uint8_t value) {
	int iter;
	uint8_t* buff;

	if (object->current_count < object->size) {
		object->mas[object->current_count] = object->mas[object->current_count - 1];
		object->mas[object->current_count - 1] = value;
		object->current_count += 1;
	}
	else {
		exit(100);
	}
}

void offset_right(number* object)
{
	if (object->current_count == 2)
	{
		*object = int_to_number(0);
	}
	else
	{
		reverse(object);
		object->mas[object->current_count - 2] = object->mas[object->current_count - 1];
		object->current_count -= 1;
		reverse(object);
		normalize(object);
	}
}

void offset_left(number* object)
{
	reverse(object);
	add_digit(object, 0);
	swap(object->mas[object->current_count - 2], object->mas[object->current_count - 1]);
	reverse(object);
	normalize(object);
}

void reverse(number* value)
{
	number prom = init();
	int i; // iterator
	for (i = value->current_count - 2; i >= 0; i--)
	{
		add_digit(&prom, value->mas[i]);
	}
	for (i = 0; i <= prom.current_count - 2; i++)
	{
		value->mas[i] = prom.mas[i];
	}
}

void print_number_as_is(number* value) {
	int i; //iterator
	for (i = 0; i <= value->current_count - 2; i++)
	{
		printf("%d", (int)value->mas[i]);
		if (i % 4 == 3)
			printf(" ");
	}
	printf(" %d", (int)value->mas[value->current_count - 1]);
	printf("\n");
}

void print_number_decimal(number* value) {
	int y; //iterator
	int x = 1; // stepen 2
	int s = 0; // summa
	if (value->mas[value->current_count - 1])
	{
		printf("-");
		nonadditional_code(value);
		
		for (y = 0; y < value->current_count - 1; y++)
		{
			s += value->mas[y] * x;
			x <<= 1;
		}
		printf("%d\n", s);
		additional_code(value);
	}
	else
	{
		for (y = 0; y < value->current_count - 1; y++)
		{
			s += value->mas[y] * x;
			x <<= 1;
		}
		printf("%d\n", s);
	}
}

void print_number(number* value) {
	int i; //iterator
	printf("%d ", (int)value->mas[value->current_count - 1]);
	while (((value->current_count) - 1) % 4 != 0)
	{
		add_digit(value, 0);
	}
	for (i = value->current_count - 2; i >= 0; i--)
	{
		printf("%d", (int)value->mas[i]);
		if (i % 4 == 0)
			printf(" ");
	}
	normalize(value);
	printf("\n");
}

BOOL is_zero(number* object)
{
	int iterator = 0;

	for (iterator = 0; iterator < object->current_count; iterator++)
	{
		if (object->mas[iterator] != 0)
		{
			return FALSE;
		}
	}

	return TRUE;
}

BOOL is_equal(number* value1, number* value2)
{
	short iterator = 0;

	normalize(value1);
	normalize(value2);

	if (value1->current_count != value2->current_count)
		return FALSE;
	for (iterator = 0; iterator < value1->current_count; iterator++)
	{
		if (value1->mas[iterator] != value2->mas[iterator])
			return FALSE;
	}

	return TRUE;
}

number addition(number* value1, number* value2) {
	number summand, addend;
	number carry = init();
	int real_symb = 0;
	int oper_sign = 0;
	int iter = 0;
	int max_symb = 0;

	normalize(value1); normalize(value2);

	if ((value1->current_count) >= (value2->current_count)) {
		summand = copy(value1);
		addend = copy(value2);
	}
	else {
		summand = copy(value2);
		addend = copy(value1);
	}

	if (summand.mas[summand.current_count - 1] && addend.mas[addend.current_count - 1])
	{
		nonadditional_code(&summand);
		nonadditional_code(&addend);
		carry = addition(&summand, &addend);
		additional_code(&carry);

		normalize(&carry);
		return carry;
	}

	oper_sign = summand.mas[summand.current_count - 1] + addend.mas[addend.current_count - 1];
	real_symb = max(summand.current_count, addend.current_count);

	while (!is_zero(&addend))
	{
		max_symb = max(summand.current_count, addend.current_count);
		max_symb = max(max_symb, carry.current_count);
		if (max_symb == 2) { max_symb++; real_symb++; }

		for (iter = max_symb - summand.current_count; iter > 0; iter--)
		{
			if (summand.mas[summand.current_count - 1])
				add_digit(&summand, 1);
			else
				add_digit(&summand, 0);
		}
		for (iter = max_symb - addend.current_count; iter > 0; iter--)
		{
			if (addend.mas[addend.current_count - 1])
				add_digit(&addend, 1);
			else
				add_digit(&addend, 0);
		}
		for (iter = max_symb - carry.current_count; iter > 0; iter--)
		{
			if (carry.mas[carry.current_count - 1])
				add_digit(&carry, 1);
			else
				add_digit(&carry, 0);
		}

		//carry = (summand & addend);
		for (iter = 0; iter < max_symb; iter++)
		{
			carry.mas[iter] = AND(summand.mas[iter], addend.mas[iter]);
		}
		//summand = summand ^ addend;
		for (iter = 0; iter < max_symb; iter++)
		{
			summand.mas[iter] = XOR(summand.mas[iter], addend.mas[iter]);
		}
		//addend = (carry << 1);
		addend = copy(&carry);
		offset_left(&addend);
		if (oper_sign == 1)
		{
			if (summand.current_count > real_symb)
			{
				summand.mas[real_symb] = 0;
			}
		}
	}

	normalize(&summand);

	return summand;
}

number difference(number* value1, number* value2) {
	number b = copy(value2), buff;
	if (value2->mas[value2->current_count - 1])
		nonadditional_code(&b);
	else
		additional_code(&b);
	// _b = -b
	// a-b = a + (-b) = a + _b
	buff = addition(value1, &b);

	return buff;
}

number easy_mult(number* value1, number* value2)
{
	number result;
	int a = number_to_int(value1);
	int b = number_to_int(value2);
	
	result = int_to_number(a*b);

	return result;
}

number karatsuba(number* value1, number* value2)
{
	int n; int k; int iter;
	number res = init(), buff1, buff2;
	number a, b, c, d, p1, p2, t, v1, v2;

	// k = n/2
	// v1 = a * (2^k) + b, v2 = c * (2^k) + d
	// p1 = b * d
	// p2 = a * c
	// t = (a+b)*(c+d) - p1 - p2
	// res = p2 * 2^n + t * 2^k + p1

	n = max(value1->current_count, value2->current_count) - 1;
	k = n / 2;

	if (n <= 5)
	{
#ifdef DEBUG
		printf("Start easyMult\n");

		printf("n = %d\n", n);
		printf("k = %d\n", k);

		printf("v1 = ");
		print_number(value1);
		printf("v2 = ");
		print_number(value2);
#endif // DEBUG   
		return easy_mult(value1, value2);
	}
	else
	{
		v1 = copy(value1); v2 = copy(value2);

		a = init(); b = init(); c = init(); d = init();

		for (iter = n - v1.current_count; iter > 0; iter--)
		{
			add_digit(&v1, 0);
		}
		for (iter = n - v2.current_count; iter > 0; iter--)
		{
			add_digit(&v2, 0);
		}

		for (iter = 0; iter < k; iter++)
		{
			add_digit(&b, v1.mas[iter]);
			add_digit(&d, v2.mas[iter]);
		}

		for (iter = k; iter < n; iter++)
		{
			add_digit(&a, v1.mas[iter]);
			add_digit(&c, v2.mas[iter]);
		}

#ifdef DEBUG
		printf("Before all\n");

		printf("n = %d\n", n);
		printf("k = %d\n", k);

		printf("v1 = ");
		print_number(&v1);
		printf("v2 = ");
		print_number(&v2);

		printf("a = ");
		print_number(&a);
		printf("b = ");
		print_number(&b);
		printf("c = ");
		print_number(&c);
		printf("d = ");
		print_number(&d);
#endif // DEBUG                  

		p1 = karatsuba(&b, &d);
		p2 = karatsuba(&a, &c);
		buff1 = addition(&a, &b);
		buff2 = addition(&c, &d);
		t = karatsuba(&buff1, &buff2);

		buff1 = copy(&t);
		t = difference(&buff1, &p1);

		buff1 = copy(&t);
		t = difference(&buff1, &p2);

#ifdef DEBUG
		printf("Berofe offset\np2 = ");
		print_number(&p2);
		printf("t = ");
		print_number(&t);
		printf("p1 = ");
		print_number(&p1);
#endif // DEBUG

		for (iter = 0; iter < 2 * k; iter++)
		{
			offset_left(&p2);
		}

		for (iter = 0; iter < k; iter++)
		{
			offset_left(&t);
		}

#ifdef DEBUG
		printf("After all\np2 = ");
		print_number(&p2);
		printf("t = ");
		print_number(&t);
		printf("p1 = ");
		print_number(&p1);
#endif // DEBUG

		buff1 = copy(&res);
		res = addition(&buff1, &p2);

		buff1 = copy(&res);
		res = addition(&buff1, &p1);

		buff1 = copy(&res);
		res = addition(&buff1, &t);
#ifdef DEBUG
		printf("res = ");
		print_number(&res);
#endif // DEBUG
		////////////////////////////////////////////////////////////////////////////////////////////////
		return res;
	}
}

number multiplication(number* value1, number* value2) {
	number result, a, b;
	a = copy(value1); b = copy(value2);
	int sign = a.mas[a.current_count - 1] + b.mas[b.current_count - 1];
	if (a.mas[a.current_count - 1])
	{
		additional_code(&a);
	}
	if (b.mas[b.current_count - 1])
	{
		additional_code(&b);
	}

	result = karatsuba(&a, &b);

	if (sign == 1) {
		additional_code(&result);
	}
	normalize(&result);
	return result;
}

number division_with_module(number* value1, number* value2, number* ost)
{
	number mod = int_to_number(0), rem = copy(value1), sub = copy(value2);
	number add = int_to_number(1);
	number buff;
	short shifts = 1;

	if (is_zero(value2))
	{
		exit(100);
	}
	if (value2->mas[value2->current_count - 1])
	{
		buff = copy(value2);
		nonadditional_code(&buff);
		mod = division_with_module(value1, &buff, &rem);

		*ost = rem;
		additional_code(&mod);
		return mod;
	}
	if (value1->mas[value1->current_count - 1])
	{
		// b - ( |a| % b )
		buff = copy(value1);
		nonadditional_code(&buff);
		mod = division_with_module(&buff, value2, &rem); // ost = ( |a| % b )

		if (is_zero(&rem))
		{
			buff = int_to_number(0);
			rem = copy(&buff);
		}
		else {
			buff = difference(value2, &rem);
			rem = copy(&buff);

			buff = addition(&mod, &add);
			mod = copy(&buff);
		}
		*ost = rem;
		additional_code(&mod);
		return mod;
	}

	buff = difference(&sub, &rem);
	while (buff.mas[buff.current_count - 1])
	{
		offset_left(&sub);
		offset_left(&add);
		buff = difference(&sub, &rem);
		shifts++;
	}

	while (shifts)
	{
		buff = difference(&rem, &sub);
		while (!buff.mas[buff.current_count - 1])
		{
			buff = difference(&rem, &sub);
			rem = copy(&buff);

			buff = addition(&add, &mod);
			mod = copy(&buff);

			buff = difference(&rem, &sub);
		}
		offset_right(&sub);
		offset_right(&add);
		shifts--;
	}

	normalize(&rem);
	normalize(&mod);
	*ost = rem;
	return mod;
}

number module_pow(number* a, number* t, number* b)
{
	number d, ost, iterator = init(), buff, buff2, buff3;

	add_digit(&iterator, 1);
	buff3 = division_with_module(a, b, &d);
	ost = copy(&d);

	if (is_zero(&d))
	{
		return ost;
	}
	else
	{
		iterator = copy(t);

		ost = int_to_number(1);

		buff2 = copy(a);
		while (!is_zero(&iterator))
		{
			if (iterator.mas[0] % 2 == 1)
			{
				buff = multiplication(&ost, &buff2);
				buff3 = division_with_module(&buff, b, &ost);
			}
			buff = multiplication(&buff2, &buff2);
			buff3 = division_with_module(&buff, b, &buff2);

			offset_right(&iterator);
		}
		buff = copy(&ost);
		buff3 = division_with_module(&buff, b, &ost);
	}
	normalize(&ost);
	return ost;
}

number euclide_algorithm(number* value1, number* value2)
{
	number buff, a, b, mod;

	a = copy(value1);
	if (a.mas[a.current_count - 1])
	{
		nonadditional_code(&a);
	}
	b = copy(value2);
	if (b.mas[b.current_count - 1])
	{
		nonadditional_code(&b);
	}
	buff = difference(&a, &b);
	if (buff.mas[buff.current_count - 1])
	{
		a = copy(value2);
		b = copy(value1);
	}
	else
	{
		a = copy(value1);
		b = copy(value2);
	}
	if (a.mas[a.current_count - 1])
	{
		nonadditional_code(&a);
	}
	if (b.mas[b.current_count - 1])
	{
		nonadditional_code(&b);
	}
	//a = b * q_0 + r_1                          
	buff = division_with_module(&a, &b, &mod);

	if (!is_zero(&mod))
	{
		buff = euclide_algorithm(&b, &mod);
		normalize(&buff);
		return buff;
	}
	else
	{
		normalize(&b);
		return b;
	}
}

number euclide_algorithm_modifyed(number* value1, number* value2, number* values)
{
	number buff, a, b, mod, div, GCD;
	number _a, _b, _c, _d;

	a = copy(value1);
	b = copy(value2);
	buff = difference(&a, &b);
	if (buff.mas[buff.current_count - 1])
	{
		a = copy(value2);
		b = copy(value1);
	}
	else
	{
		a = copy(value1);
		b = copy(value2);
	}
	//a = b * q_0 + r_1  

	div = division_with_module(&a, &b, &mod);
	if (!is_zero(&mod))
	{
		buff = euclide_algorithm_modifyed(&b, &mod, values);
		GCD = copy(&buff);

		_a = copy(&values[0]);
		_b = copy(&values[1]);
		_c = copy(&values[2]);
		_d = copy(&values[3]);

		values[0] = copy(&_b);

		buff = multiplication(&_b, &div);
		values[1] = difference(&_a, &buff);

		values[2] = copy(&_d);

		buff = multiplication(&_d, &div);
		values[3] = difference(&_c, &buff);

		normalize(&GCD);

		return GCD;
	}
	else
	{
		GCD = copy(&b);

		_a = copy(&values[0]);
		_b = copy(&values[1]);
		_c = copy(&values[2]);
		_d = copy(&values[3]);

		values[0] = copy(&_b);

		buff = multiplication(&_b, &div);
		values[1] = difference(&_a, &buff);

		values[2] = copy(&_d);

		buff = multiplication(&_d, &div);
		values[3] = difference(&_c, &buff);

		normalize(&GCD);
		return GCD;
	}
}

number generate_random(int bit_count)
{
	int i;
	number res = init();
	for (i = 0; i < bit_count - 1; i++)
	{
		add_digit(&res, rand() % 2);
	}
	return res;
}

BOOL Millers_method(number* value)
{
	number t, buff, buff2, a, N_minus_1;
	BOOL fl1, fl2;
	number step = int_to_number(1);
	number step2 = int_to_number(2);
	number N_3 = int_to_number(3);
	int n = MILLERS_METHOD_ITERATIONS_NUMBER;
	int s = 0;
	int i, k, j; // iterators

	if (is_equal(value, &step2))
	{
		return TRUE;
	}

	if (is_equal(value, &N_3))
	{
		return TRUE;
	}

	if (!value->mas[0])
	{
		return FALSE;
	}

	//N-1 = 2^s * t, t - �������

	N_minus_1 = difference(value, &step);
	t = copy(&N_minus_1);

	while (t.mas[0] == 0)
	{
		s++;
		offset_right(&t);
	}

	srand((unsigned int)time(NULL));

	for (i = 0; i < n; i++)
	{
		printf("i is %d\n", i);
		fl1 = TRUE;
		fl2 = TRUE;

		a = generate_random(value->current_count - 1);
		buff = difference(&a, &step2);
		while (buff.mas[buff.current_count - 1])
		{
			a = generate_random(value->current_count - 1);
			buff = difference(&a, &step2);
		}

		buff = euclide_algorithm(value, &a);
		if (!is_equal(&buff, &step)) //�������� 1
		{
			fl1 = FALSE;
		}

		buff = module_pow(&a, &t, value);
		if (!is_equal(&buff, &step)) // �������� 2
		{
			fl2 = FALSE;
			for (k = 1; k <= s; k++)
			{
				buff2 = copy(&t);
				for (j = 0; j < k - 1; j++)
				{
					offset_left(&buff2);
				}

				buff = module_pow(&a, &buff2, value);

				if (is_equal(&buff, &N_minus_1))
				{
					//printf("= is %d\n", is_equal(&buff, &N_minus_1));
					fl2 = TRUE;
				}
			}
		}

		if (!fl1 || !fl2)
		{
			return FALSE;
		}
	}

	return TRUE;
}
