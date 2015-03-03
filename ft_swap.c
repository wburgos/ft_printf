void	ft_swap(char *a, char *b)
{
	char	tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}