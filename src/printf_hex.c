/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:45:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:58:06 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static int	hex_nbdigits(uintmax_t n)
{
	int			len;

	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		len++;
		n >>= 4;
	}
	return (len);
}

static char	*conv_hex(uintmax_t n, int *nbdig)
{
	int			i;
	int			len;
	char		*sym;
	char		*hex;

	i = 0;
	len = (n == 0) ? 1 : 0;
	*nbdig = hex_nbdigits(n);
	hex = ft_strnew(*nbdig);
	*hex = '0';
	sym = ft_strdup("0123456789ABCDEF");
	if (sym && hex)
	{
		while (n != 0)
		{
			hex[len++] = sym[n & 0xF];
			n >>= 4;
		}
		while (i < len / 2)
		{
			hex[i] ^= hex[len - i - 1];
			hex[len - i - 1] ^= hex[i];
			hex[i] ^= hex[len - i - 1];
			i++;
		}
		free(sym);
	}
	if (!sym)
		return (NULL);
	return (hex);
}

int		printf_hex(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	if (opts & P)
		len = ft_formatunbr((uintmax_t)va_arg(ap, void *), opts, min_width, precision, &conv_hex);
	else if (opts & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision, &conv_hex);
	else if (opts & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision, &conv_hex);
	else if (opts & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision, &conv_hex);
	else if (opts & L)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision, &conv_hex);
	else if (opts & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision, &conv_hex);
	else if (opts & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision, &conv_hex);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision, &conv_hex);
	return (len);
}
