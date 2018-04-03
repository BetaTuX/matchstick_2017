/*
** EPITECH PROJECT, 2018
** engine
** File description:
** assets loading func
*/

#include "engine.h"

int load_textures(engine_t *engine, const char *tex_path[][2], int path_nb)
{
	sfTexture *tex = NULL;

	for (int i = 0; i < path_nb; i++) {
		tex = sfTexture_createFromFile(tex_path[i][1], NULL);
		if (tex)
			add_var(&(engine->textures), (char *)tex_path[i][0], \
tex);
		else
			return (1);
	}
	return (0);
}

int load_fonts(engine_t *engine, const char *font_path[][2], int path_nb)
{
	sfFont *font = NULL;

	for (int i = 0; i < path_nb; i++) {
		font = sfFont_createFromFile(font_path[i][1]);
		if (font)
			add_var(&(engine->fonts), (char *)font_path[i][0], \
font);
		else
			return (1);
	}
	return (0);
}

int load_sounds(engine_t *engine, const char *sounds_path[][2], int path_nb)
{
	sfMusic *music = NULL;

	for (int i = 0; i < path_nb; i++) {
		music = sfMusic_createFromFile(sounds_path[i][1]);
		if (music)
			add_var(&(engine->sounds), (char *)sounds_path[i][0],\
music);
		else
			return (1);
	}
	return (0);
}