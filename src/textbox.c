/*
** EPITECH PROJECT, 2022
** textbox.c
** File description:
** textbox
*/

#include "../include/libmy.h"

void set_position(sfVideoMode videoMode, sfRenderWindow *parent,
sfRenderWindow *messageBoxWindow)
{
    sfVector2u parentSize = sfRenderWindow_getSize(parent);
    sfVector2i parentPosition = sfRenderWindow_getPosition(parent);
    sfVector2i messageBoxPosition = {
        parentPosition.x + (parentSize.x - videoMode.width) / 2,
        parentPosition.y + (parentSize.y - videoMode.height) / 2
    };

    sfRenderWindow_setPosition(messageBoxWindow, messageBoxPosition);
}

int check_buttonclick(sfRectangleShape *okButton, sfRenderWindow
*messageBoxWindow)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow
    (messageBoxWindow);
    sfFloatRect okButtonBounds = sfRectangleShape_getGlobalBounds(okButton);
    return sfFloatRect_contains(&okButtonBounds, mousePosition.x,
    mousePosition.y);
}

void draw_textbox(sfRenderWindow *messageBoxWindow, sfText *text,
sfText *okButtonText, sfRectangleShape *okButton)
{
    sfRenderWindow_clear(messageBoxWindow, sfColor_fromRGB(200, 200, 200));
    sfRenderWindow_drawText(messageBoxWindow, text, NULL);
    sfRenderWindow_drawRectangleShape(messageBoxWindow, okButton, NULL);
    sfRenderWindow_drawText(messageBoxWindow, okButtonText, NULL);
    sfRenderWindow_display(messageBoxWindow);
}

void display_messagebox(sfRenderWindow *parent, const char *message)
{
    sfVideoMode videoMode = {300, 200, 32};
    sfRenderWindow *messageBoxWindow =
    sfRenderWindow_create(videoMode, "Message Box", sfClose, NULL);
    set_position(videoMode, parent, messageBoxWindow);
    sfText *text = create_messagetext(message);
    sfText *okButtonText = create_okbuttontext();
    sfRectangleShape *okButton = create_okbutton();

    int running = 1;
    while (running) {
        sfEvent event;
        hover_textbox(okButton, messageBoxWindow);
        while (sfRenderWindow_pollEvent(messageBoxWindow, &event)) {
            running = (event.type == sfEvtClosed) ? 0 : 1;
            running = (event.type == sfEvtMouseButtonPressed &&
                        check_buttonclick(okButton, messageBoxWindow)) ? 0 : 1;
        } draw_textbox(messageBoxWindow, text, okButtonText, okButton);
    } sfRectangleShape_destroy(okButton);
    sfRenderWindow_close(messageBoxWindow), sfText_destroy(okButtonText);
    sfRenderWindow_destroy(messageBoxWindow), sfText_destroy(text);
}
