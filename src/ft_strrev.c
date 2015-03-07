/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 19:41:24 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 19:41:25 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
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
