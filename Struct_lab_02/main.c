#include "input.h"
#include "output.h"

int main()
{
	ull numbers[6] = {0,0,0,0,0,0};
	WORK_MODE wm;

	int i = check_input(&wm, numbers);

	for (i = 0; i < 6; i++)
	{
		printf("%d\n", numbers[i]);
	}
	printf("%d", i);
}