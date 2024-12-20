/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 09:42:47 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/15 22:26:23 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_game_status_game_right(int keycode, t_map *map)
{
	if (keycode == 100 && map->map[map->start_y][map->start_x + 1] != '1'
		&& map->map[map->start_y][map->start_x + 1] != 'W')
	{
		if (map->start_y != map->bfs->next_y
			|| map->start_x != map->bfs->next_x)
			map->map[map->start_y][map->start_x] = '0';
		else
			map->map[map->bfs->next_y][map->bfs->next_x] = 'E';
		map->start_x += 1;
		verif_c(map);
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
		mlx_clear_window(map->game->mlx, map->game->window);
		ft_create_map_init(map, 0, 0);
	}
}

static void	ft_game_status_game_down(int keycode, t_map *map)
{
	if (keycode == 115 && (map->map[map->start_y + 1][map->start_x] != '1'
		&& map->map[map->start_y + 1][map->start_x] != 'W'))
	{
		if (map->start_y != map->bfs->next_y
			|| map->start_x != map->bfs->next_x)
			map->map[map->start_y][map->start_x] = '0';
		else
			map->map[map->bfs->next_y][map->bfs->next_x] = 'E';
		map->start_y += 1;
		verif_c(map);
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
		mlx_clear_window(map->game->mlx, map->game->window);
		ft_create_map_init(map, 0, 0);
	}
}

static void	ft_game_status_game_up(int keycode, t_map *map)
{
	if (keycode == 119 && (map->map[map->start_y - 1][map->start_x] != '1'
		&& map->map[map->start_y - 1][map->start_x] != 'W'))
	{
		if (map->start_y != map->bfs->next_y
			|| map->start_x != map->bfs->next_x)
			map->map[map->start_y][map->start_x] = '0';
		else
			map->map[map->bfs->next_y][map->bfs->next_x] = 'E';
		map->start_y -= 1;
		verif_c(map);
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
		mlx_clear_window(map->game->mlx, map->game->window);
		ft_create_map_init(map, 0, 0);
	}
}

static void	ft_game_status_game_left(int keycode, t_map *map)
{
	if (keycode == 97 && map->map[map->start_y][map->start_x - 1] != '1'
		&& map->map[map->start_y][map->start_x - 1] != 'W')
	{
		if (map->start_y != map->bfs->next_y
			|| map->start_x != map->bfs->next_x)
			map->map[map->start_y][map->start_x] = '0';
		else
			map->map[map->bfs->next_y][map->bfs->next_x] = 'E';
		map->start_x -= 1;
		verif_c(map);
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
		mlx_clear_window(map->game->mlx, map->game->window);
		ft_create_map_init(map, 0, 0);
	}
}

void	ft_game_status_game(int keycode, t_map *map)
{
	if (map->game_status == 1)
	{
		ft_game_status_play_bot(map, keycode);
		ft_game_status_game_right(keycode, map);
		ft_game_status_game_down(keycode, map);
		ft_game_status_game_up(keycode, map);
		ft_game_status_game_left(keycode, map);
		ft_game_status_exit(map);
		if (keycode == 65307)
		{
			map->i = 0;
			map->game_status = 4;
			mlx_clear_window(map->game->mlx, map->game->window);
			mlx_destroy_window(map->game->mlx, map->game->window);
			map->game->window = mlx_new_window(map->game->mlx,
					445, 445, "so_long");
			mlx_key_hook(map->game->window, move, map);
			mlx_hook(map->game->window, 17, 0, ft_close, map);
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->img_save, 0, 0);
		}
		ft_verif_bot_player(map);
		ft_print_path(map);
	}
}
