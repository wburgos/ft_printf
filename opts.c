/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:23:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/28 13:47:15 by wburgos          ###   ########.fr       */
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
	if (fmt[i] != '.')
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

	conv = malloc(sizeof(*conv) * C_SIZE);
	conv[I_S] = 's';
	conv[I_BIGS] = 'S';
	conv[I_P] = 'p';
	conv[I_D] = 'd';
	conv[I_BIGD] = 'D';
	conv[I_I] = 'i';
	conv[I_O] = 'o';
	conv[I_BIGO] = 'O';
	conv[I_U] = 'u';
	conv[I_BIGU] = 'U';
	conv[I_X] = 'x';
	conv[I_BIGX] = 'X';
	conv[I_C] = 'c';
	conv[I_BIGC] = 'C';
	return (conv);
}

int		*init_corres(void)
{
	int		*corres;

	corres = malloc(sizeof(*corres) * C_SIZE);
	corres[I_S] = S;
	corres[I_BIGS] = BIG_S;
	corres[I_P] = P;
	corres[I_D] = D;
	corres[I_BIGD] = BIG_D;
	corres[I_I] = I;
	corres[I_O] = O;
	corres[I_BIGO] = BIG_O;
	corres[I_U] = U;
	corres[I_BIGU] = BIG_U;
	corres[I_X] = X;
	corres[I_BIGX] = BIG_X;
	corres[I_C] = C;
	corres[I_BIGC] = BIG_C;
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
	return (opts);
}
