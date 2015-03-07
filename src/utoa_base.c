/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 19:35:51 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 19:59:03 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbdigits_base(uintmax_t n, int base)
{
	int			len;

	len = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char		*utoa_base(uintmax_t n, int *nbdig, int base)
{
	uintmax_t	rem;
	int			len;
	char		*res;

	*nbdig = nbdigits_base(n, base);
	res = ft_strnew(*nbdig);
	if (res)
	{
		len = (n == 0) ? 1 : 0;
		*res = '0';
		while (n != 0)
		{
			rem = n % base;
			n /= base;
			res[len++] = rem + '0';
		}
		res[len] = '\0';
		res = ft_strrev(res);
	}
	return (res);
}
