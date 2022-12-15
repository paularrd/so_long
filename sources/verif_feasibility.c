/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_feasibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:45:21 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/25 11:16:27 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_num_c(char **map)
{
	int	i;
	int	y;
	int	s;

	i = 1;
	s = 0;
	while (map[i + 1])
	{
		y = 1;
		while (map[i][y + 1])
		{
			if (map[i][y] == 'c')
				s++;
			y++;
		}
		i++;
	}
	return (s);
}

void	verif_exit(t_cpy_map *cpy, int y, int x)
{
	char	c;

	c = 'Z';
	if (cpy->is_sword == 1)
		c = '2';
	cpy->cpy_map[x][y] = '#';
	if (cpy->cpy_map[x][y + 1] != '1' && cpy->cpy_map[x][y + 1] != '#'
		&& cpy->cpy_map[x][y + 1] != c)
		verif_exit(cpy, y + 1, x);
	if (cpy->cpy_map[x][y - 1] != '1' && cpy->cpy_map[x][y - 1] != '#'
		&& cpy->cpy_map[x][y - 1] != c)
		verif_exit(cpy, y - 1, x);
	if (cpy->cpy_map[x + 1][y] != '1' && cpy->cpy_map[x + 1][y] != '#'
		&& cpy->cpy_map[x + 1][y] != c)
		verif_exit(cpy, y, x + 1);
	if (cpy->cpy_map[x - 1][y] != '1' && cpy->cpy_map[x - 1][y] != '#'
		& cpy->cpy_map[x - 1][y] != c)
		verif_exit(cpy, y, x - 1);
}

void	get_p_position(char **map, t_cpy_map *cpy)
{
	int	x;
	int	y;

	x = 0;
	while (map[x + 1])
	{
		y = 1;
		while (map[x][y + 1])
		{
			if (map[x][y] == 'P')
			{
				cpy->x = x;
				cpy->y = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int	test_possibility(char **map)
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
			if (map[i][y] == 'C')
				s_map.count_collectible++;
			else if (map[i][y] == 'E')
				s_map.count_exit++;
			else if (map[i][y] == 'P')
				s_map.count_start++;
		}
	}
	if (s_map.count_exit != 0 || s_map.count_start != 0
		|| s_map.count_collectible != 0)
		return (1);
	return (0);
}

int	verif_feasibility(char **map, char *path)
{
	t_cpy_map	cpy_map;

	cpy_map.cpy_map = store_map(path);
	get_p_position(map, &cpy_map);
	cpy_map.is_sword = 0;
	if (verif_feasibility_sword(map, path) == 0 && is_a_sword(map) == 0)
		cpy_map.is_sword = 1;
	verif_exit(&cpy_map, cpy_map.y, cpy_map.x);
	if (test_possibility(cpy_map.cpy_map) == 1)
	{
		free_split(cpy_map.cpy_map);
		return (1);
	}
	free_split(cpy_map.cpy_map);
	return (0);
}
