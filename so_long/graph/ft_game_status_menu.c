/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 08:26:16 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/07 23:29:02 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_game_menu_start_move(t_map *map)
{
	if (map->i == 1)
	{
		map->game_status = 1;
		mlx_clear_window(map->game->mlx, map->game->window);
		mlx_destroy_window(map->game->mlx, map->game->window);
		map->game->window = mlx_new_window(map->game->mlx,
				map->screen_x, map->screen_y, "so_long");
		mlx_key_hook(map->game->window, move, map);
		mlx_hook(map->game->window, 17, 0, ft_close, map);
		ft_create_map_init(map, 0, 0);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->fog, map->screen_x / 2 - (32 * 3 + 16),
			map->screen_y / 2 - (32 * 3 + 16));
	}
	if (map->i == 2)
	{
		map->game_status = 2;
		mlx_clear_window(map->game->mlx, map->game->window);
		map->i = -1;
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_1080, 0, 0);
	}
	if (map->i == 3)
		mlx_loop_end(map->game->mlx);
}

static void	ft_game_menu_start(t_map *map, int keycode)
{
	if (keycode == 65307)
		mlx_loop_end(map->game->mlx);
	if (keycode == 65293 && (map->i == 1 || map->i == 2 || map->i == 3))
		ft_game_menu_start_move(map);
	if (keycode == 65293 && map->i == 0)
		map->i = 1;
}

static void	ft_game_menu_len(t_map *map, int keycode)
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
