/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** library
*/
#include <math.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#ifndef libmy
    #define libmy

void pass(void);
void back(void);
void space(void);
void my_putchar(char c);
void my_put_nbr(int nb);
void free_tab(char **tab);
void my_putstr(char const *str);
void my_put_float(double nb, int p, int z);
void my_put_tab(char **buff, char *separator);
void my_put_scientific(double nb, char c, int p, int z);
int my_isint(char c);
int my_nbrlen(int nb);
int my_isalpha(char c);
int my_str2int(char *str);
int my_tablen(char **tab);
int my_isintstr(char *str);
int my_isalphastr(char *str);
int my_wordscount(char *str);
int my_isalphanum(char *str);
int my_longestlen(char **tab);
int my_strlen(char const *str);
int my_int2bin(unsigned long nb);
int my_charocc(char *str, char c);
int my_strocc(char *str, char *sub);
int my_isintab(char **tab, char *str);
int my_strcontains(char *args, char c);
int my_onlycontains(char *str, char *chars);
int my_skipline(char *str, int index, char c);
int my_strcmp(char const *s1, char const *s2);
int my_intextract(char *str, int index, char delim);
int my_strnlen(char const *str, int index, char delim);
int my_strncmp(const char* s1, const char* s2, size_t n);
char *my_int2str(int nb);
char *my_revstr(char *str);
char *my_strsort(char *str);
char *my_strtrim(char *str);
char *my_filestr(char *file);
char *my_strdup(const char *src);
char *my_strdel(char *str, char c);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char *my_strfuse(char *src1, char const *src2);
char *my_strsub(char* str, int index, char end);
char *my_tab2str(char **strings, char separator);
char *my_strncpy(char* dest, const char* src, int n);
char **my_getwords(char *str);
char **my_str2tab(char *str, int index, char delim, int end);

typedef struct Pen {
    sfBool isSelected;
    int size;
    sfColor color;
} Pen;

typedef struct Button {
    sfRectangleShape *button;
    sfBool display;
} Button;

typedef struct Graphic {
    sfRenderWindow *window;
    sfRectangleShape *menuBar;
    sfRectangleShape *sideBar;
    Button **buttons;
    sfTexture **textures;
    Pen *pen;
} Graphic;

typedef struct Paint {
    int nb_elem;
    char **resources;
    char *login;
    sfVector2f *pos;
} Paint;

int args_check(int ac, char **av);
void main_window(Graphic *c, Paint *p);
void event_handler(Graphic *c, Paint *p, sfEvent event);

void init_bodies(Paint *p);
void init_resources(Paint *p);
void init_pos_texts(Paint *p);
void init_positions(Paint *p);
void init_sprites(Graphic *g, Paint *p);
void init_struct(Graphic *g, Paint *p);

sfRectangleShape *build_button(sfRectangleShape *button,
sfVector2f size, sfVector2f pos, sfColor color);
void build_menus(Graphic *g, Paint *p);

void hover_state(Graphic *g, Paint *p);
void pressed_state(Graphic *g, Paint *p);
void hover_textbox(sfRectangleShape *rect, sfRenderWindow *window);

void draw(Graphic *g, sfEvent event);
void build_draw(Graphic *g);

sfText* create_okbuttontext(void);
sfRectangleShape* create_okbutton(void);
sfText* create_messagetext(const char *message);
void display_messagebox(sfRenderWindow *parent, const char *message);

void save_image(Graphic *g);

#endif
