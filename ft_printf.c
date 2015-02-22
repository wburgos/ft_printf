/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/22 16:22:32 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/22 19:30:00 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

int		ft_printf(char *arg, ...)
{
	int		i;
	va_list	ap;
	char	*str;

	va_start(ap, arg);
	i = 0;
	while (*arg)
	{
		if (*arg != '%')
			ft_putchar(*arg);
		else
		{
			arg++;
			if (!*arg)
				break ;
			if (*arg == 's')
			{
				str = ft_strdup(va_arg(ap, char *));
				ft_putstr(str);
				i += ft_strlen(str) - 1;
				arg++;
			}
		}
		i++;
		arg++;
	}
	return (i);
}
