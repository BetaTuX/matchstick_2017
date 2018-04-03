/*
** EPITECH PROJECT, 2017
** bootstrap my_printf
** File description:
** same behavior as printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

static int print_fstr(char *str, va_list vl);
static char *get_flags(char const *str, int *ind);

char *get_flags(char const *str, int *ind)
{
	int start = *ind;
	char *ans = malloc(sizeof(char));

	for (;str[*ind] != '\0' && (is_a_flag(str[*ind]) || IS_NUM(str[*ind]));\
*ind += 1);
	if (is_a_ope(str[*ind]) && start != *ind) {
		free(ans);
		ans = my_strpick(str, start, *ind);
	} else if (!is_a_ope(str[*ind]) && str[*ind] != '\0'){
		ans[0] = '\0';
		*ind = start - 1;
	} else {
		ans[0] = '\0';
		*ind = start;
	}
	return (ans);
}

int print_fstr(char *str, va_list vl)
{
	int chr_nb = 0;
	int chr_start;
	char *flags = "";
	char *classic_str = "";

	for (int j = 0; j < my_strlen(str); j++) {
		chr_start = j;
		for (; j < my_strlen(str) && str[j] != '%'; j++);
		classic_str = my_strpick(str, chr_start, j);
		my_putstr(classic_str);
		free(classic_str);
		chr_nb += j - chr_start;
		if (str[j] == '%') {
			j++;
			flags = get_flags(str, &j);
			chr_nb += print_special(str[j], flags, vl);
		}
	}
	return (chr_nb);
}

int my_printf(char *str, ...)
{
	int chr_nb = 0;
	va_list vl;

	va_start(vl, str);
	chr_nb = print_fstr(str, vl);
	va_end(vl);
	return (chr_nb);
}