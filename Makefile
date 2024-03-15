##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make
##

SRC =	lib/my/my_len.c\
        lib/my/my_put.c\
        lib/my/my_str.c\
        lib/my/my_sort.c\
        lib/my/my_type.c\
        lib/my/my_strr.c\
        lib/my/my_words.c\
        lib/my/my_float.c\
        lib/my/my_tools.c\
        lib/my/my_strrr.c\
        lib/my/my_convert.c\
        src/args.c\
        src/window.c\
        src/event.c\
        src/init.c\
        src/build.c\
        src/states.c\
        src/draw.c\
        src/textbox.c\
	$(BINARY).c

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

LIB = -L. -lmy

INCLUDE = -I include

CSFML = -lcsfml-graphics -lcsfml-window -lcsfml-system

BINARY = my_paint

all:	$(NAME)

$(NAME):$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(BINARY) $(BINARY).c $(INCLUDE) $(LIB) $(CSFML) -lm

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete
	find . -name "#*#" -delete
	find . -name "vgcore.*" -delete

fclean:	clean
	rm -f $(NAME)
	rm -f $(BINARY)

re:	fclean all

.PHONY:	clean fclean re all
