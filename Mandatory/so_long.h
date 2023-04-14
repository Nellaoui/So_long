/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:18:35 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/13 22:23:36 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000
# endif
# define EXIT_ESC 3
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.a/libft.h"
# include <stdbool.h>
# include "printf/ft_printf.h"
# include "../lib/libmlx42/MLX42.h"

typedef struct elements {
	int				p;
	int				e;
	int				c;
	int				x;
	int				y;
	int				random_data;
	int				x_p;
	int				y_p;
	int				c_count;
	int				c_cnt;
	int				x_floor;
	int				y_floor;
	int				width;
	int				height;
	int				move;
	char			**map;
	char			*map_data;
	int				display_width;
	int				display_height;
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}	t_elements;

void	ft_so_long(char **av);
void	ft_error_texture(mlx_texture_t *texture, mlx_t *mlx);
void	ft_exit_key(t_elements	*s);
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
char	**ft_check_map(char *av, t_elements	*s);
void	ft_putmap(char **map, t_elements *s);
void	ft_map_error(void);
void	ft_putwalls(char **m, mlx_t *ml, mlx_image_t *i, mlx_texture_t *t);
int		ft_count(char **map);
void	ft_floor(char **map, mlx_t *mlx, mlx_image_t *img);
void	ft_coins(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx);
void	ft_pexit(char **map, mlx_t *mlx, mlx_image_t *img, mlx_texture_t *tx);
void	ft_keyhok(mlx_key_data_t keydata, void *i);
void	ft_keyw(t_elements	*s);
void	ft_keys(t_elements	*s);
void	ft_keya(t_elements	*s);
void	ft_keyd(t_elements	*s);
void	ft_freel(char **map);
void	ft_putmap_key(t_elements *s);
int		ft_count_width(char **map);
int		ft_count_height(char **map);
#endif
