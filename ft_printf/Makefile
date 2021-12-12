# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skillian <skillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/28 18:33:13 by skillian          #+#    #+#              #
#    Updated: 2021/08/29 16:44:23 by skillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -c
RM = rm
RM_FlAGS = -f

SOURCES = ft_convert.c ft_dectohex.c ft_printf.c \
			ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	$(CC) $(CC_FLAGS) $(SOURCES)
	ar -crs $(NAME) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(CC_FLAGS) $(SOURCES)

clean:
	$(RM) $(RM_FlAGS) $(OBJECTS)

fclean: clean
	$(RM) $(RM_FlAGS) $(NAME)

re: fclean all
