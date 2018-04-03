/*
** EPITECH PROJECT, 2018
** Cook
** File description:
** map const objects
*/

#include "graph_matchstick.h"

const int BACKGROUND_WIDTH = 1280;

const int BACKGROUND_HEIGHT = 960;

const int STICK_NB = 25;

const char *SCN_MENU = "menu";
const char *SCN_GAME = "game";
const char *SCN_WIN = "win";
const char *SCN_LOST = "lost";

const char *tex[TEX_NB][2] = {
	{"button_play", "assets/tex/button_play.png"},
	{"button_exit", "assets/tex/button_exit.png"},
	{"button_quit", "assets/tex/button_quit.png"},
	{"button_resume", "assets/tex/button_resume.png"},
	{"button_how2", "assets/tex/button_howto.png"},
	{"bg_menu", "assets/tex/bg_menu.jpg"},
	{"bg_game", "assets/tex/bg_game.png"},
	{"bg_win", "assets/tex/bg_win.jpg"},
	{"bg_lost", "assets/tex/bg_lose.jpg"},
	{"act_stick", "assets/tex/act_batonnet.png"},
	{"logo", "assets/tex/logo.png"}
};

const char *font[FONT_NB][2] = {
	{"minecraft", "assets/font/Minecraft.ttf"},
	{"south_park", "assets/font/south_park.ttf"}
};

const char *sounds[SOUND_NB][2] = {
	{"music_menu", "assets/music/music_menu.ogg"},
	{"music_epreuve", "assets/music/music_epreuve.ogg"},
	{"music_matin", "assets/music/music_matin.ogg"},
	{"music_main", "assets/music/music_main.ogg"},
	{"music_lost", "assets/music/music_oof.ogg"},
	{"music_game", "assets/music/music_game.ogg"}
};