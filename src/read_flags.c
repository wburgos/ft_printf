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
