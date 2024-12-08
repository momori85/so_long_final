/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_img_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:51 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/07 14:58:43 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_init_wall_one(t_map *map, int len)
{
	map->img_wall->solo_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_down.xpm", &len, &len);
	map->img_wall->solo_top = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_top.xpm", &len, &len);
	map->img_wall->top_left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_left.xpm", &len, &len);
	map->img_wall->top_midle = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_midle.xpm", &len, &len);
	map->img_wall->top_right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_right.xpm", &len, &len);
	map->img_wall->top_and_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/top_and_down.xpm", &len, &len);
	map->img_wall->solo_left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_left.xpm", &len, &len);
	map->img_wall->solo_right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo_right.xpm", &len, &len);
	map->img_wall->water = mlx_xpm_file_to_image(
			map->game->mlx, ".img/water/water.xpm", &len, &len);
}

void	ft_init_wall(t_map *map, int len)
{
	map->img_wall->front_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/front_down.xpm", &len, &len);
	map->img_wall->left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/left.xpm", &len, &len);
	map->img_wall->left_and_right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/left_and_right.xpm", &len, &len);
	map->img_wall->left_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/left_down.xpm", &len, &len);
	map->img_wall->midle = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/midle.xpm", &len, &len);
	map->img_wall->midle_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/midle_down.xpm", &len, &len);
	map->img_wall->right = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/right.xpm", &len, &len);
	map->img_wall->right_down = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/right_down.xpm", &len, &len);
	map->img_wall->solo = mlx_xpm_file_to_image(
			map->game->mlx, ".img/wall/solo.xpm", &len, &len);
}

void	ft_init_img_path(t_map *map, int len)
{
	map->img->img_path = mlx_xpm_file_to_image(
			map->game->mlx, ".img/path/full.xpm", &len, &len);
}

void	ft_init_img_screen(t_map *map, int len)
{
	map->img->img_left = mlx_xpm_file_to_image(
			map->game->mlx, ".img/left_game.xpm", &len, &len);
	map->img->img_settings = mlx_xpm_file_to_image(
			map->game->mlx, ".img/settings_screen.xpm", &len, &len);
	map->img->img_game = mlx_xpm_file_to_image(
			map->game->mlx, ".img/start_screen.xpm", &len, &len);
	map->img->img_480 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/480p.xpm", &len, &len);
	map->img->img_720 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/720p.xpm", &len, &len);
	map->img->img_1080 = mlx_xpm_file_to_image(
			map->game->mlx, ".img/1080p.xpm", &len, &len);
	map->img->img_exit_settings = mlx_xpm_file_to_image(
			map->game->mlx, ".img/settings_exit.xpm", &len, &len);
}

void	ft_init_img(t_map *map)
{
	int		len;

	len = 64;
	map->img->img_c = mlx_xpm_file_to_image(
			map->game->mlx, ".img/c.xpm", &len, &len);
	map->img->img_exit = mlx_xpm_file_to_image(
			map->game->mlx, ".img/exit.xpm", &len, &len);
	map->img->img_player = mlx_xpm_file_to_image(
			map->game->mlx, ".img/player.xpm", &len, &len);
	map->img->bot = mlx_xpm_file_to_image(
			map->game->mlx, ".img/goblin.xpm", &len, &len);
	map->img->fog = mlx_xpm_file_to_image(
			map->game->mlx, ".img/fog.xpm", &len, &len);
	ft_init_img_path(map, len);
	ft_init_wall_one(map, len);
	ft_init_wall(map, len);
	ft_init_img_screen(map, len);
}
