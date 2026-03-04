#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (j < i)
	{
		dest[j] = s[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
