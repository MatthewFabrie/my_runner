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
#include <fcntl.h>

void check_close(data_t *data, paralax_t *dat, structs_t *adata)
{
    if (data->event.type == sfEvtClosed) {
        sfMusic_destroy(dat->music);
        sfSoundBuffer_destroy(data->buff_jump);
        sfSound_destroy(data->jump_sound);
        sfRenderWindow_close(data->window);
        sfMusic_destroy(adata->mapi->gameover);
        sfMusic_destroy(adata->click->mlg);
    }
    if (data->event.type == sfEvtKeyPressed && data->event.key.code ==
    sfKeyEscape) {
        sfMusic_destroy(dat->music);
        sfSoundBuffer_destroy(data->buff_jump);
        sfSound_destroy(data->jump_sound);
        sfRenderWindow_close(data->window);
        sfMusic_destroy(adata->mapi->gameover);
        sfMusic_destroy(adata->click->mlg);
    }
    return;
}

void main_menu(char **argv)
{
    structs_t *adata = all_dat(argv);
    adata->enemies = map_init(adata);
    adata->map = map_ini(adata);
    adata->small = enemy_init(adata);
    adata->flag = flag_i(adata);

    sfMusic_play(adata->dat->music);
    sfMusic_setLoop(adata->dat->music, sfTrue);
    sfRenderWindow_setFramerateLimit(adata->data->window, 60);
    while (sfRenderWindow_isOpen(adata->data->window)) {
        parallax(adata->data, adata->dat, adata->d, adata);
        if (adata->mapi->died == true || adata->click->won == true || adata->
        click->died == true)
            sfMusic_pause(adata->dat->music);
        while (adata->data->mam == false)
            mainmen(adata);
        space(adata);
    }
    destroyer(adata->data, adata->dat, adata->d, adata);
}

void helper(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n");
    my_putstr("  ./my_runner level(1-5).txt\n\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("  -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("  SPACE KEY         jump\n");
    my_putstr("  ESC KEY           close the window");
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        my_putstr("please read the usage (incorrect arguments)");
        return (84);
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        helper();
    else
        main_menu(argv);
    return (0);
}