##
## EPITECH PROJECT, 2017
## CPE_Pushswap_2017
## File description:
## Makefile
##

NAME	=	matchstick

SRC_DIR	=	src/

SRC	=	main.c \
		display_map.c \
		player.c \
		ai.c \
		ai_utils.c \
		ai_calculation.c \
		global.c \

OBJ	=	$(SRC:%.c=$(SRC_DIR)%.o)

CFLAGS	=	-I include/ -I lib/my/include -Wextra -Wall

LIBDIR	=	lib/my

LIBS	=	-L $(LIBDIR) -lmy

UT_DIR	=	tests/

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C $(LIBDIR)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	$(MAKE) clean -C $(LIBDIR)
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C $(LIBDIR)
	rm -f $(NAME)

re:	fclean all

debug:	CFLAGS += -O0 -s -g
debug:	re

tests_run:	all
	$(MAKE) -C $(UT_DIR)
	$(UT_DIR)test

tests_clean:
	$(MAKE) clean -C $(UT_DIR)

tests_fclean:
	$(MAKE) fclean -C $(UT_DIR)