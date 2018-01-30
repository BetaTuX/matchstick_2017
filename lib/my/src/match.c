/*
** EPITECH PROJECT, 2017
** CPool_match
** File description:
** match
*/

#include "my.h"
#include "match.h"

static int next_char_to_find(s_str *str)
{
	int ans = 0;

	for (; (*str).str[(*str).ind] != '\0' && (*str).str[(*str).ind] == '*';\
str -> ind += 1)
		ans = ((*str).str[(*str).ind] == '*') ? 1 : ans;
	return (ans);
}

static int browse_str(s_str *s1, s_str *s2, int *i, int *f_star)
{
	for (*i = 0; (*s1).ind <= (*s1).len && (*s2).ind <= (*s2).len;\
(*s1).ind += 1) {
		if ((*s2).str[(*s2).ind + *i] == '*')
			return (1);
		if ((*s2).str[(*s2).ind + *i] == '\0' && \
(*s1).str[(*s1).ind] == '\0')
			return (2);
		if ((*s1).str[(*s1).ind] != (*s2).str[(*s2).ind + *i] &&\
f_star) {
			(*s1).ind += (*i == 0);
			return (0);
		}
		if ((*s1).str[(*s1).ind] != (*s2).str[(*s2).ind + *i] &&\
!f_star)
			return (-1);
		if ((*s1).str[(*s1).ind] == (*s2).str[(*s2).ind + *i])
			*i += 1;
	}
	return (0);
}

int my_match(char const *s1, char const *s2)
{
	s_str s_s1 = {s1, my_strlen(s1), 0};
	s_str s_s2 = {s2, my_strlen(s2), 0};
	int i = 0;
	int f_star = 0;

	f_star = next_char_to_find(&s_s2);
	while (s_s1.ind < s_s1.len) {
		switch (browse_str(&s_s1, &s_s2, &i, &f_star)) {
		case -1:
			return (0);
			break;
		case 1 :
			s_s2.ind += i;
			i = 0;
			f_star = next_char_to_find(&s_s2);
			break;
		case 2:
			return (1);
		}
	}
	return (s_s2.str[s_s2.ind] == '\0' && s_s1.str[s_s1.ind] == '\0');
}
