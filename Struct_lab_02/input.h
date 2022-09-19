#pragma once
#include "config.h"

// Exist
// s m a x0 c n 
// array:
// a c n m s x0
// 
// cn cx m
// m
// inp
// size - 6

// check digit
#define min_digit '0'
#define max_digit '9'

// arguments
#define get_c "get_c"
#define get_a "get_a"
#define lcg "lcg"
#define test "test"

int check_input(WORK_MODE* wm, ull* array, char* inp_file);
