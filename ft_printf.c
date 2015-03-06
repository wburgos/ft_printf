/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/06 17:12:27 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_wclen(wchar_t wchar)
{
	int		len;

	len = 0;
	if (wchar < 0x80)
		len = 1;
	else if (wchar < 0x0800)
		len = 2;
	else if (wchar < 0x010000)
		len = 3;
	else if (wchar < 0x110000)
		len = 4;
	return (len);
}

int		ft_wcutf8(wchar_t wchar, char *conv_temp)
{
	int		len;

	len = 0;
	if (wchar < 0x80)
		conv_temp[len++] = ((wchar >> 0) & 0x7F) | 0x00;
	else if (wchar < 0x0800)
	{
		conv_temp[len++] = ((wchar >> 6) & 0x1F) | 0xC0;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x010000)
	{
		conv_temp[len++] = ((wchar >> 12) & 0x0F) | 0xE0;
		conv_temp[len++] = ((wchar >> 6) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x110000)
	{
		conv_temp[len++] = ((wchar >> 18) & 0x07) | 0xF0;
		conv_temp[len++] = ((wchar >> 12) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 6) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	return (len);
}

wchar_t	*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (len < n)
	{
		len += ft_wclen(src[i]);
		if (len > n)
			break ;
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}

wchar_t	*ft_wcsnew(size_t size)
{
	wchar_t	*str;

	str = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (str);
}

int		ft_wcslen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len += ft_wclen(*str);
		str++;
	}
	return (len);
}

int		ft_putwchar(wchar_t c)
{
	int		len;
	char	conv_temp[4];

	len = ft_wcutf8(c, conv_temp);
	write(1, conv_temp, len);
	return (len);
}

int		ft_putwstr(wchar_t *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		ft_putwchar(*str);
		len += ft_wclen(*str);
		str++;
	}
	return (len);
}

int		putwspaces(int min_width, int len, int opts)
{
	wchar_t	wc;

	while ((min_width - len) > 0)
	{
		wc = ((opts & ZERO) && !(opts & MINUS)) ? L'0' : L' ';
		ft_putwchar(wc);
		len += ft_wclen(wc);
	}
	return (len);
}

int		putspaces(int min_width, int len, int opts)
{
	while ((min_width - len) > 0)
	{
		ft_putchar(((opts & ZERO) && !(opts & MINUS)) ? '0' : ' ');
		len++;
	}
	return (len);
}

int		print_wstr(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	wchar_t	*str;
	wchar_t	*cpy;

	str = va_arg(ap, wchar_t *);
	if (!str && !(opts & PRECISION))
		return (ft_putwstr(L"(null)"));
	if (opts & PRECISION)
	{
		cpy = ft_wcsnew(precision);
		if (str)
			cpy = ft_wcsncpy(cpy, str, precision);
		str = cpy;
	}
	len = ft_wcslen(str);
	if (!(opts & MINUS))
		len = putspaces(min_width, len, opts);
	ft_putwstr(str);
	if (opts & MINUS)
		len = putspaces(min_width, len, opts);
	return (len);
}

int		print_str(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	char	*str;
	char	*cpy;

	if (opts & L)
		return (print_wstr(ap, opts, min_width, precision));
	str = va_arg(ap, char *);
	if (!str && !(opts & PRECISION))
		return (ft_putstr("(null)") * sizeof(char));
	if (opts & PRECISION)
	{
		cpy = ft_strnew(precision);
		if (str)
			cpy = ft_strncpy(cpy, str, precision);
		str = cpy;
	}
	len = ft_strlen(str);
	if (!(opts & MINUS))
		len = putspaces(min_width, len, opts);
	ft_putstr(str);
	if (opts & MINUS)
		len = putspaces(min_width, len, opts);
	return (len);
}

int		nbdigits_base(uintmax_t n, int base)
{
	int			len;

	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*utoa_base(uintmax_t n, int *nbdig, int base)
{
	uintmax_t	rem;
	int			len;
	char		*res;

	*nbdig = nbdigits_base(n, base);
	res = ft_strnew(*nbdig);
	if (res)
	{
		len = (n == 0) ? 1 : 0;
		*res = '0';
		while (n != 0)
		{
			rem = n % base;
			n /= base;
			res[len] = rem + '0';
			len++;
		}
		res = ft_strrev(res);
	}
	return (res);
}

char	*conv_octal(uintmax_t n, int *nbdig)
{
	return (utoa_base(n, nbdig, 8));
}

char	*conv_dec(uintmax_t n, int *nbdig)
{
	return (utoa_base(n, nbdig, 10));
}

int		hex_nbdigits(uintmax_t n)
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

char	*conv_hex(uintmax_t n, int *nbdig)
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

int		print_hex(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	if (opts & P)
		len = ft_formatunbr((uintmax_t)va_arg(ap, void *), opts, min_width, precision, &conv_hex);
	else if (opts & L)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision, &conv_hex);
	else if (opts & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision, &conv_hex);
	else if (opts & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision, &conv_hex);
	else if (opts & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision, &conv_hex);
	else if (opts & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision, &conv_hex);
	else if (opts & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision, &conv_hex);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision, &conv_hex);
	return (len);
}

int		print_oct(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	if (opts & L || opts & BIG_O)
		len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision, &conv_octal);
	else if (opts & LL)
		len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision, &conv_octal);
	else if (opts & HH)
		len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision, &conv_octal);
	else if (opts & H)
		len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision, &conv_octal);
	else if (opts & J)
		len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision, &conv_octal);
	else if (opts & Z)
		len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision, &conv_octal);
	else
		len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision, &conv_octal);
	return (len);
}

int		print_nbr(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	len = 0;
	if (opts & D || opts & I || opts & BIG_D)
	{
		if (opts & LL)
			len = ft_formatnbr(va_arg(ap, long long), opts, min_width, precision);
		else if (opts & L || opts & BIG_D)
			len = ft_formatnbr(va_arg(ap, long), opts, min_width, precision);
		else if (opts & HH)
			len = ft_formatnbr((char)va_arg(ap, int), opts, min_width, precision);
		else if (opts & H)
			len = ft_formatnbr((short)va_arg(ap, int), opts, min_width, precision);
		else if (opts & J || opts & Z)
			len = ft_formatnbr(va_arg(ap, intmax_t), opts, min_width, precision);
		else
			len = ft_formatnbr(va_arg(ap, int), opts, min_width, precision);
	}
	if (opts & U || opts & BIG_U)
	{
		if (opts & LL)
			len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision, &conv_dec);
		else if (opts & L || opts & BIG_U)
			len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision, &conv_dec);
		else if (opts & HH)
			len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision, &conv_dec);
		else if (opts & H)
			len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision, &conv_dec);
		else if (opts & J)
			len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision, &conv_dec);
		else if (opts & Z)
			len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision, &conv_dec);
		else
			len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision, &conv_dec);
	}
	return (len);
}

int		print_wchar(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	wchar_t	c;

	c = va_arg(ap, wint_t);
	if (opts & PRECISION && precision == 0)
		c = L'\0';
	len = ft_wclen(c);
	if (!(opts & MINUS))
		len = putwspaces(min_width, len, opts);
	ft_putwchar(c);
	if (opts & MINUS)
		len = putwspaces(min_width, len, opts);
	return (len);
}

int		print_badchar(char c, int opts, int min_width, int precision)
{
	int		len;

	if (opts & PRECISION && precision == 0)
		c = 0;
	len = sizeof(char);
	if (!(opts & MINUS))
		len = putspaces(min_width, len, opts);
	ft_putchar(c);
	if (opts & MINUS)
		len = putspaces(min_width, len, opts);
	return (len);
}

int		print_char(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	char	c;

	if (opts & L)
		return (print_wchar(ap, opts, min_width, precision));
	c = va_arg(ap, int);
	if (opts & PRECISION && precision == 0)
		c = 0;
	len = sizeof(char);
	if (!(opts & MINUS))
		len = putspaces(min_width, len, opts);
	ft_putchar(c);
	if (opts & MINUS)
		len = putspaces(min_width, len, opts);
	return (len);
}

fprint	*init_ftab()
{
	fprint *ftab;

	ftab = ft_memalloc(sizeof(*ftab) * C_SIZE);
	ftab[I_S] = print_str;
	ftab[I_BIGS] = print_wstr;
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
	ftab[I_BIGC] = print_wchar;
	return (ftab);
}

int		check_next_pct(char *fmt)
{
	int		i;

	i = 0;
	while (fmt[i] == ' ')
		i++;
	if (fmt[i] == '%')
		return (i + 1);
	return (0);
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
	int		fwd;

	va_start(ap, fmt);
	conv = init_conv();
	ftab = init_ftab();
	i = 0;
	opts = 0;
	min_width = 0;
	precision = 0;
	conv_i = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar(*fmt);
			i++;
		}
		else
		{
			fmt++;
			if (!*fmt)
				break ;
			if ((fwd = check_next_pct(fmt)))
			{
				ft_putchar('%');
				i++;
				fmt += fwd;
				continue ;
			}
			opts = parse_opts(&fmt, &min_width, &precision, &conv_i, conv);
			if (conv_i == -1)
				i += print_badchar(*fmt, opts, min_width, precision) ;
			else
				i += ftab[conv_i](ap, opts, min_width, precision);
		}
		fmt++;
	}
	free(conv);
	free(ftab);
	return (i);
}
