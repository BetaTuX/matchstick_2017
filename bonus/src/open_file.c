/*
** EPITECH PROJECT, 2018
** Get Next Line Macros
** File description:
** Macros for the get_next_line projet
*/

#include "xml.h"

int get_file(char *path)
{
	int fd = 0;

	if (!path)
		return (NULL);
	if ((fd = open(path, O_RDONLY)) == -1) {
		my_printf("ERROR: THIS FILE DOESN'T EXIST!\n");
		return (NULL);
	} else {
		return (fd);
	}
	return (NULL);
}

char **parse_line(int fd)
{
	char *line = NULL;
	char **args = NULL;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	if (line[0] != '<' || line[my_strlen(line) - 1] != '>')
		return (NULL);
	args = my_str_to_word_array(line);
	return (args);
}

char **parse_arguments(char *args)
{
	char **parse = NULL;
	int line = 0;
	int k = 0;

	parse = malloc((sizeof(*parse) * 2) + 3);
	if (parse == NULL)
		return (NULL);
	parse[line] = malloc(sizeof(*parse) * my_strlen(args));
	for (int carac = 0; args[carac] != '\0'; carac += 1) {
		if (args[carac] == '=') {
			parse[line][k] = '\0';
			carac += 2;
			line += 1;
			k = 0;
			parse[line] = malloc(sizeof(*parse) * my_strlen(args));
		}
		parse[line][k] = args[carac];
		k += 1;
	}
	parse[line][k - 1] = '\0';
	return (parse);
}