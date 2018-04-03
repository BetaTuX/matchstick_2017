/*
** EPITECH PROJECT, 2018
** cook
** File description:
** engine prefab
*/

#include <stdlib.h>
#include "my.h"
#include "graph_matchstick.h"

DICT_RET(fetch_turn, e_turn_t);

static int play_validate(scene_t *parent_scene)
{
	e_turn_t *turn = fetch_turn(parent_scene->gamemode->var, "turn");
	int stick_selected_nb = count_selected_stick(parent_scene);

	if (HAS_FAILED(turn))
		return (1);
	if (stick_selected_nb <= 0 || 3 < stick_selected_nb)
		return (0);
	my_delete_nodes(&(parent_scene->actors), NULL, &stick_selected);
	*turn = E_AI;
	return (0);
}

static void game_gm_tick(gamemode_t *self, UNUSED float delta)
{
	e_turn_t *turn = fetch_turn(self->var, "turn");
	scene_t *scn = fetch_var(self->var, "parent_scene");
	engine_t *engine = fetch_var(self->var, "engine");

	if (HAS_FAILED(turn) || HAS_FAILED(scn) || HAS_FAILED(engine))
		return;
	if (count_actor_named(scn, "stick") == 0) {
		engine_changescene(engine, SCN_LOST, false);
		return;
	}
	if (*turn == E_AI) {
		gm_ai(scn);
		*turn = E_PLAYER;
	}
	if (count_actor_named(scn, "stick") == 0)
		engine_changescene(engine, SCN_WIN, false);
}

static void game_gm_destroy(gamemode_t *self)
{
	void *turn = fetch_turn(self->var, "turn");

	if (!HAS_FAILED(turn))
		free(turn);
	gamemode_destroy(self);
}

static int add_custom_vars(gamemode_t *gm)
{
	e_turn_t *turn = malloc(sizeof(*turn));

	if (!turn)
		return (1);
	*turn = E_PLAYER;
	add_var(&(gm->var), "turn", turn);
	return (0);
}

int prefab_game_gm(engine_t *engine, scene_t *parent_scene)
{
	gamemode_t *gm = parent_scene->gamemode;

	if (add_custom_vars(gm))
		return (1);
	add_var(&(gm->var), "engine", engine);
	add_var(&(gm->var), "parent_scene", parent_scene);
	add_var(&(gm->var), "play_validate", &play_validate);
	gm->tick = &game_gm_tick;
	gm->destroy = &game_gm_destroy;
	return (0);
}