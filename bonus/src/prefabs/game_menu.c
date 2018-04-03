/*
** EPITECH PROJECT, 2018
** Game Menu
** File description:
** Prefabs for the menu
*/

#include "graph_matchstick.h"

static void transform_button(actor_t *play_button, actor_t *exit_button, \
actor_t *logo, actor_t *howtop)
{
	logo->transform.pos.x = BACKGROUND_WIDTH / 2;
	logo->transform.pos.y = 200;
	play_button->transform.pos.x = BACKGROUND_WIDTH / 2;
	play_button->transform.pos.y = 500;
	howtop->transform.pos.x = BACKGROUND_WIDTH / 2;
	howtop->transform.pos.y = 650;
	play_button->transform.scale.x = 1.5;
	play_button->transform.scale.y = 1.5;
	exit_button->transform.pos.x = BACKGROUND_WIDTH / 2;
	exit_button->transform.pos.y = 800;
	exit_button->transform.scale.x = 1.5;
	exit_button->transform.scale.y = 1.5;
	howtop->transform.scale.x = 1.5;
	howtop->transform.scale.y = 1.5;
}

static void append_of_the_menu(scene_t *parent_scene, actor_t *logo, \
actor_t *exit_button, actor_t *play_button)
{
	append(&parent_scene->actors, logo);
	append(&parent_scene->actors, play_button);
	append(&parent_scene->actors, exit_button);
}

int prefab_game_menu(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *play_button_txt = fetch_var(engine->textures, "button_play");
	sfTexture *exit_button_txt = fetch_var(engine->textures, "button_exit");
	sfTexture *logo_txt = fetch_var(engine->textures, "logo");
	sfTexture *howtop_txt = fetch_var(engine->textures, "button_how2");
	actor_t *play_button = actor_create("play_button", play_button_txt, \
&init_menu_button);
	actor_t *exit_button = actor_create("exit_button", exit_button_txt, \
&init_menu_button);
	actor_t *logo = actor_create("logo", logo_txt, NULL);
	actor_t *howtop = actor_create("but_howtoplay", howtop_txt, \
&init_menu_button);

	if (HAS_FAILED(play_button_txt) || HAS_FAILED(exit_button_txt) || \
play_button == NULL || exit_button == NULL)
		return (1);
	append_of_the_menu(parent_scene, logo, exit_button, play_button);
	append(&parent_scene->actors, howtop);
	add_var_actor(howtop, play_button, exit_button, engine);
	transform_button(play_button, exit_button, logo, howtop);
	return (0);
}