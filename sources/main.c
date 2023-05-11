/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg  <fle-tolg@student.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:56:12 by fle-tolg          #+#    #+#             */
/*   Updated: 2023/05/11 14:42:53 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_program(int keycode, t_data *img)
{
	if (keycode == ESCAPE || keycode == BACKSPACE)
		clean_close_program(img);
	return (0);
}

int	close_program2(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_windows);
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	free_split(img->map);
	free(img->mlx);
	exit(0);
	return (0);
}

void	first_image(t_data *img)
{
	char	*message;

	img->mlx_windows = mlx_new_window(img->mlx, img->l_map,
			img->w_map, "so_long");
	add_background(img);
	add_wall(img);
	add_collectible(img);
	add_exit(img);
	add_sword(img);
	add_zombie(img);
	message = get_number_of_move(img);
	mlx_string_put(img->mlx, img->mlx_windows, 10, 15,
		0xFFFFFF, message);
	free(message);
	add_character(img);
}

void	loop_mlx(t_data *img)
{
	mlx_loop_hook(img->mlx, map_move, img);
	mlx_key_hook(img->mlx_windows, map_move, img);
	mlx_loop_hook(img->mlx, close_program, img);
	mlx_hook(img->mlx_windows, 17, 0, close_program2, img);
	mlx_loop(img->mlx);
}

int	main(int argc, char **argv)
{
	t_data			img;
	t_background	background;
	t_char			character;

	if (argc != 2 || verif_path(argv[1]) == 1)
	{
		write(2, "Error\nNon-valid argument\n", 26);
		return (1);
	}
	img.background = &background;
	img.character = &character;
	img.map = store_map(argv[1]);
	if (verif_map(img.map) != 0 || verif_counter(img.map) != 0
		|| verif_wall(img.map) != 0 || verif_square(img.map) != 0
		|| verif_feasibility(img.map, argv[1]) != 0
		|| verif_non_valid_char(img.map) != 0)
	{
		ft_error_mlx(&img);
	}
	initialize_map(&img);
	img.mlx = mlx_init();
	if (!img.mlx)
		ft_error_mlx(&img);
	first_image(&img);
	loop_mlx(&img);
}
