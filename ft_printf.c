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
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

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
	size_t	i;

	i = 0;
	while (str[i] != L'\0')
		i++;
	return (i);
}

void	ft_putwchar(wchar_t c)
{
	write(1, &c, 1);
}

int		ft_putwstr(wchar_t *str)
{
	int		len;

	len = ft_wcslen(str);
	write(1, str, len * sizeof(wchar_t));
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
	if (opts & PRECISION)
	{
		cpy = ft_strnew(precision);
		cpy = ft_strncpy(cpy, str, precision);
		str = cpy;
	}
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_strlen(str);
	if (!(opts & MINUS))
		len = putspaces(min_width, len, opts);
	ft_putstr(str);
	if (opts & MINUS)
		len = putspaces(min_width, len, opts);
	return (len);
}

int		ft_putoctal(size_t n)
{
	size_t	rem;
	size_t	i;
	int		len;
	char	*res;

	res = malloc(sizeof(*res) * 50);
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
		ft_putstr(ft_strrev(res));
		free(res);
	}
	return (len);
}

int		ft_dectohex(size_t n, char **res, int opts, int precision, int min_width)
{
	int		len;
	int		i;
	char	*hex;

	len = 0;
	i = 0;
	hex = ft_strnew(16);
	ft_strcpy(hex, "0123456789ABCDEF");
	**res = '0';
	if (n == 0)
		len++;
	while (n != 0)
	{
		(*res)[len] = hex[n & 0xF];
		len++;
		n >>= 4;
	}
	while (precision > len || (min_width > mlen(opts, len) && zero(opts) && !minus(opts) && !prec(opts)))
		(*res)[len++] = '0';
	if (p(opts) || diese(opts))
	{
		(*res)[len++] = 'x';
		(*res)[len++] = '0';
	}
	while (min_width > len && ((!zero(opts) || prec(opts)) && !minus(opts)))
		(*res)[len++] = ' ';
	while (i < len / 2)
	{
		(*res)[i] ^= (*res)[len - i - 1];
		(*res)[len - i - 1] ^= (*res)[i];
		(*res)[i] ^= (*res)[len - i - 1];
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
	int		len;
	char	*hex;
	size_t	n;

	n = (size_t)(va_arg(ap, void *));
	hex = malloc(sizeof(*hex) * (ft_nbdigits(n) + precision + min_width));
	len = ft_dectohex(n, &hex, opts, precision, min_width);
	ft_putstr(ft_strtolower(hex));
	if (minus(opts))
	{
		while ((min_width - len) > 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	free(hex);
	return (len);
}

int		print_oct(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	len = 0;
	if (opts & DIESE)
	{
		ft_putchar('0');
		len++;
	}
	if (opts & O)
		len = ft_putoctal(va_arg(ap, int));
	if ((opts & BIG_O) || (opts & O && opts & L))
		len = ft_putoctal(va_arg(ap, long));
	return (len);
}

int		ft_putlnbr(long n)
{
	ft_putstr(ft_ltoa(n));
	return (ft_lnbdigits(n));
}

int		print_lnbr(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	len = ft_putlnbr(va_arg(ap, long));
	return (len);
}

int		print_nbr(va_list ap, int opts, int min_width, int precision)
{
	int		len;

	len = 0;
	if (opts & D || opts & I)
		len = ft_putnbr(va_arg(ap, int));
	if (opts & U)
		len = ft_putunbr(va_arg(ap, unsigned int));
	return (len);
}

int		print_char(va_list ap, int opts, int min_width, int precision)
{
	ft_putchar(va_arg(ap, int));
	return (1);
}

fprint	*init_ftab()
{
	fprint *ftab;

	ftab = malloc(sizeof(*ftab) * C_SIZE);
	ftab[I_S] = print_str;
	ftab[I_BIGS] = print_wstr;
	ftab[I_P] = print_hex;
	ftab[I_D] = print_nbr;
	ftab[I_BIGD] = print_lnbr;
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

void	init_val(int *opts, int *min_width, int *precision, int *conv_i)
{
	*opts = 0;
	*min_width = 0;
	*precision = 0;
	*conv_i = 0;
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
	init_val(&opts, &min_width, &precision, &conv_i);
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
				continue ;
			i += ftab[conv_i](ap, opts, min_width, precision);
		}
		fmt++;
	}
	free(conv);
	free(ftab);
	return (i);
}
