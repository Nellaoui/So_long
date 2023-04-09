/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:24:10 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/09 23:31:39 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(1, "Somthing is wrong about mlx\n", 28);
	exit(EXIT_FAILURE);
}

void	ft_keyw(t_elements	*s)
{
	if (!(s->map[s->y_p - 1][s->x_p] == '1') && !(s->map[s->y_p - 1][s->x_p] == 'E'))
	{
		if (s->map[s->y_p - 1][s->x_p] == 'C')
			s->c_count++;
		s->map[s->y_p - 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
	}
	else if (s->map[s->y_p - 1][s->x_p] == 'E' && s->c_count == s->c)
	{
		s->map[s->y_p - 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		exit(EXIT_SUCCESS);
	}
}

void	ft_keys(t_elements	*s)
{
	if (!(s->map[s->y_p + 1][s->x_p] == '1') && !(s->map[s->y_p + 1][s->x_p] == 'E'))
	{
		if (s->map[s->y_p + 1][s->x_p] == 'C')
			s->c_count++;
		s->map[s->y_p + 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
	}
	else if (s->map[s->y_p + 1][s->x_p] == 'E' && s->c_count == s->c)
	{
		s->map[s->y_p + 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		exit(EXIT_SUCCESS);
	}
}

void	ft_keyd(t_elements	*s)
{

	if (!(s->map[s->y_p][s->x_p + 1] == '1') && !(s->map[s->y_p][s->x_p + 1] == 'E'))
	{
		if (s->map[s->y_p][s->x_p + 1] == 'C')
			s->c_count++;
		s->map[s->y_p][s->x_p + 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
	}
	else if (s->map[s->y_p][s->x_p + 1] == 'E' && s->c_count == s->c)
	{
		s->map[s->y_p][s->x_p + 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		exit(EXIT_SUCCESS);
	}
}

void	ft_keya(t_elements	*s)
{

	if (!(s->map[s->y_p][s->x_p - 1] == '1') && !(s->map[s->y_p][s->x_p - 1] == 'E'))
	{
		if (s->map[s->y_p][s->x_p - 1] == 'C')
			s->c_count++;
		s->map[s->y_p][s->x_p - 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
	}
	else if (s->map[s->y_p][s->x_p - 1] == 'E' && s->c_count == s->c)
	{
		s->map[s->y_p][s->x_p - 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		exit(EXIT_SUCCESS);
	}
}

void	ft_keyhok(mlx_key_data_t keydata, void *i)
{
	t_elements	*s;

	s = (t_elements *) i;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_keyw(s);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_keys(s);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_keyd(s);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_keya(s);
	ft_putmap(s->map, s);
}

int	main(int ac, char *av[])
{
	t_elements	s;

	(void) ac;
	// s.mlx = mlx_init(750, 300, "Donpha", false);
	s.map = ft_check_map(av[1]);
	ft_count(&s, s.map);
	printf("%s", s.map[1]);
	// printf("%d", s.c);
	// ft_putmap(s.map, &s);
	// mlx_key_hook(s.mlx, ft_keyhok, &s);
	// mlx_loop(s.mlx);
	// mlx_terminate(s.mlx);

}

void	ft_putmap(char **map, t_elements *s)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	s->x_p = ft_i_x(s->map);
	s->y_p = ft_i_y(s->map);
	texture = mlx_load_png("./images/floor.png");
	image = mlx_texture_to_image(s->mlx, texture);
	ft_floor(map, s->mlx, image);
	ft_putwalls(map, s->mlx, image, texture);
	ft_coins(map, s->mlx, image, texture);
	ft_pexit(map, s->mlx, image, texture);
	texture = mlx_load_png("./images/darius.png");
	image = mlx_texture_to_image(s->mlx, texture);
	mlx_image_to_window(s->mlx, image, (s->x_p * 50), (s->y_p * 50));
}

void	ft_putwalls(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx)
{
	int	y;
	int	x;

	tx = mlx_load_png("./images/wall.png");
	img = mlx_texture_to_image(mlx, tx);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_image_to_window(mlx, img, (x * 50), (y * 50));
			x++;
		}
		y++;
	}
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
	int	y;
	int	x;

	tx = mlx_load_png("./images/coins.png");
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
}

void	ft_pexit(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx)
{
	int	y;
	int	x;

	tx = mlx_load_png("./images/exit.png");
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
}
void	ft_count(t_elements *s, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				s->c++;
			x++;
		}
	}
}
