#ifndef CONFIG_H
#define CONFIG_H

#define _CRT_SECURE_NO_WARNINGS
//#define DEBUG

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdint.h>
#include <locale.h>
#include <sys/stat.h>

// files
#define INPUT_FILENAME "input.txt"
#define OUTPUT_FILENAME "output.txt"
#define FILE_OPENING_ERROR "Cannot open the %s file.\n"

// boolean
#define BOOL int
#define TRUE 1
#define FALSE 0

/// <summary>
/// Exit codes for exit()
/// </summary>
enum EXIT_CODE {
	SUCCESS,
	FAILURE,
	ARGUMENT_FAILURE,
	FILE_OPEN_FAILURE,
	DEBUG_EXIT_CODE = 100
};

// work mode
typedef enum {
	GET_C,
	GET_A,
	LCG,
	TEST
}WORK_MODE;

enum {
	GET_C_AC = 4,
	GET_A_AC = 2,
	LCG_AC = 6,
	TEST_AC = 2
}WM_ARG_COUNT;

// fast funcs
#define swap(a,b); b = a+b; a = b-a; b = b-a;
#ifdef _WIN32
#else
#define max(a,b) (a>b)? a : b
#endif
#define ull unsigned long long

#endif // !CONFIG_H