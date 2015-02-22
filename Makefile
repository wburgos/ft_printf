#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 14:13:14 by wburgos           #+#    #+#              #
#    Updated: 2015/02/20 14:48:49 by wburgos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SRC = src/
SRCS = 	ft_printf.c ft_putchar.c ft_putstr.c ft_strlen.c ft_strdup.c \
		ft_strcpy.c
OBJ = $(SRCS:.c=.o)
INC = includes/

all: $(NAME)

$(NAME):
	@echo "Compiling printf ..."
	@gcc -c $(SRCS) -I$(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Done"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
