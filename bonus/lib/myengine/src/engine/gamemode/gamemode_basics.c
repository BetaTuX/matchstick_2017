/*
** EPITECH PROJECT, 2018
** engine
** File description:
** gamemode basic
*/

#include <stdlib.h>
#include "engine.h"

static void gamemode_tick(UNUSED gamemode_t *gamemode, UNUSED float dta)
{
	return;
}

void gamemode_destroy(gamemode_t *gamemode)
{
	if (!gamemode)
		return;
	destroy_varlist(gamemode->var);
	free(gamemode);
}

gamemode_t *gamemode_create(void (*init)(gamemode_t *))
{
	gamemode_t *gm = malloc(sizeof(*gm));

	if (!gm)
		return (NULL);
	gm->paused = false;
	gm->var = NULL;
	gm->tick = &gamemode_tick;
	gm->destroy = &gamemode_destroy;
	if (init)
		init(gm);
	return (gm);
}