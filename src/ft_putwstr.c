/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:07:40 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:07:41 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		ft_putwchar(*str);
		len += ft_wclen(*str);
		str++;
	}
	return (len);
}
