/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:24:10 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/02 22:34:28 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
#include <mlx.h>

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

char	*ft_map_holder(char *string)
{
	int			fd;
	char static	map_data[500000];

	fd = open(string, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error Map cannot be loaded\n", 2);
		exit(EXIT_FAILURE);
	}
	else
		read(fd, map_data, BUFFER_SIZE);
	return (map_data);
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

char	**ft_split_map(char *map_data)
{
	char	**split_map;

	split_map = ft_split(map_data, '\n');
	if (!split_map)
		return (NULL);
	return (split_map);
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

void ft_initialize_elements(t_elements *elements)
{
	elements->p = 0;
	elements->e = 0;
	elements->c = 0;
	elements->x = 0;
	elements->y = 0;
	elements->random_data = 0;
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

int	ft_give_index_x(char **splited_map)
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

int	ft_give_index_y(char **splited_map)
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

int	main(int ac, char *av[])
{
	int		x;
	int		y;
	char	*map_data;
	char	**splited;
	char	**duplicated;

	(void) ac;
	ft_check_file_ber(av[1]);
	map_data = ft_map_holder(av[1]);
	splited = ft_split_map(map_data);
	x = ft_give_index_x(splited);
	y = ft_give_index_y(splited);
	duplicated = ft_split_map(map_data);
	ft_flood_fill(x, y, duplicated);
	if (ft_check_map_dimension(splited) || ft_check_for_double_line(map_data)
		|| ft_check_elements(splited) || ft_check_map_walls(splited) || ft_check_flood_fill(duplicated))
	{
		ft_putstr_fd("Map cannot be loaded, check it\n", 2);
		return (EXIT_FAILURE);
	}
	void *wn;
	void *mlx = mlx_init();
	wn = mlx_new_window(mlx, 100, 100, "donpha");
	// void *pl = mlx_xpm_file_to_image(mlx, )
	mlx_loop(mlx);
}
