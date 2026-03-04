#include "so_long.h"

int	count_line_map(int fd)
{
	int		count_line;
	int		len;
	int		i;
	char	*line;

	count_line = 0;
	line = get_next_line(fd);
	if (line)
		count_line++;
	len = ft_strlen(line) - 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (count_line);
		count_line++;
		i = ft_strlen(line);
		if (line[i - 1] == '\n')
			i -= 1;
		free(line);
		if (len != i)
			return (get_next_line(-1), 0);
	}
	return (count_line);
}

char	*read_map(char *file)
{
	int		fd;
	int		line_map;
	char	*line;
	char	*res;

	res = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_msg("🔎❌ MAP file not found ❌🔎\n", NULL, NULL);
	line_map = count_line_map(fd);
	close(fd);
	if (line_map == 0)
		error_msg("🚫🚫 MAP is not rectangular or contains empty line(s) 🚫🚫\n",
			NULL, NULL);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (close(fd), res);
		res = ft_strjoin(res, line);
		free(line);
	}
	close(fd);
	return (res);
}

void	init_map(t_map *map, char *file)
{
	char	*map_str;
	int		height;

	height = 0;
	map_str = read_map(file);
	map->map = ft_split(map_str, '\n');
	map->height = 0;
	map->width = 0;
	free(map_str);
	while (map->map[height])
		height++;
	map->height = height;
	map->width = ft_strlen(map->map[0]);
	map->collect_count = 0;
	map->exit_count = 0;
	map->player_count = 0;
	map->enemy.axis = 0;
	map->enemy.dir_x = 1;
	map->enemy.dir_y = 1;
	map->enemy_count = 0;
}

void	check_walls(t_map map)
{
	int	i;

	i = 0;
	while (map.map[0][i])
	{
		if (map.map[0][i] != '1' || map.map[map.height - 1][i] != '1')
			error_msg("🚫🚫 Map must be closed 🚫🚫\n", NULL, map.map);
		i++;
	}
	i = 1;
	while (i < map.height - 1)
	{
		if (map.map[i][0] != '1' || map.map[i][map.width - 1] != '1')
			error_msg("🚫🚫 Map must be closed by walls 🚫🚫\n", NULL, map.map);
		i++;
	}
}
