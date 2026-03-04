#include "so_long.h"

void	check_element(t_map *a, char *file)
{
	char	*map;
	int		i;

	i = -1;
	map = read_map(file);
	init_map(a, file);
	while (map[++i])
		count_element(map, a, i);
	if (a->collect_count <= 0)
		error_msg("🚫🚫 Map must contain at least one 'C' 🚫🚫\n", map, a->map);
	if (a->exit_count != 1)
		error_msg("🚫🚫 Map must contain exactly one 'E' 🚫🚫\n", map, a->map);
	if (a->player_count != 1)
		error_msg("🚫🚫 Map must contain exactly one 'P' 🚫🚫\n", map, a->map);
	if (a->enemy_count > 1)
		error_msg("🚫🚫 Map must contain exactly one  or zero 'X' 🚫🚫\n", map, a->map);
	set_pos_player(a);
	free(map);
}

void	count_element(char *map, t_map *a, int i)
{
	if (map[i] == 'C')
		a->collect_count += 1;
	else if (map[i] == 'E')
		a->exit_count += 1;
	else if (map[i] == 'P')
		a->player_count += 1;
	else if (map[i] == 'X')
		a->enemy_count += 1;
	else if (map[i] != '1' && map[i] != '0' && map[i] != '\n')
		error_msg("🚫🚫 Invalid character found in map 🚫🚫\n", map, a->map);
}
