/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_oct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:37:02 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:43:57 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

static char	*conv_octal(uintmax_t n, int *nbdig)
{
	return (utoa_base(n, nbdig, 8));
}

int			printf_oct(va_list ap, t_opts *opts)
{
	int		len;

	if (opts->flags & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, &conv_octal);
	else if (opts->flags & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, &conv_octal);
	else if (opts->flags & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts, &conv_octal);
	else if (opts->flags & L || opts->flags & BIG_O)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, &conv_octal);
	else if (opts->flags & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts,
			&conv_octal);
	else if (opts->flags & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts,
			&conv_octal);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, &conv_octal);
	return (len);
}
