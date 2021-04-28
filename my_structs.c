/*
** EPITECH PROJECT, 2020
** click
** File description:
** this will check if the player clicked on the bird
*/

#include "include/my.h"
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

menu_t *ini(void)
{
    menu_t *m = malloc(sizeof(menu_t));

    m->tm = sfSprite_create();
    m->tmt = sfTexture_createFromFile("mm.png", NULL);
    m->menu_pos.x = 500;
    m->menu_pos.y = 200;
    m->sound = sfSprite_create();
    m->soundt = sfTexture_createFromFile("off.png", NULL);
    m->sound_pos.x = 0;
    m->sound_pos.y = 0;
    m->soundb = true;
    m->soundbool = false;
    m->start = sfSprite_create();
    m->startex = sfTexture_createFromFile("start.png", NULL);
    m->button_pos.x = 625;
    m->button_pos.y = 500;
    return (m);
}

menu_t *initialisation(void)
{
    menu_t *m = ini();

    m->custom = sfSprite_create();
    m->customtexture = sfTexture_createFromFile("custom.png", NULL);
    m->custom_pos.x = 647;
    m->custom_pos.y = 710;
    m->custombool = true;
    m->tester = true;
    return (m);
}

custom_t *i(char **argv)
{
    custom_t *c = malloc(sizeof(custom_t));

    c->ghead = sfSprite_create();
    c->rhead = sfSprite_create();
    c->green = sfTexture_createFromFile("ghead.png", NULL);
    c->red = sfTexture_createFromFile("rhead.png", NULL);
    c->gpos.x = 1200;
    c->gpos.y = 650;
    c->rpos.x = 1200;
    c->rpos.y = 850;
    c->score = 0;
    c->text = sfText_create();
    c->font = sfFont_createFromFile("Brokenbrush.ttf");
    c->text_pos.x = 1600;
    c->text_pos.y = 50;
    c->score_timer = sfClock_create();
    c->map = malloc(sizeof(char) * 100000);
    c->fd = open(argv[1], O_RDONLY);
    c->rd = read(c->fd, c->map, 100000);
    return (c);
}

map_t **map_ini(structs_t *adata)
{
    map_t **map = malloc(sizeof(map_t *) * (adata->c->rd));
    int x = 0;
    int i = 0;

    while (i != adata->c->rd) {
        if (adata->c->map[i] == '1') {
            map[x] = malloc(10000);
            map[x]->brick = sfSprite_create();
            map[x]->brick_text = sfTexture_createFromFile("ground.png", NULL);
            map[x]->brick_pos.x = i * 100;
            map[x]->brick_pos.y = 970;
            map[x]->i = 0;
            x++;
        }
        i++;
    }
    adata->mapi->d = x;
    return (map);
}

maps_t *map_data_i(void)
{
    maps_t *mapi = malloc(sizeof(maps_t));

    mapi->map_movement = sfClock_create();
    mapi->enemy_movement = sfClock_create();
    mapi->dead = sfSprite_create();
    mapi->go = sfTexture_createFromFile("game_over.jpeg", NULL);
    mapi->gameover = sfMusic_createFromFile("dead.flac");
    mapi->died = false;
    mapi->tmp = 0;
    mapi->sscore = sfSprite_create();
    mapi->your_score = sfTexture_createFromFile("score.png", NULL);
    mapi->spos.x = 600;
    mapi->spos.y = 700;
    mapi->yspos.x = 725;
    mapi->yspos.y = 835;
    mapi->hscore = sfSprite_create();
    mapi->hiscore = sfTexture_createFromFile("hscore.png", NULL);
    mapi->hpos.x = 950;
    mapi->hpos.y = 700;
    return (mapi);
}