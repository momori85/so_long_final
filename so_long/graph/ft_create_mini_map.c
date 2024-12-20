/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mini_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:04:34 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/18 10:23:44 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_create_mini_map_to_window(t_map *map, int y, int i, int j)
{
	if (map->mini_map[i][j] == 'B')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_mini_bot, map->x, y);
	if (map->mini_map[i][j] == '1' || map->mini_map[i][j] == 'W')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_mini_wall, map->x, y);
	if (map->mini_map[i][j] == '0')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_mini_path, map->x, y);
	if (map->mini_map[i][j] == 'P')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_mini_player, map->x, y);
	if (map->mini_map[i][j] == 'C' || map->mini_map[i][j] == 'E')
		mlx_put_image_to_window(map->game->mlx, map->game->window,
			map->img->img_mini_player, map->x, y);
}

void	ft_create_mini_map(t_map *map)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	j = 0;
	y = 300;
	if (map->screen_x != 1980)
		return ;
	while (map->mini_map[i] && i <= map->map_y && y < 600)
	{
		map->x = 30;
		while (map->mini_map[i][j] && j <= map->len && map->x < 600)
		{
			ft_create_mini_map_to_window(map, y, i, j);
			j++;
			map->x += 8;
		}
		j = 0;
		y += 8;
		i++;
	}
}
