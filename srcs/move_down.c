/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:48:35 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 20:57:12 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void check_down(t_game *game);
static bool is_down_wall(t_game *game);

void move_down(t_game *game)
{
	check_down(game);
	game->player.mem = down;
	mlx_put_image_to_window(game->mlx, game->window, game->player.ptr, game->player.x, game->player.y);
}

static void check_down(t_game *game)
{
	if (game->player.y < ((game->map.height * SPRITE_SIZE) - (SPRITE_SIZE * 2)))
	{
		if(!is_down_wall(game))
		{
			game->player.y +=SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
}

static bool is_down_wall(t_game *game)
{
	return (!(game->map.map[((game->player.y + SPRITE_SIZE) / SPRITE_SIZE)][(game->player.x /SPRITE_SIZE)] != '1'));
}