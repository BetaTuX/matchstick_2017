/*
** EPITECH PROJECT, 2018
** Includes for my cook
** File description:
** Functions used for my cook
*/

#ifndef __MY_COOK_
#define __MY_COOK_
	#include "engine.h"

	#define BACKGROUND_WIDTH 1280
	#define BACKGROUND_HEIGHT 960

	#define TEX_NB 38
	#define FONT_NB 2
	#define SOUND_NB 2
	#define RECIPES_NB 4

	#define TIME_BEGIN 30.0
	#define INGREDIENT_MAX 3
	#define INGREDIENT_START 18
	#define INGREDIENT_END 26

	#define RECIPE_SUCC_BONUS 3.0
	#define RECIPE_SUCC 50
	#define RECIPE_FAIL 20
	#define CUSTOMER_SPWN_MIN 3
	#define CUSTOMER_SPWN_MAX 8
	#define CUSTOMER_WAIT 9.0
	#define CUSTOMER_START 6
	#define CUSTOMER_END 10
	#define CUSTOMER_OFFSET 250
	#define CUSTOMER_SPACEMENT 400

	#define SCN_MENU "menu"
	#define SCN_GAME "game"
	#define SCN_CRDT "credits"
	#define SCN_HOW2 "how_to"
	#define SCN_ENDG "end"

	extern const char *tex[TEX_NB][2];
	extern const char *font[FONT_NB][2];
	extern const char *sounds[SOUND_NB][2];
	extern const char *recipes[RECIPES_NB][INGREDIENT_MAX + 1];

	void plate_event(actor_t *self, sfEvent *evt);
	void button_init(actor_t *);
	int get_env_var_ind(char **env, char *identifier);
	bool recipe_eq(char *recipe[3], char *ingredients[3]);
	char *my_float_to_str(float nbr);
	char *my_intstr(int nbr);
	void game_gm_add_ingredient(scene_t *parent_scene, actor_t *ingredient);
	void game_gm_order_send(scene_t *scene, char *recipe);
	void game_gm_customer_flee(scene_t *scene, actor_t *customer);
	void game_gm_reset(scene_t *scene);
	int add_customer_randomly(engine_t *engine, scene_t *parent_scene);
	void add_var_actor(actor_t *howtop, actor_t *play_button, \
actor_t *exit_button, engine_t *engine);

	/* PREFAB */
	int prefab_game_ui(engine_t *engine, scene_t *parent_scene);
	int prefab_game_menu(engine_t *engine, scene_t *parent_scene);
	int prefab_background(engine_t *engine, scene_t *parent_scene);
	int prefab_game_gm(engine_t *engine, scene_t *parent_scene);
	int prefab_game_bg(engine_t *engine, scene_t *parent_scene);
	int prefab_game_ingredients(engine_t *engine, scene_t *parent_scene);
	int prefab_game_customers(engine_t *engine, scene_t *parent_scene);
	int prefab_game_recipes(engine_t *engine, scene_t *parent_scene);
	int prefab_howtoplay(engine_t *engine, scene_t *parent_scene);
	int prefab_end_bg(engine_t *engine, scene_t *parent_scene);
	int prefab_scene_game(engine_t *engine);
	int prefab_scene_menu(engine_t *engine);
	int prefab_scene_how2(engine_t *engine);
	int prefab_scene_endg(engine_t *engine);

	/* ACTOR PREFAB/INIT */
	void plate_init(actor_t *plate);
	void plate_render(actor_t *self, sfRenderWindow *wdw);
	void button_init(actor_t *);
	void init_menu_button(actor_t *);
	void init_game_button(actor_t *);
	void pnj_init(actor_t *);
	void customers_init(actor_t *);
	void customers_tick(actor_t *self, float dta);
	void recipes_init(actor_t *self);

	/* STATIC INLINE FXs */
	static inline char *floatdata_to_str(void *data)
	{
		return (my_float_to_str(*(float *)data));
	}

	static inline char *intdata_to_str(void *data)
	{
		return (int_to_str(*(int *)data));
	}

	static inline int customer_eq(void *act1, void *act2)
	{
		return (!(act1 == act2));
	}

#endif