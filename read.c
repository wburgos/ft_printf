/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 17:55:38 by wburgos           #+#    #+#             */
/*   Updated: 2015/02/27 17:56:22 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		read_precision(char *fmt, int *precision)
{
	int		i;

	i = 0;
	if (fmt[i] != '.' || (fmt[i] == '.' && !ft_isdigit(fmt[i + 1])))
		return (0);
	i++;
	while (ft_isdigit(fmt[i]))
		i++;
	*precision = (i == 1) ? 0 : ft_atoi(ft_strsub(fmt, 1, i));
	return (i);
}

int		read_min_width(char *fmt, int *min_width)
{
	int		i;

	i = 0;
	while (ft_isdigit(fmt[i]))
		i++;
	if (i > 0)
		*min_width = ft_atoi(ft_strsub(fmt, 0, i));
	return (i);
}

int		read_modifiers(char *fmt, int *opts)
{
	int		nb_h;
	int		nb_l;
	int		i;

	nb_l = 0;
	nb_h = 0;
	i = 0;
	while (fmt[i] == 'h' || fmt[i] == 'l' || fmt[i] == 'j' || fmt[i] == 'z')
	{
		if (fmt[i] == 'h')
			nb_h++;
		if (fmt[i] == 'l')
			nb_l++;
		if (fmt[i] == 'j')
			*opts |= J;
		if (fmt[i] == 'z')
			*opts |= Z;
		i++;
	}
	if (nb_h == 1 || nb_h >= 3)
		*opts |= H;
	if (nb_h == 2 || nb_h >= 3)
		*opts |= HH;
	if (nb_l == 1 || nb_l >= 3)
		*opts |= L;
	if (nb_l == 2 || nb_l >= 3)
		*opts |= LL;
	return (i);
}
