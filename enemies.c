/*
** EPITECH PROJECT, 2020
** click
** File description:
** this will check if the player clicked on the bird
*/

#include "include/my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>
#include <fcntl.h>

void small_enemies(structs_t *adata)
{
    sfTime mapmove = sfClock_getElapsedTime(adata->click->small_move);
    float seconds = mapmove.microseconds / 1000000.0;

    if (seconds > 0.01) {
        for (int p = 0; p != adata->click->m; p++) {
            adata->small[p]->brick_pos.x -= 10;
            sfSprite_setTexture(adata->small[p]->brick,
            adata->small[p]->brick_text, sfTrue);
            sfSprite_setPosition(adata->small[p]->brick,
            adata->small[p]->brick_pos);
        }
        sfClock_restart(adata->click->small_move);
    }
    for (int o = 0; o != adata->click->m; o++)
        sfRenderWindow_drawSprite(adata->data->window, adata->small[o]->brick,
        NULL);
}

void s_contact(structs_t *adata)
{
    sfFloatRect mario = sfSprite_getGlobalBounds(adata->d->mario);
    bool you_died = false;

    for (int temp = 0; temp < adata->click->m; temp++) {
        if (sfFloatRect_contains(&mario, adata->small[temp]->brick_pos.x,
        adata->small[temp]->brick_pos.y) == 1) {
            you_died = true;
            adata->mapi->tmp++;
            adata->mapi->died = true;
        }
    }
    if (adata->mapi->died == true) {
        sfSprite_setTexture(adata->mapi->dead, adata->mapi->go, sfTrue);
        sfRenderWindow_drawSprite(adata->data->window, adata->mapi->dead, NULL);
        set_score(adata);
        if (you_died == true && adata->mapi->tmp == 1 && sfRenderWindow_isOpen
        (adata->data->window))
            sfMusic_play(adata->mapi->gameover);
    }
}

void flag(structs_t *adata)
{
    sfTime mapmove = sfClock_getElapsedTime(adata->click->flag_move);
    float seconds = mapmove.microseconds / 1000000.0;

    if (seconds > 0.01) {
        for (int p = 0; p != adata->click->x; p++) {
            adata->flag[p]->brick_pos.x -= 10;
            sfSprite_setTexture(adata->flag[p]->brick,
            adata->flag[p]->brick_text, sfTrue);
            sfSprite_setPosition(adata->flag[p]->brick,
            adata->flag[p]->brick_pos);
        }
        sfClock_restart(adata->click->flag_move);
    }
    for (int o = 0; o != adata->click->x; o++)
        sfRenderWindow_drawSprite(adata->data->window, adata->flag[o]->brick,
        NULL);
}

void f_contact(structs_t *adata)
{
    sfFloatRect mario = sfSprite_getGlobalBounds(adata->d->mario);
    bool you_won = false;

    for (int temp = 0; temp < adata->click->x; temp++) {
        if (sfFloatRect_contains(&mario, adata->flag[temp]->brick_pos.x,
        adata->flag[temp]->brick_pos.y) == 1) {
            adata->click->won = true;
            adata->mapi->tmp++;
            you_won = true;
        }
    }
    if (adata->click->won == true) {
        sfSprite_setTexture(adata->click->winner, adata->click->you_win,sfTrue);
        sfRenderWindow_drawSprite(adata->data->window, adata->click->winner,
        NULL);
        set_score(adata);
        if (you_won == true && adata->mapi->tmp == 1)
            sfMusic_play(adata->click->mlg);
    }
}

void my_shortened(structs_t *adata)
{
    score(adata);
    my_open(adata);
    my_enemies(adata);
    small_enemies(adata);
    flag(adata);
    sfRenderWindow_drawSprite(adata->data->window, adata->d->mario, NULL);
    s_contact(adata);
    f_contact(adata);
    contact(adata);
}