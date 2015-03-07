/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:33:54 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:55:34 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*conv_dec(uintmax_t n, int *nbdig)
{
	return (utoa_base(n, nbdig, 10));
}

int			printf_nb(va_list ap, t_opts *opts)
{
	int		len;
	int		flags;
	int		min_width;
	int		precision;

	len = 0;
	flags = opts->flags;
	min_width = opts->min_width;
	precision = opts->precision;
	if (flags & D || flags & I || flags & BIG_D)
	{
		if (flags & J || flags & Z)
			len = ft_formatnbr(va_arg(ap, intmax_t), flags, min_width, precision);
		else if (flags & LL)
			len = ft_formatnbr(va_arg(ap, long long), flags, min_width, precision);
		else if (flags & L || flags & BIG_D)
			len = ft_formatnbr(va_arg(ap, long), flags, min_width, precision);
		else if (flags & HH)
			len = ft_formatnbr((char)va_arg(ap, int), flags, min_width, precision);
		else if (flags & H)
			len = ft_formatnbr((short)va_arg(ap, int), flags, min_width, precision);
		else
			len = ft_formatnbr(va_arg(ap, int), flags, min_width, precision);
	}
	if (flags & U || flags & BIG_U)
	{
		if (flags & J)
			len = ft_formatunbr(va_arg(ap, uintmax_t), flags, min_width, precision, &conv_dec);
		else if (flags & Z)
			len = ft_formatunbr(va_arg(ap, size_t), flags, min_width, precision, &conv_dec);
		else if (flags & LL)
			len = ft_formatunbr(va_arg(ap, unsigned long long), flags, min_width, precision, &conv_dec);
		else if (flags & L || flags & BIG_U)
			len = ft_formatunbr(va_arg(ap, unsigned long), flags, min_width, precision, &conv_dec);
		else if (flags & HH)
			len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), flags, min_width, precision, &conv_dec);
		else if (flags & H)
			len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), flags, min_width, precision, &conv_dec);
		else
			len = ft_formatunbr(va_arg(ap, unsigned int), flags, min_width, precision, &conv_dec);
	}
	return (len);
}
