/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:36:52 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/06 18:51:41 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen(src) + 1;
	dst = (char*)malloc(sizeof(char) * len);
	if (dst)
		ft_strcpy(dst, src);
	return (dst);
}
