/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:20:57 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 22:14:15 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(uintmax_t n)
{
	char	*str;
	size_t	i;

	str = ft_strnew(11);
	i = 0;
	if (n != 0)
	{
		while (n != 0)
		{
			str[i++] = (n % 10) + '0';
			n /= 10;
		}
		str[i] = '\0';
		str = ft_strrev(str);
	}
	else
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}
