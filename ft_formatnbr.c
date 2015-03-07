/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 18:03:26 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 17:46:41 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int		octal_alt(uintmax_t n, int opts, int prec)
{
	if ((opts & O || opts & BIG_O) && opts & DIESE &&
		(n != 0 || (n == 0 && opts & PRECISION && prec == 0)))
		return (1);
	return (0);
}

int		hex_alt(uintmax_t n, int opts)
{
	if (((opts & X || opts & BIG_X) && opts & DIESE && n != 0) || opts & P)
		return (1);
	return (0);
}

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

static int	put_zeroes(int minw, int prec, int len, int opts, int not_null)
{
	int		ref;
	int		i;

	i = 0;
	if (opts & MIN_WIDTH && opts & ZERO && !(opts & PRECISION))
		ref = minw;
	else
		ref = prec;
	if (opts & PRECISION && hex_alt(not_null, opts))
		ref += 2;
	while (ref > len++)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

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

static int put_prefix(uintmax_t n, int opts, int prec)
{
	int		len;

	len = 0;
	if (octal_alt(n, opts, prec))
	{
		ft_putchar('0');
		len = 1;
	}
	else if (hex_alt(n, opts))
	{
		ft_putchar('0');
		if (opts & P || opts & X)
			ft_putchar('x');
		else
			ft_putchar('X');
		len = 2;
	}
	return (len);
}

int		ft_formatunbr(uintmax_t n, int opts, int minw, int prec, char *(*convert)(uintmax_t, int *))
{
	int		len;
	int		tmp;
	char	*res;

	res = convert(n, &len);
	if (opts & X || opts & P)
		ft_strtolower(res);
	if (opts & PRECISION && prec == 0 && n == 0)
		len--;
	if (octal_alt(n, opts, prec))
		len++;
	else if (hex_alt(n, opts))
		len += 2;
	tmp = len;
	if (!(opts & MINUS) && !(opts & ZERO))
		len += put_spaces(minw, prec, tmp);
	put_prefix(n, opts, prec);
	if ((!(opts & MINUS) && opts & ZERO) || opts & PRECISION)
		len += put_zeroes(minw, prec, tmp, opts, (n != 0));
	if (!(opts & PRECISION && prec == 0 && n == 0))
		ft_putstr(res);
	free(res);
	if (opts & MINUS)
		len += put_spaces(minw, prec, tmp);
	return (len);
}

static void		ft_putnchar(char c, int n)
{
	while (n-- > 0)
		ft_putchar(c);
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
