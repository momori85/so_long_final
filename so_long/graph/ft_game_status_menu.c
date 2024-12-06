/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:26:16 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/06 08:26:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_game_menu_start(t_map *map, int keycode)
{
	if (keycode == 65307)
		mlx_loop_end(map->game->mlx);
	if (keycode == 65293 && (map->i == 1 || map->i == 2 || map->i == 3))
	{
		map->game_status = map->i;
		if (map->i == 1)
		{
			mlx_clear_window(map->game->mlx, map->game->window);
			mlx_destroy_window(map->game->mlx, map->game->window);
			map->game->window = mlx_new_window(map->game->mlx,
					map->screen_x, map->screen_y, "adventure_time");
			mlx_key_hook(map->game->window, move, map);
			ft_create_map_init(map, 0, 0);
		}
		if (map->i == 2)
		{
			mlx_clear_window(map->game->mlx, map->game->window);
			map->i = 0;
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->img_1080, 0, 0);
		}
		if (map->i == 3)
			mlx_loop_end(map->game->mlx);
	}
}

void	ft_game_menu_len(t_map *map, int keycode)
{
	if (keycode == 119 && map->i != 1)
	{
		map->i = 1;
		mlx_clear_window(map->game->mlx, map->game->window);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_game, 0, 0);
	}
	if (keycode == 115 && map->i != 2)
	{
		map->i = 2;
		mlx_clear_window(map->game->mlx, map->game->window);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_settings, 0, 0);
	}
	if (keycode == 100 && map->i != 3)
	{
		map->i = 3;
		mlx_clear_window(map->game->mlx, map->game->window);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_left, 0, 0);
	}
}

void	ft_game_menu(t_map *map, int keycode)
{
	if (map->game_status == 0)
	{
		ft_game_menu_len(map, keycode);
		if (keycode == 97 && map->i != 2)
		{
			map->i = 2;
			mlx_clear_window(map->game->mlx, map->game->window);
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->img_settings, 0, 0);
		}
		ft_game_menu_start(map, keycode);
	}
}
