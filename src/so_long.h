#ifndef so_long_H
# define so_long_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_enemy
{
	int		x;
	int		y;
	int		axis;
	int		dir_x;
	int		dir_y;
}				t_enemy;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		player_count;
	int		enemy_count;
	int		collect_count;
	int		exit_count;
	int		exit_x;
	int		exit_y;
	t_enemy	enemy;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;

	void	*player;
	void	*player_r;
	void	*player_r2;
	void	*player_l;
	void	*player_l2;
	void	*collect;
	void	*collect1;
	void	*wall;
	void	*floor;
	void	*enemy;
	void	*exit;
	void	*ex_op;
	void	*en_img;

	t_map	map;
	int		steps;
	char	under;
	char	under_en;
}				t_game;

int		count_line_map(int fd);
void	error_msg(char *msg, char *s, char **map);
void	check_element(t_map *a, char *file);
int		destroy_all(t_game *game);
char	*read_map(char *file);
void	init_map(t_map *map, char *file);
void	check_walls(t_map map);
void	set_pos_player(t_map *map);
void	set_pos_enemy(t_map *map, int i, int j);
void	draw_map(t_game *game);
int		assign_button(int key, t_game *game);
void	free_tab(char **s);
void	init_game(t_game *game);
void	check_map_extenstion(char *av);
void	move(int new_x, int new_y, t_game *game);
void	animation_enemy(t_game *game);
void	count_element(char *map, t_map *a, int i);
void	animate_exit(t_game *game, int i, int j);
void	put_steps(int step, t_game *game);
void	flood_fill(char **map, int x, int y);
void	msg_game_over(t_game *game);
int		animation_player(t_game *game);
void	put_img(t_game *a, void *img, int i, int j);
void	draw_line_map(t_game *game, int j);
void	check_map_solvable(char *arg, t_map mp);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *s1, char *s2);
int		chr_line(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
#endif
