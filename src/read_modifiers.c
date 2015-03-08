/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_modifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 18:05:44 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 18:28:00 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_hh(char c, char n, t_opts *opts)
{
	if (c == 'h')
	{
		if (n == 'h')
		{
			opts->flags |= HH;
			return (1);
		}
		else
			opts->flags |= H;
	}
	return (0);
}

static int	check_ll(char c, char n, t_opts *opts)
{
	if (c == 'l')
	{
		if (n == 'l')
		{
			opts->flags |= LL;
			return (1);
		}
		else
			opts->flags |= L;
	}
	return (0);
}

int			read_modifiers(char *fmt, t_opts *opts)
{
	int		i;

	i = 0;
	while (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == 'j' || fmt[i] == 'z')
	{
		i += check_hh(fmt[i], fmt[i + 1], opts);
		i += check_ll(fmt[i], fmt[i + 1], opts);
		if (fmt[i] == 'j')
			opts->flags |= J;
		if (fmt[i] == 'z')
			opts->flags |= Z;
		i++;
	}
	return (i);
}
