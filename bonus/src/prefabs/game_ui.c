/*
** EPITECH PROJECT, 2018
** cook
** File description:
** ui prefab
*/

#include "my_cook.h"

static void butt_pause(void *data)
{
	bool *paused = (bool *)data;

	*paused = !(*paused);
}

static void butt_quit(void *data)
{
	engine_t *engine = (engine_t *)data;

	engine_changescene(engine, SCN_MENU, false);
}

static int fetch_pause(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *tex_play = fetch_var(engine->textures, "button_resume");
	sfTexture *tex_quit = fetch_var(engine->textures, "button_quit");
	comp_button_t *but1 = component_create_button("pause", \
&(parent_scene->gamemode->paused), tex_play, &butt_pause);
	comp_button_t *but2 = component_create_button("quit", \
engine, tex_quit, &butt_quit);

	if (HAS_FAILED(tex_play) || HAS_FAILED(tex_quit) || !but1 || !but2)
		return (1);
	but1->trans.pos = (sfVector2f){BACKGROUND_WIDTH / 2, \
BACKGROUND_HEIGHT * .33};
	but2->trans.pos = (sfVector2f){BACKGROUND_WIDTH / 2, \
BACKGROUND_HEIGHT * .66};
	scene_addcomponent(parent_scene, (component_t *)but1);
	scene_addcomponent(parent_scene, (component_t *)but2);
	return (0);
}

int prefab_game_ui(engine_t *engine, scene_t *parent_scene)
{
	sfFont *font = fetch_var(engine->fonts, "minecraft");

	if (HAS_FAILED(font))
		return (1);
	if (fetch_pause(engine, parent_scene))
		return (1);
	return (0);
}