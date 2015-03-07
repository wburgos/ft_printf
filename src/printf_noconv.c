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

int		printf_noconv(char c, int opts, int min_width, int precision)
{
	int		len;

	len = sizeof(char);
	if (!(opts & MINUS))
		len = printf_spaces(min_width, len, opts);
	ft_putchar(c);
	if (opts & MINUS)
		len = printf_spaces(min_width, len, opts);
	return (len);
}
