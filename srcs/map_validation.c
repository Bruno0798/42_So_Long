/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:51:02 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 23:52:38 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_surrounded_by_trees(t_game *game, int y, int x)
{
	if ((game->map.map[game->map.height - 1][x] != '1') || \
		(game->map.map[0][x] != '1') || (game->map.map[y] \
		[game->map.length - 1] != '1') || (game->map.map[y][0] != '1'))
	{
		return (false);
	}
	return (true);
}

bool	is_rectangular(t_game *game)
{
	if (game->map.height == game->map.length)
	{
		return (false);
	}
	return (true);
}

bool	is_valid_character(t_game *game, int y, int x)
{
	if (!(ft_strchr("01CEP", game->map.map[y][x])))
	{
		return (false);
	}
	return (true);
}

bool	is_double_line(char *string_map, int i)
{
	return ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])));
}

void	is_elements_number_valid(t_game *game, t_counter *cnt, char *temp)
{
	if (\
	!(cnt->collectible > 0 && cnt->exit == 1 && \
	cnt->start == 1 && cnt->empty > 0))
	{
		free(temp);
		endgame("Invalid, file!", game, file_error);
	}
}