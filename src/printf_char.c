/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:02:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:52:26 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		printf_char(va_list ap, t_opts *opts)
{
	int		len;
 	char	c;

	if (opts->flags & L)
		return (printf_wchar(ap, opts));
	c = va_arg(ap, int);
	len = sizeof(char);
	if (!(opts->flags & MINUS))
		len = printf_spaces(opts->min_width, len, opts->flags);
	ft_putchar(c);
	if (opts->flags & MINUS)
		len = printf_spaces(opts->min_width, len, opts->flags);
	return (len);
}
