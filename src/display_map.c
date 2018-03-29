/*
** EPITECH PROJECT, 2017
** matchsitkc
** File description:
** map display
*/

#include "my.h"
#include "matchstick.h"

static int process_width(int line_ind)
{
	int ans = 1;

	for (int i = 0; i < line_ind; i++)
		ans += 2;
	return (ans);
}

static void display_line(int *map, int line_ind, int size)
{
	int displayed_chr = 0;

	for (int i = 1; \
i < (process_width(size) - process_width(line_ind)) / 2; i++)
		displayed_chr += my_putchar(' ');
	for (int i = 0; i < map[line_ind]; i++)
		displayed_chr += my_putchar('|');
	for (int i = 1; i < (process_width(size) - displayed_chr - 1); i++)
		my_putchar(' ');
}

void display_map(int *map, int size)
{
	int length = process_width(size);
	for (int i = 0; i < length; i++)
		my_putchar('*');
	my_putchar('\n');
	for (int i = 0; i < size; i++) {
		my_putchar('*');
		display_line(map, i, size);
		my_putstr("*\n");
	}
	for (int i = 0; i < length; i++)
		my_putchar('*');
	my_putchar('\n');
}