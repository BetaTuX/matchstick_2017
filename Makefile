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
		global.c \

OBJ	=	$(SRC:%.c=$(SRC_DIR)%.o)

CFLAGS	=	-I include/ -I lib/my/include -Wextra -Wall

LIBDIR	=	lib/my

LIBS	=	-L $(LIBDIR) -lmy

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

bonus:	$(MAKE) re -C $(BONUS)
bonus:	clean
