/*
** EPITECH PROJECT, 2020
** click
** File description:
** my.h
*/

#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <math.h>
#define WIDTH 1920
#define HEIGHT 1080

typedef struct menu_s {
    sfSprite *tm;
    sfTexture *tmt;
    sfVector2f menu_pos;
    sfSprite *sound;
    sfTexture *soundt;
    sfVector2f sound_pos;
    bool soundb;
    bool soundbool;
    sfSprite *start;
    sfTexture *startex;
    sfVector2f button_pos;
    sfSprite *custom;
    sfTexture *customtexture;
    sfVector2f custom_pos;
    bool custombool;
    bool tester;
}menu_t;

typedef struct data_s {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfSprite *sprite;
    sfTexture *mm;
    sfIntRect rect;
    sfSound *jump_sound;
    sfSoundBuffer *buff_jump;
    bool mam;
}data_t;

typedef struct paralax_s {
    sfClock *clocko;
    sfClock *clockt;
    sfClock *clockth;
    sfSprite *spo;
    sfSprite *spt;
    sfSprite *spth;
    sfTexture *back;
    sfTexture *mid;
    sfTexture *front;
    sfTime timeo;
    sfTime timet;
    sfTime timeth;
    float seconds;
    float secondst;
    float secondsth;
    sfIntRect bg;
    sfIntRect mg;
    sfIntRect fg;
    sfMusic *music;
}paralax_t;

typedef struct player_s {
    sfSprite *mario;
    sfClock *timer;
    sfTexture *player;
    sfTime ptime;
    sfIntRect r;
    float secs;
    sfVector2f pos;
    sfEvent evt;
    sfMusic *sound;
    sfClock *hourglass;
    sfTime dt;
    int i;
    sfTexture *jump;
    int jump_speed;
    int jump_height;
    int peak;
}player_t;

typedef struct custom_s {
    sfSprite *ghead;
    sfSprite *rhead;
    sfTexture *green;
    sfTexture *red;
    sfVector2f gpos;
    sfVector2f rpos;
    int score;
    sfFont *font;
    sfText *text;
    sfVector2f text_pos;
    sfClock *score_timer;
    int fd;
    int rd;
    char *map;
}custom_t;

typedef struct maps_s {
    sfClock *map_movement;
    sfClock *enemy_movement;
    int d;
    int g;
    sfSprite *dead;
    sfTexture *go;
    sfMusic *gameover;
    bool died;
    int tmp;
    sfSprite *sscore;
    sfTexture *your_score;
    sfVector2f spos;
    sfVector2f yspos;
    sfSprite *hscore;
    sfTexture *hiscore;
    sfVector2f hpos;
}maps_t;

typedef struct map_s {
    sfSprite *brick;
    sfTexture *brick_text;
    sfVector2f brick_pos;
    sfClock *map_movement;
    int i;
}map_t;

typedef struct more_s {
    sfSprite *brick;
    sfTexture *brick_text;
    sfVector2f brick_pos;
    sfClock *map_movement;
    int i;
}more_t;

typedef struct small_s {
    sfSprite *brick;
    sfTexture *brick_text;
    sfVector2f brick_pos;
    sfClock *map_movement;
    int i;
}small_t;

typedef struct flag_s {
    sfSprite *brick;
    sfTexture *brick_text;
    sfVector2f brick_pos;
    sfClock *map_movement;
    int i;
}flag_t;

typedef struct click_s {
    bool clicked;
    int m;
    sfClock *small_move;
    int x;
    sfClock *flag_move;
    bool won;
    sfMusic *mlg;
    sfSprite *winner;
    sfTexture *you_win;
    bool died;
    int tmp;
}click_t;

typedef struct structs_s {
    data_t *data;
    paralax_t *dat;
    player_t *d;
    menu_t *m;
    custom_t *c;
    map_t **map;
    maps_t *mapi;
    more_t **enemies;
    click_t *click;
    small_t **small;
    flag_t **flag;
}structs_t;

data_t *init_data(void);
data_t *init_data_ex(void);
int my_putstr(char const *str);
void my_putchar(char c);
void parallax(data_t *data, paralax_t *dat, player_t *d, structs_t *adata);
paralax_t *ini_data(void);
paralax_t *in_data(void);
void mg(paralax_t *dat);
void bg(paralax_t *dat);
void fg(paralax_t *dat);
player_t *initialise(void);
void player(data_t *data, player_t *d, structs_t *adata);
void jump(data_t *data, paralax_t *dat, player_t *d, structs_t *adata);
void check_close(data_t *data, paralax_t *dat, structs_t *adata);
void down(data_t *data, paralax_t *dat, player_t *d);
float go_up(player_t *d);
void main_menu(char **argv);
void sound(structs_t *adata);
void destroyer(data_t *data, paralax_t *dat, player_t *d, structs_t *adata);
void deleter(data_t *data, paralax_t *dat, player_t *d, structs_t *adata);
void positions(player_t *d);
void jump_parallax(data_t *data, paralax_t *dat, player_t *d, structs_t *adata);
void score(structs_t *adata);
char *nb_in_text(int number);
char *my_revstr(char *str);
int my_strlen(char const *str);
void mainmen(structs_t *adata);
void paralax_menu(structs_t *adata);
void buttons(structs_t *adata);
structs_t *all_dat(char **argv);
menu_t *ini(void);
void check_sound(structs_t *adata);
void play(structs_t *adata);
void customisation(structs_t *adata);
menu_t *initialisation(void);
void personalisation(structs_t *adata);
void parallox(data_t *data, paralax_t *dat, player_t *d, structs_t *adata);
void check_closed(structs_t *adata);
custom_t *i(char **argv);
void my_open(structs_t *adata);
void display_ground(structs_t *adata, int i);
map_t **map_ini(structs_t *adata);
maps_t *map_data_i(void);
more_t **map_init(structs_t *adata);
void my_enemies(structs_t *adata);
void extra(structs_t *adata);
void contact(structs_t *adata);
void set_score(structs_t *adata);
int my_getnbr(char const *str);
click_t *click_i(void);
small_t **enemy_init(structs_t *adata);
void small_enemies(structs_t *adata);
void s_contact(structs_t *adata);
flag_t **flag_i(structs_t *adata);
void flag(structs_t *adata);
void f_contact(structs_t *adata);
void my_shortened(structs_t *adata);
void space(structs_t *adata);