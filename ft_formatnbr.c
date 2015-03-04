/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 18:03:26 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/04 18:37:09 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	put_spaces(int minw, int prec, int len)
{
	int		i;

	i = 0;
	if (prec > len)
		len = prec;
	while (minw > len++)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	put_zeroes(int minw, int prec, int len, int opts)
{
	int		ref;
	int		i;

	i = 0;
	ref = (opts & ZERO && minw > prec) ? minw : prec;
	while (ref > len++)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

static int put_sign(intmax_t n, int opts, int *tmp)
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
	if (sign == 0 || sign == '-')
		return (0);
	(*tmp)++;
	return (1);
}

int		ft_formatunbr(uintmax_t n, int opts, int minw, int prec)
{
	int		len;
	int		tmp;

	len = ft_unbdigits(n);
	tmp = len;
	if (!(opts & MINUS) && !(opts & ZERO))
		len += put_spaces(minw, prec, tmp);
	if ((!(opts & MINUS) && opts & ZERO) || opts & PRECISION)
		len += put_zeroes(minw, prec, tmp, opts);
	ft_putunbr(n);
	if (opts & MINUS)
		len += put_spaces(minw, prec, tmp);
	return (len);
}

int		ft_formatnbr(intmax_t n, int opts, int minw, int prec)
{
	int		len;
	int		tmp;

	len = ft_nbdigits(n);
	tmp = len;
	if (!(opts & MINUS) && !(opts & ZERO))
		len += put_spaces(minw, prec, tmp);
	len += put_sign(n, opts, &tmp);
	if ((!(opts & MINUS) && opts & ZERO) || opts & PRECISION)
		len += put_zeroes(minw, prec, tmp, opts);
	ft_putunbr((n < 0) ? (-n) : (n));
	if (opts & MINUS)
		len += put_spaces(minw, prec, tmp);
	return (len);
}
