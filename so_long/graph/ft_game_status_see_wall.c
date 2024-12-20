/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_status_see_wall.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:13:13 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:27:05 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static int	ft_see_map_wall_one(t_map *map)
{
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y + 1][map->end_x] == '1'
			&& map->map[map->end_y][map->end_x + 1] == '1'
				&& map->map[map->end_y][map->end_x - 1] == '1'
					&& map->map[map->end_y][map->end_x] == '1')
		return (0);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y + 1][map->end_x] == '1'
			&& map->map[map->end_y][map->end_x - 1] == '1'
				&& map->map[map->end_y][map->end_x] == '1')
		return (1);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x + 1] == '1'
			&& map->map[map->end_y][map->end_x - 1] == '1'
				&& map->map[map->end_y][map->end_x] == '1')
		return (2);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x + 1] == '1'
			&& map->map[map->end_y + 1][map->end_x] == '1'
				&& map->map[map->end_y][map->end_x] == '1')
		return (3);
	return (-1);
}

static int	ft_see_map_wall_two(t_map *map)
{
	if (map->map[map->end_y + 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x + 1] == '1'
			&& map->map[map->end_y][map->end_x - 1] == '1'
				&& map->map[map->end_y][map->end_x] == '1')
		return (4);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x + 1] == '1'
			&& map->map[map->end_y][map->end_x] == '1')
		return (5);
	if (map->map[map->end_y + 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x + 1] == '1'
			&& map->map[map->end_y][map->end_x] == '1')
		return (6);
	return (-1);
}

static int	ft_see_map_wall_three(t_map *map)
{
	if (map->map[map->end_y + 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x - 1] == '1'
			&& map->map[map->end_y][map->end_x] == '1')
		return (7);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x - 1] == '1'
			&& map->map[map->end_y][map->end_x] == '1')
		return (8);
	if (map->map[map->end_y][map->end_x - 1] == '1'
		&& map->map[map->end_y][map->end_x + 1] == '1'
			&& map->map[map->end_y][map->end_x] == '1')
		return (9);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y + 1][map->end_x] == '1'
			&& map->map[map->end_y][map->end_x] == '1')
		return (10);
	if (map->map[map->end_y - 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x] == '1')
		return (11);
	return (-1);
}

static int	ft_see_map_wall_four(t_map *map)
{
	if (map->map[map->end_y][map->end_x + 1] == '1'
		&& map->map[map->end_y][map->end_x] == '1')
		return (12);
	if (map->map[map->end_y + 1][map->end_x] == '1'
		&& map->map[map->end_y][map->end_x] == '1')
		return (13);
	if (map->map[map->end_y][map->end_x - 1] == '1'
		&& map->map[map->end_y][map->end_x] == '1')
		return (14);
	if (map->map[map->end_y][map->end_x] == '1')
		return (15);
	return (-1);
}

int	ft_see_map_wall(t_map *map)
{
	int	i;

	i = ft_see_map_wall_one(map);
	if (i < 0)
		i = ft_see_map_wall_two(map);
	if (i < 0)
		i = ft_see_map_wall_three(map);
	if (i < 0)
		i = ft_see_map_wall_four(map);
	return (i);
}
