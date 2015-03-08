/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 18:02:02 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 18:20:57 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		read_flags(char c, t_opts *opts)
{
	if (c == '#')
		opts->flags |= DIESE;
	if (c == '0')
		opts->flags |= ZERO;
	if (c == '-')
		opts->flags |= MINUS;
	if (c == ' ')
		opts->flags |= SPACE;
	if (c == '+')
		opts->flags |= PLUS;
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}
