#include "so_long_b.h"

void	player_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->player[0]);
	if (key == 'd')
		game->player[0] = mlx_xpm_file_to_image
			(game->mlx, "images/player.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->player[0] = mlx_xpm_file_to_image
			(game->mlx, "images/player1.xpm", &game->img_w, &game->img_h);
}

int	square(t_game *game)
{
	map_size(game);
	if (game->max_x == game->max_y)
		return (0);
	return (1);
}
