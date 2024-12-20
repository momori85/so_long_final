/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_create_bot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:23:54 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:24:08 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static int	ft_verif_bot_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

static void	ft_game_create_bot_one(t_map *map)
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

static void	ft_game_create_bot_two(t_map *map)
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

static void	ft_game_create_bot_three(t_map *map)
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
	map->bot->bot1_x = -1;
	map->bot->bot2_x = -1;
	map->bot->bot3_x = -1;
	if (ft_verif_bot_map(map) == 1)
		ft_game_create_bot_one(map);
	if (ft_verif_bot_map(map) == 1)
		ft_game_create_bot_two(map);
	if (ft_verif_bot_map(map) == 1)
		ft_game_create_bot_three(map);
}
