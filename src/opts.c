/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:23:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:50:45 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static char	*init_conv(void)
{
	char	*conv;

	conv = ft_strnew(C_SIZE);
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

static int	reads(char **fmt, int *opts, int *min_width, int *precision)
{
	char	*init;
	int		fwd;

	init = *fmt;
	fwd = 0;
	while (read_flags(**fmt, opts))
		(*fmt)++;
	while ((fwd = read_min_width(*fmt, min_width)))
	{
		*opts |= MIN_WIDTH;
		(*fmt) += fwd;
	}
	while ((fwd = read_precision(*fmt, precision)))
	{
		*opts |= PRECISION;
		(*fmt) += fwd;
	}
	while ((fwd = read_modifiers(*fmt, opts)))
		(*fmt) += fwd;
	return (*fmt > init);
}


int			parse_opts(char **fmt, int *min_width, int *precision, int *conv_i)
{
	int		opts;
	int		is_valid;
	char	*conv;

	opts = 0;
	conv = init_conv();
	while (**fmt)
	{
		is_valid = reads(fmt, &opts, min_width, precision);
		if (ft_inarray(**fmt, conv) != -1)
		{
			*conv_i = read_converter(**fmt, &opts, conv);
			break ;
		}
		if (!is_valid)
			break ;
	}
	return (opts);
}
