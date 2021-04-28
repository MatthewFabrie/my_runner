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

data_t *init_data_ex(void)
{
    data_t *data = malloc(sizeof(data_t));

    data->mode.width = WIDTH;
    data->mode.height = HEIGHT;
    data->mode.bitsPerPixel = 32;
    data->window = sfRenderWindow_create(data->mode, "my_runner", sfDefaultStyle
    , NULL);
    data->sprite = sfSprite_create();
    data->rect.top = 0;
    data->rect.left = 0;
    data->rect.width = 1920;
    data->rect.height = 1080;
    data->jump_sound = sfSound_create();
    data->buff_jump = sfSoundBuffer_createFromFile("jump.ogg");
    data->mam = false;
    return (data);
}

paralax_t *ini_data(void)
{
    paralax_t *dat = malloc(sizeof(paralax_t) * 10);

    dat->clocko = sfClock_create();
    dat->clockt = sfClock_create();
    dat->clockth = sfClock_create();
    dat->timeo = sfClock_getElapsedTime(dat->clocko);
    dat->timet = sfClock_getElapsedTime(dat->clockt);
    dat->timeth = sfClock_getElapsedTime(dat->clockth);
    dat->spo = sfSprite_create();
    dat->spt = sfSprite_create();
    dat->spth = sfSprite_create();
    dat->back = sfTexture_createFromFile("back-buildings.png", NULL);
    dat->mid = sfTexture_createFromFile("far-buildings.png", NULL);
    dat->front = sfTexture_createFromFile("foreground.png", NULL);
    dat->seconds = dat->timeo.microseconds / 1000000.0;
    dat->secondst = dat->timet.microseconds / 1000000.0;
    dat->secondsth = dat->timeth.microseconds / 1000000.0;
    dat->music = sfMusic_createFromFile("song.wav");
    return (dat);
}

paralax_t *in_data(void)
{
    paralax_t *dat = ini_data();

    dat->bg.top = 0;
    dat->bg.left = 0;
    dat->bg.width = 1920;
    dat->bg.height = 1080;
    dat->mg.top = 0;
    dat->mg.left = 0;
    dat->mg.width = 1920;
    dat->mg.height = 1080;
    dat->fg.top = 0;
    dat->fg.left = 0;
    dat->fg.width = 1920;
    dat->fg.height = 1080;
    return (dat);
}

player_t *initialise(void)
{
    player_t *d = malloc(sizeof(player_t));

    d->mario = sfSprite_create();
    d->timer = sfClock_create();
    d->player = sfTexture_createFromFile("mario.png", NULL);
    d->jump = sfTexture_createFromFile("jump.png", NULL);
    d->r.top = 0;
    d->r.left = 0;
    d->r.width = 99;
    d->r.height = 175;
    d->pos.x = 0;
    d->pos.y = 800;
    d->hourglass = sfClock_create();
    d->i = 0;
    d->jump_speed = 100;
    d->jump_height = 250;
    d->peak = 0;
    return (d);
}

structs_t *all_dat(char **argv)
{
    structs_t *adata = malloc(sizeof(structs_t));

    adata->d = initialise();
    adata->data = init_data_ex();
    adata->dat = in_data();
    adata->m = initialisation();
    adata->c = i(argv);
    adata->click = click_i();
    adata->mapi = map_data_i();
    return (adata);
}