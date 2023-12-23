/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:47:18 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 23:47:53 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	red_cross(t_game *game)
{
	endgame("", game, event_ending);
	return (0);
}

int	mini_maker(t_game *game)
{
	render_map(game);
	if (game->i.movements == 0)
		player_init(game);
	else if (game->player.mem == down)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.ptr, game->player.x, game->player.y);
	else if (game->player.mem == left)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_l.ptr, game->player.x, game->player.y);
	else if (game->player.mem == right)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_r.ptr, game->player.x, game->player.y);
	else if (game->player.mem == up)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player_u.ptr, game->player.x, game->player.y);
	return (0);
}