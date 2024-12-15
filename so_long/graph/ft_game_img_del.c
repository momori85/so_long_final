/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_img_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:41:59 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/15 19:21:07 by amaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

static void	ft_del_wall(t_map *map)
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
	mlx_destroy_image(map->game->mlx, map->img_wall->water_one);
	mlx_destroy_image(map->game->mlx, map->img_wall->water_two);
	mlx_destroy_image(map->game->mlx, map->img_wall->water_tree);
}

static void	ft_clear_screen(t_map *map)
{
	mlx_destroy_image(map->game->mlx, map->img->img_game);
	mlx_destroy_image(map->game->mlx, map->img->img_game_save);
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
	mlx_destroy_image(map->game->mlx, map->img->fog_two);
	mlx_destroy_image(map->game->mlx, map->img->fog_tree);
	mlx_destroy_image(map->game->mlx, map->img->died);
	mlx_destroy_image(map->game->mlx, map->img->gold_count);
	mlx_destroy_image(map->game->mlx, map->img->save_exit);
	mlx_destroy_image(map->game->mlx, map->img->save_one);
	mlx_destroy_image(map->game->mlx, map->img->save_two);
	mlx_destroy_image(map->game->mlx, map->img->save_tree);
}

static void	ft_clear_player(t_map *map)
{
	mlx_destroy_image(map->game->mlx, map->player->player_frame_1);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_2);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_3);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_4);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_5);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_6);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_7);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_8);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_9);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_10);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_11);
	mlx_destroy_image(map->game->mlx, map->player->player_frame_12);
	mlx_destroy_image(map->game->mlx, map->img->img_mini_player);
	mlx_destroy_image(map->game->mlx, map->img->img_mini_wall);
	mlx_destroy_image(map->game->mlx, map->img->img_mini_path);
	mlx_destroy_image(map->game->mlx, map->img->img_mini_bot);
	mlx_destroy_image(map->game->mlx, map->img->img_save);
	mlx_destroy_image(map->game->mlx, map->img->img_save_exit);
	mlx_destroy_image(map->game->mlx, map->img->img_resume);
}

void	ft_clear_graph(t_map *map)
{
	ft_del_wall(map);
	ft_clear_screen(map);
	ft_clear_player(map);
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
	free(map->player);
	free(map->save);
}
