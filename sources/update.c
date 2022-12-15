/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:06:15 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/13 11:11:00 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_close_program(t_data *img)
{
	mlx_destroy_window(img->mlx, img->mlx_windows);
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	free_split(img->map);
	free(img->mlx);
	exit(0);
}

void	new_image(t_data *img)
{
	char	*message;

	redo_background(img);
	add_wall(img);
	add_sword(img);
	update_collectible(img);
	add_collectible(img);
	add_exit(img);
	add_enter(img);
	add_tombstone(img);
	message = get_number_of_move(img);
	mlx_string_put(img->mlx, img->mlx_windows, 10, 15,
		0xFFFFFF, message);
	free(message);
	add_character(img);
}

void	update_collectible(t_data *img)
{
	int		i;
	int		y;

	i = img->character->y_character / 32;
	y = img->character->x_character / 32;
	if (img->map[i][y] == 'C')
		img->map[i][y] = '0';
	if (img->map[i][y] == 'S')
	{
		img->map[i][y] = '0';
		img->character->path_to_char = "./files/character_w_sword.xpm";
		img->character->is_w_sword = 1;
	}
	if (img->map[i][y] == 'Z' && img->character->is_w_sword == 1)
		img->map[i][y] = 'T';
	if (img->map[i][y] == 'Z' && img->character->is_w_sword == 0)
	{
		ft_printf("You lose in %i move\n", img->number_of_move);
		clean_close_program(img);
	}
	if (img->map[i][y] == 'E' && img->character->is_collectible_collected == 0)
	{
		ft_printf("You win in %i move, Congratulations!\n", img->number_of_move);
		clean_close_program(img);
	}
}

void	redo_background(t_data *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/grass.xpm",
			&img->background->length, &img->background->width);
	mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
		img->character->last_x, img->character->last_y);
	mlx_destroy_image(img->mlx, img->img);
}
