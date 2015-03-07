/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wclen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 18:55:36 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:30:27 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_wclen(wchar_t wchar)
{
	int		len;

	len = 0;
	if (wchar < 0x80)
		len = 1;
	else if (wchar < 0x0800)
		len = 2;
	else if (wchar < 0x010000)
		len = 3;
	else if (wchar < 0x110000)
		len = 4;
	return (len);
}
