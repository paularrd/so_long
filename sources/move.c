/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:59:04 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/14 13:07:58 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*join_n_move(t_data *img)
{
	char	*num;
	char	*message;
	char	*n_move;

	num = ft_itoa(img->number_of_move);
	message = ft_strdup("Number of move = ");
	n_move = ft_strjoin(message, num);
	free(message);
	free(num);
	return (n_move);
}

char	*get_number_of_move(t_data *img)
{
	char	*n_move;

	n_move = join_n_move(img);
	return (n_move);
}

int	is_wall(t_data *img, char pos, char sign)
{
	if (pos == 'y' && sign == '-')
	{
		if (img->map[(img->character->y_character / 32) - 1]
			[(img->character->x_character / 32)] == '1')
			return (1);
	}
	else if (pos == 'y' && sign == '+')
	{
		if (img->map[(img->character->y_character / 32) + 1]
			[(img->character->x_character / 32)] == '1')
			return (1);
	}
	else if (pos == 'x' && sign == '-')
	{
		if (img->map[(img->character->y_character / 32)]
			[(img->character->x_character / 32) - 1] == '1')
			return (1);
	}
	else if (pos == 'x' && sign == '+')
	{
		if (img->map[(img->character->y_character / 32)]
			[(img->character->x_character / 32) + 1] == '1')
			return (1);
	}
	return (0);
}

void	update_position(t_data *img, int i)
{
	img->character->last_y = img->character->y_character;
	img->character->last_x = img->character->x_character;
	if (i == 0)
		img->character->y_character -= 32;
	else if (i == 1)
		img->character->y_character += 32;
	else if (i == 2)
		img->character->x_character -= 32;
	else if (i == 3)
		img->character->x_character += 32;
	img->number_of_move++;
	if (img->number_of_move >= 2147483646)
		img->number_of_move = 0;
}

int	map_move(int keycode, t_data *img)
{
	if (keycode == ESCAPE || keycode == BACKSPACE)
		clean_close_program(img);
	else if ((keycode == UP || keycode == W) && is_wall(img, 'y', '-') == 0)
		update_position(img, 0);
	else if ((keycode == DOWN || keycode == S) && is_wall(img, 'y', '+') == 0)
		update_position(img, 1);
	else if ((keycode == LEFT || keycode == A) && is_wall(img, 'x', '-') == 0)
		update_position(img, 2);
	else if ((keycode == RIGHT || keycode == D) && is_wall(img, 'x', '+') == 0)
		update_position(img, 3);
	new_image(img);
	return (0);
}
