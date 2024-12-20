/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_save_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:13:44 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:25:55 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_game_menu_save_move_two(t_map *map)
{
	if (map->i == 1)
	{
		if (ft_init_save(map, "save_one.txt") == 1)
		{
			if (map->map != NULL)
				free_map(map->map);
			map->map = map->save->save_map;
			free_map(map->save->save);
			map->save->file = 1;
		}
	}
	if (map->i == 2)
	{
		if (ft_init_save(map, "save_two.txt") == 1)
		{
			if (map->map != NULL)
				free_map(map->map);
			map->map = map->save->save_map;
			free_map(map->save->save);
			map->save->file = 2;
		}
	}
}

void	ft_game_menu_save_move(t_map *map)
{
	ft_game_menu_save_move_two(map);
	if (map->i == 3)
	{
		if (ft_init_save(map, "save_three.txt") == 1)
		{
			if (map->map != NULL)
				free_map(map->map);
			map->map = map->save->save_map;
			free_map(map->save->save);
			map->save->file = 3;
		}
	}
	if (map->i == 4)
	{
		mlx_clear_window(map->game->mlx, map->game->window);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_game, 0, 0);
		map->game_status = 0;
		map->i = -1;
	}
}

void	ft_game_status_save_full_or_empty(t_map *map)
{
	ft_save(map);
	if (map->save->file_one == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->full, 410, 560);
	else
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->empty, 410, 570);
	if (map->save->file_two == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->full, 410, 660);
	else
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->empty, 410, 670);
	if (map->save->file_three == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->full, 410, 760);
	else
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->empty, 410, 770);
}
