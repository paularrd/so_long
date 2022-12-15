/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-tolg <fle-tolg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 08:42:28 by fle-tolg          #+#    #+#             */
/*   Updated: 2022/11/25 11:13:02 by fle-tolg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_square(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen_n(map[i]) != ft_strlen_n(map[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen_n(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	count_line(char *path_to_map)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile do not open\n");
		exit(0);
	}
	i = 0;
	str = ft_strdup("Pas NULL");
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

char	**store_map(char *path_to_map)
{
	int		i;
	int		fd;
	char	**map;

	map = malloc(count_line(path_to_map) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(path_to_map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile do not open\n");
		exit(0);
	}
	i = 0;
	while (i < count_line(path_to_map))
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
