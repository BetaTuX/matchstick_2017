##
## EPITECH PROJECT, 2017
## Header makefile
## File description:
## makefile for libmy
##

CC	=	gcc

CFLAGS	+=	-I ./include -W -Wall

SRC_DIR	=	src/

SRC	=	actor/animations/update_anim.c \
		actor/actor_event.c \
		actor/actor_management.c \
		actor/actor_utilities.c \
		engine/gamemode/gamemode_basics.c \
		engine/ui/ui_basics.c \
		engine/ui/ui_draw.c \
		engine/ui/components/components_management.c \
		engine/ui/components/component_button.c \
		engine/scenes/scene_event.c \
		engine/scenes/scene_manager.c \
		engine/scenes/scene_utilities.c \
		engine/scenes/scene_addobj.c \
		engine/engine_customvar.c \
		engine/engine_events.c \
		engine/engine_management.c \
		engine/engine_utilities.c \
		engine/engine_run.c \
		engine/engine_mouse.c \
		assets_loading.c \

LDFLAGS	=	-L ../mylist -lmylist \
		-L ../my -lmy \

OBJ	=	$(SRC:%.c=$(SRC_DIR)%.o)

NAME	=	libmyengine.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

debug:	CFLAGS += -O0 -s -g
debug:	re
