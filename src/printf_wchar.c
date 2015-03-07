/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:42:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:46:14 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int			printf_wchar(va_list ap, t_opts opts)
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
