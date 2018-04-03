/*
** EPITECH PROJECT, 2018
** Reset Scenes
** File description:
** Function who resets scenes when you are leaving it
*/

#include <stdlib.h>
#include "graph_matchstick.h"

static void reset_plate(scene_t *scene)
{
	actor_t *plate = NULL;
	void (*clear)(actor_t *) = NULL;

	for (linked_list_t *cur = scene->actors; cur; cur = cur->next) {
		plate = (actor_t *)cur->data;
		if (plate && plate->name && !my_strcmp(plate->name, "plate"))
			break;
		plate = NULL;
	}
	if (!plate)
		return;
	clear = fetch_var(plate->custom_var, "clear_fx");
	if (!HAS_FAILED(clear))
		clear(plate);
}

static void reset_customers(scene_t *scene)
{
	actor_t *cust = NULL;
	linked_list_t **list = NULL;

	for (linked_list_t *cur = scene->actors; cur; cur = cur->next) {
		cust = (actor_t *)cur->data;
		if (cust && cust->name && !my_strcmp(cust->name, "customers"))
			break;
		cust = NULL;
	}
	if (!cust)
		return;
	list = fetch_var(cust->custom_var, "customers");
	if (HAS_FAILED(list))
		return;
	for (linked_list_t *cur = *list; *list;) {
		((actor_t *)(*list)->data)->destroy((actor_t *)(*list)->data);
		cur = *list;
		*list = (*list)->next;
		free(cur);
	}
}

static void reset_customers_clock(scene_t *scene)
{
	actor_t *custo = NULL;
	sfClock *timer = NULL;

	for (linked_list_t *cur = scene->actors; cur; cur = cur->next) {
		custo = (actor_t *)cur->data;
		if (custo && custo->name && \
!my_strcmp(custo->name, "customers"))
			break;
		custo = NULL;
	}
	if (!custo)
		return;
	timer = fetch_var(custo->custom_var, "timer");
	if (!HAS_FAILED(timer))
		sfClock_restart(timer);
}

void game_gm_reset(scene_t *scene)
{
	float *time_left = fetch_var(scene->gamemode->var, "time_left");
	int *fail_nb = fetch_var(scene->gamemode->var, "fail_nb");
	int *score = fetch_var(scene->gamemode->var, "score");

	scene->gamemode->paused = false;
	reset_plate(scene);
	reset_customers(scene);
	reset_customers_clock(scene);
	if (HAS_FAILED(time_left) || HAS_FAILED(fail_nb) || HAS_FAILED(score))
		return;
	*(time_left) = TIME_BEGIN;
	*fail_nb = 0;
	*score = 0;
}