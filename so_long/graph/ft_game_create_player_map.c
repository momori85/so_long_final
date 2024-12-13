/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_create_player_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:47:15 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/10 15:47:16 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_frame_one(t_map *map)
{
	if (map->frame == 1200)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_12, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		map->frame = 0;
	}
	else if (map->frame == 1100)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_11, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
}

static void	ft_frame_two(t_map *map)
{
	if (map->frame == 1000)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_10, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
	else if (map->frame == 900)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_9, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
}

static void	ft_frame_tree(t_map *map)
{
	if (map->frame == 800)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_8, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
	else if (map->frame == 700)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_7, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
}

static void	ft_frame_four(t_map *map)
{
	if (map->frame == 600)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_6, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
	else if (map->frame == 500)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_5, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
}

int	ft_frame(t_map *map)
{
	if (map->game_status == 1)
	{
		if (map->frame_1 % 150 == 0)
		{
			map->frame_1 = 1;
			map->frame++;
		}
		ft_frame_one(map);
		ft_frame_two(map);
		ft_frame_tree(map);
		ft_frame_four(map);
		ft_frame_five(map);
		ft_frame_six(map);
		map->frame_1++;
	}
	return (0);
}
