/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:45:55 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/07 23:22:57 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "so_long_struct.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "graph/ft_graph.h"

int		ft_verif_map(t_map *map, t_verif *count);
void	free_map(char **tab, t_map	*map);
int		ft_init_bfs(t_map *map, t_verif *count, char **tab);
int		ft_end_buf(t_bfs *buf);
int		ft_start_buf(t_bfs *buf, int index);
void	ft_init_buf(t_bfs *buf, int capacity);
char	**ft_tabdup_(t_map *map);
int		ft_bfs(t_map *map, t_verif *count, char **str);
int		ft_init_bfs(t_map *map, t_verif *count, char **str);

#endif
