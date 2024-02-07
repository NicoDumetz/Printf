##
## EPITECH PROJECT, 2023
## Makefile libmy.a
## File description:
## create lib for my_printf
##

RESSOURCES_PATH = ressources

FLAGS_PATH = flags

SRC =	$(RESSOURCES_PATH)/my_convert_base.c \
	$(RESSOURCES_PATH)/my_putchar.c \
	$(RESSOURCES_PATH)/my_put_nbr.c \
	$(RESSOURCES_PATH)/my_putstr.c \
	$(RESSOURCES_PATH)/my_intlen.c \
	$(RESSOURCES_PATH)/my_put_float.c \
	$(RESSOURCES_PATH)/my_put_sci_nbr.c \
	$(RESSOURCES_PATH)/my_strlen.c \
	$(FLAGS_PATH)/flags.c \
	$(FLAGS_PATH)/flags2.c \
	$(FLAGS_PATH)/flags3.c \
	my_printf.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

header:
	cp $(RESSOURCES_PATH)/my_printf.h include

$(NAME): header $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f include/my_printf.h

re: fclean all