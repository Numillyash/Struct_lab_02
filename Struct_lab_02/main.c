#include "input.h"
#include "LCG.h"

int main()
{
	ull numb = 0 + (1 << 10);
	ull n2 = 9237589452;
	number nu = ull_to_number(numb);
	number nu2 = ull_to_number(n2);
	printf("%d\n", is_pow_2(&nu));
	print_number_as_is(&nu);
	printf("%d\n", is_pow_2(&nu2));
	print_number_as_is(&nu2);
	printf("%d %d\n", n2 / numb, n2 % numb);
	number tst, md;
	tst = division_with_module(&nu2, &nu, &md);
	print_number_decimal(&tst);
	print_number_decimal(&md);
	print_number_as_is(&md);
	print_number_as_is(&tst);

	save_init();
	ull numbers[6] = {0,0,0,0,0,0};
	WORK_MODE wm;
	int i = check_input(&wm, numbers);

	if (i == -1)
	{
		save_text("incorrect command");
	}
	else
	{
		switch (wm)
		{
		case GET_C:
			get_c_wm(numbers);
			break;
		case GET_A:
			get_a_wm(numbers);
			break;
		case LCG:
			lcg_wm(numbers);
			break;
		case BITS:
			bits_wm(numbers);
			break;
		default:
			break;
		}
	}

	save_close();
}