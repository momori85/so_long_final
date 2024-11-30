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
	if (map->end_y >= 0 && map->end_y <= map->map_y && map->end_x >= 0 && map->end_x <= map->len) 
	{
		if (map->map[map->end_y][map->end_x] == '1')
			mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_wall, x, y);
		if (map->map[map->end_y][map->end_x] == '0')
			mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_path, x, y);
		if (map->map[map->end_y][map->end_x] == 'E')
			mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_exit, x, y);
		if (map->map[map->end_y][map->end_x] == 'P')
			mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_player, x, y);
		if (map->map[map->end_y][map->end_x] == 'C')
			mlx_put_image_to_window(map->game->mlx, map->game->window, map->img->img_c, x, y);
	}
}

int	ft_create_map(t_map *map)
{
	int x;
	int y;
	int len_max_x;
	int len_max_y;
	int tmp;
	int tmp_x;

	x = 1980 / 2 - 20 - (40 * map->count->vision);
	y = 1080 / 2 - 20 - (40 * map->count->vision);
	len_max_x = map->count->vision + map->start_x;
	len_max_y = map->count->vision + map->start_y;
	
	map->end_x = map->start_x - map->count->vision;
	map->end_y = map->start_y - map->count->vision;
	if (map->end_x < 0)
	{
		x += 40 * - map->end_x;
		map->end_x = 0;
	}
	if (map->end_y < 0)
	{
		y += 40 * - map->end_y;
		map->end_y = 0;
	}
	while (map->end_y <= map->map_y &&  map->end_y <= len_max_y)
	{
		tmp_x = x;
		tmp = map->end_x;
		while(map->end_x <= map->len && map->end_x <= len_max_x)
		{
			printf("%c", map->map[map->end_y][map->end_x]);
			ft_create_map_condition(map, x, y);
			map->end_x++;
			x += 40;
		}
		printf("\n");
		x = tmp_x;
		map->end_x = tmp;
		map->end_y++;
		y += 40;
	}
	printf("\n");
	return (1);
}

void verif_c(t_map *map)
{
	if (map->map[map->start_y][map->start_x] == 'C')
	{
		printf("salut");
		map->count->vision++;
		map->count->count_c--;
	}
}

void	ft_move_player(int keycode, t_map *map)
{
	printf("[%c]", map->map[map->bfs->next_y][map->bfs->next_x]);
	if (map->map[map->bfs->next_y][map->bfs->next_x] != 'E')
		map->map[map->bfs->next_y][map->bfs->next_x] == 'E';
	if (keycode == 115 && (map->map[map->start_y + 1][map->start_x] != '1'))
	{
		map->map[map->bfs->next_y][map->bfs->next_x] == 'E';
		map->start_y += 1;
		verif_c(map);
		map->map[map->start_y - 1][map->start_x] = '0';
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
	}
	if (keycode == 119 && (map->map[map->start_y - 1][map->start_x] != '1'))
	{
		map->map[map->bfs->next_y][map->bfs->next_x] == 'E';
		map->start_y -= 1;
		verif_c(map);
		map->map[map->start_y + 1][map->start_x] = '0';
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
	}
	if (keycode == 97 && map->map[map->start_y][map->start_x - 1] != '1')
	{
		map->map[map->bfs->next_y][map->bfs->next_x] == 'E';
		map->start_x -= 1;
		verif_c(map);
		map->map[map->start_y][map->start_x + 1] = '0';
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
	}
}

int	move(int keycode, t_map *map)
{
	printf("Keycode: %d\n", keycode);
	map->map[map->bfs->next_y][map->bfs->next_x] == 'E';
	ft_move_player(keycode, map);
	if (keycode == 100 && map->map[map->start_y][map->start_x + 1] != '1')
	{
		map->map[map->bfs->next_y][map->bfs->next_x] == 'E';
		map->start_x += 1;
		verif_c(map);
		map->map[map->start_y][map->start_x - 1] = '0';
		map->map[map->start_y][map->start_x] = 'P';
		map->path++;
	}
	if (keycode == 65307)
		mlx_loop_end(map->game->mlx);
	ft_printf("count : %d\n", map->path);
	mlx_clear_window(map->game->mlx, map->game->window);
	ft_create_map(map);
	return (0);
}

int	ft_graph(t_map *map, t_verif *count)
{	
	/*map->img = (t_game_img *)malloc(sizeof(t_game_img));
	map->game = (t_window_game *)malloc(sizeof(t_window_game));
	map->count = (t_verif *)malloc(sizeof(t_verif));*/
	
	map->img = (t_game_img *)ft_calloc(1, sizeof(t_game_img));
	if (!map->img)
    	return (0);
	map->game = (t_window_game *)ft_calloc(1, sizeof(t_window_game));
	if (!map->game)
    	return (0);
	map->bfs = (t_bfs *)ft_calloc(1, sizeof(t_bfs));
	if (!map->bfs)
    	return (0);
	map->count = (t_verif *)ft_calloc(1, sizeof(t_verif));
	if (!map->count)
    	return (0);
	memset(map->game, 0, sizeof(t_window_game));
	map->game->mlx = mlx_init();
	if (!map->game->mlx)
	{
    	fprintf(stderr, "Error: MLX initialization failed\n");
    	return (0);
	}
	//map->game->mlx = mlx_init();
	map->path = 0;
	map->count->vision = 2;
	map->bfs->next_x = map->end_x;
	map->bfs->next_y = map->end_y;
	printf("%d  %d\n", map->bfs->next_x, map->bfs->next_y);
	ft_init_img(map);
	map->game->window = mlx_new_window(map->game->mlx, 1980, 1080, "adventure_time");
	if (map->game->window == 0)
		return (0);
	if (ft_create_map(map) == 0)
		return (0);
	mlx_key_hook(map->game->window, move, map);
	mlx_loop(map->game->mlx);
	ft_clear_graph(map);
	free(map->img);
	free(map->count);
	free(map->game->mlx);
	free(map->game);
	free(map->bfs);
	return (1);
}
/*
for (int i = 0; i < map->map_y; i++)
    free(map->map[i]);
free(map->map);*/
