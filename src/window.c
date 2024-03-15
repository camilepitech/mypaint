/*
** EPITECH PROJECT, 2022
** window.c
** File description:
** window
*/
#include "../include/libmy.h"

void draw_all(Graphic *g, Paint *p)
{
    sfRenderWindow_drawRectangleShape(g->window, g->menuBar, NULL);
    sfRenderWindow_drawRectangleShape(g->window, g->sideBar, NULL);

    for (int i = 0; i < p->nb_elem ; i++)
        if (g->buttons[i]->display)
            sfRenderWindow_drawRectangleShape
            (g->window, g->buttons[i]->button, NULL);
}

void main_window(Graphic *g, Paint *p)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(g->window, &event))
        event_handler(g, p, event);

    hover_state(g, p);
    pressed_state(g, p);

    draw_all(g, p);

    sfRenderWindow_display(g->window);
}
