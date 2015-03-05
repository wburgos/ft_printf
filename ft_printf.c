/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/04 18:14:11 by wburgos          ###   ########.fr       */
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

	i = 0;
	while (i < n && src[i] != L'\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = L'\0';
		i++;
	}
	return (dst);
}

wchar_t	*ft_wcsnew(size_t size)
{
	wchar_t	*str;

	str = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (str);
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
	if (!str)
		return (ft_putwstr(L"(null)"));
	if (opts & PRECISION)
	{
		cpy = ft_wcsnew(precision);
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
	if (!str)
		return (ft_putstr("(null)") * sizeof(char));
	if (opts & PRECISION)
	{
		cpy = ft_strnew(precision);
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

int		ft_putoctal(uintmax_t n, int opts)
{
	uintmax_t	rem;
	uintmax_t	i;
	int			len;
	char		*res;
	uintmax_t	tn;

	res = ft_strnew(50);
	tn = n;
	if (res)
	{
		i = 1;
		len = (n == 0) ? 1 : 0;
		*res = '0';
		while (n != 0)
		{
			rem = n % 8;
			n /= 8;
			res[len] = rem + '0';
			len++;
		}
		if (opts & DIESE && tn != 0)
			res[len++] = '0';
		ft_putstr(ft_strrev(res));
		free(res);
	}
	return (len);
}

int		ft_dectohex(uintmax_t n, char *res, int opts, int precision, int min_width)
{
	int			len;
	int			i;
	char		*hex;
	uintmax_t	tn;

	i = 0;
	hex = ft_strnew(16);
	ft_strcpy(hex, "0123456789ABCDEF");
	res[0] = '0';
	tn = n;
	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		res[len] = hex[n & 0xF];
		len++;
		n >>= 4;
	}
	while (precision > len || (min_width > mlen(opts, len) && zero(opts) && !minus(opts) && !prec(opts)))
		res[len++] = '0';
	if (p(opts) || (diese(opts) && tn != 0))
	{
		res[len++] = 'X';
		res[len++] = '0';
	}
	while (min_width > len && ((!zero(opts) || prec(opts)) && !minus(opts)))
		res[len++] = ' ';
	while (i < len / 2)
	{
		res[i] ^= res[len - i - 1];
		res[len - i - 1] ^= res[i];
		res[i] ^= res[len - i - 1];
		i++;
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

int		print_hex(va_list ap, int opts, int min_width, int precision)
{
	int			len;
	char		hex[50];
	uintmax_t	n;

	ft_bzero(hex, 50);
	if (opts & HH)
		n = (unsigned char)(va_arg(ap, unsigned int));
	else if (opts & H)
		n = (unsigned short)(va_arg(ap, unsigned int));
	else
		n = (uintmax_t)(va_arg(ap, void *));
	len = ft_dectohex(n, hex, opts, precision, min_width);
	if (opts & X || opts & P)
		ft_putstr(ft_strtolower(hex));
	else
		ft_putstr(hex);
	if (minus(opts))
	{
		while ((min_width - len) > 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	return (len);
}

int		print_oct(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	if (opts & L || opts & BIG_O)
		len = ft_putoctal(va_arg(ap, unsigned long), opts);
	else if (opts & LL)
		len = ft_putoctal(va_arg(ap, unsigned long long), opts);
	else if (opts & HH)
		len = ft_putoctal((unsigned char)va_arg(ap, unsigned int), opts);
	else if (opts & H)
		len = ft_putoctal((unsigned short)va_arg(ap, unsigned int), opts);
	else if (opts & J)
		len = ft_putoctal(va_arg(ap, uintmax_t), opts);
	else if (opts & Z)
		len = ft_putoctal(va_arg(ap, size_t), opts);
	else
		len = ft_putoctal(va_arg(ap, unsigned int), opts);
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
			len = ft_formatunbr(va_arg(ap, unsigned long long), opts, min_width, precision);
		else if (opts & L || opts & BIG_U)
			len = ft_formatunbr(va_arg(ap, unsigned long), opts, min_width, precision);
		else if (opts & HH)
			len = ft_formatunbr((unsigned char)va_arg(ap, unsigned int), opts, min_width, precision);
		else if (opts & H)
			len = ft_formatunbr((unsigned short)va_arg(ap, unsigned int), opts, min_width, precision);
		else if (opts & J)
			len = ft_formatunbr(va_arg(ap, uintmax_t), opts, min_width, precision);
		else if (opts & Z)
			len = ft_formatunbr(va_arg(ap, size_t), opts, min_width, precision);
		else
			len = ft_formatunbr(va_arg(ap, unsigned int), opts, min_width, precision);
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
