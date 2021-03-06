#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 14:13:14 by wburgos           #+#    #+#              #
#    Updated: 2015/03/04 14:46:30 by wburgos          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SDIR = src/
ODIR = obj/
FILES = ft_printf.c opts.c ft_inarray.c ft_memalloc.c ft_putchar.c ft_strnew.c \
		printf_char.c printf_hex.c printf_nb.c printf_noconv.c printf_oct.c \
		printf_str.c printf_wchar.c printf_wstr.c read_precision.c ft_atoi.c  \
		read_converter.c read_modifiers.c read_min_width.c ft_bzero.c ft_swap.c\
		ft_formatnbr.c ft_formatunbr.c ft_isdigit.c read_flags.c ft_nbdigits.c \
		ft_putnchar.c ft_putstr.c ft_putunbr.c ft_putwchar.c ft_putwstr.c \
		ft_strdup.c ft_strlen.c ft_strncpy.c ft_strsub.c ft_strtolower.c \
		ft_wcsdup.c ft_wclen.c printf_spaces.c ft_wcslen.c ft_strcpy.c \
		ft_wcscpy.c ft_wcsncpy.c ft_wcsnew.c ft_wcutf8.c utoa_base.c \
		ft_strrev.c printf_bin.c
OBJ = $(FILES:.c=.o)
SRC = $(addprefix $(SDIR), $(FILES))
INC = -Iincludes/
FLAGS = -Wall -Wextra -Werror -g3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "Compiling printf ..."
	@gcc -c $(FLAGS) $(SRC) $(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) generated."

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
