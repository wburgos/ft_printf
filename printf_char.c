/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:02:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:05:30 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_char(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	char	c;

	if (opts & L)
		return (printf_wchar(ap, opts, min_width, precision));
	c = va_arg(ap, int);
	len = sizeof(char);
	if (!(opts & MINUS))
		len = printf_spaces(min_width, len, opts);
	ft_putchar(c);
	if (opts & MINUS)
		len = printf_spaces(min_width, len, opts);
	return (len);
}
