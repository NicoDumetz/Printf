##
## EPITECH PROJECT, 2023
## Makefile libmy_printf.a
## File description:
## create lib for my_printf
##

SRC =	my_convert_base.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_intlen.c \
	my_put_float.c \
	my_put_sci_nbr.c \
	my_strlen.c

OBJ = $(SRC:.c=.o)

NAME = libmy_printf.a

CFLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
re: fclean all
