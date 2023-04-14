/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:56:10 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/14 18:31:59 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putwalls(char **m, mlx_t *ml, mlx_image_t *i, mlx_texture_t *t)
{
	int			y;
	int			x;
	t_elements	*s;

	s = NULL;
	t = mlx_load_png("./Mandatory/images/wall.png");
	ft_error_texture(t, ml);
	i = mlx_texture_to_image(ml, t);
	y = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == '1')
				mlx_image_to_window(ml, i, (x * 50), (y * 50));
			x++;
		}
		y++;
	}
	mlx_delete_texture(t);
}

void	ft_floor(char **map, mlx_t *mlx, mlx_image_t *img)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_image_to_window(mlx, img, (x * 50), (y * 50));
			x++;
		}
		y++;
	}
}

void	ft_coins(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx)
{
	int			y;
	int			x;
	t_elements	*s;

	s = NULL;
	tx = mlx_load_png("./Mandatory/images/coins.png");
	ft_error_texture(tx, mlx);
	img = mlx_texture_to_image(mlx, tx);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_image_to_window(mlx, img, (x * 50), (y * 50));
			x++;
		}
		y++;
	}
	mlx_delete_texture(tx);
}

void	ft_pexit(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx)
{
	int			y;
	int			x;
	t_elements	*s;

	s = NULL;
	tx = mlx_load_png("./Mandatory/images/exit.png");
	ft_error_texture(tx, mlx);
	img = mlx_texture_to_image(mlx, tx);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				mlx_image_to_window(mlx, img, (x * 50), (y * 50));
			x++;
		}
		y++;
	}
	mlx_delete_texture(tx);
}

void	ft_putmap(char **map, t_elements *s)
{
	s->x_p = ft_i_x(s->map);
	s->y_p = ft_i_y(s->map);
	s->texture = mlx_load_png("./Mandatory/images/floor.png");
	ft_error_texture(s->texture, s->mlx);
	s->image = mlx_texture_to_image(s->mlx, s->texture);
	mlx_delete_texture(s->texture);
	ft_floor(map, s->mlx, s->image);
	ft_putwalls(map, s->mlx, s->image, s->texture);
	ft_coins(map, s->mlx, s->image, s->texture);
	ft_pexit(map, s->mlx, s->image, s->texture);
	s->texture = mlx_load_png("./Mandatory/images/darius.png");
	ft_error_texture(s->texture, s->mlx);
	s->image = mlx_texture_to_image(s->mlx, s->texture);
	mlx_image_to_window(s->mlx, s->image, (s->x_p * 50), (s->y_p * 50));
	mlx_delete_texture(s->texture);
}
