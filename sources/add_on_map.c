/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_on_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:17:15 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/17 13:14:45 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_sword(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/sword.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'S')
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	add_collectible(t_data *img)
{
	int		i;
	int		y;

	img->character->is_collectible_collected = 0;
	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/diamond.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'C')
			{
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
				img->character->is_collectible_collected++;
			}
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	add_exit(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/exit.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'E')
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	add_zombie(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/zombie.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'Z')
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}

void	add_enter(t_data *img)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(img->mlx, "./files/start.xpm",
			&img->character->length, &img->character->width);
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'P')
				mlx_put_image_to_window(img->mlx, img->mlx_windows, img->img,
					y * 32, i * 32);
			y++;
		}
		i++;
	}
	mlx_destroy_image(img->mlx, img->img);
}
