/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:55:05 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 23:55:40 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_player(t_game *game);

void	player_init(t_game	*game)
{
	t_point	point;

	point.y = 0;
	while (game->map.map[point.y])
	{
		point.x = 0;
		while (game->map.map[point.y][point.x])
		{
			if (game->map.map[point.y][point.x] == 'P')
			{
				game->player.x = (SPRITE_SIZE * point.x);
				game->player.y = (SPRITE_SIZE * point.y);
				render_player(game);
				return ;
			}
			point.x++;
		}
		point.y++;
	}
	return ;
}

static void	render_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->player.ptr, game->player.x, game->player.y);
}