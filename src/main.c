#include "so_long.h"

void	free_tab(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	error_msg(char *msg, char *s, char **map)
{
	if (msg)
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (s)
		free(s);
	if (map)
		free_tab(map);
	exit(EXIT_FAILURE);
}

void	msg_game_over(t_game *game)
{
	printf("😩😨 GAME OVER : You were hit by a bomb! 💣💥\n");
	destroy_all(game);
	error_msg(NULL, NULL, game->map.map);
}

void	check_map_extenstion(char *av)
{
	char	*begin;
	int		i;

	i = -1;
	begin = NULL;
	if (av)
	{
		while (av[++i])
			if (av[i] == '.')
				begin = &av[i];
		if (!begin || ft_strncmp(begin, ".ber", ft_strlen(begin)) != 0)
			error_msg("⛔ Invalid MAP extension. EXPECTED .ber ⛔\n", NULL, NULL);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		check_map_extenstion(av[1]);
		check_element(&game.map, av[1]);
		check_map_solvable(av[1], game.map);
		check_walls(game.map);
		init_game(&game);
		mlx_key_hook(game.mlx_win, assign_button, &game);
		mlx_loop_hook(game.mlx, animation_player, &game);
		mlx_hook(game.mlx_win, 17, 0, destroy_all, &game);
		mlx_loop(game.mlx);
		free_tab(game.map.map);
	}
	else
		error_msg("⚠️  UTILISATION : $>./so_long map.ber\n", NULL, NULL);
	return (0);
}
