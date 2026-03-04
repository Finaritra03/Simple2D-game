#include "so_long.h"

int	assign_button(int key, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->map.x;
	new_y = game->map.y;
	if (key == 65307)
		destroy_all(game);
	else if (key == 'w')
		new_y--;
	else if (key == 's')
		new_y++;
	else if (key == 'd')
	{
		game->player = game->player_l;
		new_x++;
	}
	else if (key == 'a')
	{
		game->player = game->player_r;
		new_x--;
	}
	if (key == 'w' || key == 's' || key == 'd' || key == 'a')
		move(new_x, new_y, game);
	return (0);
}

void	put_steps(int step, t_game *game)
{
	char	*steps;
	char	*txt;
	char	*res;

	txt = ft_strdup("Steps : ");
	res = NULL;
	steps = ft_itoa(step);
	res = ft_strjoin(txt, steps);
	free(steps);
	mlx_string_put(game->mlx, game->mlx_win, 78, 78, 0x000, res);
	free(res);
}

void	move(int new_x, int new_y, t_game *game)
{
	if (game->map.map[new_y][new_x] != '1')
	{
		if (game->map.map[new_y][new_x] == 'C')
			game->map.collect_count--;
		game->map.map[game->map.y][game->map.x] = game->under;
		game->under = game->map.map[new_y][new_x];
		if (game->map.map[game->map.y][game->map.x] == 'C')
			game->map.map[game->map.y][game->map.x] = '0';
		game->map.y = new_y;
		game->map.x = new_x;
		game->map.map[new_y][new_x] = 'P';
		game->steps++;
		if (game->map.x == game->map.exit_x && \
			game->map.y == game->map.exit_y && !game->map.collect_count)
		{
			printf("🎉 CONGRATULATIONS.YOU WIN IN %d STEPS 🎁\n", game->steps);
			destroy_all(game);
		}
		draw_map(game);
	}
}
