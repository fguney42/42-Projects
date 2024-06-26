#ifndef SO_LONG_B_H
# define SO_LONG_B_H

# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*player[2];
	void	*coin[2];
	void	*img_exit;
	void	*img_enemy;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		n_enemy;
	int		x_player;
	int		y_player;
	int		moves;
	int		enemyspeed;
	int		endgame;
	int		max_x;
	int		max_y;
	int		p_anim;
	int		c_anim;
	int		animcounter;
}	t_game;

# define KEY_ESC 53

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);
void	game_init(t_game *game);
char	**read_map(char *path);
int		map_checker(t_game *game);
void	gameplay(t_game *game);
void	player_w(t_game *game);
void	player_d(t_game *game);
void	player_s(t_game *game);
void	player_a(t_game *game);
int		exit_game(t_game *game);
void	free_map(char **map);
int		ft_skip(t_game *game);
void	n_col(t_game *game);
void	ft_mlx_put_image(t_game *game, void *obj, int x, int y);
void	map_size(t_game *game);
void	player_update_image(char key, t_game *game);
int		square(t_game *game);

#endif
