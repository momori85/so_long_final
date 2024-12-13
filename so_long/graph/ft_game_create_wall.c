/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_create_wall.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:09:21 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/06 15:09:22 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_create_map_wall_two(t_map *map, int result, int x, int y)
{
	if (result == 0)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->midle, x, y);
	if (result == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->right, x, y);
	if (result == 2)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->midle_down, x, y);
	if (result == 3)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->left, x, y);
	if (result == 4)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->top_midle, x, y);
	if (result == 5)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->left_down, x, y);
	if (result == 6)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->top_left, x, y);
	if (result == 7)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->solo_top, x, y);
}

static void	ft_create_map_wall_one(t_map *map, int result, int x, int y)
{
	if (result == 8)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->right_down, x, y);
	if (result == 9)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->top_and_down, x, y);
	if (result == 10)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->left_and_right, x, y);
	if (result == 11)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->solo_down, x, y);
	if (result == 12)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->solo_left, x, y);
	if (result == 13)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->solo_top, x, y);
	if (result == 14)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->solo_right, x, y);
	if (result == 15)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->solo, x, y);
}

void	ft_create_map_wall(t_map *map, int x, int y)
{
	int	result;

	result = ft_see_map_wall(map);
	ft_create_map_wall_one(map, result, x, y);
	ft_create_map_wall_two(map, result, x, y);
}
