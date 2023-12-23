/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:38:58 by bsousa-d          #+#    #+#             */
/*   Updated: 2023/12/23 00:29:31 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>

# define WALL_PATH		"./img/tree.xpm"
# define FLOOR_PATH		"./img/floor.xpm"
# define COLLECT_PATH	"./img/potion.xpm"
# define EXIT_PATH	"./img/exit.xpm"
# define CHAR_PATH		"./img/link_sprites/down_1__.xpm"
# define CHAR_L_PATH	"./img/link_sprites/left_1__.xpm"
# define CHAR_R_PATH	"./img/link_sprites/right_1__.xpm"
# define CHAR_U_PATH	"./img/link_sprites/up_1__.xpm"

# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define ENDC	"\033[0m"

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307
# define WINDOW_NAME "./so_long"
# define SPRITE_SIZE 32

# define KEY_RELEASE	3
# define DESTROY_NOTIFY	17
# define EXPOSE		12

# define KEY_RELEASE_MASK	2
# define NO_EVENT_MASK		0
# define EXPOSURE_MASK		32768

enum e_direction
{
	down,
	right,
	left,
	up,
};

enum e_state
{
	event_ending = -1,
	game_over = -1,
	error = 2,
	file_error = 3,
	map_char_error = 4,
};

typedef struct s_counter
{
	int empty;
	int collectible;
	int exit;
	int start;
	int movements;
} t_counter;

typedef struct s_sprites
{
	void *ptr;
	int *pixels;
	int line_size;
	int mem;
	int x;
	int y;
	int movements;
} t_sprites;

typedef struct s_map
{
	char **map;
	int height;
	int length;
	char *line;
} t_map;

typedef struct s_game
{
	void *mlx;
	void *window;
	t_counter i;
	t_map map;
	t_sprites player;
	t_sprites player_l;
	t_sprites player_r;
	t_sprites player_u;
	t_sprites floor;
	t_sprites wall;
	t_sprites collect;
	t_sprites exit;
} t_game;

typedef struct s_point
{
	int x;
	int y;
} t_point;


void destroy_image(t_game *game);
void free_map(t_game *game);
void endgame(char *message, t_game *game, enum e_state i);
void init_window(t_game *game);
void init_images(t_game *game);
t_sprites new_sprite(void *mlx, char *path);
void	player_init(t_game	*game);
void	init_map(t_game *game, char *path);
int	open_file(char *path);
t_counter	new_counter(void);
int	len_map_validation(char **map, t_game *game);
bool	is_surrounded_by_trees(t_game *game, int y, int x);
bool	is_rectangular(t_game *game);
bool	is_valid_character(t_game *game, int y, int x);
bool	is_double_line(char *string_map, int i);
void	is_elements_number_valid(t_game *game, t_counter *cnt, char *temp);
void	render_map(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
int key_check(int keycode, t_game *game);
void print_moves(t_game *game);
t_point	get_screen_size(t_game *game);
bool	is_larger_than_window(t_game *game);
int	red_cross(t_game *game);
int	mini_maker(t_game *game);

#endif //SO_LONG_H
