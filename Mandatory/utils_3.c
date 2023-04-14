/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:50:53 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/14 18:29:44 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_window_size(t_elements *s)
{
	s->display_height = 0;
	s->display_width = 0;
	mlx_get_monitor_size(0, &s->display_width, &s->display_height);
	if ((s->width * 50) > s->display_width
		|| (s->height * 50) > s->display_height)
	{
		ft_putstr_fd("Error : Map Is To Large\n", 2);
		mlx_terminate(s->mlx);
		exit(EXIT_FAILURE);
	}
}

void	ft_so_long(char **av)
{
	t_elements	s;

	s.map = ft_check_map(av[1], &s);
	s.width = ft_count_width(s.map);
	s.height = ft_count_height(s.map);
	s.mlx = mlx_init((s.width * 50), (s.height * 50), "So_long", false);
	ft_check_window_size(&s);
	s.c_cnt = ft_count(s.map);
	s.c_count = 0;
	ft_putmap(s.map, &s);
	mlx_key_hook(s.mlx, ft_keyhok, &s);
	mlx_loop(s.mlx);
	mlx_terminate(s.mlx);
}

void	ft_error_texture(mlx_texture_t *texture, mlx_t *mlx)
{
	mlx = NULL;
	if (texture == NULL)
	{
		ft_putstr_fd("Error : images didn't loaded correctly\n", 2);
		exit(EXIT_FAILURE);
	}
}
