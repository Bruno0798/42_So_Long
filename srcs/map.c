/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:50:03 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/01/04 11:38:44 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**dup_map(t_game *game);

static void	check_map_maker(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == 'E')
	{
		game->exit.x = x * SPRITE_SIZE;
		game->exit.y = y * SPRITE_SIZE;
		mlx_put_image_to_window(game->mlx, game->window, game->exit.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	}
	else if (game->map.map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->wall.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else if (game->map.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->collect.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
	else
		mlx_put_image_to_window(game->mlx, game->window,game->floor.ptr, (x * SPRITE_SIZE), (y * SPRITE_SIZE));
}

static void	map_check_one(t_game *game, int y, int x)
{
	static int flag = 0;
	char **map_dup;
	

	if (!flag)
	{
		map_dup = dup_map(game);
		flag = 1;
		player_init(game);
	}
	
	if (!is_surrounded_by_trees(game, y, x))
		endgame("Not surrounded by trees!", game, map_char_error);
	else if (!is_rectangular(game))
		endgame("Map is not rectangular!", game, map_char_error);
	else if (!is_valid_character(game, y, x))
		endgame("Invalid character in map", game, map_char_error);
	else if ((is_path_valid(game->i.collectible, map_dup, game->player.y / SPRITE_SIZE, game->player.x / SPRITE_SIZE)) == 1)
	{
		printf("teste: %i\n", (is_path_valid(game->i.collectible, map_dup, game->player.y / SPRITE_SIZE, game->player.x / SPRITE_SIZE)));
		endgame("Invalid path!", game, map_char_error);
	}
	check_map_maker(game, y, x);
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
}


bool is_path_valid(int coins, char **map, int y, int x)
{
    static int collectibles;
    static int exit;
	
    if (map[y][x] == '1')
        return false;
    else if (map[y][x] == 'C')
        collectibles++;
    else if (map[y][x] == 'E')
        exit++;
    map[y][x] = '1';
	
    is_path_valid(coins, map, y - 1, x);
    is_path_valid(coins, map, y + 1, x);
    is_path_valid(coins, map, y, x - 1);
    is_path_valid(coins, map, y, x + 1);

	printf("collectibles: %d\n", collectibles);
	printf("Exit %i\n", exit);
	printf("Coins %i\n", coins);
	
	if (collectibles == coins && exit == 1)
		return 1;
    return 0;
}


char	**dup_map(t_game *game)
{
	char	**map_test;
	int	i;

	i = -1;
	map_test = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!map_test)
		free(map_test);
	while (++i < game->map.height)
		map_test[i] = ft_strdup(game->map.map[i]);
	return (map_test);
}
