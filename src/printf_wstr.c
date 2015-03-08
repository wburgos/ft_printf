/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:44:39 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:47:08 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		printf_wstr(va_list ap, t_opts *opts)
{
	int		len;
	wchar_t	*str;
	wchar_t	*cpy;

	str = va_arg(ap, wchar_t *);
	if (!str)
		str = ft_wcsdup(L"(null)");
	if (opts->flags & PRECISION)
	{
		cpy = ft_wcsnew(opts->precision);
		if (str)
			cpy = ft_wcsncpy(cpy, str, opts->precision);
		str = cpy;
	}
	len = ft_wcslen(str);
	if (!(opts->flags & MINUS))
		len = printf_spaces(opts->min_width, len, opts->flags);
	ft_putwstr(str);
	if (opts->flags & MINUS)
		len = printf_spaces(opts->min_width, len, opts->flags);
	return (len);
}
