/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:42:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:18:04 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

// static int	putwspaces(int min_width, int len, int opts)
// {
// 	wchar_t	wc;

// 	while ((min_width - len) > 0)
// 	{
// 		wc = ((opts & ZERO) && !(opts & MINUS)) ? L'0' : L' ';
// 		ft_putwchar(wc);
// 		len += ft_wclen(wc);
// 	}
// 	return (len);
// }

int			printf_wchar(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	wchar_t	c;

	c = va_arg(ap, wint_t);
	len = ft_wclen(c);
	if (!(opts & MINUS))
		len = printf_spaces(min_width, len, opts);
	ft_putwchar(c);
	if (opts & MINUS)
		len = printf_spaces(min_width, len, opts);
	return (len);
}
