/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:48:20 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 23:49:54 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_point	get_screen_size(t_game *game)
{
	t_point	point;

	mlx_get_screen_size(game->mlx, &point.x, &point.y);
	return (point);
}

bool	is_larger_than_window(t_game *game)
{
	t_point	screen_size;

	screen_size = get_screen_size(game);
	return (((game->map.length * SPRITE_SIZE) > screen_size.x) || ((game->map.height * SPRITE_SIZE) > screen_size.y));
}