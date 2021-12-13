# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skillian <skillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 17:42:48 by skillian          #+#    #+#              #
#    Updated: 2021/12/13 17:33:16 by skillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME1 = client
NAME2 = server
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a
SRC =   client.c \
        server.c
OBJ =   $(SRC:.c=.o)
all: $(NAME1) $(NAME2)

%.o: %.c
	gcc -c -Wall -Werror -Wextra $^ -o $@
$(NAME1): $(LIBFT) $(FT_PRINTF) client.o 
	gcc $(FLAGS) $(LIBFT) $(FT_PRINTF) client.o -o $(NAME1)
$(NAME2): $(LIBFT) $(FT_PRINTF) server.o 
	gcc $(FLAGS) $(LIBFT) $(FT_PRINTF) server.o -o $(NAME2)
$(LIBFT):
	make --directory=./Libft
$(FT_PRINTF):
	make --directory=./ft_printf
clean:
	rm -fr $(OBJ)
	make -C ft_printf clean
	make -C libft clean
fclean: clean
	rm -fr $(NAME1) $(NAME2)
re: fclean all
