/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:41:27 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 12:22:14 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	def_flags(char **symbols)
{
	*symbols[DIESE] = '#';
	*symbols[ZERO] = '0';
	*symbols[MINUS] = '-';
	*symbols[PLUS] = '+';
	*symbols[SPACE] = ' ';
}

void	def_conv(char **symbols)
{
	*symbols[S] = 's';
	*symbols[BIG_S] = 'S';
	*symbols[P] = 'p';
	*symbols[D] = 'd';
	*symbols[BIG_D] = 'D';
	*symbols[I] = 'i';
	*symbols[O] = 'o';
	*symbols[BIG_O] = 'O';
	*symbols[U] = 'u';
	*symbols[BIG_U] = 'U';
	*symbols[X] = 'x';
	*symbols[BIG_X] = 'X';
	*symbols[C] = 'c';
	*symbols[BIG_C] = 'C';
}

char	*init_symbols(char *symbols)
{
	symbols = malloc(sizeof(*symbols) * NB_SYMBOLS);
	def_flags(&symbols);
	def_conv(&symbols);
	return (symbols);
}

// void	init_flags(t_opts *opts)
// {
// 	opts->diese = 0;
// 	opts->zero = 0;
// 	opts->minus = 0;
// 	opts->space = 0;
// 	opts->plus = 0;
// }

// void	init_length_modifiers(t_opts *opts)
// {
// 	opts->h = 0;
// 	opts->hh = 0;
// 	opts->l = 0;
// 	opts->ll = 0;
// 	opts->j = 0;
// 	opts->z = 0;
// }

// void	init_converters(t_opts *opts)
// {
// 	opts->s = 0;
// 	opts->big_s = 0;
// 	opts->p = 0;
// 	opts->d = 0;
// 	opts->big_d = 0;
// 	opts->i = 0;
// 	opts->o = 0;
// 	opts->big_o = 0;
// 	opts->u = 0;
// 	opts->big_u = 0;
// 	opts->x = 0;
// 	opts->big_x = 0;
// 	opts->c = 0;
// 	opts->big_c = 0;
// }

// void	init_opts(t_opts *opts)
// {
// 	init_flags(opts);
// 	opts->min_size = 0;
// 	opts->precision = 0;
// 	init_length_modifiers(opts);
// 	init_converters(opts);
// }