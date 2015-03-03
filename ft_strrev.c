#include "libft.h"

char		*ft_strrev(char *str)
{
	char	*end;
	char	*tmp;
	int		len;

	if (str)
	{
		tmp = str;
		len = ft_strlen(str);
		end = str + len - 1;
		while (tmp < end)
			ft_swap(tmp++, end--);
	}
	return (str);
}