/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:44:39 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:03:50 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>
#include "ft_printf.h"
#include "libft.h"

int		printf_wstr(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	wchar_t	*str;
	wchar_t	*cpy;

	str = va_arg(ap, wchar_t *);
	if (!str)
		str = ft_strwdup(L"(null)");
	if (opts & PRECISION)
	{
		cpy = ft_wcsnew(precision);
		if (str)
			cpy = ft_wcsncpy(cpy, str, precision);
		str = cpy;
	}
	len = ft_wcslen(str);
	if (!(opts & MINUS))
		len = printf_spaces(min_width, len, opts);
	ft_putwstr(str);
	if (opts & MINUS)
		len = printf_spaces(min_width, len, opts);
	return (len);
}
