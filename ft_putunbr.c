#include "libft.h"

int		ft_putunbr(size_t n)
{
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (ft_nbdigits(n));
}
