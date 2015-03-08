/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:51:09 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static fprint	*init_ftab()
{
	fprint *ftab;

	ftab = ft_memalloc(sizeof(*ftab) * C_SIZE);
	ftab[I_S] = printf_str;
	ftab[I_BIGS] = printf_wstr;
	ftab[I_P] = printf_hex;
	ftab[I_D] = printf_nb;
	ftab[I_BIGD] = printf_nb;
	ftab[I_I] = printf_nb;
	ftab[I_O] = printf_oct;
	ftab[I_BIGO] = printf_oct;
	ftab[I_U] = printf_nb;
	ftab[I_BIGU] = printf_nb;
	ftab[I_X] = printf_hex;
	ftab[I_BIGX] = printf_hex;
	ftab[I_C] = printf_char;
	ftab[I_BIGC] = printf_wchar;
	return (ftab);
}

static int		parse(va_list ap, char **fmt, fprint *ftab)
{
	int		conv_i;
	t_opts	opts;
	int		i;

	i = 0;
	opts.flags = 0;
	opts.min_width = 0;
	opts.precision = 0;
	if (!**fmt)
		return (-1);
	conv_i = parse_opts(fmt, &opts);
	if (!**fmt)
		return (-1);
	if (conv_i == -1)
		i += printf_noconv(**fmt, &opts);
	else
		i += ftab[conv_i](ap, &opts); 
	return (i);
}

static int		print(va_list ap, char *fmt)
{
	int		i;
	fprint	*ftab;
	int		parse_len;

	i = 0;
	ftab = init_ftab();
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt);
			i++;
		}
		else
		{
			fmt++;
			parse_len = parse(ap, &fmt, ftab);
			if (parse_len == -1)
				break ;
			i += parse_len;
		}
		fmt++;
	}
	free(ftab);
	return (i);
}

int				ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = print(ap, fmt);
	va_end(ap);
	return (len);
}
