/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 18:29:46 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/07 18:29:47 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	*init_corres(void)
{
	int		*corres;

	corres = ft_memalloc(sizeof(*corres) * C_SIZE);
	corres[I_S] = S;
	corres[I_BIGS] = BIG_S;
	corres[I_P] = P;
	corres[I_D] = D;
	corres[I_BIGD] = BIG_D;
	corres[I_I] = I;
	corres[I_O] = O;
	corres[I_BIGO] = BIG_O;
	corres[I_U] = U;
	corres[I_BIGU] = BIG_U;
	corres[I_X] = X;
	corres[I_BIGX] = BIG_X;
	corres[I_C] = C;
	corres[I_BIGC] = BIG_C;
	return (corres);
}

int			read_converter(char c, int *opts, char *conv)
{
	int		*corres;
	int		i;

	i = -1;
	corres = init_corres();
	if (c && ((i = ft_inarray(c, conv)) != -1))
		*opts |= corres[i];
	return (i);
}
