# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taikwata <taikwata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/08 14:11:32 by taikwata          #+#    #+#              #
#    Updated: 2024/09/28 11:33:07 by taikwata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRC_FILES = ft_printf.c ft_putchar.c ft_puthex.c  ft_putnbr.c  ft_putptr.c  ft_putstr.c  ft_putunsigned.c ft_strlen.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(AR) $(NAME) $(OBJ_FILES)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
