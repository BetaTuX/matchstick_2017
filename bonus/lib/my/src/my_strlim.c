/*
** EPITECH PROJECT, 2018
** My lib 2018
** File description:
** str to limit
*/

int my_strlim(char *str, char delim)
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