/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:37:02 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:58:41 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*conv_octal(uintmax_t n, int *nbdig)
{
	return (utoa_base(n, nbdig, 8));
}

int			printf_oct(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	if (opts & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision, &conv_octal);
	else if (opts & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision, &conv_octal);
	else if (opts & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision, &conv_octal);
	else if (opts & L || opts & BIG_O)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision, &conv_octal);
	else if (opts & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision, &conv_octal);
	else if (opts & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision, &conv_octal);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision, &conv_octal);
	return (len);
}
