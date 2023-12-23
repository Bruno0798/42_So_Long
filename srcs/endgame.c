/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:37:52 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/19 22:40:53 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.ptr);
	mlx_destroy_image(game->mlx, game->floor.ptr);
	mlx_destroy_image(game->mlx, game->exit.ptr);
	mlx_destroy_image(game->mlx, game->collect.ptr);
	mlx_destroy_image(game->mlx, game->player.ptr);
	mlx_destroy_image(game->mlx, game->player_l.ptr);
	mlx_destroy_image(game->mlx, game->player_r.ptr);
	mlx_destroy_image(game->mlx, game->player_u.ptr);
	mlx_destroy_window(game->mlx, game->window);
	free_map(game);
	free(game->mlx);
}

void free_map(t_game *game)
{
	while(game->map.height > 0)
	{
		free(game->map.map[game->map.height - 1]);
		game->map.height--;
	}
	free(game->map.map);
}

void endgame(char *message, t_game *game, enum e_state i)
{
	if (i == event_ending || i == game_over)
	{
		ft_printf("%s\n", message);
		destroy_image(game);
		exit(0);
	}
	else if (i == error || i == file_error)
	{
		ft_printf(RED"Error\n%s\n"ENDC,message);
		exit(1);
	}
	ft_printf(RED"Error\n%s\n", message);
	destroy_image(game);
	exit(1);
}
