/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_create_bot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:23:54 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/06 11:23:57 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_game_create_bot_one(t_map *map)
{
	int	x;
	int	y;

	x = map->adress % map->len;
	y = map->adress % map->map_y;
	while (map->map[y][x] != '0')
	{
		simple_hash(map);
		x = map->adress % map->len;
		simple_hash(map);
		y = map->adress % map->map_y;
	}
	map->bot->bot1_x = x;
	map->bot->bot1_y = y;
	map->map[y][x] = 'B';
}

void	ft_game_create_bot_two(t_map *map)
{
	int	x;
	int	y;

	x = map->adress % map->len;
	y = map->adress % map->map_y;
	while (map->map[y][x] != '0')
	{
		simple_hash(map);
		x = map->adress % map->len;
		simple_hash(map);
		y = map->adress % map->map_y;
	}
	map->bot->bot2_x = x;
	map->bot->bot2_y = y;
	map->map[y][x] = 'B';
}

void	ft_game_create_bot_tree(t_map *map)
{
	int	x;
	int	y;

	x = map->adress % map->len;
	y = map->adress % map->map_y;
	while (map->map[y][x] != '0')
	{
		simple_hash(map);
		x = map->adress % map->len;
		simple_hash(map);
		y = map->adress % map->map_y;
	}
	map->bot->bot3_x = x;
	map->bot->bot3_y = y;
	map->map[y][x] = 'B';
}

void	ft_game_create_bot(t_map *map)
{
	ft_game_create_bot_one(map);
	ft_game_create_bot_two(map);
	ft_game_create_bot_tree(map);
}
