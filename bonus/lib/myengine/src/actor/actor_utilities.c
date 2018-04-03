/*
** EPITECH PROJECT, 2018
** Runner 2017
** File description:
** Actor utilites
*/

#include "engine.h"

void actor_render(actor_t *actor, sfRenderWindow *wdw)
{
	sfSprite_setTextureRect(actor->spritesheet, actor->rect);
	sfSprite_setOrigin(actor->spritesheet,\
(sfVector2f){actor->rect.width / 2, actor->rect.height / 2});
	sfSprite_setPosition(actor->spritesheet, actor->transform.pos);
	sfSprite_setScale(actor->spritesheet, actor->transform.scale);
	sfSprite_setRotation(actor->spritesheet, actor->transform.rot);
	sfRenderWindow_drawSprite(wdw, actor->spritesheet, NULL);
}

void actor_tick(UNUSED actor_t *actor, UNUSED float dta)
{
	return;
}