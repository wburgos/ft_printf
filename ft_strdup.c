/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:36:52 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 18:11:00 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen(src) + 1;
	dst = ft_memalloc(sizeof(char) * len);
	if (dst)
		ft_strcpy(dst, src);
	return (dst);
}
