#include "../so_long.h"

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	int		i;
	size_t	j;
	char	*res;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	res = (char *)malloc(lens1 + lens2 + 1);
	if (!res || !s2)
		return (NULL);
	i = -1;
	while (++i < (int)lens1)
		res[i] = s1[i];
	j = 0;
	while (j < lens2)
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

int	chr_line(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == '\n')
			return (1);
	return (0);
}
