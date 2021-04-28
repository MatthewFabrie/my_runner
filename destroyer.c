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

void destroyer(data_t *data, paralax_t *dat, player_t *d, structs_t *adata)
{
    sfSprite_destroy(data->sprite);

    sfRenderWindow_destroy(data->window);
    free(data);
    sfClock_destroy(dat->clocko);
    sfClock_destroy(dat->clockt);
    sfClock_destroy(dat->clockth);
    sfSprite_destroy(dat->spo);
    sfSprite_destroy(dat->spt);
    sfSprite_destroy(dat->spth);
    sfTexture_destroy(dat->back);
    sfTexture_destroy(dat->mid);
    sfTexture_destroy(dat->front);
    free(dat);
    sfSprite_destroy(d->mario);
    sfClock_destroy(d->timer);
    sfTexture_destroy(d->player);
    sfTexture_destroy(d->jump);
    sfClock_destroy(d->hourglass);
    deleter(data, dat, d, adata);
}

void deleter(data_t *data, paralax_t *dat, player_t *d, structs_t *adata)
{
    free(d);
}

void space(structs_t *adata)
{
    while (sfRenderWindow_pollEvent(adata->data->window,&adata->data->event)) {
        check_close(adata->data, adata->dat, adata);
        if (adata->data->event.type == sfEvtKeyPressed && adata->data->event
        .key.code == sfKeySpace && adata->d->i == 0 && adata->mapi->died ==
        false && adata->click->won == false)
            jump(adata->data, adata->dat, adata->d, adata);
    }
}