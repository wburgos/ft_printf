/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 21:34:46 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/08 20:45:06 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int		read_precision(va_list ap, char *fmt, t_opts *opts)
{
	int		i;
	char	*nb;

	i = 0;
	if (fmt[i] != '.')
		return (0);
	i++;
	if (fmt[i] == '*')
	{
		opts->precision = va_arg(ap, int);
		i++;
	}
	else
	{
		while (ft_isdigit(fmt[i]))
			i++;
		nb = ft_strsub(fmt, 1, i);
		opts->precision = (i == 1) ? 0 : ft_atoi(nb);
		free(nb);
	}
	return (i);
}
