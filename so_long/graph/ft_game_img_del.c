/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_img_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:59 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/07 14:59:56 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void	ft_del_wall(t_map *map)
{
	mlx_destroy_image(map->game->mlx, map->img_wall->front_down);
	mlx_destroy_image(map->game->mlx, map->img_wall->left);
	mlx_destroy_image(map->game->mlx, map->img_wall->left_and_right);
	mlx_destroy_image(map->game->mlx, map->img_wall->left_down);
	mlx_destroy_image(map->game->mlx, map->img_wall->midle);
	mlx_destroy_image(map->game->mlx, map->img_wall->midle_down);
	mlx_destroy_image(map->game->mlx, map->img_wall->right);
	mlx_destroy_image(map->game->mlx, map->img_wall->right_down);
	mlx_destroy_image(map->game->mlx, map->img_wall->solo);
	mlx_destroy_image(map->game->mlx, map->img_wall->solo_down);
	mlx_destroy_image(map->game->mlx, map->img_wall->solo_top);
	mlx_destroy_image(map->game->mlx, map->img_wall->top_left);
	mlx_destroy_image(map->game->mlx, map->img_wall->top_midle);
	mlx_destroy_image(map->game->mlx, map->img_wall->top_right);
	mlx_destroy_image(map->game->mlx, map->img_wall->top_and_down);
	mlx_destroy_image(map->game->mlx, map->img_wall->solo_right);
	mlx_destroy_image(map->game->mlx, map->img_wall->solo_left);
	mlx_destroy_image(map->game->mlx, map->img_wall->water);
}

void	ft_clear_screen(t_map *map)
{
	mlx_destroy_image(map->game->mlx, map->img->img_game);
	mlx_destroy_image(map->game->mlx, map->img->img_settings);
	mlx_destroy_image(map->game->mlx, map->img->img_left);
	mlx_destroy_image(map->game->mlx, map->img->img_480);
	mlx_destroy_image(map->game->mlx, map->img->img_720);
	mlx_destroy_image(map->game->mlx, map->img->img_1080);
	mlx_destroy_image(map->game->mlx, map->img->img_exit_settings);
	mlx_destroy_image(map->game->mlx, map->img->img_player);
	mlx_destroy_image(map->game->mlx, map->img->img_path);
	mlx_destroy_image(map->game->mlx, map->img->img_c);
	mlx_destroy_image(map->game->mlx, map->img->img_exit);
	mlx_destroy_image(map->game->mlx, map->img->bot);
	mlx_destroy_image(map->game->mlx, map->img->fog);
}

void	ft_clear_graph(t_map *map)
{
	ft_del_wall(map);
	ft_clear_screen(map);
	mlx_clear_window(map->game->mlx, map->game->window);
	mlx_destroy_window(map->game->mlx, map->game->window);
	mlx_destroy_display(map->game->mlx);
	free(map->img);
	free(map->count);
	free(map->game->mlx);
	free(map->game);
	free(map->bfs);
	free(map->img_wall);
	free(map->bot);
}
