/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 12:23:16 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/26 14:00:35 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int		ft_inarray(char c, char *arr)
// {
// 	int		i;

// 	i = 0;
// 	while (arr[i] && c != arr[i])
// 		i++;
// 	if (c == arr[i])
// 		return (i);
// 	return (-1);
// }

// int		*parse_opts(char *fmt)
// {
// 	int		*opts;
// 	int		i;
// 	int		index;
// 	char	*flags;
// 	char	*conv;

// 	i = 0;
// 	flags = init_flags();
// 	conv = init_conv();
// 	if ((opts = malloc(sizeof(*opts) * NB_SYMBOLS)))
// 	{
// 		while (fmt[i] && !is_conv_sym(fmt[i]))
// 		{
// 			if ((index = ft_inarray(fmt[i], symbols)) != -1)
// 				opts[index] = 1;
// 			i++;
// 		}
// 		if (!fmt[i])
// 			ft_putstr(fmt);
// 	}
// 	return (opts);
// }

int		read_flags(char c, int *opts)
{
	if (c == '#')
		*opts |= DIESE;
	if (c == '0')
		*opts |= ZERO;
	if (c == '-')
		*opts |= MINUS;
	if (c == ' ')
		*opts |= SPACE;
	if (c == '+')
		*opts |= PLUS;
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int		read_min_width(char *fmt)
{
	int		i;

	i = 0;
	while (ft_isdigit(fmt[i]))
		i++;
	return (ft_atoi(ft_strsub(fmt, 0, i)));
}

int		parse_opts(char *fmt, int *min_width, int *precision)
{
	int		opts;

	while (*fmt)
	{
		while (read_flags(*fmt, &opts))
			fmt++;
		opts |= read_min_width(fmt);
	}
	return (opts);
}
