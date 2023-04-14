/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:52:34 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/14 17:53:04 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_keyw(t_elements	*s)
{
	if (!(s->map[s->y_p - 1][s->x_p] == '1')
		&& !(s->map[s->y_p - 1][s->x_p] == 'E'))
	{
		if (s->map[s->y_p - 1][s->x_p] == 'C')
			s->c_count++;
		s->map[s->y_p - 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		s->x_floor = s->x_p;
		s->y_floor = s->y_p;
		ft_printf("movement number %d\n", ++s->move);
	}
	else if (s->map[s->y_p - 1][s->x_p] == 'E' && s->c_count == s->c_cnt)
	{
		s->map[s->y_p - 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		ft_printf("movement number %d\n", ++s->move);
		mlx_terminate(s->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_keys(t_elements	*s)
{
	if (!(s->map[s->y_p + 1][s->x_p] == '1')
		&& !(s->map[s->y_p + 1][s->x_p] == 'E'))
	{
		if (s->map[s->y_p + 1][s->x_p] == 'C')
			s->c_count++;
		s->map[s->y_p + 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		s->x_floor = s->x_p;
		s->y_floor = s->y_p;
		ft_printf("movement number %d\n", ++s->move);
	}
	else if (s->map[s->y_p + 1][s->x_p] == 'E' && s->c_count == s->c_cnt)
	{
		s->map[s->y_p + 1][s->x_p] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		ft_printf("movement number %d\n", ++s->move);
		mlx_terminate(s->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_keyd(t_elements	*s)
{
	if (!(s->map[s->y_p][s->x_p + 1] == '1')
		&& !(s->map[s->y_p][s->x_p + 1] == 'E'))
	{
		if (s->map[s->y_p][s->x_p + 1] == 'C')
			s->c_count++;
		s->map[s->y_p][s->x_p + 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		s->x_floor = s->x_p;
		s->y_floor = s->y_p;
		ft_printf("movement number %d\n", ++s->move);
	}
	else if (s->map[s->y_p][s->x_p + 1] == 'E' && s->c_count == s->c_cnt)
	{
		s->map[s->y_p][s->x_p + 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		ft_printf("movement number %d\n", ++s->move);
		mlx_terminate(s->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_keya(t_elements	*s)
{
	if (!(s->map[s->y_p][s->x_p - 1] == '1')
		&& !(s->map[s->y_p][s->x_p - 1] == 'E'))
	{
		if (s->map[s->y_p][s->x_p - 1] == 'C')
			s->c_count++;
		s->map[s->y_p][s->x_p - 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		s->x_floor = s->x_p;
		s->y_floor = s->y_p;
		ft_printf("movement number %d\n", ++s->move);
	}
	else if (s->map[s->y_p][s->x_p - 1] == 'E' && s->c_count == s->c_cnt)
	{
		s->map[s->y_p][s->x_p - 1] = 'P';
		s->map[s->y_p][s->x_p] = '0';
		ft_printf("movement number %d\n", ++s->move);
		mlx_terminate(s->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_keyhok(mlx_key_data_t k, void *i)
{
	t_elements	*s;

	s = (t_elements *) i;
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
		ft_exit_key(s);
	if (k.key == MLX_KEY_W && (k.action == MLX_PRESS || k.action == MLX_REPEAT))
	{
		ft_keyw(s);
		ft_putmap_key(s);
	}
	if (k.key == MLX_KEY_S && (k.action == MLX_PRESS || k.action == MLX_REPEAT))
	{
		ft_keys(s);
		ft_putmap_key(s);
	}
	if (k.key == MLX_KEY_D && (k.action == MLX_PRESS || k.action == MLX_REPEAT))
	{
		ft_keyd(s);
		ft_putmap_key(s);
	}
	if (k.key == MLX_KEY_A && (k.action == MLX_PRESS || k.action == MLX_REPEAT))
	{
		ft_keya(s);
		ft_putmap_key(s);
	}
}
