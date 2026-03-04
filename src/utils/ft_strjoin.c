#include "../so_long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;

	len_s1 = (int)ft_strlen(s1);
	len_s2 = (int)ft_strlen(s2);
	i = 0;
	j = -1;
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (i < len_s1)
		{
			res[i] = s1[i];
			i++;
		}
	}
	while (i < (len_s2 + len_s1))
		res[i++] = s2[++j];
	res[i] = '\0';
	return (free(s1), res);
}
