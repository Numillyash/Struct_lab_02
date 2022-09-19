#include "output.h"

FILE* file;

void save_init()
{
	file = fopen(OUTPUT_FILENAME, "w");
	if (file == NULL)
		exit(250);
}

void save_int(ull number)
{
	fprintf(file, "%llu\n", number);
}

void save_bin(ull number)
{
	char bin_f[65] = "\0";
	
	ull del = ((ull) 1) << 63;

	for (int i = 0; i < 64; i++)
	{
		if (number >= del) {
			bin_f[i] = '1';
			number -= del;
		}
		else
			bin_f[i] = '0';
		del >>= 1;
	}

	char* st = strchr(bin_f, '1');
	
	fprintf(file, "%s\n", st);
}

void save_text(char* str)
{
	fprintf(file, "%s\n", str);
}

void save_close()
{
	fclose(file);
}