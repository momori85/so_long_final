/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:15 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/06 14:55:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_create_map_condition(t_map *map, int x, int y)
{
	if (map->map[map->end_y][map->end_x] == '1')
		mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_wall, x, y);
	if (map->map[map->end_y][map->end_x] == '0')
		mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_path, x, y);
	if (map->map[map->end_y][map->end_x] == 'E')
		mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_exit, x, y);
	if (map->map[map->end_y][map->end_x] == 'P')
		mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_start, x, y);
	if (map->map[map->end_y][map->end_x] == 'C')
		mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_c, x, y);
}

int	ft_create_map(t_map *map)
{
	int x;
	int y;
	int len;
	int tmp;

	x = 1980 / 2 - 20 - (40 * map->count->vision);
	y = 1080 / 2 - 20 - (40 * map->count->vision);
	len = map->count->vision * 2 + 1;
	
	map->end_x = map->start_x - map->count->vision;
	map->end_y = map->start_y - map->count->vision;
	if (map->end_x < 0)
		map->end_x = 0;
	if (map->end_y < 0)
		map->end_x = 0;
	while (map->end_y < map->map_y)
	{
		tmp = map->end_x;
		while(map->end_x < map->len)
		{
			ft_create_map_condition(map, x, y);
			map->end_x++;
			x += 40;
		}
		x = 1980 / 2 - 20 - (40 * map->count->vision);
		map->end_x = tmp;
		map->end_y++;
		y += 40;
	}
	return (1);
}

void	ft_move_player(int keycode, t_map *map)
{
	if (keycode == 115
		&& (map->map[map->start_y + 1][map->start_x] != '1'))
	{
		map->map[map->start_y][map->start_x] = '0';
		map->map[map->start_y + 1][map->start_x] = 'P';
		map->path++;
	}
	if (keycode == 119
		&& (map->map[map->start_y - 1][map->start_x] != '1'))
	{
		map->map[map->start_y][map->start_x] = '0';
		map->map[map->start_y - 1][map->start_x] = 'P';
		map->path++;
	}
	if (keycode == 97 &&map->map[map->start_y][map->start_x - 1] != '1')
	{
		map->map[map->start_y][map->start_x] = '0';
		map->map[map->start_y][map->start_x - 1] = 'P';
		map->path++;
	}
}

int	move(int keycode, t_map *map)
{
	printf("Keycode: %d\n", keycode);
	if (map->map[map->start_y][map->start_x] == 'C')
	{
		map->map[map->start_y][map->start_x] = '0';
		map->count->vision++;
		map->count->count_c--;
	}
	ft_move_player(keycode, map);
	if (keycode == 100 && map->map[map->start_y + 1][map->start_x + 1] != '1')
	{
		map->map[map->start_y][map->start_x] = '0';
		map->map[map->start_y][map->start_x - 1] = 'P';
		map->path++;
	}
	if (keycode == 65307
		|| (map->map[map->start_y][map->start_x] && map->count->count_c <= 0))
		mlx_loop_end(map->game->mlx);
	ft_printf("count : %d\n", map->path);
	mlx_clear_window(map->game->mlx, map->game->window);
	ft_create_map(map);
	return (0);
}

int	ft_graph(t_map *map, t_verif *count)
{
	t_window_game	game;
	t_game_img		img;
	
	map->img = (t_game_img *)malloc(sizeof(t_game_img));
	map->game = (t_window_game *)malloc(sizeof(t_window_game));
	map->count = (t_verif *)malloc(sizeof(t_verif));
	map->game->mlx = mlx_init();
	map->path = 0;
	map->count->vision = 2;
	ft_init_img(map);
	map->game->window = mlx_new_window(map->game->mlx, 1980, 1080, "adventure_time");
	if (map->game->window == 0)
		return (0);
	if (ft_create_map(map) == 0)
		return (0);
	mlx_key_hook(map->game->window, move, map);
	mlx_loop(map->game->mlx);
	ft_clear_graph(map);
	return (1);
}
/*
for (int i = 0; i < map->map_y; i++)
    free(map->map[i]);
free(map->map);*/
