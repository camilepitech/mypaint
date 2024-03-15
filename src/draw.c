/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "../include/libmy.h"

void draw_circles(Graphic *g, int steps, float *coord, sfVector2i prevMousePos)
{
    struct Pen *p = g->pen;

    for (int i = 0; i <= steps; i++) {
        float t = (float)i / steps;
        float xi = (1 - t) * (prevMousePos.x - p->size) + t * coord[0];
        float yi = (1 - t) * (prevMousePos.y - p->size) + t * coord[1];

        sfCircleShape* circle = sfCircleShape_create();
        sfCircleShape_setPosition(circle, (sfVector2f){xi, yi});
        sfCircleShape_setRadius(circle, p->size);
        sfCircleShape_setFillColor(circle, p->color);
        sfRenderWindow_drawCircleShape(g->window, circle, NULL);
        sfCircleShape_destroy(circle);
    }
}

void draw(Graphic *g, sfEvent event)
{
    struct Pen *p = g->pen; static sfVector2i prevMousePosition = {-1, -1};
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(g->window);
    float x = mousePosition.x - p->size, y = mousePosition.y - p->size;
    int isDrawing = (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft) ||
    (event.type == sfEvtMouseMoved && sfMouse_isButtonPressed(sfMouseLeft));
    int isInside = (x > (100 - p->size) && y > (100 - p->size));

    if (p->isSelected && isDrawing && isInside) {
        if (prevMousePosition.x != -1 && prevMousePosition.y != -1) {
            float dx = x - (prevMousePosition.x - p->size);
            float dy = y - (prevMousePosition.y - p->size);
            float distance = sqrt(dx * dx + dy * dy), coord[] = {x, y};
            int steps = ceil(distance / p->size);
            draw_circles(g, steps, coord, prevMousePosition);
        }
        prevMousePosition = mousePosition; sfRenderWindow_display(g->window);
    } else {
        prevMousePosition.x = -1, prevMousePosition.y = -1;
    }
}

void build_draw(Graphic *g)
{
    g->pen = malloc(sizeof(Pen));

    struct Pen *p = g->pen;
    p->size = 20;
    p->color = sfBlack;
    p->isSelected = sfFalse;
}

void save_image(Graphic *g)
{

    sfVector2u windowSize = sfRenderWindow_getSize(g->window);

    sfTexture *texture = sfTexture_create(windowSize.x, windowSize.y);

    sfTexture_updateFromRenderWindow(texture, g->window, 0, 0);

    sfImage *image = sfTexture_copyToImage(texture);
    sfBool result = sfImage_saveToFile(image, "paint.png");

    display_messagebox(g->window, "file saved!\npaint.png");

    sfImage_destroy(image);
    sfTexture_destroy(texture);
}
