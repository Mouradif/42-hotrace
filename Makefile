# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akopera <akopera@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/23 15:28:34 by akopera           #+#    #+#              #
#    Updated: 2016/04/23 18:30:13 by mkejji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= hotrace

SRC		= src/main.c src/search.c src/get_next_line.c\
		src/ft_strsub.c src/ft_strnew.c src/ft_strlen.c src/ft_strjoin.c\
		src/ft_strdup.c src/ft_strcpy.c src/ft_strcmp.c src/ft_strchr.c\
		src/ft_putstr.c src/ft_putchar.c src/ft_memset.c src/ft_bzero.c\
		src/create_node.c src/ft_putendl.c

CC		= gcc -Iinc -Wall -Werror -Wextra

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

%.o: %.c
		$(CC) $< -c -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
