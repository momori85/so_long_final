/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_game_echap_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:38:40 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:26:19 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_read_create_save_two(t_map *map)
{
	char	buf[1];

	map->fd = open("save_two.txt", O_CREAT | O_RDWR, 0644);
	if (read(map->fd, buf, 1) == 0)
	{
		ft_create_save(map);
		map->save->file = 2;
	}
	else
	{
		map->fd = open("save_three.txt", O_CREAT | O_RDWR, 0644);
		if (read(map->fd, buf, 1) == 0)
		{
			ft_create_save(map);
			map->save->file = 3;
		}
	}
}

void	ft_read_create_save(t_map *map)
{
	char	buf[1];

	if (map->i == 1)
	{
		map->fd = open("save_one.txt", O_CREAT | O_RDWR, 0644);
		if (read(map->fd, buf, 1) == 0)
		{
			ft_create_save(map);
			map->save->file = 1;
		}
		else
		{
			ft_read_create_save_two(map);
		}
		if (map->fd != -1)
			close(map->fd);
	}
}

void	ft_echap_resume(t_map *map)
{
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
		if (map->count->vision == 1)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->fog, map->screen_x / 2 - (32 * 3 + 16),
				map->screen_y / 2 - (32 * 3 + 16));
		if (map->count->vision == 2)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->fog_two, map->screen_x / 2 - (32 * 7),
				map->screen_y / 2 - (32 * 7));
		if (map->count->vision >= 3)
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->fog_tree, map->screen_x / 2 - (32 * 9),
				map->screen_y / 2 - (32 * 9));
	}
}
