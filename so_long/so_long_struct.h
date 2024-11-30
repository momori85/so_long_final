/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:34:53 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/28 12:34:54 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

#include "so_long.h"

typedef struct s_verif
{
	int	count_p;
	int	count_e;
	int	count_c;
	int vision;
}				t_verif;

typedef struct s_bfs
{
	int	*tab;
	int	front;
	int	last;
	int	capacity;
	int	recur;
	int	recur_x;
	int	recur_y;
	int	next_x;
	int	next_y;
	int	count_bfs_c;
	int	count_bfs_e;
}				t_bfs;

typedef struct s_window_game
{
	void	*window;
	void	*mlx;
}	t_window_game;

typedef struct s_game_img
{
	void	*img_player;
	void	*img_wall;
	void	*img_path;
	void	*img_c;
	void	*img_exit;
	void	*img_start;
}				t_game_img;

typedef struct s_map
{
	char			**map;
	int				len;
	int				start_x;
	int				end_x;
	int				start_y;
	int				end_y;
	int				map_y;
	int				path;
	t_verif 		*count;
	t_window_game	*game;
	t_game_img		*img;
	t_bfs			*bfs;
}				t_map;

#endif
