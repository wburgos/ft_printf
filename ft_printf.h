/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:07:15 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/24 17:43:42 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_opts
{
	char		diese;
	char		zero;
	char		minus;
	char		space;
	char		plus;
	int			min_size;
	int			precision;
	char		hh;
	char		h;
	char		l;
	char		ll;
	char		j;
	char		z;
	char		s;
	char		big_s;
	char		p;
	char		d;
	char		big_d;
	char		i;
	char		o;
	char		big_o;
	char		u;
	char		big_u;
	char		x;
	char		big_x;
	char		c;
	char		big_c;
}				t_opts;

void	init_opts(t_opts *opts);

#endif
