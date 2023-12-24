/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:52:56 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/24 20:00:45 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void			read_map(t_game *game, int fd);
static t_counter	start_counter(char *string_map, t_game *game);
static void			count_elements(t_counter *cnt, char c);

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open_file(path);
	read_map(game, fd);
	game->map.length = len_map_validation(game->map.map, game);
	close(fd);
}

static void	read_map(t_game *game, int fd)
{
	char	*temp;

	temp = ft_strdup("");
	game->map.height = 0;
	while (fd)
	{
		game->map.line = get_next_line(fd);
		if (game->map.line == NULL)
			break ;
		temp = join(temp, game->map.line);
		free(game->map.line);
		game->map.height++;
	}
	game->i = start_counter(temp, game);
	game->map.map = ft_split(temp, '\n');
	free(temp);
}

static t_counter	start_counter(char *string_map, t_game *game)
{
	t_counter	cnt;
	int			i;

	cnt = new_counter();
	i = 0;
	while (string_map[i] != '\0')
	{
		if (is_double_line(string_map, i))
		{
			free(string_map);
			endgame("Invalid, file!", game, file_error);
		}
		count_elements(&cnt, string_map[i]);
		i++;
	}
	is_elements_number_valid(game, &cnt, string_map);
	return (cnt);
}

static void	count_elements(t_counter *cnt, char c)
{
	if (c == 'C')
		cnt->collectible++;
	else if (c == 'E')
		cnt->exit++;
	else if (c == 'P')
		cnt->start++;
	else if (c == '0')
		cnt->empty++;
}