/*
** EPITECH PROJECT, 2022
** event.c
** File description:
** events
*/
#include "../include/libmy.h"

void file_sett_visibility(Graphic *g)
{
    struct Button **b = g->buttons;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(g->window);
    sfFloatRect fileMenu = sfRectangleShape_getGlobalBounds(b[0]->button);
    sfFloatRect settMenu = sfRectangleShape_getGlobalBounds(b[2]->button);
    sfFloatRect save = sfRectangleShape_getGlobalBounds(b[5]->button);

    if (sfFloatRect_contains(&fileMenu, mousePos.x, mousePos.y)) {
        b[3]->display = !b[3]->display;
        b[4]->display = !b[4]->display;
        b[5]->display = !b[5]->display;
    }
    if (sfFloatRect_contains(&settMenu, mousePos.x, mousePos.y)) {
        b[8]->display = !b[8]->display;
        b[9]->display = !b[9]->display;
    }
    if (sfFloatRect_contains(&save, mousePos.x, mousePos.y)
        && g->buttons[5]->display == sfTrue)
        save_image(g);
}

void draw_visibility(Graphic *g, Paint *p)
{
    struct Button **b = g->buttons;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(g->window);
    sfFloatRect drawMenu = sfRectangleShape_getGlobalBounds(b[1]->button);
    sfFloatRect about = sfRectangleShape_getGlobalBounds(b[8]->button);
    sfFloatRect help = sfRectangleShape_getGlobalBounds(b[9]->button);
    sfBool visible = g->buttons[8]->display == sfTrue;

    if (sfFloatRect_contains(&drawMenu, mousePos.x, mousePos.y)) {
        b[6]->display = !b[6]->display;
        b[7]->display = !b[7]->display;
        for (int i = 10; i < 17; i++)
            b[i]->display = !b[i]->display;
    }
    if (sfFloatRect_contains(&about, mousePos.x, mousePos.y) && visible)
        display_messagebox(g->window, p->login);

    if (sfFloatRect_contains(&help, mousePos.x, mousePos.y) && visible)
        display_messagebox(g->window, "This program reproduce Paint.\nYou "
        "can paint, choose the\ncolor, choose the brush size,\nerase,"
        " and clear all.");
}

void change_size(Graphic *g)
{
    struct Button **b = g->buttons;
    struct Pen *p = g->pen;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(g->window);
    sfFloatRect size_up = sfRectangleShape_getGlobalBounds(b[10]->button);
    sfFloatRect size_down = sfRectangleShape_getGlobalBounds(b[11]->button);
    sfFloatRect refresh = sfRectangleShape_getGlobalBounds(b[12]->button);
    sfFloatRect pen_select = sfRectangleShape_getGlobalBounds(b[6]->button);
    sfBool visible = g->buttons[6]->display;

    if (sfFloatRect_contains(&size_up, mousePos.x, mousePos.y) && visible)
        p->size += (p->size < 50) ? 5 : 0;
    if (sfFloatRect_contains(&size_down, mousePos.x, mousePos.y) && visible)
        p->size -= (p->size > 5) ? 5 : 0;
    if (sfFloatRect_contains(&refresh, mousePos.x, mousePos.y) && visible)
        sfRenderWindow_clear(g->window, sfWhite);
    if (sfFloatRect_contains(&pen_select, mousePos.x, mousePos.y) && visible) {
        p->isSelected = sfTrue;
        p->color = sfBlack;
    }
}

void change_color(Graphic *g)
{
    struct Button **b = g->buttons; struct Pen *p = g->pen;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(g->window);
    sfFloatRect white = sfRectangleShape_getGlobalBounds(b[7]->button);
    sfFloatRect black = sfRectangleShape_getGlobalBounds(b[13]->button);
    sfFloatRect red = sfRectangleShape_getGlobalBounds(b[14]->button);
    sfFloatRect yellow = sfRectangleShape_getGlobalBounds(b[15]->button);
    sfFloatRect blue = sfRectangleShape_getGlobalBounds(b[16]->button);
    sfBool is_visible = g->buttons[6]->display;

    if (sfFloatRect_contains(&white, mousePos.x, mousePos.y) && is_visible)
        p->color = sfWhite;
    if (sfFloatRect_contains(&black, mousePos.x, mousePos.y) && is_visible)
        p->color = sfBlack;
    if (sfFloatRect_contains(&red, mousePos.x, mousePos.y) && is_visible)
        p->color = sfRed;
    if (sfFloatRect_contains(&yellow, mousePos.x, mousePos.y) && is_visible)
        p->color = sfYellow;
    if (sfFloatRect_contains(&blue, mousePos.x, mousePos.y) && is_visible)
        p->color = sfBlue;
}

void event_handler(Graphic *g, Paint *p, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(g->window);
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft) {
            file_sett_visibility(g);
            draw_visibility(g, p);
            change_size(g);
            change_color(g);
        }
    }

    draw(g, event);
}
