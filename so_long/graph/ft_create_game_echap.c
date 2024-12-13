/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game_echap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:43:51 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/13 13:43:52 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_create_game_echap(int keycode, t_map *map)
{
	int i;
	
	i = 0;
	if (map->game_status == 4)
	{
		if (keycode == 65307 && map->i == 1)
			mlx_loop_end(map->game->mlx);
		if (map->i == 0)
			map->i = 1;
		if (keycode == 115 && map->i < 3)
		{
			map->i++;
			if (map->i == 2)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_save_exit, 0, 0);
			if (map->i == 3)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_resume, 0, 0);
		}
		if (keycode == 119 && map->i > 1)
		{
			map->i--;
			if (map->i == 2)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_save_exit, 0, 0);
			if (map->i == 1)
				mlx_put_image_to_window(map->game->mlx, map->game->window,
					map->img->img_save, 0, 0);
		}
		if (keycode == 65293)
		{
			if (map->i == 2)
				mlx_loop_end(map->game->mlx);
			if (map->i == 3)
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
			if (map->i == 1)
			{
				map->fd = open("save.ber", O_CREAT | O_RDWR | O_TRUNC);
				while (map->map[i])
				{
					write(map->fd, map->map[i], ft_strlen(map->map[i]));
					write(map->fd, "\n", 1);
					i++;
				}
			}
		}
	}
}
