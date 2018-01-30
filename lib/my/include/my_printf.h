/*
** EPITECH PROJECT, 2017
** Printf lib 2017
** File description:
** printf header
*/

#ifndef __MY_PF__
#define __MY_PF__

#include <stdarg.h>

#define IS_NUM(value) ('0' <= value && value <= '9')
#define OPE_NUMBER 12
#define FLAG_NUMBER 7

typedef struct pf_type {
	char sign;
	int (*fx)(va_list, char *);
} s_pf_type_t;

int pf_c(va_list vl, char *flags);
int pf_id(va_list vl, char *flags);
int pf_s(va_list vl, char *flags);
int pf_b(va_list vl, char *flags);
int pf_s(va_list vl, char *flags);
int pf_up_s(va_list vl, char *flags);
int pf_mod(va_list vl, char *flags);
int pf_x(va_list vl, char *flags);
int pf_x_up(va_list vl, char *flags);
int pf_o(va_list vl, char *flags);
int pf_u(va_list vl, char *flags);
int pf_p(va_list vl, char *flags);
int print_special(char c_sel, char *flags, va_list vl);
short is_a_flag(char c);
short is_a_ope(char c);
int offset_sflag(char *str, char *flags);
int offset_iflag(int nbr, char *flags);
int offset_oflag(unsigned int nbr, char *flags);
int my_printf(char *str, ...);

#endif