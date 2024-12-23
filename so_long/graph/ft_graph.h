/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:11 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 17:39:28 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include "../so_long.h"

/*************/
/* game init */
/*************/

int		ft_graph(t_map *map);
int		ft_init_img(t_map *map);
void	ft_clear_graph(t_map *map);
int		ft_init_settings_sreen(void);
int		ft_init_game_sreen(t_map *map);
int		move(int keycode, t_map *map);
int		ft_init_img_screen_three(t_map *map, int len);
int		ft_init_img_screen_two(t_map *map, int len);
int		ft_init_wall_three(t_map *map, int len);
int		ft_init_wall_two(t_map *map, int len);
int		ft_init_player_two(t_map *map, int len);
int		ft_init_img_two(t_map *map, int len);

/*************/
/* game menu */
/*************/

void	ft_game_menu(t_map *map, int keycode);
void	ft_game_status_settings(t_map *map, int keycode);

/*************/
/* game play */
/*************/

t_map	*simple_hash(t_map *map);
void	ft_game_status_play_bot(t_map *map, int keycode);
void	ft_create_map_init(t_map *map, int x, int y);
void	ft_create_map_wall(t_map *map, int x, int y);
void	ft_game_create_bot(t_map *map);
int		ft_see_map_wall(t_map *map);
int		ft_putnbr_base_ten(t_map *map, char *base, unsigned long result);
void	ft_random(t_map *map);
void	ft_fill(t_map *map, int x, int y);
int		ft_game_malloc_list(t_map *map);
void	ft_game_status_game(int keycode, t_map *map);
void	verif_c(t_map *map);
void	ft_create_map_vision(t_map *map);
int		ft_frame(t_map *map);
void	ft_frame_six(t_map *map);
void	ft_frame_five(t_map *map);
void	ft_print_path(t_map *map);
void	ft_verif_bot_player(t_map *map);
int		ft_init_img_path(t_map *map, int len);
void	ft_map_seed_tree(t_map *map);
void	ft_map_seed_two(t_map *map);
void	ft_map_seed_one(t_map *map);
void	ft_map_seed_zero(t_map *map);
void	ft_create_game_echap(int keycode, t_map *map);
void	ft_game_status_save(int keycode, t_map *map);
void	ft_create_mini_map(t_map *map);
void	ft_game_status_save_full_or_empty(t_map *map);
void	ft_game_menu_save_move(t_map *map);
int		ft_init_save(t_map *map, char *name);
void	ft_game_status_exit(t_map *map);
void	ft_read_create_save(t_map *map);
void	ft_create_save(t_map *map);
void	ft_echap_resume(t_map *map);

#endif
