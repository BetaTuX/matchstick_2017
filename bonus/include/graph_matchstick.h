/*
** EPITECH PROJECT, 2018
** Grapical_matchstick
** File description:
** graphical bonus header for matchstick
*/

#ifndef GRAPH_MATCHSITCK_H_
	#define GRAPH_MATCHSITCK_H_
	#include "engine.h"

	#define TEX_NB 11
	#define FONT_NB 2
	#define SOUND_NB 6

	extern const char *SCN_MENU;
	extern const char *SCN_GAME;
	extern const char *SCN_WIN;
	extern const char *SCN_LOST;
	extern const int STICK_NB;
	extern const int BACKGROUND_WIDTH;
	extern const int BACKGROUND_HEIGHT;
	extern const char *tex[TEX_NB][2];
	extern const char *font[FONT_NB][2];
	extern const char *sounds[SOUND_NB][2];

	typedef enum {
		E_PLAYER = 0,
		E_AI = 1
	} e_turn_t;

	int prefab_scene_game(engine_t *engine);
	int prefab_scene_menu(engine_t *engine);
	int prefab_scene_win(engine_t *engine);
	int prefab_scene_lost(engine_t *engine);
	int get_env_var_ind(char **, char *);
	int gm_ai(scene_t *parent_scene);
	char *my_intstr(int nbr);
	char *my_float_to_str(float nbr);
	void init_menu_button(actor_t *button);
	void add_var_actor(actor_t *howtop, actor_t *play_button, \
actor_t *exit_button, engine_t *engine);
	int prefab_game_menu(engine_t *engine, scene_t *parent_scene);
	int prefab_game_gm(engine_t *engine, scene_t *parent_scene);
	int prefab_game_ui(engine_t *engine, scene_t *parent_scene);
	int prefab_background(engine_t *engine, scene_t *parent_scene, char *);
	int prefab_game_end(engine_t *engine, scene_t *parent_scene);
	int prefab_game_actors(engine_t *engine, scene_t *parent_scene);
	void add_var_exit(actor_t *exit_button, engine_t *engine);
	void stick_init(actor_t *actor);
	void logo_init(actor_t *actor);
	int count_actor_named(scene_t *scn, char *name);
	int count_selected_stick(scene_t *scn);

	/* STATIC INLINE FXs */
	static inline char *floatdata_to_str(void *data)
	{
		return (my_float_to_str(*(float *)data));
	}

	static inline char *intdata_to_str(void *data)
	{
		return (int_to_str(*(int *)data));
	}

	static inline int stick_selected(actor_t *v1, actor_t *v2)
	{
		bool *selected = fetch_var(\
(v1) ? v1->custom_var : v2->custom_var, "selected");

		if (!HAS_FAILED(selected))
			return (!(*selected));
		return (1);
	}

	static inline int actor_is_stick(actor_t *v1, actor_t *v2)
	{
		char *name = (v1) ? v1->name : v2->name;

		if (!HAS_FAILED(name))
			return (my_strcmp(name, "stick"));
		return (1);
	}

	#define DICT_RET(Fx_name, Type, ...) \
	\
		static Type *Fx_name(linked_dict_t *list, const char *id) \
		{ \
			return ((Type *)fetch_var(list, id)); \
		}
#endif