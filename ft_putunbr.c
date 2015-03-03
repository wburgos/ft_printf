/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:57:47 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 17:28:33 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putunbr(uintmax_t n)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (ft_unbdigits(n));
}
