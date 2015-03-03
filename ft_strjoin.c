/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:16:58 by wburgos           #+#    #+#             */
/*   Updated: 2014/11/08 15:16:58 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;

	c = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	ft_strcpy(c, s1);
	ft_strcat(c, s2);
	return (c);
}
