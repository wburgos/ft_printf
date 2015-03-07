/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:50:36 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 21:15:57 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsnew(size_t size)
{
	wchar_t	*str;

	str = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (str);
}
