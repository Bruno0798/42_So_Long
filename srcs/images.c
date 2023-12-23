/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 19:55:35 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 20:48:23 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (is_larger_than_window(game))
	{
		free(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		endgame("Map size larger than display", game, error);
	}
	else
	{
		game->window = mlx_new_window(game->mlx, (game->map.length * SPRITE_SIZE), (game->map.height * SPRITE_SIZE), WINDOW_NAME);
	}
}

void init_images(t_game *game)
{
	game->wall = new_sprite(game->mlx, WALL_PATH);
	game->floor = new_sprite(game->mlx, FLOOR_PATH);
	game->collect = new_sprite(game->mlx, COLLECT_PATH);
	game->exit = new_sprite(game->mlx, EXIT_PATH);
	game->player = new_sprite(game->mlx, CHAR_PATH);
	game->player_l = new_sprite(game->mlx,CHAR_L_PATH);
	game->player_r = new_sprite(game->mlx, CHAR_R_PATH);
	game->player_u = new_sprite(game->mlx, CHAR_U_PATH);
}

t_sprites new_sprite(void *mlx, char *path)
{
	t_sprites sprite;

	sprite.ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	return (sprite);
}