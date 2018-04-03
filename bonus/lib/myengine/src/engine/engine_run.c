/*
** EPITECH PROJECT, 2018
** my engine
** File description:
** run the engine
*/

#include "engine.h"

static float delta_time(sfClock *clock)
{
	sfTime time = sfClock_getElapsedTime(clock);

	sfClock_restart(clock);
	return ((float)sfTime_asMilliseconds(time) / 1000);
}

void engine_run(engine_t *engine)
{
	sfClock *clock = sfClock_create();

	while (sfRenderWindow_isOpen(engine->wdw)) {
		engine->poll_event(engine);
		engine->tick(engine, delta_time(clock));
		engine->render(engine);
	}
	sfClock_destroy(clock);
}