#include "../so_long.h"

static int	count(int i)
{
	int	j;

	j = 0;
	if (i < 0)
	{
		j++;
		i = -i;
	}
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;

	len = count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	res = (char *)malloc(sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		res[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (res);
}
