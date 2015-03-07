/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:44:19 by wburgos          ###   ########.fr       */
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

int		ft_printf(char *fmt, ...)
{
	int		i;
	va_list	ap;
	int		opts;
	int		min_width;
	int		precision;
	int		conv_i;
	fprint	*ftab;
	int		fwd;

	va_start(ap, fmt);
	ftab = init_ftab();
	i = 0;
	opts = 0;
	min_width = 0;
	precision = 0;
	while (*fmt)
	{
		conv_i = -1;
		if (*fmt != '%')
		{
			ft_putchar(*fmt);
			i++;
		}
		else
		{
			fmt++;
			if (!*fmt)
				break ;
			opts = parse_opts(&fmt, &min_width, &precision, &conv_i);
			if (!*fmt)
				break ;
			if (conv_i == -1)
				i += printf_noconv(*fmt, opts, min_width, precision) ;
			else if (conv_i != -1)
				i += ftab[conv_i](ap, opts, min_width, precision);
		}
		fmt++;
	}
	free(ftab);
	return (i);
}
