/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 18:03:26 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 17:50:46 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_sign(intmax_t n, int opts)
{
	char	sign;

	sign = 0;
	if (n < 0)
		sign = '-';
	else if (n >= 0)
	{
		if (opts & PLUS)
			sign = '+';
		else if (opts & SPACE)
			sign = ' ';
	}
	if (sign != 0)
		ft_putchar(sign);
}

static int		has_sign(intmax_t n, int opts)
{
	return (n >= 0 && (opts & PLUS || opts & SPACE));
}

int		ft_formatnbr(intmax_t n, int opts, int minw, int prec)
{
	int		len;
	int		sign;
	int		nbzero;
	int		nbspaces;

	nbzero = 0;
	nbspaces = 0;
	sign = has_sign(n, opts);
	len = (opts & PRECISION && prec == 0 && n == 0) ? 0 : (ft_nbdigits(n) + sign);
	if (opts & PRECISION && prec > len - (n < 0 || sign))
	{
		nbzero += prec - len + (n < 0 || sign);
		len += nbzero;
	}
	if (opts & MIN_WIDTH && opts & ZERO && !(opts & MINUS)
		&& !(opts & PRECISION) && minw > len)
	{
		nbzero += minw - len;
		len += nbzero;
	}
	if (opts & MIN_WIDTH && (!(opts & ZERO) || opts & MINUS || opts & PRECISION) && minw > len)
	{
		nbspaces += minw - len;
		len += nbspaces;
	}
	if (!(opts & MINUS))
		ft_putnchar(' ', nbspaces);
	put_sign(n, opts);
	ft_putnchar('0', nbzero);
	if (!(opts & PRECISION && prec == 0 && n == 0))
		ft_putunbr((n < 0) ? (-n) : (n));
	if (opts & MINUS)
		ft_putnchar(' ', nbspaces);
	return (len);
}
