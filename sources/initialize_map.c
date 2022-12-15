/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:56:11 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/17 13:24:33 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_error_mlx(t_data *img)
{
	write(2, "Error\nUnavailable map\n", 23);
	free_split(img->map);
	exit(0);
}

int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'E' && c != 'P' && c != 'C' && c != 'Z'
		&& c != 'S' && c != '\n')
		return (1);
	return (0);
}

int	verif_non_valid_char(char **map)
{
	int		i;
	int		y;

	i = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (is_valid_char(map[i][y]) == 1)
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

void	initalize_value(t_data *img)
{
	img->character->length = 32;
	img->character->width = 32;
	img->character->is_collectible_collected = 0;
	img->number_of_move = 0;
	img->character->path_to_char = "./files/character.xpm";
	img->character->is_w_sword = 0;
	img->background->length = 32;
	img->background->width = 32;
}

void	initialize_map(t_data *img)
{
	int		i;
	int		y;

	initalize_value(img);
	img->l_map = ((ft_strlen(img->map[0]) - 1) * 32);
	i = 0;
	while (img->map[i])
		i++;
	img->w_map = i * 32;
	i = 1;
	while (img->map[i])
	{
		y = 0;
		while (img->map[i][y])
		{
			if (img->map[i][y] == 'P')
			{
				img->character->x_character = y * 32;
				img->character->y_character = i * 32;
			}
			y++;
		}
		i++;
	}
}
