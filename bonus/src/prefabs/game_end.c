/*
** EPITECH PROJECT, 2018
** Game Menu
** File description:
** Prefabs for the menu
*/

#include "graph_matchstick.h"

int prefab_game_end(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *exit_button_txt = fetch_var(engine->textures, "button_exit");
	actor_t *exit_button = actor_create("exit_button", exit_button_txt, \
&init_menu_button);

	if (HAS_FAILED(exit_button_txt))
		return (1);
	exit_button->transform.pos.x = BACKGROUND_WIDTH / 2;
	exit_button->transform.pos.y = 800;
	exit_button->transform.scale.x = 1.5;
	exit_button->transform.scale.y = 1.5;
	add_var_exit(exit_button, engine);
	append(&parent_scene->actors, exit_button);
	return (0);
}