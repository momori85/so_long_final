/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:19:07 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/15 19:13:25 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

int	ft_putnbr_base_ten(t_map *map, char *base, unsigned long result)
{
	while (map->adress >= 10)
	{
		map->adress = map->adress / 10;
		result = result * 10 + base[map->adress % 10];
	}
	return (result);
}

t_map	*simple_hash(t_map *map)
{
	map->adress ^= (map->adress << 13);
	map->adress ^= (map->adress >> 17);
	map->adress ^= (map->adress << 5);
	return (map);
}

void	ft_random(t_map *map)
{
	void	*adress;

	adress = malloc(1);
	if (adress == NULL)
		return ;
	map->adress = (unsigned long)adress;
	map->adress = ft_putnbr_base_ten(simple_hash(map), "0123456789abcdef", 0);
	free(adress);
}

void	ft_fill(t_map *map, int x, int y)
{
	if (x > map->len || x < 0 || y > map->map_y || y < 0
		|| map->map[y][x] == 'W' || map->map[y][x] == '0'
					|| map->map[y][x] == 'C' || map->map[y][x] == 'E'
							|| map->map[y][x] == 'P')
		return ;
	else
		map->map[y][x] = 'W';
	ft_fill(map, x + 1, y);
	ft_fill(map, x - 1, y);
	ft_fill(map, x, y + 1);
	ft_fill(map, x, y - 1);
	return ;
}

int	ft_game_malloc_list(t_map *map)
{
	map->img = (t_game_img *)ft_calloc(1, sizeof(t_game_img));
	if (!map->img)
		return (0);
	map->bot = (t_bot *)ft_calloc(1, sizeof(t_bot));
	if (!map->bot)
		return (0);
	map->img_wall = (t_img_wall *)ft_calloc(1, sizeof(t_img_wall));
	if (!map->img_wall)
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
	map->player = (t_img_player *)ft_calloc(1, sizeof(t_img_player));
	if (!map->player)
		return (0);
	map->save = (t_save *)ft_calloc(1, sizeof(t_save));
	if (!map->save)
		return (0);
	memset(map->game, 0, sizeof(t_window_game));
	return (1);
}
