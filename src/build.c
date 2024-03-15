/*
** EPITECH PROJECT, 2022
** build.c
** File description:
** build
*/
#include "../include/libmy.h"

sfRectangleShape *build_button(sfRectangleShape *button,
sfVector2f size, sfVector2f pos, sfColor color)
{
    button = sfRectangleShape_create();
    sfRectangleShape_setSize(button, size);
    sfRectangleShape_setPosition(button, pos);
    sfRectangleShape_setFillColor(button, color);
    sfRectangleShape_setOutlineThickness(button, 1.0);
    sfRectangleShape_setOutlineColor(button, sfBlack);

    return button;
}

void build_menus(Graphic *g, Paint *p)
{
    g->buttons = malloc(sizeof(Button *) * p->nb_elem);

    sfVector2f size = {60, 60};
    sfColor color = sfWhite;

    for (int i = 0; i < p->nb_elem; i++) {
        g->buttons[i] = malloc(sizeof(Button *));
        g->buttons[i]->button = build_button
        (g->buttons[i]->button, size, p->pos[i], color);
        g->buttons[i]->display = (i < 3 || i > 9 ) ? sfTrue : sfFalse;
    }
}

sfText* create_messagetext(const char *message)
{
    sfText *text = sfText_create();
    sfText_setString(text, message);
    sfText_setCharacterSize(text, 20);
    sfText_setFillColor(text, sfBlack);
    sfText_setPosition(text, (sfVector2f){10.f, 10.f});
    sfFont *font = sfFont_createFromFile("resources/arial.ttf");
    sfText_setFont(text, font);
    return text;
}

sfRectangleShape* create_okbutton(void)
{
    sfRectangleShape *okButton = sfRectangleShape_create();
    sfRectangleShape_setSize(okButton, (sfVector2f){80, 40});
    sfRectangleShape_setFillColor(okButton, (sfColor){150, 150, 150, 255});
    sfRectangleShape_setOutlineColor(okButton, sfBlack);
    sfRectangleShape_setOutlineThickness(okButton, 2.f);
    sfRectangleShape_setPosition(okButton, (sfVector2f){110.f, 140.f});
    return okButton;
}

sfText* create_okbuttontext(void)
{
    sfText *okButtonText = sfText_create();
    sfText_setString(okButtonText, "OK");
    sfText_setCharacterSize(okButtonText, 20);
    sfText_setFillColor(okButtonText, sfBlack);
    sfText_setPosition(okButtonText, (sfVector2f){135.f, 147.f});
    sfFont *font = sfFont_createFromFile("resources/arial.ttf");
    sfText_setFont(okButtonText, font);
    return okButtonText;
}
