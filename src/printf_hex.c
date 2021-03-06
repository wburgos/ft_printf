/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:45:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/08 19:10:13 by wburgos          ###   ########.fr       */
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

static void	get_hex(uintmax_t n, char *hex, char *hex_sym)
{
	int		i;
	int		len;

	i = 0;
	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		hex[len++] = hex_sym[n & 0xF];
		n >>= 4;
	}
	while (i < len / 2)
	{
		hex[i] ^= hex[len - i - 1];
		hex[len - i - 1] ^= hex[i];
		hex[i] ^= hex[len - i - 1];
		i++;
	}
}

static char	*conv_hex(uintmax_t n, int *nbdig)
{
	char		*hex;
	char		*hex_sym;

	*nbdig = hex_nbdigits(n);
	hex = ft_strnew(*nbdig);
	*hex = '0';
	hex_sym = ft_strdup("0123456789ABCDEF");
	if (hex_sym && hex)
	{
		get_hex(n, hex, hex_sym);
		free(hex_sym);
	}
	if (!hex_sym)
		return (NULL);
	return (hex);
}

int			printf_hex(va_list ap, t_opts *opts)
{
	int		len;

	len = 0;
	if (opts->flags & P)
		len = ft_formatunbr((uintmax_t)va_arg(ap, void *), opts, &conv_hex);
	else if (opts->flags & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, &conv_hex);
	else if (opts->flags & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, &conv_hex);
	else if (opts->flags & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts, &conv_hex);
	else if (opts->flags & L)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, &conv_hex);
	else if (opts->flags & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts,
			&conv_hex);
	else if (opts->flags & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts,
			&conv_hex);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, &conv_hex);
	return (len);
}
