#include "so_long_b.h"

static void	ft_move_enemy(t_game *game, int x, int y)
{
	if (game->map[y][x + 1] == 'P' || game->map[y][x - 1] == 'P')
		exit_game(game);
	else if (game->map[y][x + 1] == '0')
	{
		ft_mlx_put_image(game, game->img_enemy, x + 1, y);
		ft_mlx_put_image(game, game->img_backg, x, y);
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'N';
	}
	else
	{
		ft_mlx_put_image(game, game->img_backg, x, y);
		game->map[y][x] = '0';
		while (game->map[y][x] != '1' && x)
				x--;
		if (game->map[y][x + 1] == 'P')
			exit_game(game);
		ft_mlx_put_image(game, game->img_enemy, x + 1, y);
		game->map[y][x + 1] = 'N';
	}
}

static void	is_move_enemy(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->max_y)
	{
		x = -1;
		while (++x < game->max_x)
		{
			if (game->map[y][x] == 'N')
			{
				ft_move_enemy(game, x, y);
				x++;
			}
		}
	}
}

static void	ft_anim(t_game *game, int x, int y, char type)
{
	if (type == 'C')
	{
		if (game->c_anim >= 2)
			game->c_anim = 0;
		ft_mlx_put_image(game, game->coin[game->c_anim], x, y);
	}
}

static void	ft_isanim(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->max_y)
	{
		x = -1;
		while (++x < game->max_x)
		{
			if (game->map[y][x] == 'C')
				ft_anim(game, x, y, 'C');
		}
	}
	game->c_anim++;
}

int	ft_skip(t_game *game)
{
	game->enemyspeed++;
	game->animcounter++;
	if (game->animcounter >= 1000)
	{
		map_size(game);
		ft_isanim(game);
		game->animcounter = 0;
	}
	if (game->enemyspeed >= 3100)
	{
		map_size(game);
		is_move_enemy(game);
		game->enemyspeed = 0;
	}
	return (0);
}
