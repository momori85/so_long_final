/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_save.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:03:33 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:28:36 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_save_atoi(t_map *map)
{
	map->start_x = ft_atoi(map->save->save[map->save->len++]);
	map->start_y = ft_atoi(map->save->save[map->save->len++]);
	map->bot->bot1_x = ft_atoi(map->save->save[map->save->len++]);
	map->bot->bot1_y = ft_atoi(map->save->save[map->save->len++]);
	map->bot->bot2_x = ft_atoi(map->save->save[map->save->len++]);
	map->bot->bot2_y = ft_atoi(map->save->save[map->save->len++]);
	map->bot->bot3_x = ft_atoi(map->save->save[map->save->len++]);
	map->bot->bot3_y = ft_atoi(map->save->save[map->save->len++]);
	map->path = ft_atoi(map->save->save[map->save->len++]);
	map->count->vision = ft_atoi(map->save->save[map->save->len++]);
	map->len = ft_atoi(map->save->save[map->save->len++]);
	map->map_y = ft_atoi(map->save->save[map->save->len++]);
	map->count_c = ft_atoi(map->save->save[map->save->len++]);
	map->save->verif = 1;
}

int	ft_init_save(t_map *map, char *name)
{
	int	i;

	i = 0;
	map->save->len = 0;
	map->save->save = ft_so_long(name);
	if (map->save->save != NULL)
	{
		while (map->save->save[i][0] != '*')
			i++;
		map->save->save_map = ft_calloc(i + 1, sizeof(char *));
		while (map->save->len < i)
		{
			map->save->save_map[map->save->len]
				= ft_strdup(map->save->save[map->save->len]);
			map->save->len++;
		}
		map->save->save_map[map->save->len] = NULL;
		map->save->len++;
		ft_save_atoi(map);
		return (1);
	}
	return (0);
}

static void	ft_game_status_save_move(int keycode, t_map *map)
{
	if (keycode == 119 && map->i > 1)
		map->i--;
	if (keycode == 115 && map->i < 4)
		map->i++;
	if (map->i == 1)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->save_one, 0, 0);
	if (map->i == 2)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->save_two, 0, 0);
	if (map->i == 3)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->save_tree, 0, 0);
	if (map->i == 4)
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->save_exit, 0, 0);
}

static void	ft_game_save_remove(t_map *map)
{
	int	fd;

	if (map->i == 1)
	{
		fd = open("save_one.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		map->save->file_one = 0;
		close(fd);
	}
	if (map->i == 2)
	{
		fd = open("save_two.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		map->save->file_two = 0;
		close(fd);
	}
	if (map->i == 3)
	{
		fd = open("save_three.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		map->save->file_one = 0;
		close(fd);
	}
}

void	ft_game_status_save(int keycode, t_map *map)
{
	if (map->game_status == 6)
	{
		if (keycode == 65535)
			ft_game_save_remove(map);
		ft_game_status_save_move(keycode, map);
		ft_game_status_save_full_or_empty(map);
		if (keycode == 65307)
			mlx_loop_end(map->game->mlx);
		if (keycode == 65293 && (map->i == 1 || map->i == 2
				|| map->i == 3 || map->i == 4))
			ft_game_menu_save_move(map);
		if (map->i == -1)
			map->i = 1;
	}
}
