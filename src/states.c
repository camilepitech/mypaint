/*
** EPITECH PROJECT, 2022
** states.c
** File description:
** states
*/
#include "../include/libmy.h"

void hover_state(Graphic *g, Paint *p)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g->window);
    sfColor color;

    for (int i = 0; i < (p->nb_elem - 1); i++) {
        sfRectangleShape *rect = g->buttons[i]->button;
        sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect);

        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
            color = (i > 2) ? sfGreen : sfRed;
        else
            color = sfBlack;

        sfRectangleShape_setOutlineColor(rect, color);
    }
}

void pressed_state(Graphic *g, Paint *p)
{
    sfBool is_mouse_pressed = sfMouse_isButtonPressed(sfMouseLeft);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(g->window);
    sfColor color;

    for (int i = 0; i < (p->nb_elem - 1); i++) {
        sfRectangleShape *rect = g->buttons[i]->button;
        sfFloatRect rect_bounds = sfRectangleShape_getGlobalBounds(rect);
        sfBool is_mouse_over_rect = sfFloatRect_contains
        (&rect_bounds, mouse_pos.x, mouse_pos.y);

        if (is_mouse_pressed && is_mouse_over_rect)
            color = sfColor_fromRGBA(0, 0, 0, 60);
        else
            color = sfWhite;

        sfRectangleShape_setFillColor(rect, color);
    }
}

void hover_textbox(sfRectangleShape *rect, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect);
    sfColor color;

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y))
        color = sfColor_fromRGBA(0, 0, 0, 60);
    else
        color = sfWhite;

    sfRectangleShape_setFillColor(rect, color);
}
