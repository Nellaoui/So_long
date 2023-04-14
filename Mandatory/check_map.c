/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:16:58 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/13 21:23:44 by nelallao         ###   ########.fr       */
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
		if ((map_data[i] == '\n' && map_data[i + 1] == '\n')
			|| map_data[0] == '\n')
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
	t_elements	s;

	ft_initialize_elements(&s);
	while (split[s.y])
	{
		s.x = 0;
		while (split[s.y][s.x])
		{
			if (split[s.y][s.x] == 'C')
				s.c++;
			else if (split[s.y][s.x] == 'P')
				s.p++;
			else if (split[s.y][s.x] == 'E')
				s.e++;
			else if (split[s.y][s.x] != '0' && split[s.y][s.x] != '1')
				s.random_data++;
		s.x++;
		}
		s.y++;
	}
	if (s.c <= 0 || s.p != 1 || s.e != 1 || s.random_data != 0)
		return (true);
	return (false);
}
