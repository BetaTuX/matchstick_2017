/*
** EPITECH PROJECT, 2018
** engine
** File description:
** component add function
*/

#include "engine.h"

void scene_addcomponent(scene_t *scene, component_t *comp)
{
	append(&(scene->ui->components), comp);
}

void scene_addactor(scene_t *scene, actor_t *actor)
{
	append(&(scene->actors), actor);
}

void scene_setgamemode(scene_t *scene, gamemode_t *gamemode)
{
	if (scene->gamemode)
		scene->gamemode->destroy(scene->gamemode);
	scene->gamemode = gamemode;
}

void scene_setui(scene_t *scene, ui_t *ui)
{
	if (scene->ui)
		scene->ui->destroy(scene->ui);
	scene->ui = ui;
}