#include "so_long.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->y_player -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->y_player += 1;
		player_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->x_player += 1;
		player_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->x_player -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	int	a;

	if (keycode == KEY_ESC)
		exit_game(game);
	else if (!game->endgame || game->n_collect != 0)
	{
		a = game->moves;
		game_events(keycode, game);
		if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		{
			if (game->map[game->y_player][game->x_player] != '1' || game->map[game->y_player][game->x_player] != 'E')
				ft_printf("\rStep : %d", game->moves);
		}
	}
	return (0);
}

void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 0, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}
