#include "input.h"
#include "LCG.h"

int main()
{
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