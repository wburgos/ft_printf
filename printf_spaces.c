/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:01:03 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:01:05 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_spaces(int min_width, int len, int opts)
{
	while ((min_width - len) > 0)
	{
		ft_putchar(((opts & ZERO) && !(opts & MINUS)) ? '0' : ' ');
		len++;
	}
	return (len);
}
