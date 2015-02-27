/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:58:01 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/10 21:26:12 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r'
	|| c == '\f');
}

int			ft_atoi(const char *str)
{
	int		k;
	int		neg;

	k = 0;
	neg = 1;
	while (ft_isblank(*str))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && ft_isdigit(*str))
	{
		k = (k << 3) + (k << 1) + (*str) - '0';
		str++;
	}
	return (k * neg);
}
