#include "so_long_b.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_mlx_put_image(t_game *game, void *obj, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		obj, x * 64, y * 64);
}

void	map_size(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			x++;
		}
		y++;
	}
	game->max_y = y;
	game->max_x = x;
}

void	n_col(t_game *game)
{
	game->n_collect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	game->n_enemy = 0;
}

int	exit_game(t_game *game)
{
	int	x;

	free_map(game->map);
	x = 0;
	while (x < 2)
		free(game->player[x++]);
	x = 0;
	while (x < 2)
		free(game->coin[x++]);
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_enemy);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	exit(0);
	return (0);
}
