/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:34:53 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/02 21:06:05 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

#include "so_long.h"

typedef struct s_bot
{
	int bot1_x;
	int bot1_y;
	int bot2_x;
	int bot2_y;
	int bot3_x;
	int bot3_y;
}				t_bot;

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
	void	*img_game;
    void	*img_settings;
    void	*img_left;
    void	*img_480;
    void	*img_720;
    void	*img_1080;
    void	*img_exit_settings;
    void	*bot;
}				t_game_img;

typedef struct s_img_wall
{
	void	*front_down;
	void	*left;
	void	*left_and_right;
	void	*left_and_down;
	void	*left_down;
	void	*midle;
	void	*midle_down;
	void	*right;
	void	*right_down;
	void	*solo;
	void	*solo_down;
	void	*solo_top;
	void	*top_left;
	void	*top_midle;
	void	*top_right;
	void	*top_and_down;
	void	*solo_left;
	void	*solo_right;
	void	*water;
}			t_img_wall;

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
	int				i;
	int 			game_status;
	int				screen_x;
	int				screen_y;
	char			lim;
	char			ch;
	unsigned long	adress;
	t_verif 		*count;
	t_window_game	*game;
	t_game_img		*img;
	t_bfs			*bfs;
	t_img_wall		*img_wall;
	t_bot			*bot;
}				t_map;

#endif
