/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:33:54 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:33:55 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*conv_dec(uintmax_t n, int *nbdig)
{
	return (utoa_base(n, nbdig, 10));
}

int			printf_nb(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	len = 0;
	if (opts & D || opts & I || opts & BIG_D)
	{
		if (opts & J || opts & Z)
			len = ft_formatnbr(va_arg(ap, intmax_t), opts, min_width, precision);
		else if (opts & LL)
			len = ft_formatnbr(va_arg(ap, long long), opts, min_width, precision);
		else if (opts & L || opts & BIG_D)
			len = ft_formatnbr(va_arg(ap, long), opts, min_width, precision);
		else if (opts & HH)
			len = ft_formatnbr((char)va_arg(ap, int), opts, min_width, precision);
		else if (opts & H)
			len = ft_formatnbr((short)va_arg(ap, int), opts, min_width, precision);
		else
			len = ft_formatnbr(va_arg(ap, int), opts, min_width, precision);
	}
	if (opts & U || opts & BIG_U)
	{
		if (opts & J)
			len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision, &conv_dec);
		else if (opts & Z)
			len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision, &conv_dec);
		else if (opts & LL)
			len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision, &conv_dec);
		else if (opts & L || opts & BIG_U)
			len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision, &conv_dec);
		else if (opts & HH)
			len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision, &conv_dec);
		else if (opts & H)
			len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision, &conv_dec);
		else
			len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision, &conv_dec);
	}
	return (len);
}
