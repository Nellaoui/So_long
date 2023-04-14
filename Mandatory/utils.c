/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:38:13 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/12 22:17:52 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_i_x(char **splited_map)
{
	int	x;
	int	y;

	y = 0;
	while (splited_map[y])
	{
		x = 0;
		while (splited_map[y][x])
		{
			if (splited_map[y][x] == 'P')
				return (x);
			x++;
		}
		y++;
	}
	return (false);
}

int	ft_i_y(char **splited_map)
{
	int	x;
	int	y;

	y = 0;
	while (splited_map[y])
	{
		x = 0;
		while (splited_map[y][x])
		{
			if (splited_map[y][x] == 'P')
				return (y);
			x++;
		}
		y++;
	}
	return (false);
}

char	*ft_map_holder(char *string)
{
	int			fd;
	char static	map_data[500000];

	fd = open(string, O_RDONLY);
	if (read(fd, map_data, BUFFER_SIZE) == 0)
		exit(EXIT_FAILURE);
	if (fd < 0)
	{
		ft_putstr_fd("Error Map cannot be loaded\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
}

int	ft_count(char **map)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

int	ft_count_width(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y][x])
	{
		x++;
	}
	return (x);
}
