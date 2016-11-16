# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrang <atrang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/28 09:52:45 by atrang            #+#    #+#              #
#    Updated: 2016/05/16 18:19:03 by atrang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Wolf3D

SRC = main.c color.c util.c parse.c hook.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
				make -C libft
				gcc $(OBJ) -o $(NAME) -lft -L ./libft -framework OpenGl -lmlx -framework AppKit

%.o:%.c
				gcc -c $< -o $@ -Includes $(FLAGS)

clean:
				make -C libft/ clean
				rm -rf $(OBJ)

fclean:clean
				make -C libft/ fclean
				rm -rf $(NAME)

re: fclean all
