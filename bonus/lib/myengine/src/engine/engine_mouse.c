/*
** EPITECH PROJECT, 2018
** engine
** File description:
** mouse position calculation
*/

#include "engine.h"

bool mouse_overlap(actor_t *self, sfVector2i *mse_pos)
{
	int pos_x = self->transform.pos.x;
	int pos_y = self->transform.pos.y;
	int width = self->rect.width * self->transform.scale.x;
	int height = self->rect.height * self->transform.scale.y;

	if (!mse_pos)
		return (false);
	return (pos_x - (width / 2) <= mse_pos->x && \
mse_pos->x <= (pos_x + (width / 2)) && (pos_y - (height / 2)) <= mse_pos->y && \
mse_pos->y <= (pos_y + (height / 2)));
}