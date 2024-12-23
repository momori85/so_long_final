/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:15 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 17:36:42 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	verif_c(t_map *map)
{
	if (map->map[map->start_y][map->start_x] == 'C')
	{
		map->count->vision++;
		map->count_c--;
	}
}

int	move(int keycode, t_map *map)
{
	ft_game_menu(map, keycode);
	ft_game_status_settings(map, keycode);
	ft_game_status_game(keycode, map);
	ft_create_game_echap(keycode, map);
	ft_game_status_save(keycode, map);
	return (0);
}

int	ft_close(t_map *map)
{
	mlx_loop_end(map->game->mlx);
	return (0);
}

static void	ft_init_graph(t_map *map)
{
	map->i = 0;
	map->game_status = 0;
	map->screen_x = 1980;
	map->screen_y = 1080;
	map->frame = 0;
	map->frame_1 = 0;
	map->save->file = 0;
	map->save->verif = 0;
	map->path = 0;
	map->count->vision = 1;
	map->bfs->next_x = map->end_x;
	map->bfs->next_y = map->end_y;
	map->save->save_map = NULL;
}

int	ft_graph(t_map *map)
{
	ft_fill(map, 0, 0);
	if (ft_game_malloc_list(map) == 0)
		return (0);
	ft_random(map);
	ft_init_graph(map);
	ft_game_create_bot(map);
	map->game->mlx = mlx_init();
	map->game->window = mlx_new_window(map->game->mlx,
			990, 990, "so_long");
	if (ft_init_img(map) == 0)
	{
		map->count->vision = -2;
		return (1);
	}
	mlx_put_image_to_window(map->game->mlx,
		map->game->window, map->img->img_game, 0, 0);
	mlx_hook(map->game->window, 17, 0, ft_close, map);
	mlx_key_hook(map->game->window, move, map);
	mlx_loop_hook(map->game->mlx, ft_frame, map);
	mlx_loop(map->game->mlx);
	if (map->count->vision == -1)
		sleep (2);
	return (1);
}
