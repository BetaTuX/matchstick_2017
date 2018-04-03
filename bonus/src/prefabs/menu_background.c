/*
** EPITECH PROJECT, 2018
** Prefab Background
** File description:
** Background game
*/

#include "graph_matchstick.h"

static void init_background_menu(actor_t *background)
{
	background->rect = (sfIntRect){0, 0, BACKGROUND_WIDTH, \
BACKGROUND_HEIGHT};
}

int prefab_background(engine_t *engine, scene_t *parent_scene, char *bg_tex)
{
	sfTexture *background_txt = fetch_var(engine->textures, bg_tex);
	actor_t *background = NULL;

	if (HAS_FAILED(background_txt))
		return (1);
	background = actor_create("background", background_txt, \
&init_background_menu);
	append(&parent_scene->actors, background);
	background->transform.pos.x = BACKGROUND_WIDTH / 2;
	background->transform.pos.y = BACKGROUND_HEIGHT / 2;
	return (0);
}