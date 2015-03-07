/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:30:51 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:05:02 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		printf_str(va_list ap, int opts, int min_width, int precision)
{
	int		len;
	char	*str;
	char	*cpy;

	if (opts & L)
		return (printf_wstr(ap, opts, min_width, precision));
	str = va_arg(ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	if (opts & PRECISION)
	{
		cpy = ft_strnew(precision);
		if (str)
			cpy = ft_strncpy(cpy, str, precision);
		str = cpy;
	}
	len = ft_strlen(str);
	if (!(opts & MINUS))
		len = printf_spaces(min_width, len, opts);
	ft_putstr(str);
	if (opts & MINUS)
		len = printf_spaces(min_width, len, opts);
	return (len);
}
