/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:23:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/08 20:03:51 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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
	conv[I_B] = 'b';
	return (conv);
}

static int	reads(va_list ap, char **fmt, t_opts *opts)
{
	char	*init;
	int		fwd;

	init = *fmt;
	fwd = 0;
	while (read_flags(**fmt, opts))
		(*fmt)++;
	while ((fwd = read_min_width(ap, *fmt, opts)))
	{
		opts->flags |= MIN_WIDTH;
		(*fmt) += fwd;
	}
	while ((fwd = read_precision(ap, *fmt, opts)))
	{
		if (opts->precision >= 0)
			opts->flags |= PRECISION;
		(*fmt) += fwd;
	}
	while ((fwd = read_modifiers(*fmt, opts)))
		(*fmt) += fwd;
	return (*fmt > init);
}

int			parse_opts(va_list ap, char **fmt, t_opts *opts)
{
	int		conv_i;
	int		is_valid;
	char	*conv;

	opts->flags = 0;
	conv = init_conv();
	conv_i = -1;
	while (**fmt)
	{
		is_valid = reads(ap, fmt, opts);
		if (ft_inarray(**fmt, conv) != -1)
		{
			conv_i = read_converter(**fmt, opts, conv);
			break ;
		}
		if (!is_valid)
			break ;
	}
	free(conv);
	return (conv_i);
}
