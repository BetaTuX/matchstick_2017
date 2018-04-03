/*
** EPITECH PROJECT, 2017
** RUNNER 2017
** File description:
** header model
*/

#ifndef __ENGINE_CSFML__
	#define __ENGINE_CSFML__

	#include <SFML/Graphics.h>
	#include <SFML/Audio.h>
	#include <stdbool.h>
	#include "my.h"
	#include "mylist.h"

	#define FAILED (void *)-1
	#define HAS_FAILED(val) (val == FAILED)

	#define INT_MAX 2147483647
	#define INT_MIN -2147483648

	#define UI_PAUSE 0b0001
	#define UI_TYPE 0b1110
	#define UI_BUTTON 0b0010
	#define UI_LABEL 0b0100

	typedef linked_list_t linked_dict_t;
	typedef struct scene scene_t;

	typedef enum layer {
		BACKGROUND = -1,
		SCENE = 0,
		FOREGROUND = 1,
		UI = INT_MAX
	} e_layer_t;

	typedef struct transform {
		sfVector2f pos;
		sfVector2f scale;
		float rot;
	} transform_t;

	typedef struct animation {
		char *name;
		unsigned int row_ind;
		unsigned int frame_number;
		char *next;
	} anim_t;

	typedef struct ui {
		linked_list_t *components;
		void (*event)(scene_t *, sfEvent *evt);
		void (*draw)(scene_t *, sfRenderWindow *);
		void (*destroy)(struct ui *);
	} ui_t;

	typedef struct gamemode {
		bool paused;
		linked_dict_t *var;
		void (*tick)(struct gamemode *, float dta);
		void (*destroy)(struct gamemode *);
	} gamemode_t;

	struct scene {
		gamemode_t *gamemode;
		ui_t *ui;
		linked_list_t *actors;
		sfMusic *bg_music;
		bool pauseable;
		void (*tick)(scene_t *, float dta);
		void (*event)(scene_t *, sfEvent *evt);
		void (*render)(scene_t *, sfRenderWindow *window);
		void (*destroy)(scene_t *);
	};

	typedef struct engine {
		sfRenderWindow *wdw;
		char *active_scene;
		linked_dict_t *textures;
		linked_dict_t *fonts;
		linked_dict_t *sounds;
		linked_dict_t *scenes;
		linked_dict_t *custom_var;
		void (*run)(struct engine *);
		void (*poll_event)(struct engine *);
		void (*tick)(struct engine *, float);
		void (*render)(struct engine *);
		void (*destroy)(struct engine *);
	} engine_t;

	typedef struct actor {
		char *name;
		char *collision_layer;
		sfSprite *spritesheet;
		sfIntRect rect;
		transform_t transform;
		anim_t *anim;
		char *current_anim;
		linked_list_t *custom_var;
		void (*event)(struct actor *, sfEvent *);
		void (*overlap)(struct actor *, struct actor *, scene_t *);
		void (*tick)(struct actor *, float);
		void (*render)(struct actor *, sfRenderWindow *);
		void (*destroy)(struct actor *);
	} actor_t;

	typedef struct component {
		char type;
		void (*destroy)(struct component *self);
		void (*draw)(struct component *self, sfRenderWindow *window);
		char *name;
	} component_t;

	typedef struct label {
		char type;
		void (*destroy)(struct label *self);
		void (*draw)(struct label *self, sfRenderWindow *window);
		char *name;
		sfText *text;
		transform_t trans;
		void *data;
		char *(*data_to_str)(void *data);
	} comp_label_t;

	typedef struct button {
		char type;
		void (*destroy)(struct button *self);
		void (*draw)(struct button *self, sfRenderWindow *window);
		char *name;
		sfSprite *sprite;
		transform_t trans;
		void *data;
		void (*callback)(void *);
	} comp_button_t;

	/* ENGINE */
	engine_t *engine_create(sfRenderWindow *window);
	void engine_run(engine_t *);
	void engine_tick(engine_t *, float);
	void engine_render(engine_t *);
	void engine_pollevent(engine_t *);
	int engine_changescene(engine_t *engine, const char *scene_name, \
bool reset);
	bool mouse_overlap(actor_t *self, sfVector2i *mse_pos);
	int load_textures(engine_t *engine, const char *tex_path[][2], \
int path_nb);
	int load_fonts(engine_t *engine, const char *font_path[][2], \
int path_nb);
	int load_sounds(engine_t *engine, const char *sounds_path[][2], \
int path_nb);

	/* UI */
	ui_t *ui_create(void (*init)(ui_t *));
	void ui_draw(scene_t *parent_scene, sfRenderWindow *window);
	comp_label_t *component_create_label(char *name, void *data, \
sfFont *font, char *(*data_to_str)(void *));
	comp_button_t *component_create_button(char *name, void *data, \
sfTexture *tex, void (*callback)(void *));

	/* GAMEMODE */
	void gamemode_destroy(gamemode_t *gamemode);
	gamemode_t *gamemode_create(void (*init)(gamemode_t *));

	/* SCENES */
	int scene_add(engine_t *engine, char *name, gamemode_t *gamemode, \
ui_t *ui);
	int scene_remove(engine_t *engine, char *name);
	void scene_tick(scene_t *scene, float delta);
	void scene_render(scene_t *scene, sfRenderWindow *window);
	void scene_event(scene_t *scene, sfEvent *event);
	scene_t *scene_fetch(engine_t *engine, const char *scene_name);
	void scene_addcomponent(scene_t *scene, component_t *comp);
	void scene_addactor(scene_t *scene, actor_t *actor);
	void scene_setgamemode(scene_t *scene, gamemode_t *gamemode);
	void scene_setui(scene_t *scene, ui_t *ui);

	/* ACTOR */
	actor_t *actor_create(char *, sfTexture *, void (*init)(actor_t *));
	void actor_destroy(actor_t *);
	void actor_event(actor_t *, sfEvent *evt);
	void actor_overlap(actor_t *self, actor_t *other, scene_t *engine);
	void actor_render(actor_t *actor, sfRenderWindow *wdw);
	void actor_tick(actor_t *actor, float dta);
	void update_anim(actor_t *);
	void add_var(linked_list_t **list, char *id, void *data);
	void *fetch_var(linked_list_t *list, const char *id);
	void destroy_varlist(linked_list_t *var_list);

	#define ACT_X(actor_ref) actor_ref->transform.pos.x
	#define ACT_Y(actor_ref) actor_ref->transform.pos.y
	#define ACT_RECX(actor_ref) actor_ref->rect.x
	#define ACT_RECY(actor_ref) actor_ref->rect.y
#endif