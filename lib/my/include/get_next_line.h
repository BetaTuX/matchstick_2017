/*
** EPITECH PROJECT, 2018
** CPE get next line 2017
** File description:
** getnextline header
*/

#ifndef GET_NEXT_LINE_H_
#include <stdbool.h>
	#define GET_NEXT_LINE_H_
	#ifndef READ_SIZE
		#define READ_SIZE (10)
	#endif

	typedef enum {
		E_FROM_BEG = true,
		E_TO_END = false
	} e_cut_meth_t;

	char *get_next_line(int file_descriptor);

	#define MY_STRLEN(str) my_strlim(str, '\0')
#endif