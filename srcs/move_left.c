/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:58:13 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 21:06:22 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void check_left(t_game *game);
static bool is_left_wall(t_game *game);

void move_left(t_game *game)
{
	check_left(game);
	game->player.mem = left;
	mlx_put_image_to_window(game->mlx, game->window, game->player_l.ptr, game->player.x, game->player.y);
}

static void check_left(t_game *game)
{
	if(game->player.x > SPRITE_SIZE)
	{
		if (!is_left_wall(game))
		{
			game->player.x -= SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
}

static bool is_left_wall(t_game *game)
{
	return (!(game->map.map[(game->player.y / SPRITE_SIZE)][((game->player.x - SPRITE_SIZE) / SPRITE_SIZE)] != '1'));
}