/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:04:09 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/24 20:00:32 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


static void	init_game(t_game *game, char *path);
static bool	is_ber_file(const char *argv);
static void	init_hook(t_game *game, int event, \
int mask, int (*f)());

int	main(int argc, char *argv[])
{
	t_game	game;

	// if file extension is wrong enter endgame function and do not launch the game
	if (argc == 2 && !(is_ber_file(argv[1])))
		endgame("Can't open file. The format is not supported!", &game, error);
	else if (argc > 2) // if amount of arguments is wrong enter endgame function and do not launch the game
		endgame("Can't open multiple files!", &game, error);
	else if (argc == 2 && (is_ber_file(argv[1]))) //checking if input is correct (map extension and amount of input strings)
		init_game(&game, argv[1]); //if the if statement is true - enter init_game function
	 // if amount of arguments is wrong enter endgame function and do not launch the game
	endgame("Please specify file name!", &game, error);
	return (0);
}

static void	init_game(t_game *game, char *path)
{ //the whole function prepares all the wariables and initialises everything (mlx library) for game to launch
	init_map(game, path);
	init_window(game);
	init_images(game);
	render_map(game);
	init_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, key_check);
	init_hook(game, DESTROY_NOTIFY, NO_EVENT_MASK, red_cross);
	init_hook(game, EXPOSE, EXPOSURE_MASK, mini_maker);
	mlx_loop(game->mlx);
}

static bool	is_ber_file(const char *argv)
{
	char	*string;

	string = ft_strrchr(argv, '.');
	if (string)
		return (ft_strcmp(string, ".ber") == 0);
	return (false);
}

static void	init_hook(t_game *game, int event, \
int mask, int (*f)())
{
	mlx_hook(game->window, event, mask, f, game);
}