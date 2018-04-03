##
## EPITECH PROJECT, 2017
## Header makefile
## File description:
## makefile for libmy
##

CC	=	gcc

CFLAGS	+=	-I ./include -W -Wall

SRC_DIR	=	src/

SRC	=	convert_base.c \
		flag.c \
		more_operations.c \
		my_find_prime_sup.c \
		my_getnbr_base.c \
		my_getnbr.c \
		my_int_to_str.c \
		my_isneg.c \
		my_is_prime.c \
		my_power.c \
		my_printf.c \
		my_putchar.c \
		my_puterr.c \
		my_putnbr_base.c \
		my_putnbr_base_uint.c \
		my_putnbr.c \
		my_putstr.c \
		my_revstr.c \
		my_showmem.c \
		my_showstr.c \
		my_show_word_array.c \
		my_sort_int_array.c \
		my_square_root.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strpick.c \
		my_strstr.c \
		my_str_to_word_array.c \
		my_strupcase.c \
		my_swap.c \
		nbrlen.c \
		operations.c \
		string_operations.c \
		verification.c \
		get_next_line.c \
		my_nbrstr.c \
		my_strlim.c \
		match.c \
		free_it.c \

OBJ	=	$(SRC:%.c=$(SRC_DIR)%.o)

NAME	=	libmy.a

all: 	$(NAME)

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

debug:	CFLAGS += -O0 -s -g
debug:	re
