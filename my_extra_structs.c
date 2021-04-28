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

more_t **map_init(structs_t *adata)
{
    more_t **enemies = malloc(sizeof(more_t *) * (adata->c->rd));
    int count = 0;
    int i = 0;

    while (i != adata->c->rd) {
        if (adata->c->map[i] == '2') {
            enemies[count] = malloc(10000);
            enemies[count]->brick = sfSprite_create();
            enemies[count]->brick_text = sfTexture_createFromFile("PixelArt.png"
            , NULL);
            enemies[count]->brick_pos.x = i * 100;
            enemies[count]->brick_pos.y = 820;
            enemies[count]->i = 0;
            count++;
        }
        i++;
    }
    adata->mapi->g = count;
    return (enemies);
}

click_t *click_i(void)
{
    click_t *click = malloc(sizeof(custom_t));

    click->clicked = false;
    click->small_move = sfClock_create();
    click->flag_move = sfClock_create();
    click->won = false;
    click->mlg = sfMusic_createFromFile("win.flac");
    click->winner = sfSprite_create();
    click->you_win = sfTexture_createFromFile("win.jpeg", NULL);
    click->died = false;
    click->tmp = 0;
    return (click);
}

small_t **enemy_init(structs_t *adata)
{
    small_t **small = malloc(sizeof(small_t *) * (adata->c->rd));
    int count = 0;
    int i = 0;

    while (i != adata->c->rd) {
        if (adata->c->map[i] == '3') {
            small[count] = malloc(10000);
            small[count]->brick = sfSprite_create();
            small[count]->brick_text = sfTexture_createFromFile("thwimp.png"
            , NULL);
            small[count]->brick_pos.x = i * 100;
            small[count]->brick_pos.y = 869;
            small[count]->i = 0;
            count++;
        }
        i++;
    }
    adata->click->m = count;
    return (small);
}

flag_t **flag_i(structs_t *adata)
{
    flag_t **flag = malloc(sizeof(flag_t *) * (adata->c->rd));
    int count = 0;
    int i = 0;

    while (i != adata->c->rd) {
        if (adata->c->map[i] == '4') {
            flag[count] = malloc(10000);
            flag[count]->brick = sfSprite_create();
            flag[count]->brick_text = sfTexture_createFromFile("win.png"
            , NULL);
            flag[count]->brick_pos.x = i * 100;
            flag[count]->brick_pos.y = 833;
            flag[count]->i = 0;
            count++;
        }
        i++;
    }
    adata->click->x = count;
    return (flag);
}