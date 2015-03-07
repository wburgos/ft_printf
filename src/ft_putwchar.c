/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 20:09:28 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 20:09:28 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_putwchar(wchar_t c)
{
	int		len;
	char	conv_temp[4];

	len = ft_wcutf8(c, conv_temp);
	write(1, conv_temp, len);
	return (len);
}
