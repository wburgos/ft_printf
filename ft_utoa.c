/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:20:57 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 17:28:56 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(uintmax_t n)
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
