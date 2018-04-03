/*
** EPITECH PROJECT, 2018
** cook
** File description:
** scenes prefabs
*/

#include "graph_matchstick.h"

int prefab_scene_game(engine_t *engine)
{
	sfMusic *music = fetch_var(engine->sounds, "music_epreuve");
	scene_t *scene = NULL;

	scene_add(engine, (char *)SCN_GAME, gamemode_create(NULL), \
ui_create(NULL));
	scene = scene_fetch(engine, SCN_GAME);
	if (!HAS_FAILED(music)) {
		scene->bg_music = music;
		sfMusic_setLoop(music, true);
	} else
		scene->bg_music = NULL;
	prefab_background(engine, scene, "bg_game");
	prefab_game_actors(engine, scene);
	prefab_game_gm(engine, scene);
	prefab_game_ui(engine, scene);
	scene->pauseable = true;
	return (0);
}

int prefab_scene_menu(engine_t *engine)
{
	sfMusic *music = fetch_var(engine->sounds, "music_main");
	scene_t *scene = NULL;

	scene_add(engine, (char *)SCN_MENU, gamemode_create(NULL), \
ui_create(NULL));
	scene = scene_fetch(engine, SCN_MENU);
	if (!HAS_FAILED(music)) {
		scene->bg_music = music;
		sfMusic_setLoop(music, true);
	} else
		scene->bg_music = NULL;
	prefab_background(engine, scene, "bg_menu");
	prefab_game_menu(engine, scene);
	scene->pauseable = false;
	return (0);
}

int prefab_scene_win(engine_t *engine)
{
	sfMusic *music = fetch_var(engine->sounds, "music_matin");
	scene_t *scene = NULL;

	scene_add(engine, (char *)SCN_WIN, gamemode_create(NULL), \
ui_create(NULL));
	scene = scene_fetch(engine, SCN_WIN);
	if (!HAS_FAILED(music)) {
		scene->bg_music = music;
		sfMusic_setLoop(music, true);
	} else
		scene->bg_music = NULL;
	prefab_background(engine, scene, "bg_win");
	prefab_game_end(engine, scene);
	scene->pauseable = false;
	return (0);
}

int prefab_scene_lost(engine_t *engine)
{
	sfMusic *music = fetch_var(engine->sounds, "music_lost");
	scene_t *scene = NULL;

	scene_add(engine, (char *)SCN_LOST, gamemode_create(NULL), \
ui_create(NULL));
	scene = scene_fetch(engine, SCN_LOST);
	if (!HAS_FAILED(music)) {
		scene->bg_music = music;
		sfMusic_setLoop(music, true);
	} else
		scene->bg_music = NULL;
	prefab_background(engine, scene, "bg_lost");
	prefab_game_end(engine, scene);
	scene->pauseable = false;
	return (0);
}