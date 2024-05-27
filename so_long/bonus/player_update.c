#include "so_long_b.h"

void	player_n(t_game *game)
{
	game->map[game->y_player + 1][game->x_player] = '0';
	game->moves++;
	game->endgame = 1;
	exit_game(game);
}

void	player_w(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player += 1;
	else if (game->map[game->y_player][game->x_player] == 'N')
	{
		player_n(game);
	}
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_s(t_game *game)
{
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player -= 1;
	else if (game->map[game->y_player][game->x_player] == 'N')
	{
		player_n(game);
	}
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_d(t_game *game)
{
	player_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player -= 1;
	else if (game->map[game->y_player][game->x_player] == 'N')
	{
		player_n(game);
	}
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	player_a(t_game *game)
{
	player_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == 'E'
			&& game->n_collect == 0)
	{
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player += 1;
	else if (game->map[game->y_player][game->x_player] == 'N')
	{
		player_n(game);
	}
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}
