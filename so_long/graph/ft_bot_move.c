/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bot_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:38:09 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/10 17:38:10 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_map_seed_zero(t_map *map)
{
	if (map->bot->bot1_x != -1)
	{
		if (map->map[map->bot->bot1_y][map->bot->bot1_x + 1] == '0')
		{
			map->map[map->bot->bot1_y][map->bot->bot1_x + 1] = 'B';
			map->map[map->bot->bot1_y][map->bot->bot1_x] = '0';
			map->bot->bot1_x++;
		}
	}
}

void	ft_map_seed_one(t_map *map)
{
	if (map->bot->bot3_x != -1)
	{
		if (map->map[map->bot->bot3_y][map->bot->bot3_x - 1] == '0')
		{
			map->map[map->bot->bot3_y][map->bot->bot3_x - 1] = 'B';
			map->map[map->bot->bot3_y][map->bot->bot3_x] = '0';
			map->bot->bot3_x--;
		}
	}
}

void	ft_map_seed_two(t_map *map)
{
	if (map->bot->bot1_x != -1)
	{
		if (map->map[map->bot->bot1_y + 1][map->bot->bot1_x] == '0')
		{
			map->map[map->bot->bot1_y + 1][map->bot->bot1_x] = 'B';
			map->map[map->bot->bot1_y][map->bot->bot1_x] = '0';
			map->bot->bot1_y++;
		}
	}
}

void	ft_map_seed_tree(t_map *map)
{
	if (map->bot->bot3_x != -1)
	{
		if (map->map[map->bot->bot3_y - 1][map->bot->bot3_x] == '0')
		{
			map->map[map->bot->bot3_y - 1][map->bot->bot3_x] = 'B';
			map->map[map->bot->bot3_y][map->bot->bot3_x] = '0';
			map->bot->bot3_y--;
		}
	}
}
