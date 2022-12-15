/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_on_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:20:16 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/12 14:59:35 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_tombstone(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/rip.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'T')
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	add_background(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/grass.xpm",
			&img->background->length, &img->background->width);
	while (i < img->l_map)
	{
		y = 0;
		while (y < img->w_map)
		{
			mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img, i, y);
			y += 32;
		}
		i += 32;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	add_character2(t_data *img)
{
	if (img->number_of_move % 2 == 0 && img->character->is_w_sword == 1)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./files/c_w_sword.xpm",
				&img->character->length, &img->character->width);
	}
	else if (img->number_of_move % 2 == 1 && img->character->is_w_sword == 1)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./files/c_walk_w_sword.xpm",
				&img->character->length, &img->character->width);
	}
}

void	add_character(t_data *img)
{
	if (img->number_of_move % 2 == 0 && img->character->is_w_sword == 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./files/character.xpm",
				&img->character->length, &img->character->width);
	}
	else if (img->number_of_move % 2 == 1 && img->character->is_w_sword == 0)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "./files/character_walk.xpm",
				&img->character->length, &img->character->width);
	}
	else
		add_character2(img);
	mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
		img->character->x_character, img->character->y_character);
	mlx_destroy_image(img->mlx, img->img);
}

void	add_wall(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/rock.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == '1')
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}
