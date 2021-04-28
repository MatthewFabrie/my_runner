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

void mainmen(structs_t *adata)
{
    while (sfRenderWindow_isOpen(adata->data->window) && adata->data->mam
    == false) {
        paralax_menu(adata);
        while (sfRenderWindow_pollEvent(adata->data->window, &adata->data->event
        ))
            check_close(adata->data, adata->dat, adata);
    }
    adata->data->mam = true;
}

void paralax_menu(structs_t *adata)
{
    sfSprite_setTexture(adata->dat->spo, adata->dat->back, sfTrue);
    sfSprite_setTexture(adata->dat->spt, adata->dat->mid, sfTrue);
    sfSprite_setTexture(adata->dat->spth, adata->dat->front, sfTrue);
    bg(adata->dat);
    sfRenderWindow_clear(adata->data->window, sfBlack);
    sfSprite_setTextureRect(adata->dat->spo, adata->dat->bg);
    sfSprite_setTextureRect(adata->dat->spt, adata->dat->mg);
    sfSprite_setTextureRect(adata->dat->spth, adata->dat->fg);
    sfRenderWindow_drawSprite(adata->data->window, adata->dat->spt, NULL);
    sfRenderWindow_drawSprite(adata->data->window, adata->dat->spo, NULL);
    sfRenderWindow_drawSprite(adata->data->window, adata->dat->spth, NULL);
    buttons(adata);
    sfRenderWindow_display(adata->data->window);
}

void buttons(structs_t *adata)
{
    sfSprite_setTexture(adata->m->tm, adata->m->tmt, sfTrue);
    sfSprite_setPosition(adata->m->tm, adata->m->menu_pos);
    sfRenderWindow_drawSprite(adata->data->window, adata->m->tm, NULL);
    sfSprite_setTexture(adata->m->sound, adata->m->soundt, sfTrue);
    sfRenderWindow_drawSprite(adata->data->window, adata->m->sound, NULL);
    play(adata);
    if (adata->data->event.type == sfEvtMouseButtonReleased) {
        if (adata->data->event.mouseButton.button == sfMouseLeft) {
            adata->data->event.type = 0;
            adata->data->event.mouseButton.button = 0;
            check_sound(adata);
        }
    }
}

void check_sound(structs_t *adata)
{
    sfFloatRect button = sfSprite_getGlobalBounds(adata->m->sound);

    if (sfFloatRect_contains(&button, adata->data->event.mouseButton.x,
    adata->data->event.mouseButton.y) == 1 && adata->m->soundb == true) {
        adata->m->soundt = sfTexture_createFromFile("soundoff.png", NULL);
        adata->m->soundb = false;
        sfMusic_pause(adata->dat->music);
        sfSound_setVolume(adata->data->jump_sound, 0);
    } else if (sfFloatRect_contains(&button, adata->data->event.mouseButton.x,
    adata->data->event.mouseButton.y) == 1 && adata->m->soundb == false) {
        adata->m->soundt = sfTexture_createFromFile("off.png", NULL);
        adata->m->soundb = true;
        sfMusic_play(adata->dat->music);
        sfSound_setVolume(adata->data->jump_sound, 100);
    }
}

void play(structs_t *adata)
{
    sfFloatRect start;

    sfSprite_setTexture(adata->m->start, adata->m->startex, sfTrue);
    sfSprite_setPosition(adata->m->start ,adata->m->button_pos);
    sfRenderWindow_drawSprite(adata->data->window, adata->m->start, NULL);
    customisation(adata);
    start = sfSprite_getGlobalBounds(adata->m->start);
    if (adata->data->event.type == sfEvtMouseButtonPressed && adata->data->event
    .mouseButton.button == sfMouseLeft && sfFloatRect_contains(&start,
    adata->data->event.mouseButton.x, adata->data->event.mouseButton.y) == 1) {
        adata->data->mam = true;
        parallax(adata->data, adata->dat, adata->d, adata);
    }
}