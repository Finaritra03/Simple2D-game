#include "so_long.h"

void	set_pos_player(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (map->map[++j])
	{
		i = -1;
		while (map->map[j][++i])
		{
			if (map->map[j][i] == 'P')
			{
				map->x = i;
				map->y = j;
			}
			if (map->map[j][i] == 'E')
			{
				map->exit_x = i;
				map->exit_y = j;
			}
			if (map->map[j][i] == 'X')
				set_pos_enemy(map, i, j);
		}
	}
}

void	set_pos_enemy(t_map *map, int i, int j)
{
	map->enemy.x = i;
	map->enemy.y = j;
}
