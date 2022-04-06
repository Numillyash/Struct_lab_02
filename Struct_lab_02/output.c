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

void save_text(char* str)
{
	fprintf(file, "%s\n", str);
}

void save_close()
{
	fclose(file);
}