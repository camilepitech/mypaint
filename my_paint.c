/*
** EPITECH PROJECT, 2022
** my_paint.g
** File description:
** my_paint
*/
#include "include/libmy.h"

void destroy_all(Graphic *g, Paint *p)
{
    for (int i = 0; i < p->nb_elem; i++) {
        sfTexture_destroy(g->textures[i]);
        sfRectangleShape_destroy(g->buttons[i]->button);
    }

    sfRectangleShape_destroy(g->sideBar);
    sfRectangleShape_destroy(g->menuBar);
    sfRenderWindow_destroy(g->window);
    free(p->login);
    free(p->pos);
    free(p->resources);
}

void get_login(Paint *p, char **env)
{
    char *username = NULL;

    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], "USER", 4) == 0)
            username = my_strdup(env[i] + 5);

    if (username == NULL) {
        username = malloc(sizeof(char) * 10);
        username = my_strcpy(username, "not found");
    }

    p->login = my_strfuse("login: ", username);
}

void paint(Graphic *g, Paint *p)
{
    init_resources(p);
    init_positions(p);
    build_menus(g, p);
    init_sprites(g, p);
    build_draw(g);

    sfRenderWindow_clear(g->window, sfWhite);

    while (sfRenderWindow_isOpen(g->window))
        main_window(g, p);

    destroy_all(g, p);
}

int main(int ac, char **av, char **env)
{
    if (!args_check(ac, av))
        return 84;

    Graphic *g = malloc(sizeof(Graphic));
    Paint *p = malloc(sizeof(Paint));
    init_struct(g, p);
    get_login(p, env);

    paint(g, p);

    return 0;
}
