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

void customisation(structs_t *adata)
{
    sfFloatRect customb;

    sfSprite_setTexture(adata->m->custom, adata->m->customtexture, sfTrue);
    sfSprite_setPosition(adata->m->custom, adata->m->custom_pos);
    sfRenderWindow_drawSprite(adata->data->window, adata->m->custom, NULL);
    customb = sfSprite_getGlobalBounds(adata->m->custom);
    if (adata->data->event.type == sfEvtMouseButtonPressed &&adata->data->event.
    mouseButton.button == sfMouseLeft && sfFloatRect_contains(&customb, adata->
    data->event.mouseButton.x, adata->data->event.mouseButton.y) == 1) {
        adata->click->clicked = true;
        if (adata->click->clicked == true)
            personalisation(adata);
    }
}

void personalisation(structs_t *adata)
{
    sfSprite_setTexture(adata->c->rhead, adata->c->red, sfTrue);
    sfSprite_setTexture(adata->c->ghead, adata->c->green, sfTrue);
    sfSprite_setPosition(adata->c->rhead, adata->c->rpos);
    sfSprite_setPosition(adata->c->ghead, adata->c->gpos);
    sfRenderWindow_drawSprite(adata->data->window, adata->c->rhead, NULL);
    sfRenderWindow_drawSprite(adata->data->window, adata->c->ghead, NULL);
}

void check_closed(structs_t *adata)
{
    if (adata->data->event.type == sfEvtClosed) {
        sfMusic_destroy(adata->dat->music);
        sfSound_destroy(adata->data->jump_sound);
        sfSoundBuffer_destroy(adata->data->buff_jump);
        sfRenderWindow_close(adata->data->window);
    }
    if (adata->data->event.type == sfEvtKeyPressed &&
    adata->data->event.key.code == sfKeyEscape) {
        sfMusic_destroy(adata->dat->music);
        sfSound_destroy(adata->data->jump_sound);
        sfSoundBuffer_destroy(adata->data->buff_jump);
        sfRenderWindow_close(adata->data->window);
    }
    return;
}