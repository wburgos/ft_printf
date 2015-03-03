/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:18:59 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/03 22:26:03 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_putnbr(intmax_t n)
{
	char	*nb;
	int		len;

	nb = ft_itoa(n);
	len = ft_putstr(nb);
	free(nb);
	return (len);
}
