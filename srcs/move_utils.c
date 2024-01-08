/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 21:09:46 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/01/04 11:10:57 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int key_check(int keycode, t_game *game)
{
	printf("x: %d, y: %i\n", game->player.x / SPRITE_SIZE, game->player.y / SPRITE_SIZE);
	game->player.mem = 0;
	if (keycode == ESC)
		endgame("", game, event_ending);
	else if (keycode == LEFT)
		move_left(game);
	else if (keycode == RIGHT)
		move_right(game);
	else if (keycode == DOWN)
		move_down(game);
	else if (keycode == UP)
		move_up(game);
	return 0;
}

void print_moves(t_game *game)
{
	game->i.movements +=1;
	if(game->map.map[game->player.y / SPRITE_SIZE][game->player.x / SPRITE_SIZE] == 'C')
	{
		game->map.map[game->player.y / SPRITE_SIZE][game->player.x / SPRITE_SIZE] = '0';
		game->i.collectible--;
	}
	else if (game->map.map[game->player.y / SPRITE_SIZE]
		[game->player.x / SPRITE_SIZE] == 'E' && game->i.collectible == 0)
	{
		endgame(GREEN"\n\nThe End! :)"ENDC, game, game_over);
	}
	ft_putstr_fd("\rMovements: ", 1);
	ft_putnbr_fd(game->i.movements, 1);
}