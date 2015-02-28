/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:40:49 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/23 14:31:52 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_swap(char *a, char *b)
{
	char	tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

static char		*ft_strrev(char *str)
{
	char	*end;
	char	*tmp;
	int		len;

	if (str)
	{
		tmp = str;
		len = ft_strlen(str);
		end = str + len - 1;
		while (tmp < end)
			ft_swap(tmp++, end--);
	}
	return (str);
}

char			*ft_itoa(int n)
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
