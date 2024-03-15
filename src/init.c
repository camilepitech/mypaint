/*
** EPITECH PROJECT, 2022
** init.c
** File description:
** init
*/
#include "../include/libmy.h"


void init_rectangles(Graphic *g)
{
    g->menuBar = sfRectangleShape_create();
    sfRectangleShape_setSize(g->menuBar, (sfVector2f){1280.0f, 100.0f});
    sfRectangleShape_setFillColor(g->menuBar, (sfColor){150, 150, 150, 255});

    g->sideBar = sfRectangleShape_create();
    sfRectangleShape_setSize(g->sideBar, (sfVector2f){100.0f, 800.0f});
    sfRectangleShape_setFillColor(g->sideBar, (sfColor){150, 150, 150, 255});
}

void init_sprites(Graphic *g, Paint *p)
{
    init_rectangles(g);

        for (int i = 10; i < 17; i++)
            g->buttons[i]->display = sfFalse;

    g->buttons[17]->display = sfTrue;
    g->textures = malloc(sizeof(sfTexture *) * p->nb_elem);

    for (int i = 0; i < p->nb_elem; i++) {
        g->textures[i] = sfTexture_createFromFile(p->resources[i], NULL);
        sfRectangleShape_setTexture
        (g->buttons[i]->button, g->textures[i], sfTrue);
        sfRectangleShape_setOutlineThickness(g->buttons[i]->button, 2.0);
    }
}

void init_resources(Paint *p)
{
    p->resources = malloc(sizeof(char *) * p->nb_elem);
    p->resources[17] = "resources/paint.png";
    p->resources[0] = "resources/file.png";
    p->resources[1] = "resources/edit.png";
    p->resources[2] = "resources/settings.png";
    p->resources[3] = "resources/new_file.png";
    p->resources[4] = "resources/open_file.png";
    p->resources[5] = "resources/save_file.png";
    p->resources[6] = "resources/pencil.png";
    p->resources[7] = "resources/eraser.png";
    p->resources[8] = "resources/about.png";
    p->resources[9] = "resources/help.png";
    p->resources[10] = "resources/size_up.jpg";
    p->resources[11] = "resources/size_down.jpg";
    p->resources[12] = "resources/refresh.jpg";
    p->resources[13] = "resources/black.png";
    p->resources[14] = "resources/red.png";
    p->resources[15] = "resources/yellow.png";
    p->resources[16] = "resources/blue.png";
}

void init_positions(Paint *p)
{
    p->pos = malloc(sizeof(sfVector2f) * p->nb_elem);
    p->pos[17] = (sfVector2f){18.0f, 18.0f};
    p->pos[0] = (sfVector2f){280.0f, 18.0f};
    p->pos[1] = (sfVector2f){650.0f, 18.0f};
    p->pos[2] = (sfVector2f){950.0f, 18.0f};
    p->pos[3] = (sfVector2f){343.0f, 18.0f};
    p->pos[4] = (sfVector2f){406.0f, 18.0f};
    p->pos[5] = (sfVector2f){469.0f, 18.0f};
    p->pos[6] = (sfVector2f){713.0f, 18.0f};
    p->pos[7] = (sfVector2f){776.0f, 18.0f};
    p->pos[8] = (sfVector2f){1013.0f, 18.0f};
    p->pos[9] = (sfVector2f){1076.0f, 18.0f};
    p->pos[10] = (sfVector2f){20.0f, 530.0f};
    p->pos[11] = (sfVector2f){20.0f, 610.0f};
    p->pos[12] = (sfVector2f){20.0f, 690.0f};
    p->pos[13] = (sfVector2f){20.0f, 160.0f};
    p->pos[14] = (sfVector2f){20.0f, 240.0f};
    p->pos[15] = (sfVector2f){20.0f, 320.0f};
    p->pos[16] = (sfVector2f){20.0f, 400.0f};
}

void init_struct(Graphic *g, Paint *p)
{
    sfVideoMode mode = {1280, 800, 32};
    g->window = sfRenderWindow_create
    (mode, "My Paint", sfResize | sfClose, NULL);

    sfVideoMode desktopVideoMode = sfVideoMode_getDesktopMode();
    sfVector2i parentWindowPosition = {
        (desktopVideoMode.width - mode.width) / 2,
        (desktopVideoMode.height - mode.height) / 2
    };
    sfRenderWindow_setPosition(g->window, parentWindowPosition);

    sfRenderWindow_setFramerateLimit(g->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(g->window, sfTrue);
    sfRenderWindow_setMouseCursorVisible(g->window, sfTrue);

    p->nb_elem = 18;
}
