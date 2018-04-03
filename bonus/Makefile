##
## EPITECH PROJECT, 2017
## CPE_Pushswap_2017
## File description:
## Makefile
##

NAME	=	graphical_matchstick

SRC_DIR	=	src/

SRC	=	main.c \
		custom_button.c \
		env_checker.c \
		config.c \
		my_intstr.c \
		recipe_eq.c \
		my_float_to_str.c \
		count_sticks.c \
		prefabs/prefab_scenes.c \
		prefabs/menu_button.c \
		prefabs/game_end.c \
		prefabs/game_menu.c \
		prefabs/game_menu_part.c \
		prefabs/game_ui.c \
		prefabs/game_actors.c \
		prefabs/game_stick.c \
		prefabs/game_logo.c \
		prefabs/game_gm.c \
		prefabs/game_ai.c \
		prefabs/menu_background.c \

OBJ	=	$(SRC:%.c=$(SRC_DIR)%.o)

CFLAGS	=	-I include/ \
		-I lib/my/include/ \
		-I lib/mylist/include/ \
		-I lib/myengine/include/ \
		-Wextra -Wall

MY_LIB	=	my
MY_DIR	=	lib/my/

MYLIST_LIB	=	mylist
MYLIST_DIR	=	lib/mylist/

MYENGINE_LIB	=	myengine
MYENGINE_DIR	=	lib/myengine/

LDFLAGS	=	-L $(MY_DIR) -lmy \
		-L $(MYENGINE_DIR) -lmyengine \
		-L $(MYLIST_DIR) -lmylist \
		-lc_graph_prog

CC	=	gcc

all:	$(NAME)

$(NAME):	$(MY_LIB) $(MYLIST_LIB) $(MYENGINE_LIB) $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(MY_LIB):
	$(MAKE) -C $(MY_DIR)

$(MYLIST_LIB):
	$(MAKE) -C $(MYLIST_DIR)

$(MYENGINE_LIB):
	$(MAKE) -C $(MYENGINE_DIR)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug:	CFLAGS += -O0 -s -g
debug:	re

opti:	CFLAGS += -O3
opti:	re
