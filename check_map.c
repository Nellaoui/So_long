/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:16:58 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/09 23:16:39 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_file_ber(char *string)
{
	int	len;

	len = ft_strlen(string);
	if (string[len - 1] != 'r' || string[len - 2] != 'e'
		|| string[len - 3] != 'b' || string[len - 4] != '.')
	{
		ft_putstr_fd("misiing `.ber` file, Please check it\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_check_map_dimension(char **splited)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(splited[0]);
	while (splited[i])
	{
		if (ft_strlen(splited[i]) != len)
			return (true);
		i++;
	}
	return (false);
}

int	ft_check_for_double_line(char *map_data)
{
	int	i;

	i = 0;
	while (map_data[i])
	{
		if (map_data[i] == '\n' && map_data[i + 1] == '\n')
			return (true);
		i++;
	}
	return (false);
}

int	ft_check_map_walls(char **splited)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (splited[y][++x])
		if (splited[y][x] != '1')
			return (true);
	x--;
	y--;
	while (splited[++y])
		if (splited[y][x] != '1')
			return (true);
	y--;
	while (--x > 0)
		if (splited[y][x] != '1')
			return (true);
	while (y-- > 0)
		if (splited[y][x] != '1')
			return (true);
	return (false);
}

int	ft_check_elements(char **split)
{
	t_elements	elements;

	ft_initialize_elements(&elements);
	while (split[elements.y])
	{
		elements.x = 0;
		while (split[elements.y][elements.x])
		{
			if (split[elements.y][elements.x] == 'C')
				elements.c++;
			if (split[elements.y][elements.x] == 'P')
				elements.p++;
			if (split[elements.y][elements.x] == 'E')
				elements.e++;
			if (split[elements.y][elements.x] != '0'
			&& split[elements.y][elements.x] != '1')
				elements.random_data++;
		elements.x++;
		}
		elements.y++;
	}
	if (elements.c <= 0 || (elements.p > 1 || elements.p <= 0)
		|| (elements.e > 1 || elements.e <= 0) || elements.random_data < 0)
		return (true);
	return (false);
}
