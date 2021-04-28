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

void player(data_t *data, player_t *d, structs_t *adata)
{
    sfTime ptime = sfClock_getElapsedTime(d->timer);
    float secs = ptime.microseconds / 1000000.0;

    sfSprite_setTexture(d->mario, d->player, sfTrue);
    sfSprite_setTextureRect(d->mario, d->r);
    sfSprite_setPosition(d->mario, d->pos);
    if (secs > 0.2) {
        d->r.left += 99;
        if (d->r.left == 297)
            d->r.left = 0;
        sfClock_restart(d->timer);
    }
    my_shortened(adata);
}

void jump(data_t *data, paralax_t *dat, player_t *d, structs_t *adata)
{
    sound(adata);
    while (d->pos.y >= 550.00 && d->pos.y <= 800.00) {
        jump_parallax(data, dat, d, adata);
        while (sfRenderWindow_pollEvent(data->window, &data->event))
            check_close(data, dat, adata);
        if (d->i == 0) {
            d->peak = 800 - d->jump_height;
            d->i = 1;
        }
        positions(d);
        sfRenderWindow_drawSprite(data->window, d->mario, NULL);
    }
    d->i = 0;
    d->pos.y = 800;
}

float go_up(player_t *d)
{
    float height_difference = d->pos.y - d->peak;
    float adjustment_y = height_difference / sqrt(height_difference) *
    d->jump_speed * 0.016;

    if (adjustment_y > 0.470056)
        return (adjustment_y);
    else
        return (0.470056);
}

void sound(structs_t *adata)
{
    if (adata->click->won == false && adata->mapi->died == false) {
        sfSound_setBuffer(adata->data->jump_sound, adata->data->buff_jump);
        sfSound_setVolume(adata->data->jump_sound, 100);
        sfSound_play(adata->data->jump_sound);
    }
}

void positions(player_t *d)
{
    if (d->i == 1) {
        d->pos.y = d->pos.y - go_up(d);
        if (d->pos.y <= d->peak + 1) {
            d->i = 2;
            d->pos.y = d->peak + 0.016;
        }
    } if (d->i == 2) {
        if (d->pos.y <= 900)
            d->pos.y = d->pos.y + go_up(d);
        if (d->pos.y > 800)
            d->pos.y = 851;
    }
}