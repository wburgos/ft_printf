/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/27 22:57:16 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int		check_converter(char *fmt)
{
	char	*conv;
	int		found;

	found = 0;
	conv = init_conv();
	while (*fmt)
	{
		if (ft_inarray(*fmt, conv))
			found = 1;
		fmt++;
	}
	return (found);
}

int		ft_printf(char *fmt, ...)
{
	int		i;
	va_list	ap;
	int		opts;
	int		min_width;
	int		precision;
	int		conv_i;

	va_start(ap, fmt);
	i = 0;
	while (*fmt)
	{
		if (*fmt != '%' || (*fmt == '%' && !check_converter(fmt)))
		{
			ft_putchar(*fmt);
			i++;
		}
		else
		{
			fmt++;
			if (*fmt == '%')
			{
				ft_putchar(*fmt);
				fmt++;
				i++;
				continue ;
			}
			opts = parse_opts(&fmt, &min_width, &precision, &conv_i);
		}
		fmt++;
	}
	return (i);
}
