/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:50:36 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:50:52 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "libft.h"

wchar_t	*ft_wcsnew(size_t size)
{
	wchar_t	*str;

	str = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (str);
}
