/*
** EPITECH PROJECT, 2017
** bootstrap my_printf
** File description:
** same behavior as printf
*/

#include "my_printf.h"

const s_pf_type_t opes[OPE_NUMBER] = {\
	{'c', &pf_c},\
	{'s', &pf_s},\
	{'i', &pf_id},\
	{'d', &pf_id},\
	{'b', &pf_b},\
	{'x', &pf_x},\
	{'X', &pf_x_up},\
	{'u', &pf_u},\
	{'o', &pf_o},\
	{'p', &pf_p},\
	{'S', &pf_up_s},\
	{'%', &pf_mod}\
};

const char flags[FLAG_NUMBER] = {'-', '+', ' ', '0', '#', '.', '*'};

int print_special(char c_sel, char *flags, va_list vl)
{
	for (int i = 0; i < OPE_NUMBER; i++)
		if (opes[i].sign == c_sel)
			return (opes[i].fx(vl, flags));
	return (0);
}

short is_a_flag(char c)
{
	for (int i = 0; i < FLAG_NUMBER; i++) {
		if (c == flags[i])
			return (1);
	}
	return (0);
}

short is_a_ope(char c)
{
	for (int i = 0; i < OPE_NUMBER; i++) {
		if (c == opes[i].sign)
			return (1);
	}
	return (0);
}