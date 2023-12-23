/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:06:36 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 21:08:07 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


static bool	is_up_wall(t_game *game);
static void	check_up(t_game *game);

void	move_up(t_game *game)
{
	check_up(game);
	game->player.mem = up;
	mlx_put_image_to_window(game->mlx, game->window,
		game->player_u.ptr, game->player.x, game->player.y);
	return ;
}

static void	check_up(t_game *game)
{
	if ((game->player.y > SPRITE_SIZE))
	{
		if (!is_up_wall(game))
		{
			game->player.y -= SPRITE_SIZE;
			render_map(game);
			print_moves(game);
		}
	}
	return ;
}

static bool	is_up_wall(t_game *game)
{
	return (!(game->map.map[((game->player.y - SPRITE_SIZE) / SPRITE_SIZE)][(game->player.x / SPRITE_SIZE)] != '1'));
}