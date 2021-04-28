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

void score(structs_t *adata)
{
    char *score_txt = nb_in_text(adata->c->score);
    sfTime timer = sfClock_getElapsedTime(adata->c->score_timer);
    float s = timer.microseconds / 1000000.0;

    if (s > 0.01 && adata->mapi->died == false && adata->click->won == false
    && adata->click->died == false) {
        adata->c->score++;
        sfClock_restart(adata->c->score_timer);
    }
    sfText_setFont(adata->c->text, adata->c->font);
    sfText_setString(adata->c->text, score_txt);
    sfText_setCharacterSize(adata->c->text, 75);
    sfText_setPosition(adata->c->text, adata->c->text_pos);
    sfRenderWindow_drawText(adata->data->window, adata->c->text, NULL);
}

char *nb_in_text(int number)
{
    char *str = malloc(sizeof(char) * 10);
    int increment = 0;

    for (; number > 0; increment++) {
        str[increment] = (number % 10) + 48;
        number /= 10;
    }
    str[increment] = '\0';
    my_revstr(str);
    return (str);
}