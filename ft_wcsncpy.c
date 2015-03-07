/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:51:47 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:52:11 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (len < n)
	{
		len += ft_wclen(src[i]);
		if (len > n)
			break ;
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}
