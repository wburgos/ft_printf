/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:23:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/28 00:16:45 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int		read_flags(char c, int *opts)
{
	if (c == '#')
		*opts |= DIESE;
	if (c == '0')
		*opts |= ZERO;
	if (c == '-')
		*opts |= MINUS;
	if (c == ' ')
		*opts |= SPACE;
	if (c == '+')
		*opts |= PLUS;
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int		read_precision(char *fmt, int *precision)
{
	int		i;

	i = 0;
	if (fmt[i] != '.' || (fmt[i] == '.' && !ft_isdigit(fmt[i + 1])))
		return (0);
	i++;
	while (ft_isdigit(fmt[i]))
		i++;
	*precision = (i == 1) ? 0 : ft_atoi(ft_strsub(fmt, 1, i));
	return (i);
}

int		read_min_width(char *fmt, int *min_width)
{
	int		i;

	i = 0;
	while (ft_isdigit(fmt[i]))
		i++;
	if (i > 0)
		*min_width = ft_atoi(ft_strsub(fmt, 0, i));
	return (i);
}

int		read_modifiers(char *fmt, int *opts)
{
	int		nb_h;
	int		nb_l;
	int		i;

	nb_l = 0;
	nb_h = 0;
	i = 0;
	while (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == 'j' || fmt[i] == 'z')
	{
		if (fmt[i] == 'h')
			nb_h++;
		if (fmt[i] == 'l')
			nb_l++;
		if (fmt[i] == 'j')
			*opts |= J;
		if (fmt[i] == 'z')
			*opts |= Z;
		i++;
	}
	if (nb_h == 1 || nb_h >= 3)
		*opts |= H;
	if (nb_h == 2 || nb_h >= 3)
		*opts |= HH;
	if (nb_l == 1 || nb_l >= 3)
		*opts |= L;
	if (nb_l == 2 || nb_l >= 3)
		*opts |= LL;
	return (i);
}

char	*init_conv(void)
{
	char	*conv;

	conv = malloc(sizeof(*conv) * 14);
	conv[0] = 's';
	conv[1] = 'S';
	conv[2] = 'p';
	conv[3] = 'd';
	conv[4] = 'D';
	conv[5] = 'i';
	conv[6] = 'o';
	conv[7] = 'O';
	conv[8] = 'u';
	conv[9] = 'U';
	conv[10] = 'x';
	conv[11] = 'X';
	conv[12] = 'c';
	conv[13] = 'C';
	return (conv);
}

int		*init_corres(void)
{
	int		*corres;

	corres = malloc(sizeof(*corres) * 14);
	corres[0] = S;
	corres[1] = BIG_S;
	corres[2] = P;
	corres[3] = D;
	corres[4] = BIG_D;
	corres[5] = I;
	corres[6] = O;
	corres[7] = BIG_O;
	corres[8] = U;
	corres[9] = BIG_U;
	corres[10] = X;
	corres[11] = BIG_X;
	corres[12] = C;
	corres[13] = BIG_C;
	return (corres);
}

int		ft_inarray(char c, char *arr)
{
	int		i;

	i = 0;
	while (arr[i] && c != arr[i])
		i++;
	if (c == arr[i])
		return (i);
	return (-1);
}

int		read_converter(char *fmt, int *opts, char *conv)
{
	int		*corres;
	int		i;

	i = 0;
	corres = init_corres();
	if ((i = ft_inarray(*fmt, conv)) != -1)
		*opts |= corres[i];
	return (i);
}

int		parse_opts(char **fmt, int *min_width, int *precision, int *conv_i, char *conv)
{
	int		fwd;
	int		opts;

	fwd = 0;
	opts = 0;
	if (**fmt == '%')
	{
		ft_putchar('%');
		(*fmt)++;
		return (-1);
	}
	while (read_flags(**fmt, &opts))
		(*fmt)++;
	if ((fwd = read_min_width(*fmt, min_width)))
	{
		opts |= MIN_WIDTH;
		(*fmt) += fwd;
	}
	if ((fwd = read_precision(*fmt, precision)))
	{
		opts |= PRECISION;
		(*fmt) += fwd;
	}
	if ((fwd = read_modifiers(*fmt, &opts)))
		(*fmt) += fwd;
	*conv_i = read_converter(*fmt, &opts, conv);
	*(fmt)++;
	return (opts);
}
