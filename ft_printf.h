/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:07:15 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/28 12:35:39 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

typedef int (*fprint)(va_list, int);

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

# define C_SIZE		14
# define I_S		0
# define I_BIGS		1
# define I_P		2
# define I_D		3
# define I_BIGD		4
# define I_I		5
# define I_O		6
# define I_BIGO		7
# define I_U		8
# define I_BIGU		9
# define I_X		10
# define I_BIGX		11
# define I_C		12
# define I_BIGC		13

int		ft_inarray(char c, char *arr);
char	*init_conv(void);
int		parse_opts(char **fmt, int *min_width, int *precision, int *conv_i, char *conv);

#endif
