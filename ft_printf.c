/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/28 00:46:47 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

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

void	print_s(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_bigs(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_p(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_d(va_list ap, int opts)
{
	ft_putnbr(va_arg(ap, int));
}

void	print_bigd(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_i(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_o(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_bigo(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_u(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_bigu(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_x(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_bigx(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_c(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

void	print_bigc(va_list ap, int opts)
{
	ft_putstr(va_arg(ap, char *));
}

fprint	*init_ftab()
{
	fprint *ftab;

	ftab = malloc(sizeof(*ftab) * 14);
	ftab[0] = print_s;
	ftab[1] = print_bigs;
	ftab[2] = print_p;
	ftab[3] = print_d;
	ftab[4] = print_bigd;
	ftab[5] = print_i;
	ftab[6] = print_o;
	ftab[7] = print_bigo;
	ftab[8] = print_u;
	ftab[9] = print_bigu;
	ftab[10] = print_x;
	ftab[11] = print_bigx;
	ftab[12] = print_c;
	ftab[13] = print_bigc;
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
			ftab[conv_i](ap, opts);
		}
		fmt++;
	}
	return (i);
}
