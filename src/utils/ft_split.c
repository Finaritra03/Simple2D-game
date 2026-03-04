#include "../so_long.h"

static int	count_words(char const *s, char c)
{
	unsigned int	count;
	unsigned int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

static char	*malloc_a_word(char const **s, char c)
{
	size_t			size;
	char			*res;
	char const		*start;

	size = 0;
	if (s == NULL)
		return (NULL);
	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
	{
		size++;
		(*s)++;
	}
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, start, size + 1);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;
	int		i;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < words)
	{
		res[i] = malloc_a_word(&s, c);
		if (res[i] == NULL)
		{
			while (i >= 0)
				free(res[i--]);
			free(res);
			return (NULL);
		}
	}
	res[words] = NULL;
	return (res);
}
