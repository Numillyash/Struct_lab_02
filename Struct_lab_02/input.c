#include "input.h"

FILE* input_file;

int getch()
{
	return fgetc(input_file);
}

int check_integer(char* string, ull *integer)
{
	int i, str_len;
	char buff[30];
	ull result = 0;
	*integer = result;

	if (string[1] == '=') {
		str_len = strlen(string);
		for (i = 2; i < str_len; i++)
		{
			buff[i - 2] = string[i];
		}
		str_len -= 2;
	}
	else if (string[2] == '=') {
		str_len = strlen(string);
		for (i = 3; i < str_len; i++)
		{
			buff[i - 3] = string[i];
		}
		str_len -= 3;
	}
	else
		return -1;
	if (str_len == 20)
	{
		for (i = 0; i < str_len; i++)
		{
			if (buff[i] < min_digit || buff[i] > max_digit)
				return -1;
		}
		if (buff[0] > '1' 
			|| (buff[0] == '1' && buff[1] > '8') 
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] > '4')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] > '4')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] > '6')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] > '7')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] > '4')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] > '4')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] > '0')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] > '7')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] > '3')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] > '7')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] > '0')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] > '9')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] == '9' && buff[14] > '5')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] == '9' && buff[14] == '5' && buff[15] > '5')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] == '9' && buff[14] == '5' && buff[15] == '5' && buff[16] > '1')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] == '9' && buff[14] == '5' && buff[15] == '5' && buff[16] == '1' && buff[17] > '6')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] == '9' && buff[14] == '5' && buff[15] == '5' && buff[16] == '1' && buff[17] == '6' && buff[18] > '1')
			|| (buff[0] == '1' && buff[1] == '8' && buff[2] == '4' && buff[3] == '4' && buff[4] == '6' && buff[5] == '7' && buff[6] == '4' && buff[7] == '4' && buff[8] == '0' && buff[9] == '7' && buff[10] == '3' && buff[11] == '7' && buff[12] == '0' && buff[13] == '9' && buff[14] == '5' && buff[15] == '5' && buff[16] == '1' && buff[17] == '6' && buff[18] == '1' && buff[19] > '5'))
			return -1;
	}
	else
	{
		for (i = 0; i < str_len; i++)
		{
			if (buff[i] < min_digit || buff[i] > max_digit)
				return -1;
		}
	}
	result = buff[0] - min_digit;
	for (i = 1; i < str_len; i++)
	{
		result *= 10;
		result += buff[i] - min_digit;
	}
	*integer = result;
	return 1;
}

int find_param(int _args_count, char _args[7][30], char* param_name)
{
	int i;
	for (i = 0; i < _args_count; i++)
	{
		if (!strcmp(_args[i], param_name))
		{
			return i;
		}
	}
	return -1;
}

int check_args_wm(WORK_MODE *wm, char _args[7][30], ull* pr_index)
{
	// wm first second etc
	int i;
	int wm_ind = 0;
	ull buff = 0;
	int res;
	int napoln[6] = {0,0,0,0,0,0};

	switch (*wm) {
	case GET_C:
		wm_ind = find_param(GET_C_AC, _args, get_c);
		(pr_index)[0] = (ull)GET_C;
		napoln[0] = 1;
		for (i = 0; i < GET_C_AC; i++)
		{
			if (i != wm_ind)
			{
				if (_args[i][0] == 's' && _args[i][1] == '=')
				{
					if (napoln[1] > 0)
						return -1;
					napoln[1] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[1] = buff;
				}
				if (_args[i][0] == 'm' && _args[i][1] == '=')
				{
					if (napoln[2] > 0)
						return -1;
					napoln[2] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[2] = buff;
				}
			}
		}
		if (!napoln[1] || !napoln[2])
			return -1;
		break;
	case GET_A:
		wm_ind = find_param(GET_A_AC, _args, get_c);
		(pr_index)[0] = (ull)GET_A;
		napoln[0] = 1;
		for (i = 0; i < GET_A_AC; i++)
		{
			if (i != wm_ind)
			{
				if (_args[i][0] == 'm' && _args[i][1] == '=')
				{
					if (napoln[1] > 0)
						return -1;
					napoln[1] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[1] = buff;
				}
			}
		}
		if (!napoln[1])
			return -1;
		break;
	case LCG:
		wm_ind = find_param(LCG_AC, _args, get_c);
		(pr_index)[0] = (ull)LCG;
		napoln[0] = 1;
		for (i = 0; i < LCG_AC; i++)
		{
			if (i != wm_ind)
			{
				if (_args[i][0] == 'a' && _args[i][1] == '=')
				{
					if (napoln[1] > 0)
						return -1;
					napoln[1] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[1] = buff;
				}
				if (_args[i][0] == 'x' && _args[i][1] == '0' && _args[i][2] == '=')
				{
					if (napoln[2] > 0)
						return -1;
					napoln[2] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[2] = buff;
				}
				if (_args[i][0] == 'c' && _args[i][1] == '=')
				{
					if (napoln[3] > 0)
						return -1;
					napoln[3] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[3] = buff;
				}
				if (_args[i][0] == 'm' && _args[i][1] == '=')
				{
					if (napoln[4] > 0)
						return -1;
					napoln[4] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[4] = buff;
				}
				if (_args[i][0] == 'n' && _args[i][1] == '=')
				{
					if (napoln[5] > 0)
						return -1;
					napoln[5] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[5] = buff;
				}
			}
		}
		if (!napoln[1] || !napoln[2] || !napoln[3] || !napoln[4] || !napoln[5])
			return -1;
		break;
	case BITS:
		wm_ind = find_param(BITS_AC, _args, get_c);
		(pr_index)[0] = (ull)BITS;
		napoln[0] = 1;
		for (i = 0; i < BITS_AC; i++)
		{
			if (i != wm_ind)
			{
				if (_args[i][0] == 'a' && _args[i][1] == '=')
				{
					if (napoln[1] > 0)
						return -1;
					napoln[1] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[1] = buff;
				}
				if (_args[i][0] == 'x' && _args[i][1] == '0' && _args[i][2] == '=')
				{
					if (napoln[2] > 0)
						return -1;
					napoln[2] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[2] = buff;
				}
				if (_args[i][0] == 'c' && _args[i][1] == '=')
				{
					if (napoln[3] > 0)
						return -1;
					napoln[3] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[3] = buff;
				}
				if (_args[i][0] == 'm' && _args[i][1] == '=')
				{
					if (napoln[4] > 0)
						return -1;
					napoln[4] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[4] = buff;
				}
				if (_args[i][0] == 'n' && _args[i][1] == '=')
				{
					if (napoln[5] > 0)
						return -1;
					napoln[5] = 1;
					res = check_integer(_args[i], &buff);
					if (res == -1)
						return -1;
					(pr_index)[5] = buff;
				}
			}
		}
		if (!napoln[1] || !napoln[2] || !napoln[3] || !napoln[4] || !napoln[5])
			return -1;
		break;
	default:
		break;
	}
	return 1;
}

int get_wm(char _args[7][30], int _args_count, WORK_MODE *wm)
{
	BOOL is_wm = FALSE;
	int i;

	for (i = 0; i < _args_count; i++)
	{
		if (!strcmp(_args[i], get_c))
		{
			if (is_wm || _args_count != GET_C_AC)
				return -1;
			is_wm = TRUE;
			*wm = GET_C;
		}
		if (!strcmp(_args[i], get_a))
		{
			if (is_wm || _args_count != GET_A_AC)
				return -1;
			is_wm = TRUE;
			*wm = GET_A;
		}
		if (!strcmp(_args[i], lcg))
		{
			if (is_wm || _args_count != LCG_AC)
				return -1;
			is_wm = TRUE;
			*wm = LCG;
		}
		if (!strcmp(_args[i], bits))
		{
			if (is_wm || _args_count != BITS_AC)
				return -1;
			is_wm = TRUE;
			*wm = BITS;
		}
	}
	if (is_wm)
		return 1;
	return -1;
}

int get_param(char* argument)
{
	// number up to 20 symbols
	// prefix up to 5 symbols
	int c = 65537;
	char buff[30];
	int i = 0; // iterator

	for (i = 0; i < 30; i++)
		buff[i] = '\0';
	i = 0;

	while ((c = getch()) == ' ');
	
	while (c != ' ' && c != '\n' && c != EOF)
	{
		buff[i] = c;
		i++;
		if (i > 23)
		{
			return -1;
		}
		c = getch();
	}
	if (c == EOF || c == '\n')
	{
		if (!strcmp(buff, ""))
			return 2;
		strcpy(argument, buff);
		return 3;
	}
	strcpy(argument,buff);
	return 1;
}

int check_input(WORK_MODE* wm, ull *array)
{
	char _args[7][30];
	int i = 0; // iterator
	int ret = 0;

	input_file = fopen(INPUT_FILENAME, "r");
	if (input_file == NULL)
	{
		return -1;
	}
	
	for (i = 0; i < 10; i++)
	{
		ret = get_param(_args[i]);
		if (ret == 2)
		{
			ret = i;
			break;
		}
		if (ret == 3)
		{
			ret = i+1;
			break;
		}
		if (i >= 6 || ret == -1)
		{
			fclose(input_file);
			return -1;
		}
	}

	if (get_wm(_args, ret, wm) == -1)
	{
		fclose(input_file);
		return -1;
	}
	if (check_args_wm(wm, _args, array) == -1)
		return -1;

	return 1;
}