/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcutf8.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:10:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:10:52 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int		ft_wcutf8(wchar_t wchar, char *conv_temp)
{
	int		len;

	len = 0;
	if (wchar < 0x80)
		conv_temp[len++] = ((wchar >> 0) & 0x7F) | 0x00;
	else if (wchar < 0x0800)
	{
		conv_temp[len++] = ((wchar >> 6) & 0x1F) | 0xC0;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x010000)
	{
		conv_temp[len++] = ((wchar >> 12) & 0x0F) | 0xE0;
		conv_temp[len++] = ((wchar >> 6) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	else if (wchar < 0x110000)
	{
		conv_temp[len++] = ((wchar >> 18) & 0x07) | 0xF0;
		conv_temp[len++] = ((wchar >> 12) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 6) & 0x3F) | 0x80;
		conv_temp[len++] = ((wchar >> 0) & 0x3F) | 0x80;
	}
	return (len);
}
