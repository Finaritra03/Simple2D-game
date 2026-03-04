#include "so_long.h"

void	init_game(t_game *game)
{
	int	i;
	int	j;

	game->steps = 0;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * 64, \
					game->map.height * 64, "so long");
	game->player_r = mlx_xpm_file_to_image(game->mlx, "sprites/P_r.xpm", &i, &j);
	game->player_r2 = mlx_xpm_file_to_image(game->mlx, "sprites/P_r2.xpm", &i, &j);
	game->player_l = mlx_xpm_file_to_image(game->mlx, "sprites/P.xpm", &i, &j);
	game->player_l2 = mlx_xpm_file_to_image(game->mlx, "sprites/P2.xpm", &i, &j);
	game->collect = mlx_xpm_file_to_image(game->mlx, "sprites/C.xpm", &i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlx, "sprites/0.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/1.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "sprites/E_close.xpm", &i, &j);
	game->ex_op = mlx_xpm_file_to_image(game->mlx, "sprites/E_open.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "sprites/X.xpm", &i, &j);
	game->player = game->player_l;
	game->under = '0';
	game->under_en = '0';
}

void	put_img(t_game *a, void *img, int i, int j)
{
	mlx_put_image_to_window(a->mlx, a->mlx_win, img, i * 64, j * 64);
}

void	draw_map(t_game *game)
{
	int	j;

	j = -1;
	while (game->map.map[++j])
		draw_line_map(game, j);
}

void	draw_line_map(t_game *game, int j)
{
	int	i;

	i = -1;
	while (game->map.map[j][++i])
	{
		if (game->map.map[j][i] == 'P')
			put_img(game, game->player, i, j);
		else if (game->map.map[j][i] == '1')
			put_img(game, game->wall, i, j);
		else if (game->map.map[j][i] == 'X')
			put_img(game, game->enemy, i, j);
		else if (game->map.map[j][i] == '0')
			put_img(game, game->floor, i, j);
		else if (game->map.map[j][i] == 'C')
			put_img(game, game->collect, i, j);
		else if (game->map.map[j][i] == 'E')
			animate_exit(game, i, j);
	}
}

void	destroy_player(t_game *game)
{
	if (game->player_l)
		mlx_destroy_image(game->mlx, game->player_l);
	if (game->player_l)
		mlx_destroy_image(game->mlx, game->player_l2);
	if (game->player_r)
		mlx_destroy_image(game->mlx, game->player_r);
	if (game->player_r2)
		mlx_destroy_image(game->mlx, game->player_r2);

}

int	destroy_all(t_game *game)
{
	destroy_player(game);
	if (game->enemy)
		mlx_destroy_image(game->mlx, game->enemy);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->ex_op)
		mlx_destroy_image(game->mlx, game->ex_op);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_tab(game->map.map);
	exit(EXIT_SUCCESS);
}
