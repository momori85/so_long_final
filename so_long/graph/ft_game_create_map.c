/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_create_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:52:06 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/06 10:52:07 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_create_map_condition_one(t_map *map, int x, int y)
{
	if (map->map[map->end_y][map->end_x] == 'E')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_exit, x, y);
	if (map->map[map->end_y][map->end_x] == 'C')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_c, x, y);
}

static void	ft_create_map_condition(t_map *map, int x, int y)
{
	if (map->end_y >= 0 && map->end_y <= map->map_y
		&& map->end_x >= 0 && map->end_x <= map->len)
	{
		if (map->map[map->end_y][map->end_x] == '1')
		{
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->img_path, x, y);
			ft_create_map_wall(map, x, y);
		}
		if (map->map[map->end_y][map->end_x] == '0')
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->img_path, x, y);
		if (map->map[map->end_y][map->end_x] == 'B')
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->bot, x, y);
		ft_create_map_condition_one(map, x, y);
	}
}

static void	ft_create_collectible(t_map *map, int len_max_x, int len_max_y)
{
	len_max_x = 0;
	len_max_y = 25 * map->count_c;
	while (len_max_x < map->screen_y && len_max_x < len_max_y)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->gold_count, map->screen_x - 100, len_max_x);
		len_max_x += 25;
	}
}

static void	ft_create_map(t_map *map, int x, int y)
{
	int	len_max_x;
	int	len_max_y;
	int	tmp;
	int	tmp_x;

	len_max_x = map->count->vision + map->start_x;
	len_max_y = map->count->vision + map->start_y;
	while (map->end_y <= map->map_y && map->end_y <= len_max_y)
	{
		tmp_x = x;
		tmp = map->end_x;
		while (map->end_x <= map->len && map->end_x <= len_max_x)
		{
			ft_create_map_condition(map, x, y);
			map->mini_map[map->end_y][map->end_x]
				= map->map[map->end_y][map->end_x];
			map->end_x++;
			x += 64;
		}
		x = tmp_x;
		map->end_x = tmp;
		map->end_y++;
		y += 64;
	}
	ft_create_collectible(map, len_max_x, len_max_y);
}

void	ft_create_map_init(t_map *map, int x, int y)
{
	if (map->count->vision > 3)
		map->count->vision = 3;
	x = map->screen_x / 2 - 32 - (64 * map->count->vision);
	y = map->screen_y / 2 - 32 - (64 * map->count->vision);
	map->end_x = map->start_x - map->count->vision;
	map->end_y = map->start_y - map->count->vision;
	ft_create_map_vision(map);
	if (map->end_x < 0)
	{
		x += 64 * -map->end_x;
		map->end_x = 0;
	}
	if (map->end_y < 0)
	{
		y += 64 * -map->end_y;
		map->end_y = 0;
	}
	ft_create_map(map, x, y);
	ft_create_mini_map(map);
}
