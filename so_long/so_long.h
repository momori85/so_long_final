/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:45:55 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 13:43:51 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line_bonus.h"
# include "libft/libft.h"
# include "so_long_struct.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "graph/ft_graph.h"

int		ft_verif_map(t_map *map, t_verif *count);
void	free_map(char **tab);
int		ft_init_bfs(t_map *map, t_verif *count, char **tab);
int		ft_end_buf(t_bfs *buf);
int		ft_start_buf(t_bfs *buf, int index);
void	ft_init_buf(t_bfs *buf, int capacity);
char	**ft_tabdup_(t_map *map);
int		ft_init_bfs(t_map *map, t_verif *count, char **str);
char	**ft_so_long_map_create(char **tmp, int fd);
int		ft_close(t_map *map);
char	**ft_so_long(char *name);
void	ft_save(t_map *map);
void	ft_save(t_map *map);
void	ft_create_mini_map_empty(t_map *map);
int		ft_verif_len(char **str);

#endif
