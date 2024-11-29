/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:19:07 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/11 11:19:09 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_init_img(t_map *map)
{
	int		taille;

	taille = 40;
	map->img->img_wall = mlx_xpm_file_to_image(
			map->game->mlx, ".img/test.xpm", &taille, &taille);
	map->img->img_path = mlx_xpm_file_to_image(
		map->game->mlx, ".img/path.xpm", &taille, &taille);
	map->img->img_c = mlx_xpm_file_to_image(
			map->game->mlx, ".img/c.xpm", &taille, &taille);
	map->img->img_start = mlx_xpm_file_to_image(
			map->game->mlx, ".img/d.xpm", &taille, &taille);
	map->img->img_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/exit.xpm", &taille, &taille);
	map->img->img_player = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player.xpm", &taille, &taille);
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
