/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelallao <nelallao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:18:35 by nelallao          #+#    #+#             */
/*   Updated: 2023/04/02 00:17:54 by nelallao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.a/libft.h"
# include <stdbool.h>

typedef struct elements {
	int	p;
	int	e;
	int	c;
	int	x;
	int	y;
	int	random_data;
}	t_elements;

void	ft_putstr_fd(char *s, int fd);
void	ft_check_file_ber(char *string);
char	*ft_map_holder(char *string);
int		ft_check_map_dimension(char **splited);
int		ft_check_for_double_line(char *map_data);
int		ft_check_map_walls(char **splited);

#endif
