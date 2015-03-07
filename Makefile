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
SRC = src/
SRCS = 	ft_printf.c opts.c ft_inarray.c ft_memalloc.c ft_putchar.c ft_strnew.c \
		printf_char.c printf_hex.c printf_nb.c printf_noconv.c printf_oct.c \
		printf_str.c printf_wchar.c printf_wstr.c read_precision.c ft_atoi.c  \
		read_converter.c read_modifiers.c read_min_width.c ft_bzero.c \
		ft_formatnbr.c ft_formatunbr.c ft_isdigit.c read_flags.c ft_nbdigits.c \
		ft_putnchar.c ft_putstr.c ft_putunbr.c ft_putwchar.c ft_putwstr.c \
		ft_strdup.c ft_strlen.c ft_strncpy.c ft_strsub.c ft_strtolower.c \
		ft_strwdup.c ft_wclen.c printf_spaces.c ft_wcslen.c ft_strcpy.c \
		ft_wcscpy.c ft_wcsncpy.c ft_wcsnew.c ft_wcutf8.c utoa_base.c \
		ft_strrev.c ft_swap.c
OBJ = $(SRCS:.c=.o)
INC = includes/

all: $(NAME)

$(NAME):
	@echo "Compiling printf ..."
	@gcc -g3 -c $(SRCS) -I$(INC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Done"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
