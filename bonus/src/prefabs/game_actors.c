/*
** EPITECH PROJECT, 2018
** Game game
** File description:
** Prefabs for the game
*/

#include "graph_matchstick.h"

static int create_sticks(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *act_stick_tex = fetch_var(engine->textures, "act_stick");
	sfVector2u vec;
	actor_t *act = NULL;

	if (HAS_FAILED(act_stick_tex))
		return (1);
	vec = sfTexture_getSize(act_stick_tex);
	for (int i = 0; i < STICK_NB; i++) {
		act = actor_create("stick", act_stick_tex, &stick_init);
		if (!act)
			continue;
		act->transform.pos.x = \
110 + (i * ((vec.x * act->transform.scale.x) + 13));
		act->transform.pos.y = 780;
		scene_addactor(parent_scene, act);
	}
	return (0);
}

static int create_logo(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *act_logo_tex = fetch_var(engine->textures, "logo");
	actor_t *act = NULL;

	if (HAS_FAILED(act_logo_tex))
		return (1);
	act = actor_create("logo", act_logo_tex, &logo_init);
	if (!act)
		return (1);
	add_var(&(act->custom_var), "parent_scene", parent_scene);
	act->transform.pos.x = BACKGROUND_WIDTH;
	act->transform.pos.y = BACKGROUND_HEIGHT;
	scene_addactor(parent_scene, act);
	return (0);
}

int prefab_game_actors(engine_t *engine, scene_t *parent_scene)
{
	if (create_sticks(engine, parent_scene))
		return (1);
	if (create_logo(engine, parent_scene))
		return (1);
	return (0);
}