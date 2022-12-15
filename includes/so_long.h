/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:07:05 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/25 11:26:00 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define ESCAPE 0xff1b
# define BACKSPACE 0xff08
# define W 0x77
# define D 0x64
# define A 0x61
# define S 0x73
# define UP 0xff52
# define RIGHT 0xff53
# define LEFT 0xff51
# define DOWN 0xff54

typedef struct s_char
{
	char	*path_to_char;
	int		x_character;
	int		y_character;
	int		length;
	int		width;
	int		is_collectible_collected;
	int		is_w_sword;
	int		last_x;
	int		last_y;
}				t_char;

typedef struct s_backgroud
{
	char	*path_to_back;
	int		width;
	int		length;
}				t_background;

typedef struct s_data
{
	t_char			*character;
	t_background	*background;
	char			**map;
	void			*mlx;
	void			*mlx_windows;
	void			*img;
	int				bits_per_pixel;
	int				number_of_move;
	int				length;
	int				width;
	int				l_map;
	int				w_map;
}				t_data;

typedef struct s_map
{
	int		count_exit;
	int		count_start;
	int		count_collectible;
	int		count_sword;
}				t_map;

typedef struct s_cpy_map
{
	char		**cpy_map;
	int			x;
	int			y;
	int			is_sword;
}				t_cpy_map;

char	*join_n_move(t_data *img);
char	*get_number_of_move(t_data *img);
char	**store_map(char *path_to_map);

void	ft_error_mlx(t_data *img);
void	add_tombstone(t_data *img);
void	add_character(t_data *img);
void	add_character2(t_data *img);
void	add_background(t_data *img);
void	add_wall(t_data *img);
void	add_collectible(t_data *img);
void	add_exit(t_data *img);
void	add_zombie(t_data *img);
void	add_enter(t_data *img);
void	add_sword(t_data *img);
void	clean_close_program(t_data *img);
void	update_collectible(t_data *img);
void	new_image(t_data *img);
void	first_image(t_data *img);
void	loop_mlx(t_data *img);
void	initialize_map(t_data *img);
void	initalize_value(t_data *img);
void	initialize_s_map(t_map *struct_map);
void	redo_background(t_data *img);
void	update_position(t_data *img, int i);
void	verif_sword(t_cpy_map *cpy, int y, int x);
void	get_p_position(char **map, t_cpy_map *cpy);

int		verif_path(char *path);
int		verif_map(char **map);
int		verif_counter(char **map);
int		verif_wall(char **map);
int		count_line(char *path_to_map);

size_t	ft_strlen_n(char *s);

int		verif_non_valid_char(char **map);
int		is_valid_char(char c);
int		is_a_sword(char **map);
int		verif_square(char **map);
int		test_possibility(char **map);
int		verif_feasibility(char **map, char *path);
int		verif_feasibility_sword(char **map, char *path);
int		test_possibility_sword(char **map);
int		close_program(int keycode, t_data *img);
int		is_wall(t_data *img, char pos, char sign);
int		map_move(int keycode, t_data *img);
int		verif_counter_sword(char **map);

#endif
