/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 12:29:07 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

// int		set_opts(char *format, t_opts *opts, int i)
// {
// 	if (format[i] == '#')
// 	{
// 		opts->diese = 1;
// 		i++;
// 	}
// 	if (format[i] == '0')
// 	{
// 		opts->zero = 1;
// 		i++;
// 	}
// 	if (format[i] == '-')
// 	{
// 		opts->minus = 1;
// 		i++;
// 	}
// 	if (format[i] == ' ')
// 	{
// 		opts->space = 1;
// 		i++;
// 	}
// 	if (format[i] == '+')
// 	{
// 		opts->plus = 1;
// 		i++;
// 	}
// 	return (i);
// }

// void	get_opts(char *format, t_opts *opts)
// {
// 	int		i;

// 	i = 0;
// 	init_opts(opts);
// 	while (format[i])
// 	{
// 		set_opts
// 		i++;
// 	}
// }

int		ft_printf(char *fmt, ...)
{
	int		i;
	va_list	ap;
	char	*symbols;
	char	*opts;

	symbols = init_symbols(symbols);
	va_start(ap, fmt);
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
			opts = parse_opts(opts, symbols);
			i = convert(fmt, opts, i);
		}
		fmt++;
	}
	free(symbols);
	return (i);
}
