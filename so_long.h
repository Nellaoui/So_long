/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:18:35 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/09 23:24:42 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000
# endif

// # define size_x 600
// # define size_y 300

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.a/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include "/goinfre/nelallao/programs/MLX42/include/MLX42/MLX42.h"

typedef struct elements {
	int		p;
	int		e;
	int		c;
	int		x;
	int		y;
	int		random_data;
	mlx_t	*mlx;
	int		x_p;
	int		y_p;
	char	**map;
	int		c_count;
}	t_elements;

void	ft_putstr_fd(char *s, int fd);
void	ft_check_file_ber(char *string);
char	*ft_map_holder(char *string);
int		ft_check_map_dimension(char **splited);
int		ft_check_for_double_line(char *map_data);
int		ft_check_map_walls(char **splited);
char	**ft_split_map(char *map_data);
void	ft_initialize_elements(t_elements *elements);
char	*ft_map_holder(char *string);
void	ft_flood_fill(int x, int y, char **duplicated_map);
int		ft_check_flood_fill(char **duplicated_map);
int		ft_check_elements(char **split);
int		ft_check_map_walls(char **splited);
int		ft_check_for_double_line(char *map_data);
int		ft_check_map_dimension(char **splited);
void	ft_check_file_ber(char *string);
int		ft_i_x(char **splited_map);
int		ft_i_y(char **splited_map);
char	**ft_check_map(char *av);
void	ft_putmap(char **map, t_elements *s);
void	ft_putwalls(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx);
void	ft_count(t_elements *s, char **map);
void	ft_floor(char **map, mlx_t *mlx, mlx_image_t *img);
void	ft_coins(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx);
void	ft_pexit(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx);

#endif
