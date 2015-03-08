/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/08 19:43:34 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int		call_func(va_list ap, t_opts *opts, int i, char noconv)
{
	if (i == -1)
		return (printf_noconv(noconv, opts));
	else if (i == I_S)
		return (printf_str(ap, opts));
	else if (i == I_BIGS)
		return (printf_wstr(ap, opts));
	else if (i == I_D || i == I_BIGD || i == I_I || i == I_U || i == I_BIGU)
		return (printf_nb(ap, opts));
	else if (i == I_O || i == I_BIGO)
		return (printf_oct(ap, opts));
	else if (i == I_P || i == I_X || i == I_BIGX)
		return (printf_hex(ap, opts));
	else if (i == I_C)
		return (printf_char(ap, opts));
	else if (i == I_BIGC)
		return (printf_wchar(ap, opts));
	return (0);
}

static int		print(va_list ap, char **fmt)
{
	int		i;
	t_opts	opts;
	int		conv_i;

	i = 0;
	opts.flags = 0;
	opts.min_width = 0;
	opts.precision = 0;
	if (!**fmt)
		return (-1);
	conv_i = parse_opts(ap, fmt, &opts);
	if (!**fmt)
		return (-1);
	i += call_func(ap, &opts, conv_i, **fmt);
	return (i);
}

static int		parse(va_list ap, char *fmt)
{
	int		i;
	int		printlen;

	i = 0;
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
			printlen = print(ap, &fmt);
			if (printlen == -1)
				break ;
			i += printlen;
		}
		fmt++;
	}
	return (i);
}

int				ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = parse(ap, fmt);
	va_end(ap);
	return (len);
}
