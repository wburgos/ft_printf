/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:06:04 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:08:47 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcslen(wchar_t *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len += ft_wclen(*str);
		str++;
	}
	return (len);
}