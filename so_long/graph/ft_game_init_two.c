/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:33:52 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/10 16:33:53 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_init_img_path(t_map *map, int len)
{
	map->img->img_path = mlx_xpm_file_to_image(
			map->game->mlx, ".img/path/full.xpm", &len, &len);
	map->img->img_mini_path = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_path.xpm", &len, &len);
	map->img->img_mini_bot = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_bot.xpm", &len, &len);
	map->img->img_mini_wall = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_wall.xpm", &len, &len);
	map->img->img_mini_player = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/mini_player.xpm", &len, &len);
	map->img->img_save = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/save.xpm", &len, &len);
	map->img->img_save_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/save_exit.xpm", &len, &len);
	map->img->img_resume = mlx_xpm_file_to_image(
			map->game->mlx, ".img/mini_map/resume.xpm", &len, &len);
}
