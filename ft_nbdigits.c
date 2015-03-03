int		ft_nbdigits(int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = n < 0 ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}