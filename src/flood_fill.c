#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V' || map[y][x] == 'X')
		return ;
	else if (map[y][x] != 'P' && map[y][x] != '0' \
		&& map[y][x] != 'C' && map[y][x] != 'E' && map[y][x] != 'X')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

void	check_map_solvable(char *arg, t_map map)
{
	char	*map_line;
	char	**map_cpy;
	int		i;
	int		j;

	i = -1;
	map_line = read_map(arg);
	map_cpy = ft_split(map_line, '\n');
	free(map_line);
	flood_fill(map_cpy, map.x, map.y);
	while (map_cpy[++i])
	{
		j = -1;
		while (map_cpy[i][++j])
		{
			if (map_cpy[i][j] == 'C' || map_cpy[i][j] == 'E')
			{
				free_tab(map.map);
				error_msg("🚫🚫 Map is not solvable 🚫🚫\n", NULL, map_cpy);
			}
		}
	}
	free_tab(map_cpy);
}
