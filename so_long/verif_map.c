/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 08:46:24 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 13:46:24 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_verif_c_p_e(t_map *map, t_verif *vars, int x, int y)
{
	if (map->map[y][x] == 'E')
	{
		map->end_x = x;
		map->end_y = y;
		vars->count_e++;
	}
	if (map->map[y][x] == 'P')
	{
		map->start_x = x;
		map->start_y = y;
		vars->count_p++;
	}
	if (map->map[y][x] == 'C')
		vars->count_c++;
}

static int	ft_verif_map_p3(t_map *map, t_verif *vars, int x, int y)
{
	ft_verif_c_p_e(map, vars, x, y);
	if (map->map[y][x] != 'E' && map->map[y][x] != 'P' &&
			map->map[y][x] != 'C' && map->map[y][x] != '1' &&
					map->map[y][x] != '0' && map->map[y][x]
						!= '\0' && map->map[y][x] != '\n')
		return (0);
	return (1);
}

static int	ft_verif_map_p2(t_map *map, t_verif *vars, int max)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map->map[++y])
	{
		if (map->map[y][0] != '1')
			return (0);
		if (map->map[y][max] != '1')
			return (0);
		if (map->map[y][max + 1] == '\n')
			map->map[y][max + 1] = '\0';
		while (map->map[y][x++])
		{
			if (map->map[y][0] == '\n')
				break ;
			if (ft_verif_map_p3(map, vars, x, y) == 0)
				return (0);
		}
		x = 0;
	}
	return (y);
}

static int	ft_map_max(t_map *map)
{
	int	max;

	max = 0;
	while (map->map[0][max])
	{
		if (map->map[0][max] == '\n' && max >= 3)
		{
			map->map[0][max] = '\0';
			return (max - 1);
		}
		if (map->map[0][max] != '1')
			return (0);
		max++;
	}
	return (0);
}

int	ft_verif_map(t_map *map, t_verif *vars)
{
	int		y;
	int		x;

	vars->count_p = 0;
	vars->count_e = 0;
	vars->count_c = 0;
	map->len = ft_map_max(map);
	if (map->len == 0)
		return (0);
	y = ft_verif_map_p2(map, vars, map->len);
	if (y == 0)
		return (0);
	x = 0;
	while (map->map[y - 1][x++] && x < map->len)
	{
		if (map->map[y - 1][x] != '1')
			return (0);
	}
	map->map_y = y - 1;
	map->count_c = vars->count_c;
	return (vars->count_e == 1 && vars->count_p == 1 && vars->count_c >= 1);
}
