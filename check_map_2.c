/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:18:36 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/08 19:53:50 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_flood_fill(char **duplicated_map)
{
	int	x;
	int	y;

	y = 0;
	while (duplicated_map[y])
	{
		x = 0;
		while (duplicated_map[y][x])
		{
			if (duplicated_map[y][x] == 'C' || duplicated_map[y][x] == 'E')
				return (true);
			x++;
		}
		y++;
	}
	return (false);
}

void	ft_flood_fill(int x, int y, char **duplicated_map)
{
	if (duplicated_map[y][x] == '1')
		return ;
	duplicated_map[y][x] = '1';
	ft_flood_fill(x + 1, y, duplicated_map);
	ft_flood_fill(x - 1, y, duplicated_map);
	ft_flood_fill(x, y - 1, duplicated_map);
	ft_flood_fill(x, y + 1, duplicated_map);
}


void	ft_initialize_elements(t_elements *elements)
{
	elements->p = 0;
	elements->e = 0;
	elements->c = 0;
	elements->x = 0;
	elements->y = 0;
	elements->random_data = 0;
}

char	**ft_split_map(char *map_data)
{
	char	**split_map;

	split_map = ft_split(map_data, '\n');
	if (!split_map)
		return (NULL);
	return (split_map);
}

char	**ft_check_map(char *av)
{
	int		x;
	int		y;
	char	*map_data;
	char	**splited;
	char	**duplicated;

	ft_check_file_ber(av);
	map_data = ft_map_holder(av);
	splited = ft_split_map(map_data);
	x = ft_i_y(splited);
	y = ft_i_y(splited);
	duplicated = ft_split_map(map_data);
	if (ft_check_map_dimension(splited) || ft_check_for_double_line(map_data)
		|| ft_check_elements(splited) || ft_check_map_walls(splited))
	{
		ft_putstr_fd("Map cannot be loaded, check it\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_flood_fill(x, y, duplicated);
	if (ft_check_flood_fill(duplicated))
	{
		ft_putstr_fd("Map cannot be loaded, check it\n", 2);
		exit(EXIT_FAILURE);
	}
	return (splited);
}
