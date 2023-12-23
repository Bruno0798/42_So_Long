/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:50:03 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 23:50:51 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == 'E')
	{
		game->exit.x = x * SPRITE_SIZE;
		game->exit.y = y * SPRITE_SIZE;
		mlx_put_image_to_window(game->mlx, game->window, \
		game->exit.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, \
		game->wall.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, \
		game->collect.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

static void	map_check_one(t_game *game, int y, int x)
{
	if (!is_surrounded_by_trees(game, y, x))
		endgame("Not surrounded by trees!", game, map_char_error);
	else if (!is_rectangular(game))
		endgame("Map is not rectangular!", game, map_char_error);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid character in map", game, map_char_error);
	check_map_maker(game, y, x);
	return ;
}

void	render_map(t_game *game)
{
	t_point	coord;

	coord.y = 0;
	while (game->map.map[coord.y])
	{
		coord.x = 0;
		while (game->map.map[coord.y][coord.x])
		{
			map_check_one(game, coord.y, coord.x);
			coord.x++;
		}
		coord.y++;
	}
	return ;
}