/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_min_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 21:33:56 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/08 20:44:23 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

int		read_min_width(va_list ap, char *fmt, t_opts *opts)
{
	int		i;
	char	*nb;

	i = 0;
	if (fmt[i] == '*')
	{
		opts->min_width = va_arg(ap, int);
		if (opts->min_width < 0)
		{
			opts->min_width *= -1;
			opts->flags |= MINUS;
		}
		i++;
	}
	else
	{
		while (ft_isdigit(fmt[i]))
			i++;
		nb = ft_strsub(fmt, 0, i);
		opts->min_width = ft_atoi(nb);
		free(nb);
	}
	return (i);
}
