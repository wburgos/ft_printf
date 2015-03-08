/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 18:03:26 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:12:28 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

static int	has_sign(intmax_t n, int opts)
{
	return (n >= 0 && (opts & PLUS || opts & SPACE));
}

static int	get_nbzero(t_opts *opts, int *len, int has_sign)
{
	int		nbzero;

	nbzero = 0;
	if (opts->flags & PRECISION && opts->precision > *len - has_sign)
	{
		nbzero += opts->precision - *len + has_sign;
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

int			ft_formatnbr(intmax_t n, t_opts *opts)
{
	int		len;
	int		sign;
	int		nbzero;
	int		nbspaces;

	len = 0;
	sign = has_sign(n, opts->flags);
	if (!(opts->flags & PRECISION) || opts->precision != 0 || n != 0)
		len = ft_nbdigits(n) + sign;
	nbzero = get_nbzero(opts, &len, (n < 0 || sign));
	nbspaces = get_nbspaces(opts->flags, opts->min_width, &len);
	if (!(opts->flags & MINUS))
		ft_putnchar(' ', nbspaces);
	put_sign(n, opts->flags);
	ft_putnchar('0', nbzero);
	if (!(opts->flags & PRECISION && opts->precision == 0 && n == 0))
		ft_putunbr((n < 0) ? (-n) : (n));
	if (opts->flags & MINUS)
		ft_putnchar(' ', nbspaces);
	return (len);
}
