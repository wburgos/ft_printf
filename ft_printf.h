/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:07:15 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 12:28:20 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define NB_SYMBOLS 25
# define DIESE		0
# define ZERO		1
# define MINUS		2
# define PLUS		3
# define SPACE		4
# define S			5
# define BIG_S		6
# define P			7
# define D			8
# define BIG_D		9
# define I			10
# define O			11
# define BIG_O		12
# define U			13
# define BIG_U		14
# define X			15
# define BIG_X		16
# define C			17
# define BIG_C		18
# define HH			19
# define H			20
# define LL			21
# define L			22
# define J			23
# define Z			24

char	*init_symbols(char *symbols);

#endif
