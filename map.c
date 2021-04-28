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

void extra(structs_t *adata)
{
    my_open(adata);
    my_enemies(adata);
    small_enemies(adata);
    flag(adata);
    s_contact(adata);
    f_contact(adata);
    contact(adata);
}

void my_open(structs_t *adata)
{
    sfTime mapmove = sfClock_getElapsedTime(adata->mapi->map_movement);
    float seconds = mapmove.microseconds / 1000000.0;
    int o = 0;

    adata->c->map[adata->c->rd] = '\0';
    if (seconds > 0.01) {
        for (int p = 0; p != adata->mapi->d; p++) {
            adata->map[p]->brick_pos.x -= 10;
            sfSprite_setTexture(adata->map[p]->brick, adata->map[p]->brick_text,
            sfTrue);
            sfSprite_setPosition(adata->map[p]->brick, adata->map[p]->brick_pos
            );
        }
        sfClock_restart(adata->mapi->map_movement);
    }
    for (; o != adata->mapi->d; o++)
        sfRenderWindow_drawSprite(adata->data->window, adata->map[o]->brick,
        NULL);
}

void my_enemies(structs_t *adata)
{
    sfTime mapmove = sfClock_getElapsedTime(adata->mapi->enemy_movement);
    float seconds = mapmove.microseconds / 1000000.0;

    if (seconds > 0.01) {
        for (int p = 0; p != adata->mapi->g; p++) {
            adata->enemies[p]->brick_pos.x -= 10;
            sfSprite_setTexture(adata->enemies[p]->brick,
            adata->enemies[p]->brick_text, sfTrue);
            sfSprite_setPosition(adata->enemies[p]->brick,
            adata->enemies[p]->brick_pos);
        }
        sfClock_restart(adata->mapi->enemy_movement);
    }
    for (int o = 0; o != adata->mapi->g; o++)
        sfRenderWindow_drawSprite(adata->data->window, adata->enemies[o]->brick,
        NULL);
}

void contact(structs_t *adata)
{
    sfFloatRect mario = sfSprite_getGlobalBounds(adata->d->mario);
    bool you_died = false;

    for (int temp = 0; temp < adata->mapi->g; temp++) {
        if (sfFloatRect_contains(&mario, adata->enemies[temp]->brick_pos.x,
        adata->enemies[temp]->brick_pos.y) == 1) {
            adata->mapi->died = true;
            you_died = true;
            adata->mapi->tmp++;
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

void set_score(structs_t *adata)
{
    char *score_txt = nb_in_text(adata->c->score);

    sfSprite_setTexture(adata->mapi->sscore, adata->mapi->your_score, sfTrue);
    sfSprite_setPosition(adata->mapi->sscore, adata->mapi->spos);
    sfRenderWindow_drawSprite(adata->data->window, adata->mapi->sscore, NULL);
    sfText_setFont(adata->c->text, adata->c->font);
    sfText_setString(adata->c->text, score_txt);
    sfText_setCharacterSize(adata->c->text, 60);
    sfText_setPosition(adata->c->text, adata->mapi->yspos);
    sfRenderWindow_drawText(adata->data->window, adata->c->text, NULL);
    sfSprite_setTexture(adata->mapi->hscore, adata->mapi->hiscore, sfTrue);
    sfSprite_setPosition(adata->mapi->hscore, adata->mapi->hpos);
    sfRenderWindow_drawSprite(adata->data->window, adata->mapi->hscore, NULL);
}