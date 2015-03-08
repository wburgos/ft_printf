/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:30:51 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:47:16 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		printf_str(va_list ap, t_opts *opts)
{
	int		len;
	char	*str;
	char	*cpy;

	if (opts->flags & L)
		return (printf_wstr(ap, opts));
	str = va_arg(ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	if (opts->flags & PRECISION)
	{
		cpy = ft_strnew(opts->precision);
		if (str)
			cpy = ft_strncpy(cpy, str, opts->precision);
		str = cpy;
	}
	len = ft_strlen(str);
	if (!(opts->flags & MINUS))
		len = printf_spaces(opts->min_width, len, opts->flags);
	ft_putstr(str);
	if (opts->flags & MINUS)
		len = printf_spaces(opts->min_width, len, opts->flags);
	return (len);
}
