#include "../so_long.h"

char	*read_fd(int fd, char *content)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (chr_line(content) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(content);
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		content = ft_strjoin_and_free(content, buffer);
	}
	free(buffer);
	return (content);
}

char	*find_line(char *content)
{
	char	*line;
	int		i;
	int		len_line;

	if (*content == 0)
		return (NULL);
	i = 0;
	len_line = 0;
	while (content[len_line] && content[len_line] != '\n')
		len_line++;
	line = (char *)malloc(len_line + 2);
	if (!line)
		return (NULL);
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	if (content[i] == '\n')
		line[i++] = '\n';
	else
		line[i++] = '\0';
	line[i] = '\0';
	return (line);
}

char	*find_next_content(char *content)
{
	char	*next;
	int		i;
	int		j;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == 0)
	{
		free(content);
		return (NULL);
	}
	next = (char *)malloc(ft_strlen(content) - i + 1);
	if (!next)
		return (NULL);
	j = 0;
	while (content[++i])
		next[j++] = content[i];
	next[j] = '\0';
	free(content);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(content);
		return (NULL);
	}
	content = read_fd(fd, content);
	if (!content)
		return (NULL);
	line = find_line(content);
	content = find_next_content(content);
	return (line);
}
