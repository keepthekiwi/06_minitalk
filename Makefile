# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skillian <skillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 17:42:48 by skillian          #+#    #+#              #
#    Updated: 2021/12/12 18:22:21 by skillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME1 = client
NAME2 = server
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
SRC =   client.c \
        server.c
OBJ =   $(SRC:.c=.o)
all: $(NAME1) $(NAME2)

%.o: %.c
	gcc -c -Wall -Werror -Wextra $^ -o $@
$(NAME1): $(LIBFT) client.o 
	gcc $(FLAGS) $(LIBFT) client.o -o $(NAME1)
$(NAME2): $(LIBFT) server.o 
	gcc $(FLAGS) $(LIBFT) server.o -o $(NAME2)
$(LIBFT):
	make --directory=./Libft
clean:
	rm -fr $(OBJ)
fclean: clean
	rm -fr $(NAME1) $(NAME2)
re: fclean all
