#include "so_long_b.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 64, y * 64);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, image, x, y);
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == 'P')
				player_draw(game, game->player[0], x, y);
			else if (game->map[y][x] == 'C')
				img_draw(game, game->coin[0], x, y);
			else if (game->map[y][x] == 'E')
				img_draw(game, game->img_exit, x, y);
			else if (game->map[y][x] == 'N')
				img_draw(game, game->img_enemy, x, y);
		}
	}
	return (0);
}
