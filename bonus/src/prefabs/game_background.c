/*
** EPITECH PROJECT, 2018
** Prefabs to Game Background
** File description:
** Prefabs for the background components
*/

#include "graph_matchstick.h"

static void transform_actor(actor_t *game_bg, actor_t *table, \
actor_t *comptoir, actor_t *sign)
{
	game_bg->transform.pos.x = BACKGROUND_WIDTH / 2;
	game_bg->transform.pos.y = BACKGROUND_HEIGHT / 2;
	table->transform.pos.x = BACKGROUND_WIDTH / 2;
	table->transform.pos.y = BACKGROUND_HEIGHT / 2;
	comptoir->transform.pos.x = BACKGROUND_WIDTH / 2;
	comptoir->transform.pos.y = BACKGROUND_HEIGHT / 2;
	sign->transform.pos.x = 130;
	sign->transform.scale.x = 1.5;
	sign->transform.pos.y = 50;
}

static void move_knuckles(actor_t *self, sfEvent *evt)
{
	int actual_pos = (int)self->transform.pos.x;

	if (!evt)
		return;
	if (actual_pos - evt->mouseMove.x > 0 && evt->type == sfEvtMouseMoved)
		self->transform.scale.x = 1;
	else if (actual_pos - evt->mouseMove.x < 0 && \
evt->type == sfEvtMouseMoved)
		self->transform.scale.x = -1;
	if (evt->type == sfEvtMouseMoved)
		self->transform.pos.x = evt->mouseMove.x;
	else if (evt->type == sfEvtMouseButtonPressed)
		self->transform.pos.x = evt->mouseButton.x;
	else
		return;
}

static void create_knuckles(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *knuckles_txt = fetch_var(engine->textures, "knuckles");
	actor_t *knuckles = actor_create("knuckles", knuckles_txt, NULL);

	append(&parent_scene->actors, knuckles);
	knuckles->transform.pos.x = BACKGROUND_WIDTH / 2;
	knuckles->transform.pos.y = BACKGROUND_HEIGHT - 350;
	knuckles->event = &move_knuckles;
}

int prefab_game_bg(engine_t *engine, scene_t *parent_scene)
{
	sfTexture *background_txt = fetch_var(engine->textures, "game_bg");
	sfTexture *table_txt = fetch_var(engine->textures, "table");
	sfTexture *comptoir_txt = fetch_var(engine->textures, "comptoir");
	sfTexture *sign_txt = fetch_var(engine->textures, "sign");
	actor_t *game_bg = actor_create("game_bg", background_txt, NULL);
	actor_t *table = actor_create("table", table_txt, NULL);
	actor_t *comptoir = actor_create("comptoir", comptoir_txt, NULL);
	actor_t *sign = actor_create("sign", sign_txt, NULL);

	if (HAS_FAILED(background_txt) || game_bg == NULL || \
HAS_FAILED(table_txt) || table == NULL || HAS_FAILED(comptoir_txt) || \
!comptoir || !sign || HAS_FAILED(sign_txt))
		return (1);
	append(&parent_scene->actors, game_bg);
	prefab_game_customers(engine, parent_scene);
	append(&parent_scene->actors, comptoir);
	create_knuckles(engine, parent_scene);
	append(&parent_scene->actors, table);
	append(&parent_scene->actors, sign);
	transform_actor(game_bg, table, comptoir, sign);
	return (0);
}
