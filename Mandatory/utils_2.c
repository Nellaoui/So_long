/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 22:41:10 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/13 22:40:45 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_height(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		y++;
	}
	return (y);
}

void	ft_exit_key(t_elements	*s)
{
	mlx_delete_image(s->mlx, s->image);
	mlx_terminate(s->mlx);
	exit(EXIT_ESC);
}

void	ft_putmap_key(t_elements *s)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	s->x_p = ft_i_x(s->map);
	s->y_p = ft_i_y(s->map);
	texture = mlx_load_png("./Mandatory/images/floor.png");
	image = mlx_texture_to_image(s->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(s->mlx, image, (s->x_p * 50), (s->y_p * 50));
	texture = mlx_load_png("./Mandatory/images/darius.png");
	image = mlx_texture_to_image(s->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(s->mlx, image, (s->x_p * 50), (s->y_p * 50));
	texture = mlx_load_png("./Mandatory/images/floor.png");
	image = mlx_texture_to_image(s->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(s->mlx, image, (s->x_floor * 50), (s->y_floor * 50));
}

void	ft_map_error(void)
{
	ft_putstr_fd("Map cannot be loaded, check it\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_freel(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}
