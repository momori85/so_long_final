/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:15 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/07 15:04:54 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	verif_c(t_map *map)
{
	if (map->map[map->start_y][map->start_x] == 'C')
	{
		map->count->vision++;
		map->count->count_c--;
	}
}

void	ft_move_player(int keycode, t_map *map)
{
	printf("[%c]", map->map[map->bfs->next_y][map->bfs->next_x]);
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
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->fog, 0, 0);
		ft_create_map_init(map, 0, 0);
	}
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
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->fog, 0, 0);
		ft_create_map_init(map, 0, 0);
	}
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
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->fog, 0, 0);
		ft_create_map_init(map, 0, 0);
	}
}

int	move(int keycode, t_map *map)
{
	printf("Keycode: %d\n", keycode);
	ft_game_menu(map, keycode);
	ft_game_status_settings(map, keycode);
	if (map->game_status == 1)
	{
		ft_game_status_play_bot(map, keycode);
		ft_move_player(keycode, map);
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
			mlx_put_image_to_window(map->game->mlx, map->game->window,
				map->img->fog, 0, 0);
			ft_create_map_init(map, 0, 0);
		}
		if (map->start_y == map->bfs->next_y && map->start_x == map->bfs->next_x
			&& map->count->count_c <= 0)
			mlx_loop_end(map->game->mlx);
		if (keycode == 65307)
			mlx_loop_end(map->game->mlx);
		map->map[map->bot->bot1_y][map->bot->bot1_x] = 'B';
		map->map[map->bot->bot2_y][map->bot->bot2_x] = 'B';
		map->map[map->bot->bot3_y][map->bot->bot3_x] = 'B';
		if (map->map[map->start_y][map->start_x] == 'B')
			mlx_loop_end(map->game->mlx);
		ft_printf("count : %d\n", map->path);
		ft_printf("count_c : %d\n", map->bfs->count_bfs_c);
	}
	return (0);
}

int	ft_graph(t_map *map)
{
	map->ch = 'W';
	map->lim = '0';
	ft_fill(map, 0, 0);
	map->i = 0;
	map->game_status = 0;
	map->screen_x = 1980;
	map->screen_y = 1080;
	if (ft_game_malloc_list(map) == 0)
		return (0);
	ft_random(map);
	ft_game_create_bot(map);
	map->game->mlx = mlx_init();
	map->game->window = mlx_new_window(map->game->mlx,
			990, 990, "adventure_time");
	ft_init_img(map);
	mlx_put_image_to_window(map->game->mlx,
		map->game->window, map->img->img_game, 0, 0);
	map->path = 0;
	map->count->vision = 1;
	map->bfs->next_x = map->end_x;
	map->bfs->next_y = map->end_y;
	mlx_key_hook(map->game->window, move, map);
	mlx_loop(map->game->mlx);
	ft_clear_graph(map);
	return (1);
}
