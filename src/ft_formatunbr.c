/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatunbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 17:53:49 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:14:28 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

static int put_sign(uintmax_t n, int opts, int prec)
{
	int		len;

	len = 0;
	if ((opts & O || opts & BIG_O) && opts & DIESE &&
		(n != 0 || (n == 0 && opts & PRECISION && prec == 0)))
	{
		ft_putchar('0');
		len = 1;
	}
	else if (((opts & X || opts & BIG_X) && opts & DIESE && n != 0) || opts & P)
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

static int	has_sign(uintmax_t n, int opts, int prec)
{
	if ((opts & O || opts & BIG_O) && opts & DIESE &&
		(n != 0 || (n == 0 && opts & PRECISION && prec == 0)))
		return (1);
	else if (((opts & X || opts & BIG_X) && opts & DIESE && n != 0) || opts & P)
		return (2);
	return (0);
}

static int	get_nbzero(t_opts *opts, int *len, int sign)
{
	int		nbzero;

	nbzero = 0;
	if (opts->flags & PRECISION && opts->precision > *len - sign)
	{
		nbzero += opts->precision - *len + sign;
		*len += nbzero;
	}
	if (opts->flags & MIN_WIDTH && opts->flags & ZERO && !(opts->flags & MINUS)
		&& !(opts->flags & PRECISION) && opts->min_width > *len)
	{
		nbzero += opts->min_width - *len;
		*len += nbzero;
	}
	return (nbzero);
}

static int	get_nbspaces(int opts, int minw, int *len)
{
	int		nbspaces;

	nbspaces = 0;
	if (opts & MIN_WIDTH
		&& (!(opts & ZERO) || opts & MINUS || opts & PRECISION)
		&& minw > *len)
	{
		nbspaces += minw - *len;
		*len += nbspaces;
	}
	return (nbspaces);
}

int			ft_formatunbr(uintmax_t n, t_opts *opts, char *(*convert)(uintmax_t, int *))
{
	int		len;
	int		sign;
	int		nbzero;
	int		nbspaces;
	char	*converted;

	converted = convert(n, &len);
	sign = has_sign(n, opts->flags, opts->precision);
	if (opts->flags & X || opts->flags & P)
		ft_strtolower(converted);
	if (opts->flags & PRECISION && opts->precision == 0 && n == 0)
		len = 0;
	len += sign;
	nbzero = get_nbzero(opts, &len, (sign == 2) ? 2 : 0);
	nbspaces = get_nbspaces(opts->flags, opts->min_width, &len);
	if (!(opts->flags & MINUS))
		ft_putnchar(' ', nbspaces);
	put_sign(n, opts->flags, opts->precision);
	ft_putnchar('0', nbzero);
	if (!(opts->flags & PRECISION && opts->precision == 0 && n == 0))
		ft_putstr(converted);
	if (opts->flags & MINUS)
		ft_putnchar(' ', nbspaces);
	return (len);
}

// #include <stdlib.h>
// #include "libft.h"
// #include "ft_printf.h"

// static int	octal_alt(uintmax_t n, int opts, int prec)
// {
// 	if ((opts & O || opts & BIG_O) && opts & DIESE &&
// 		(n != 0 || (n == 0 && opts & PRECISION && prec == 0)))
// 		return (1);
// 	return (0);
// }

// static int	hex_alt(uintmax_t n, int opts)
// {
// 	if (((opts & X || opts & BIG_X) && opts & DIESE && n != 0) || opts & P)
// 		return (1);
// 	return (0);
// }

// static int     put_spaces(int minw, int prec, int len)
// {
// 	int		i;

// 	i = 0;
// 	if (prec > len)
// 		len = prec;
// 	while (minw > len++)
// 	{
// 		ft_putchar(' ');
// 		i++;
// 	}
// 	return (i);
// }

// static int     put_zeroes(int minw, int prec, int len, int opts, int not_null)
// {
// 	int		ref;
// 	int		i;

// 	i = 0;
// 	if (opts & MIN_WIDTH && opts & ZERO && !(opts & PRECISION))
// 		ref = minw;
// 	else
// 		ref = prec;
// 	if (opts & PRECISION && hex_alt(not_null, opts))
// 		ref += 2;
// 	while (ref > len++)
// 	{
// 		ft_putchar('0');
// 		i++;
// 	}
// 	return (i);
// }

// static int put_prefix(uintmax_t n, int opts, int prec)
// {
// 	int		len;

// 	len = 0;
// 	if (octal_alt(n, opts, prec))
// 	{
// 		ft_putchar('0');
// 		len = 1;
// 	}
// 	else if (hex_alt(n, opts))
// 	{
// 		ft_putchar('0');
// 		if (opts & P || opts & X)
// 			ft_putchar('x');
// 		else
// 			ft_putchar('X');
// 		len = 2;
// 	}
// 	return (len);
// }

// int		ft_formatunbr(uintmax_t n, t_opts *opts,
// 	char *(*convert)(uintmax_t, int *))
// {
// 	int		len;
// 	int		tmp;
// 	char	*res;

// 	res = convert(n, &len);
// 	if (opts->flags & X || opts->flags & P)
// 		ft_strtolower(res);
// 	if (opts->flags & PRECISION && opts->precision == 0 && n == 0)
// 		len--;
// 	if (octal_alt(n, opts->flags, opts->precision))
// 		len++;
// 	else if (hex_alt(n, opts->flags))
// 		len += 2;
// 	tmp = len;
// 	if (!(opts->flags & MINUS) && !(opts->flags & ZERO))
// 		len += put_spaces(opts->min_width, opts->precision, tmp);
// 	put_prefix(n, opts->flags, opts->precision);
// 	if ((!(opts->flags & MINUS) && opts->flags & ZERO) || opts->flags & PRECISION)
// 		len += put_zeroes(opts->min_width, opts->precision, tmp, opts->flags, (n != 0));
// 	if (!(opts->flags & PRECISION && opts->precision == 0 && n == 0))
// 		ft_putstr(res);
// 	free(res);
// 	if (opts->flags & MINUS)
// 		len += put_spaces(opts->min_width, opts->precision, tmp);
// 	return (len);
// }
