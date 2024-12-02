/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:39:11 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/29 12:39:17 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRAPH_H
# define FT_GRAPH_H

# include "../so_long.h"

int	ft_graph(t_map *map);
void	ft_init_img(t_map *map);
void	ft_clear_graph(t_map *map);
int ft_init_settings_sreen(void);
int ft_init_game_sreen(t_map *map);

#endif
