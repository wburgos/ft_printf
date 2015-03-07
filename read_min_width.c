/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_min_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 21:33:56 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 21:33:58 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
