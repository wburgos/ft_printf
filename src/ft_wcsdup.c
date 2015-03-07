/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:47:04 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:34:18 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsdup(wchar_t *src)
{
	wchar_t	*dst;
	int		len;

	len = ft_wcslen(src) + sizeof(wchar_t);
	dst = ft_memalloc(sizeof(wchar_t) * len);
	if (dst)
		ft_wcscpy(dst, src);
	return (dst);
}
