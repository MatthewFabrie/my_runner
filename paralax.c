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

void parallax(data_t *data, paralax_t *dat, player_t *d, structs_t *adata)
{
    sfSprite_setTexture(dat->spo, dat->back, sfTrue);
    sfSprite_setTexture(dat->spt, dat->mid, sfTrue);
    sfSprite_setTexture(dat->spth, dat->front, sfTrue);
    bg(dat);
    sfRenderWindow_clear(data->window, sfBlack);
    sfSprite_setTextureRect(dat->spo, dat->bg);
    sfSprite_setTextureRect(dat->spt, dat->mg);
    sfSprite_setTextureRect(dat->spth, dat->fg);
    sfRenderWindow_drawSprite(data->window, dat->spt, NULL);
    sfRenderWindow_drawSprite(data->window, dat->spo, NULL);
    sfRenderWindow_drawSprite(data->window, dat->spth, NULL);
    player(data, d, adata);
    sfRenderWindow_display(data->window);
}

void bg(paralax_t *dat)
{
    sfTime timeth = sfClock_getElapsedTime(dat->clockth);
    float secondsth = timeth.microseconds / 1000000.0;

    if (secondsth > 0.01) {
        dat->fg.left += 5;
        if (dat->fg.left == 1920)
            dat->fg.left = 0;
        sfClock_restart(dat->clockth);
    }
    fg(dat);
}

void fg(paralax_t *dat)
{
    sfTime timeo = sfClock_getElapsedTime(dat->clocko);
    float seconds = timeo.microseconds / 1000000.0;

    if (seconds > 0.03) {
        dat->bg.left += 5;
        if (dat->bg.left == 1920)
            dat->bg.left = 0;
        sfClock_restart(dat->clocko);
    }
    mg(dat);
}

void mg(paralax_t *dat)
{
    sfTime timet = sfClock_getElapsedTime(dat->clockt);
    float secondst = timet.microseconds / 1000000.0;

    if (secondst > 0.03) {
        dat->mg.left += 3;
        if (dat->mg.left == 1920)
            dat->mg.left = 0;
        sfClock_restart(dat->clockt);
    }
}

void jump_parallax(data_t *data, paralax_t *dat, player_t *d, structs_t *adata)
{
    sfIntRect rectangle = {.left = 0, .top = 0, .width = 102, .height = 175};

    sfSprite_setTexture(dat->spo, dat->back, sfTrue);
    sfSprite_setTexture(dat->spt, dat->mid, sfTrue);
    sfSprite_setTexture(dat->spth, dat->front, sfTrue);
    bg(dat);
    sfRenderWindow_clear(data->window, sfBlack);
    sfSprite_setTextureRect(dat->spo, dat->bg);
    sfSprite_setTextureRect(dat->spt, dat->mg);
    sfSprite_setTextureRect(dat->spth, dat->fg);
    sfRenderWindow_drawSprite(data->window, dat->spt, NULL);
    sfRenderWindow_drawSprite(data->window, dat->spo, NULL);
    sfRenderWindow_drawSprite(data->window, dat->spth, NULL);
    sfSprite_setTexture(d->mario, d->jump, sfTrue);
    sfSprite_setTextureRect(d->mario, rectangle);
    sfSprite_setPosition(d->mario, d->pos);
    sfRenderWindow_drawSprite(data->window, d->mario, NULL);
    score(adata);
    extra(adata);
    sfRenderWindow_display(data->window);
}