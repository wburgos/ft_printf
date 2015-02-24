/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/24 17:57:35 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		set_opts(char *format, t_opts *opts, int i)
{
	if (format[i] == '#')
	{
		opts->diese = 1;
		i++;
	}
	if (format[i] == '0')
	{
		opts->zero = 1;
		i++;
	}
	if (format[i] == '-')
	{
		opts->minus = 1;
		i++;
	}
	if (format[i] == ' ')
	{
		opts->space = 1;
		i++;
	}
	if (format[i] == '+')
	{
		opts->plus = 1;
		i++;
	}
	return (i);
}

void	get_opts(char *format, t_opts *opts)
{
	int		i;

	i = 0;
	init_opts(opts);
	while (format[i])
	{
		set_opts
		i++;
	}
}

int		ft_printf(char *format, ...)
{
	int		i;
	va_list	ap;
	char	*str;
	t_opts	opts;

	va_start(ap, format);
	i = 0;
	get_opts(format, &opts);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format);
		else
		{
			format++;
			if (!*format)
				break ;
		}
		i++;
		format++;
	}
	return (i);
}
