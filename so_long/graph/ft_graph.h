/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:11 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/29 12:39:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include "../so_long.h"

int		ft_graph(t_map *map);
void	ft_init_img(t_map *map);
void	ft_clear_graph(t_map *map);
int		ft_init_settings_sreen(void);
int		ft_init_game_sreen(t_map *map);
void	ft_del_wall(t_map *map);

int		move(int keycode, t_map *map);
t_map	*simple_hash(t_map *map);

/*************/
/* game menu */
/*************/

void	ft_game_menu(t_map *map, int keycode);
void	ft_game_status_settings(t_map *map, int keycode);

void	ft_game_status_play_bot(t_map *map, int keycode);
void	ft_create_map_init(t_map *map, int x, int y);
void	ft_create_map_wall(t_map *map, int x, int y);
void	ft_game_create_bot(t_map *map);
int		ft_see_map_wall(t_map *map);
int		ft_putnbr_base_ten(t_map *map, char *base, unsigned long result);
void	ft_random(t_map *map);
void	ft_fill(t_map *map, int x, int y);
int		ft_game_malloc_list(t_map *map);

#endif
