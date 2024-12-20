/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_settings.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:48:15 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:29:18 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_game_move_settings_top(t_map *map, int keycode)
{
	if (keycode == 119 && map->i > 1)
	{
		map->i--;
		mlx_clear_window(map->game->mlx, map->game->window);
		if (map->i == 1)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_1080, 0, 0);
		if (map->i == 2)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_720, 0, 0);
		if (map->i == 3)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_480, 0, 0);
		if (map->i == 4)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_exit_settings, 0, 0);
	}
}

static void	ft_game_move_settings_down(t_map *map, int keycode)
{
	if (keycode == 115 && map->i < 4)
	{
		map->i++;
		mlx_clear_window(map->game->mlx, map->game->window);
		if (map->i == 1)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_1080, 0, 0);
		if (map->i == 2)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_720, 0, 0);
		if (map->i == 3)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_480, 0, 0);
		if (map->i == 4)
			mlx_put_image_to_window(map->game->mlx,
				map->game->window, map->img->img_exit_settings, 0, 0);
	}
}

static void	ft_resize_screen_game(t_map *map, int keycode)
{
	if (keycode == 65293 && map->i > 0)
	{
		map->game_status = 0;
		mlx_clear_window(map->game->mlx, map->game->window);
		if (map->i == 1)
		{
			map->screen_x = 1980;
			map->screen_y = 1080;
		}
		if (map->i == 2)
		{
			map->screen_x = 1280;
			map->screen_y = 720;
		}
		if (map->i == 3)
		{
			map->screen_x = 640;
			map->screen_y = 480;
		}
		mlx_put_image_to_window(map->game->mlx,
			map->game->window, map->img->img_game, 0, 0);
		map->i = 1;
	}
}

void	ft_game_status_settings(t_map *map, int keycode)
{
	if (map->game_status == 2)
	{
		ft_game_move_settings_top(map, keycode);
		ft_game_move_settings_down(map, keycode);
		if (keycode == 65307)
			mlx_loop_end(map->game->mlx);
		ft_resize_screen_game(map, keycode);
		if (map->i == -1)
			map->i = 1;
	}
}
