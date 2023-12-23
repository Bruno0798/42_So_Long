/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:08:16 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 21:09:17 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	is_right_wall(t_game *game);
static void	check_right(t_game *game);

void	move_right(t_game *game)
{
	check_right(game);
	game->player.mem = right;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player_r.ptr, game->player.x, game->player.y);
	return ;
}

static void	check_right(t_game *game)
{
	if (game->player.x < \
	((game->map.length * SPRITE_SIZE) - (SPRITE_SIZE * 2)))
	{
		if (!is_right_wall(game))
		{
			game->player.x += SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_right_wall(t_game *game)
{
	return (!(game->map.map[(game->player.y / SPRITE_SIZE)][((game->player.x + SPRITE_SIZE) / SPRITE_SIZE)] != '1'));
}