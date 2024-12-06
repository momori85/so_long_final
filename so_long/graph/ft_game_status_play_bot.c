/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_play_bot.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:01:46 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/06 09:01:47 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_game_status_seed_zero(t_map *map, int seed)
{
	if (seed == 0)
	{
		if (map->map[map->bot->bot1_y][map->bot->bot1_x + 1] == '0')
		{
			map->map[map->bot->bot1_y][map->bot->bot1_x + 1] = 'B';
			map->map[map->bot->bot1_y][map->bot->bot1_x] = '0';
			map->bot->bot1_x++;
		}
		if (map->map[map->bot->bot2_y][map->bot->bot2_x + 1] == '0')
		{
			map->map[map->bot->bot2_y][map->bot->bot2_x + 1] = 'B';
			map->map[map->bot->bot2_y][map->bot->bot2_x] = '0';
			map->bot->bot2_x++;
		}
		if (map->map[map->bot->bot3_y][map->bot->bot3_x + 1] == '0')
		{
			map->map[map->bot->bot3_y][map->bot->bot3_x + 1] = 'B';
			map->map[map->bot->bot3_y][map->bot->bot3_x] = '0';
			map->bot->bot3_x++;
		}
	}
}

void	ft_game_status_seed_one(t_map *map, int seed)
{
	if (seed == 1)
	{
		if (map->map[map->bot->bot1_y][map->bot->bot1_x - 1] == '0')
		{
			map->map[map->bot->bot1_y][map->bot->bot1_x - 1] = 'B';
			map->map[map->bot->bot1_y][map->bot->bot1_x] = '0';
			map->bot->bot1_x--;
		}
		if (map->map[map->bot->bot2_y][map->bot->bot2_x - 1] == '0')
		{
			map->map[map->bot->bot2_y][map->bot->bot2_x - 1] = 'B';
			map->map[map->bot->bot2_y][map->bot->bot2_x] = '0';
			map->bot->bot2_x--;
		}
		if (map->map[map->bot->bot3_y][map->bot->bot3_x - 1] == '0')
		{
			map->map[map->bot->bot3_y][map->bot->bot3_x - 1] = 'B';
			map->map[map->bot->bot3_y][map->bot->bot3_x] = '0';
			map->bot->bot3_x--;
		}
	}
}

void	ft_game_status_seed_two(t_map *map, int seed)
{
	if (seed == 2)
	{
		if (map->map[map->bot->bot1_y + 1][map->bot->bot1_x] == '0')
		{
			map->map[map->bot->bot1_y + 1][map->bot->bot1_x] = 'B';
			map->map[map->bot->bot1_y][map->bot->bot1_x] = '0';
			map->bot->bot1_y++;
		}
		if (map->map[map->bot->bot2_y + 1][map->bot->bot2_x] == '0')
		{
			map->map[map->bot->bot2_y + 1][map->bot->bot2_x] = 'B';
			map->map[map->bot->bot2_y][map->bot->bot2_x] = '0';
			map->bot->bot2_y++;
		}
		if (map->map[map->bot->bot3_y + 1][map->bot->bot3_x] == '0')
		{
			map->map[map->bot->bot3_y + 1][map->bot->bot3_x] = 'B';
			map->map[map->bot->bot3_y][map->bot->bot3_x] = '0';
			map->bot->bot3_y++;
		}
	}
}

void	ft_game_status_seed_tree(t_map *map, int seed)
{
	if (seed == 3)
	{
		if (map->map[map->bot->bot1_y - 1][map->bot->bot1_x] == '0')
		{
			map->map[map->bot->bot1_y - 1][map->bot->bot1_x] = 'B';
			map->map[map->bot->bot1_y][map->bot->bot1_x] = '0';
			map->bot->bot1_y--;
		}
		if (map->map[map->bot->bot2_y - 1][map->bot->bot2_x] == '0')
		{
			map->map[map->bot->bot2_y - 1][map->bot->bot2_x] = 'B';
			map->map[map->bot->bot2_y][map->bot->bot2_x] = '0';
			map->bot->bot2_y--;
		}
		if (map->map[map->bot->bot3_y - 1][map->bot->bot3_x] == '0')
		{
			map->map[map->bot->bot3_y - 1][map->bot->bot3_x] = 'B';
			map->map[map->bot->bot3_y][map->bot->bot3_x] = '0';
			map->bot->bot3_y--;
		}
	}
}

void	ft_game_status_play_bot(t_map *map, int keycode)
{
	int	seed;

	if (keycode == 100 || keycode == 115 || keycode == 97 || keycode == 119)
	{
		simple_hash(map);
		seed = map->adress % 4;
		ft_game_status_seed_zero(map, seed);
		ft_game_status_seed_one(map, seed);
		ft_game_status_seed_two(map, seed);
		ft_game_status_seed_tree(map, seed);
	}
}
