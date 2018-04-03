/*
** EPITECH PROJECT, 2018
** CPE get next line 2017
** File description:
** Return the next line of the fd
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int my_strlim(char *str, char delim)
{
	int len = 0;

	if (str == 0)
		return (-1);
	for (; 1; len++) {
		if (str[len] == delim)
			return (len);
		else if (str[len] == '\0')
			return (-1);
	}
}

static char *my_strcat(char *dest, char *src, bool free_src)
{
	int new_len = ((dest != 0) ? MY_STRLEN(dest) : 0) + MY_STRLEN(src) + 1;
	char *ans = malloc(new_len * sizeof(char));
	int i = 0;

	for (; dest != 0 && i < MY_STRLEN(dest); i++)
		ans[i] = dest[i];
	for (int j = 0; j < MY_STRLEN(src); j++)
		ans[i + j] = src[j];
	ans[new_len - 1] = 0;
	free((free_src) ? src : 0);
	free(dest);
	return (ans);
}

static char *my_strcut(char **str, int ind, e_cut_meth_t meth)
{
	int new_len = (meth) ? ind + 1 : (MY_STRLEN(*str) + 1) - ind;
	char *ans = malloc(new_len * sizeof(char));

	for (int i = 0; i < new_len - 1; i++)
		ans[i] = (*str)[(meth) ? i : MY_STRLEN(*str) - new_len + i];
	if (MY_STRLEN(*str) - (new_len - 1) == 0) {
		free(*str);
		(*str) = "";
	} else
		for (int i = 0; i < MY_STRLEN(*str) - (new_len - 1); i++)
			(*str)[i] = (*str)[(meth) ? (ind + 1) + i : i];
	ans[new_len - 1] = 0;
	return (ans);
}

static char *prep_read_buff(void)
{
	char *buff = malloc((READ_SIZE + 1) * sizeof(char));

	for (int i = 0; i < READ_SIZE + 1; i++)
		buff[i] = '\0';
	return (buff);
}

char *get_next_line(int fd)
{
	static bool eof = false;
	static char *buff = 0;
	char *rd = 0;
	int new_line_ind = my_strlim(buff, '\n');

	if (READ_SIZE <= 0 || fd < 0)
		return (NULL);
	while (new_line_ind == -1 && !eof) {
		rd = prep_read_buff();
		eof = (read(fd, rd, READ_SIZE) == 0);
		rd[READ_SIZE] = '\0';
		buff = my_strcat(buff, rd, true);
		new_line_ind = my_strlim(buff, '\n');
	}
	if (0 < MY_STRLEN(buff) && new_line_ind != -1)
		return (my_strcut(&buff, new_line_ind, new_line_ind != -1));
	else if (eof && 0 == MY_STRLEN(buff))
		return (NULL);
	else
		return (my_strcut(&buff, MY_STRLEN(buff), E_FROM_BEG));
}