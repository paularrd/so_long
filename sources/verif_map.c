/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:39:15 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/25 11:12:41 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_s_map(t_map *struct_map)
{
	struct_map->count_exit = 0;
	struct_map->count_collectible = 0;
	struct_map->count_start = 0;
	struct_map->count_sword = 0;
}

int	verif_path(char *path)
{
	int		i;

	i = ft_strlen(path) - 1;
	if (path[i] != 'r' || path[i - 1] != 'e' || path[i - 2] != 'b'
		|| path[i - 3] != '.')
		return (1);
	return (0);
}

int	verif_wall(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			return (1);
		else if (map[i][(ft_strlen_n(map[i]) - 1)] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (ft_strlen_n(map[i]) != ft_strlen_n(map[i]))
			return (1);
		i++;
	}
	return (0);
}

int	verif_counter(char **map)
{
	int		i;
	int		y;
	t_map	struct_map;

	i = -1;
	initialize_s_map(&struct_map);
	while (map[++i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'C')
				struct_map.count_collectible++;
			else if (map[i][y] == 'E')
				struct_map.count_exit++;
			else if (map[i][y] == 'P')
				struct_map.count_start++;
			y++;
		}
	}
	if (struct_map.count_exit >= 2 || struct_map.count_start >= 2
		|| struct_map.count_collectible <= 0 || struct_map.count_exit <= 0
		|| struct_map.count_start <= 0 || verif_counter_sword(map) != 0)
		return (1);
	return (0);
}

int	verif_map(char **map)
{
	int		i;
	int		y;

	if (map[0] == NULL || map[1] == NULL)
		return (1);
	y = 0;
	while (map[0][y])
	{
		if (map[0][y] != '1' && map[0][y] != '\n')
			return (1);
		y++;
	}
	i = 0;
	while (map[i])
		i++;
	y = 0;
	while (map[i - 1][y])
	{
		if (map[i - 1][y] != '1' && map[i - 1][y] != '\n')
			return (1);
		y++;
	}
	return (0);
}
