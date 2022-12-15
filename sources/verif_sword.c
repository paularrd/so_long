/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_sword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:41 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/25 11:16:13 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_counter_sword(char **map)
{
	int		i;
	int		y;
	int		s;

	i = 0;
	s = 0;
	while (map[i])
	{
		y = 0;
		while (map[i][y])
		{
			if (map[i][y] == 'S')
				s++;
			y++;
		}
		i++;
	}
	if (s >= 2)
		return (1);
	return (0);
}

void	verif_sword(t_cpy_map *cpy, int y, int x)
{
	cpy->cpy_map[x][y] = '#';
	if (cpy->cpy_map[x][y + 1] != '1' && cpy->cpy_map[x][y + 1] != '#'
		&& cpy->cpy_map[x][y + 1] != 'Z')
		verif_sword(cpy, y + 1, x);
	if (cpy->cpy_map[x][y - 1] != '1' && cpy->cpy_map[x][y - 1] != '#'
		&& cpy->cpy_map[x][y - 1] != 'Z')
		verif_sword(cpy, y - 1, x);
	if (cpy->cpy_map[x - 1][y] != '1' && cpy->cpy_map[x - 1][y] != '#'
		& cpy->cpy_map[x - 1][y] != 'Z')
		verif_sword(cpy, y, x - 1);
	if (cpy->cpy_map[x + 1][y] != '1' && cpy->cpy_map[x + 1][y] != '#'
		&& cpy->cpy_map[x + 1][y] != 'Z')
		verif_sword(cpy, y, x + 1);
}

int	test_possibility_sword(char **map)
{
	int		i;
	int		y;
	t_map	s_map;

	i = -1;
	initialize_s_map(&s_map);
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == 'S')
				s_map.count_sword++;
		}
	}
	if (s_map.count_sword > 0)
		return (1);
	return (0);
}

int	verif_feasibility_sword(char **map, char *path)
{
	t_cpy_map	cpy_map;

	cpy_map.cpy_map = store_map(path);
	cpy_map.is_sword = 0;
	get_p_position(map, &cpy_map);
	verif_sword(&cpy_map, cpy_map.y, cpy_map.x);
	if (test_possibility_sword(cpy_map.cpy_map) != 0)
	{
		free_split(cpy_map.cpy_map);
		return (1);
	}
	free_split(cpy_map.cpy_map);
	return (0);
}

int	is_a_sword(char **map)
{
	int		i;
	int		y;
	t_map	s_map;

	i = -1;
	initialize_s_map(&s_map);
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == 'S')
				s_map.count_sword++;
		}
	}
	if (s_map.count_sword >= 2 || s_map.count_sword <= 0)
		return (1);
	return (0);
}
