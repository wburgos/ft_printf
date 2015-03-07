#include "libft.h"

int		read_precision(char *fmt, int *precision)
{
	int		i;

	i = 0;
	if (fmt[i] != '.')
		return (0);
	i++;
	while (ft_isdigit(fmt[i]))
		i++;
	*precision = (i == 1) ? 0 : ft_atoi(ft_strsub(fmt, 1, i));
	return (i);
}
