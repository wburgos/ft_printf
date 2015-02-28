/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/28 14:33:02 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_nbdigits(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		check_converter(char *fmt, char *conv)
{
	int		found;

	found = 0;
	while (*fmt)
	{
		if (ft_inarray(*fmt, conv))
			found = 1;
		fmt++;
	}
	return (found);
}

int		ft_wcslen(wchar_t *str)
{
	wchar_t	*tmp;

	tmp = str;
	while (*tmp)
		tmp++;
	return ((char *)tmp - (char *)str);
}

int		ft_putwstr(wchar_t *str)
{
	int		len;

	len = ft_wcslen(str);
	write(1, str, len);
	return (len);
}

int		print_str(va_list ap, int opts)
{
	int		len;

	len = 0;
	if ((opts & S) && !(opts & L))
		len = ft_putstr(va_arg(ap, char *));
	if (opts & BIG_S || ((opts & S) && (opts & L)))
		len = ft_putwstr(va_arg(ap, wchar_t *));
	return (len);
}

int		print_addr(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

int		ft_uinttooct(unsigned int n)
{
	size_t			rem;
	size_t			octal;
	size_t			i;
	int				len;

	i = 1;
	len = 1;
	octal = 0;
	while (n != 0)
	{
		rem = n % 8;
		n /= 8;
		octal += rem * i;
		i *= 10;
		len++;
	}
	ft_putunbr(octal);
	return (len);
}

int		ft_inttooct(int n)
{
	int		rem;
	int		i;
	int		len;
	int		octal;

	i = 1;
	len = 1;
	octal = 0;
	while (n != 0)
	{
		rem = n % 8;
		n /= 8;
		octal += rem * i;
		i *= 10;
		len++;
	}
	ft_putnbr(octal);
	return (len);
}

int		ft_dectohex(unsigned int n, char **res)
{
	int		len;
	int		i;
	char	*hex;

	len = 0;
	i = 0;
	hex = malloc(sizeof(*hex) * 17);
	ft_strcpy(hex, "0123456789ABCDEF");
	if (n == 0)
	{
		**res = '0';
		len++;
	}
	else
	{
		while (n != 0)
		{
			(*res)[len] = hex[n & 0xF];
			len++;
			n >>= 4;
		}
		while (i < len / 2)
		{
			(*res)[i] ^= (*res)[len - i - 1];
			(*res)[len - i - 1] ^= (*res)[i];
			(*res)[i] ^= (*res)[len - i - 1];
			i++;
		}
	}
	free(hex);
	return (len);
}

char	*ft_strtolower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int		print_hex(va_list ap, int opts)
{
	void	*n;
	int		len;
	char	*hex;

	n = va_arg(ap, void *);
	hex = malloc(sizeof(*hex) * ft_nbdigits(*(int *)n));
	len = ft_dectohex(*(int *)n, &hex);
	if (opts & X || opts & P)
		ft_putstr(ft_strtolower(hex));
	if (opts & BIG_X)
		ft_putstr(hex);
	free(hex);
	return (len);
}

int		print_oct(va_list ap, int opts)
{
	int		len;

	len = 0;
	if (opts & DIESE)
	{
		ft_putchar('0');
		len++;
	}
	if (opts & O)
		len = ft_inttooct(va_arg(ap, int));
	if ((opts & BIG_O) || (opts & O && opts & L))
		len = ft_uinttooct(va_arg(ap, unsigned int));
	return (len);
}

int		print_nbr(va_list ap, int opts)
{
	if (opts & D || opts & I)
		ft_putnbr(va_arg(ap, int));
	if (opts & U)
		ft_putunbr(va_arg(ap, unsigned int));
}

int		print_char(va_list ap, int opts)
{
	ft_putnbr(va_arg(ap, int));
}

fprint	*init_ftab()
{
	fprint *ftab;

	ftab = malloc(sizeof(*ftab) * C_SIZE);
	ftab[I_S] = print_str;
	ftab[I_BIGS] = print_str;
	ftab[I_P] = print_hex;
	ftab[I_D] = print_nbr;
	ftab[I_BIGD] = print_nbr;
	ftab[I_I] = print_nbr;
	ftab[I_O] = print_oct;
	ftab[I_BIGO] = print_oct;
	ftab[I_U] = print_nbr;
	ftab[I_BIGU] = print_nbr;
	ftab[I_X] = print_hex;
	ftab[I_BIGX] = print_hex;
	ftab[I_C] = print_char;
	ftab[I_BIGC] = print_char;
	return (ftab);
}

int		ft_printf(char *fmt, ...)
{
	int		i;
	va_list	ap;
	int		opts;
	int		min_width;
	int		precision;
	int		conv_i;
	char	*conv;
	fprint	*ftab;

	va_start(ap, fmt);
	conv = init_conv();
	ftab = init_ftab();
	i = 0;
	while (*fmt)
	{
		if (*fmt != '%' || (*fmt == '%' && !check_converter(fmt, conv)))
		{
			ft_putchar(*fmt);
			i++;
		}
		else
		{
			fmt++;
			opts = parse_opts(&fmt, &min_width, &precision, &conv_i, conv);
			if (conv_i == -1)
				continue ;
			i += ftab[conv_i](ap, opts);
		}
		fmt++;
	}
	return (i);
}
