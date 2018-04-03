/*
** EPITECH PROJECT, 2018
** Runer 017
** File description:
** Engine events manangement
*/

#include "engine.h"

static bool is_in(sfVector2f ref, sfVector2f oth, sfIntRect area)
{
	if (!(oth.x <= ref.x && ref.x<= oth.x + area.width))
		return (false);
	if (!(oth.y <= ref.y && ref.y<= oth.y + area.height))
		return (false);
	return (true);
}

static void is_overlap(scene_t *scene, actor_t *ref, actor_t *oth)
{
	if (!my_strcmp(ref->collision_layer, oth->collision_layer)) {
		if (is_in(ref->transform.pos, oth->transform.pos, oth->rect) \
|| is_in((sfVector2f){ref->transform.pos.x + ref->rect.width, \
ref->transform.pos.y}, oth->transform.pos, oth->rect) \
|| is_in((sfVector2f){ref->transform.pos.x + ref->rect.width, \
ref->transform.pos.y + ref->rect.height}, oth->transform.pos, oth->rect) \
|| is_in((sfVector2f){ref->transform.pos.x, \
ref->transform.pos.y + ref->rect.height}, oth->transform.pos, oth->rect)) {
			ref->overlap(ref, oth, scene);
		}
	}
}

static void check_overlap(scene_t *scene)
{
	linked_list_t *actors = scene->actors;

	for (linked_list_t *ref = actors; ref; ref = ref->next) {
		for (linked_list_t *oth = actors; oth; oth = oth->next)
			is_overlap(scene, ref->data, oth->data);
	}
}

void engine_pollevent(engine_t *engine)
{
	scene_t *scene = fetch_var(engine->scenes, engine->active_scene);
	sfEvent evt;

	if (HAS_FAILED(scene))
		return;
	while (sfRenderWindow_pollEvent(engine->wdw, &evt)) {
		scene->event(scene, &evt);
		if (evt.type == sfEvtClosed)
			sfRenderWindow_close(engine->wdw);
	}
	check_overlap(scene);
}