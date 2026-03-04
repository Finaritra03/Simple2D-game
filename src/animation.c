#include "so_long.h"

void	animate_exit(t_game *game, int i, int j)
{
	if (game->map.collect_count != 0)
		put_img(game, game->exit, i, j);
	else
		put_img(game, game->ex_op, i, j);
}

int	animation_player(t_game *game)
{
	static int	frame = 0;
	
	++frame;
	usleep(5000);
	if (game->map.x == game->map.enemy.x && game->map.y == game->map.enemy.y)
		msg_game_over(game);
	if (frame % 56 == 0)
	{
		if (game->player == game->player_l)
			game->player = game->player_l2;
		else if (game->player == game->player_r)
			game->player = game->player_r2;
	}
	else if (frame % 17 == 0)
	{
		if (game->player == game->player_l2)
			game->player = game->player_l;
		else if (game->player == game->player_r2)
			game->player = game->player_r;
	}
	if (frame % 30 == 0)
		animation_enemy(game);
	draw_map(game);
	put_steps(game->steps, game);
	return (0);
}

void	animation_enemy(t_game *game)
{
	int	nx;
	int	ny;

	int frame1 = rand();
	nx = game->map.enemy.x;
	ny = game->map.enemy.y;
	if (game->map.enemy.axis == 0)
		nx += game->map.enemy.dir_x;
	else
		ny += game->map.enemy.dir_y;
	if (nx < 0 || nx >= game->map.width || ny < 0 || \
	ny >= game->map.height || game->map.map[ny][nx] == '1')
	{
		if (frame1 % 2 == 0)
			game->map.enemy.dir_x *= -1;
		else if (frame1 % 5 == 0)
			game->map.enemy.dir_y *= -1;
		if (game->map.enemy.axis == 0)
			game->map.enemy.dir_x *= -1;
		else
			game->map.enemy.dir_y *= -1;
		game->map.enemy.axis = !game->map.enemy.axis;
		return;
	}
	else
	{
		if (frame1 % 7 == 0)
			game->map.enemy.dir_x *= -1;
		else if (frame1 % 11 == 0)
			game->map.enemy.dir_y *= -1;
	}
	game->map.map[game->map.enemy.y][game->map.enemy.x] = game->under_en;
	game->under_en = game->map.map[ny][nx];
	game->map.enemy.x = nx;
	game->map.enemy.y = ny;
	game->map.map[ny][nx] = 'X';
}
