/*
** EPITECH PROJECT, 2017
** Matchstick bonus 2017
** File description:
** slav version
*/

#include <stdlib.h>
#include <time.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "my.h"
#include "graph_matchstick.h"

static void print_usage(void)
{
	my_printf("~~~ a basic matchstick game... #FortBoyard ~~~\n");
	my_printf("Made by:\n\tArgann\n\n");
	my_printf("A tribute to:\n\tOlivier Minne\n");
}

static void prepare_and_run_window(engine_t *engine)
{
	if (load_textures(engine, tex, TEX_NB))
		return;
	if (load_fonts(engine, font, FONT_NB))
		return;
	if (load_sounds(engine, sounds, SOUND_NB))
		return;
	prefab_scene_menu(engine);
	prefab_scene_game(engine);
	prefab_scene_win(engine);
	prefab_scene_lost(engine);
	sfRenderWindow_setFramerateLimit(engine->wdw, 60);
	engine_changescene(engine, SCN_MENU, false);
	engine->run(engine);
}

int main(int argc, char **argv, char **env)
{
	sfVideoMode v_mode = {BACKGROUND_WIDTH, BACKGROUND_HEIGHT, 32};
	sfRenderWindow *window = NULL;
	engine_t *engine = NULL;

	srand(time(NULL));
	if (get_env_var_ind(env, "DISPLAY") == -1)
		return (84);
	if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
		print_usage();
	} else if (argc == 1) {
		window = sfRenderWindow_create(v_mode, \
"Graphical matchstick", sfClose, 0);
		engine = engine_create(window);
		prepare_and_run_window(engine);
		engine->destroy(engine);
	}
	return (0);
}