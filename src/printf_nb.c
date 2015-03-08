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

static int	signed_nb(va_list ap, t_opts *opts)
{
	int		len;

	len = 0;
	if (opts->flags & J || opts->flags & Z)
		len = ft_formatnbr(va_arg(ap, intmax_t), opts);
	else if (opts->flags & LL)
		len = ft_formatnbr(va_arg(ap, long long), opts);
	else if (opts->flags & L || opts->flags & BIG_D)
		len = ft_formatnbr(va_arg(ap, long), opts);
	else if (opts->flags & HH)
		len = ft_formatnbr((char)va_arg(ap, int), opts);
	else if (opts->flags & H)
		len = ft_formatnbr((short)va_arg(ap, int), opts);
	else
		len = ft_formatnbr(va_arg(ap, int), opts);
	return (len);
}

static int	unsigned_nb(va_list ap, t_opts *opts)
{
	int		len;

	len = 0;
	if (opts->flags & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, &conv_dec);
	else if (opts->flags & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, &conv_dec);
	else if (opts->flags & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts,
			&conv_dec);
	else if (opts->flags & L || opts->flags & BIG_U)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, &conv_dec);
	else if (opts->flags & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts,
			&conv_dec);
	else if (opts->flags & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts,
			&conv_dec);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, &conv_dec);
	return (len);
}

int			printf_nb(va_list ap, t_opts *opts)
{
	int		len;
	int		flags;

	len = 0;
	flags = opts->flags;
	if (flags & D || flags & I || flags & BIG_D)
		len = signed_nb(ap, opts);
	if (flags & U || flags & BIG_U)
		len = unsigned_nb(ap, opts);
	return (len);
}
