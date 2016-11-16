# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataibi <ataibi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 13:59:19 by ataibi            #+#    #+#              #
#    Updated: 2016/03/21 16:57:48 by atrang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a 
SRCS	= ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_islower.c ft_isprint.c ft_isupper.c ft_memcmp.c ft_strequ.c ft_strcmp.c \
ft_strncmp.c ft_strnequ.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_strlen.c \
ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcpy.c ft_memdel.c \
ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strclr.c ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncpy.c ft_strnew.c ft_strnstr.c ft_strchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strcpy.c ft_strjoin.c ft_itoa.c ft_strcat.c \
ft_strchr.c ft_strdup.c ft_strrchr.c ft_strtrim.c ft_isspace.c ft_lstadd.c \
ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstlen.c \
ft_lastelem.c ft_putstr_endl.c ft_puttab.c get_next_line.c

DIRSRC	= $(addprefix ./ , $(SRCS))
OBJS	= ${SRCS:%.c=.obj/%.o}
INC		= ./
FLAGS	= -Wall -Wextra -Werror
CC		= gcc
AR		= ar rc
RANLIB	= ranlib

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(RANLIB) $(NAME)
	@echo "Création de $(NAME)"

.obj/%.o: %.c
	@mkdir -p .obj
	@$(CC) -c $< -o $@ $(FLAGS) -I $(INC)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all
