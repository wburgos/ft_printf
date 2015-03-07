/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:23:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 18:00:55 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		parse_opts(char **fmt, int *min_width, int *precision, int *conv_i, char *conv)
{
	int		fwd;
	int		opts;
	int		is_valid;

	fwd = 0;
	opts = 0;
	while (**fmt)
	{
		is_valid = 0;
		while (read_flags(**fmt, &opts))
		{
			(*fmt)++;
			is_valid = 1;
		}
		while ((fwd = read_min_width(*fmt, min_width)))
		{
			opts |= MIN_WIDTH;
			(*fmt) += fwd;
			is_valid = 1;
		}
		while ((fwd = read_precision(*fmt, precision)))
		{
			opts |= PRECISION;
			(*fmt) += fwd;
			is_valid = 1;
		}
		while ((fwd = read_modifiers(*fmt, &opts)))
		{
			(*fmt) += fwd;
			is_valid = 1;
		}
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
