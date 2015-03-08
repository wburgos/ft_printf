/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_noconv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:04:09 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 22:17:50 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		printf_noconv(char c, t_opts *opts)
{
	int		len;

	len = sizeof(char);
	if (!(opts->flags & MINUS))
		len = printf_spaces(opts->min_width, len, opts->flags);
	ft_putchar(c);
	if (opts->flags & MINUS)
		len = printf_spaces(opts->min_width, len, opts->flags);
	return (len);
}
