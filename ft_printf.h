/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:07:15 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 13:45:53 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DIESE		1
# define ZERO		2
# define MINUS		4
# define PLUS		8
# define SPACE		16
# define S			32
# define BIG_S		64
# define P			128
# define D			256
# define BIG_D		512
# define I			1024
# define O			2048
# define BIG_O		4096
# define U			8192
# define BIG_U		16384
# define X			32768
# define BIG_X		65536
# define C			131072
# define BIG_C		262144
# define HH			524288
# define H			1048576
# define LL			2097152
# define L			4194304
# define J			8388608
# define Z			16777216
# define MIN_WIDTH	33554432
# define PRECISION	67108864

char	*init_symbols(char *symbols);

#endif
