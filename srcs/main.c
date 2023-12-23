/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:04:09 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/22 19:55:22 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool is_ber_file(char *file);

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc == 2 && !(is_ber_file(argv[1])))
	    endgame("Can't open file.", &game, error);
    return 0;
}

static bool is_ber_file(char *file)
{
	char *str;

	str = ft_strrchr(file, '.');
	if (str)
		return (ft_strcmp(str, ".ber") == 0);
	return (false);
}
