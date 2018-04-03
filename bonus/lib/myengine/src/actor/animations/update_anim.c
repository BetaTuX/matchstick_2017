/*
** EPITECH PROJECT, 2018
** Runner 2017
** File description:
** Animation system
*/

#include "engine.h"

static anim_t *retrieve_anim_info(actor_t *actor)
{
	for (int i = 0; 1; i++)
		if (my_strcmp(actor->current_anim, actor->anim[i].name) == 0)
			return (&(actor->anim[i]));
	return (NULL);
}

void update_anim(actor_t *actor)
{
	anim_t *anim = retrieve_anim_info(actor);

	if ((unsigned int)(actor->rect.top / actor->rect.height) ==\
(anim->row_ind))
		if (((anim->frame_number) - 1) <= \
(unsigned int)actor->rect.left / actor->rect.width) {
			actor->rect.left = 0;
			actor->current_anim = anim->next;
		} else
			actor->rect.left += actor->rect.width;
	else {
		actor->rect.left = 0;
		actor->rect.top = (anim->row_ind) * actor->rect.height;
	}
}