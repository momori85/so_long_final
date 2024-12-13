/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map_vision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:43:14 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/10 15:43:16 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_create_map_vision(t_map *map)
{
	if (map->count->vision == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->water_one, map->screen_x / 2 - (32 * 3),
			map->screen_y / 2 - (32 * 3));
	if (map->count->vision == 2)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->water_two, map->screen_x / 2 - (32 * 7),
			map->screen_y / 2 - (32 * 7));
	if (map->count->vision >= 3)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img_wall->water_tree, map->screen_x / 2 - (32 * 9),
			map->screen_y / 2 - (32 * 9));
	mlx_put_image_to_window(map->game->mlx, map->game->window,
		map->img->img_path, map->screen_x / 2 - 32, map->screen_y / 2 - 32);
}

void	ft_print_path(t_map *map)
{
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
	mlx_string_put(map->game->mlx, map->game->window, 20,
		20, 0xffffff, "count path :");
	map->count_path = ft_itoa(map->path);
	mlx_string_put(map->game->mlx, map->game->window, 35,
		35, 0xffffff, map->count_path);
	free(map->count_path);
	ft_printf("count : %d\n", map->path);
}

void	ft_frame_five(t_map *map)
{
	if (map->frame == 400)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_4, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
	else if (map->frame == 300)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_3, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
}

void	ft_frame_six(t_map *map)
{
	if (map->frame == 200)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_2, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
	else if (map->frame == 100)
	{
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_path, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->player->player_frame_1, map->screen_x / 2 - 32,
			map->screen_y / 2 - 32);
	}
}

void	ft_verif_bot_player(t_map *map)
{
	if (map->bot->bot1_x != -1)
		map->map[map->bot->bot1_y][map->bot->bot1_x] = 'B';
	if (map->bot->bot2_x != -1)
		map->map[map->bot->bot2_y][map->bot->bot2_x] = 'B';
	if (map->bot->bot3_x != -1)
		map->map[map->bot->bot3_y][map->bot->bot3_x] = 'B';
	if (map->map[map->start_y][map->start_x] == 'B')
	{
		mlx_clear_window(map->game->mlx, map->game->window);
		mlx_destroy_window(map->game->mlx, map->game->window);
		map->game->window = mlx_new_window(map->game->mlx,
				1980, 1080, "so_long");
		mlx_put_image_to_window(map->game->mlx,
			map->game->window, map->img->died, 0, 0);
		map->game_status = -1;
		map->count->vision = -1;
		mlx_loop_end(map->game->mlx);
	}
}
