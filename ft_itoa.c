/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:40:49 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 17:29:06 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(intmax_t n)
{
	char	*str;
	int		sign;
	size_t	i;

	str = ft_strnew(11);
	i = 0;
	if (n != 0)
	{
		sign = n < 0 ? -1 : 1;
		while (n != 0)
		{
			str[i++] = (n % (10 * sign)) * sign + '0';
			n /= 10;
		}
		if (sign < 0)
			str[i++] = '-';
		str[i] = '\0';
		str = ft_strrev(str);
	}
	else
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}
