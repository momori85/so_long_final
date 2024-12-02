/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:19:07 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/02 20:36:24 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_init_img(t_map *map)
{
	int		len;

	len = 40;
	map->img->img_wall = mlx_xpm_file_to_image(
			map->game->mlx, ".img/test.xpm", &len, &len);
	map->img->img_path = mlx_xpm_file_to_image(
		map->game->mlx, ".img/path.xpm", &len, &len);
	map->img->img_c = mlx_xpm_file_to_image(
			map->game->mlx, ".img/c.xpm", &len, &len);
	map->img->img_start = mlx_xpm_file_to_image(
			map->game->mlx, ".img/d.xpm", &len, &len);
	map->img->img_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/exit.xpm", &len, &len);
	map->img->img_player = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player.xpm", &len, &len);
	map->img->img_left = mlx_xpm_file_to_image(map->game->mlx, ".img/left_game.xpm", &len, &len);
	map->img->img_settings = mlx_xpm_file_to_image(map->game->mlx, ".img/settings_screen.xpm", &len, &len);
	map->img->img_game = mlx_xpm_file_to_image(map->game->mlx, ".img/start_screen.xpm", &len, &len);
	map->img->img_480 = mlx_xpm_file_to_image(map->game->mlx, ".img/480p.xpm", &len, &len);
	map->img->img_720 = mlx_xpm_file_to_image(map->game->mlx, ".img/720p.xpm", &len, &len);
	map->img->img_1080 = mlx_xpm_file_to_image(map->game->mlx, ".img/1080p.xpm", &len, &len);
	map->img->img_exit_settings = mlx_xpm_file_to_image(map->game->mlx, ".img/settings_exit.xpm", &len, &len);
}

void	ft_clear_graph(t_map *map)
{
	mlx_destroy_image(map->game->mlx, map->img->img_player);
	mlx_destroy_image(map->game->mlx, map->img->img_path);
	mlx_destroy_image(map->game->mlx, map->img->img_c);
	mlx_destroy_image(map->game->mlx, map->img->img_wall);
	mlx_destroy_image(map->game->mlx, map->img->img_start);
	mlx_destroy_image(map->game->mlx, map->img->img_exit);
	mlx_clear_window(map->game->mlx, map->game->window);
	mlx_destroy_window(map->game->mlx, map->game->window);
	mlx_destroy_display(map->game->mlx);
}
