/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:39:01 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/28 12:39:05 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **tab, t_map *map)
{
	int	i;

	i = 0;
	(void)map;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

char	**ft_so_long_map_create(t_map *map, int fd)
{
	int	i;

	i = 0;
	map->map[i] = get_next_line(fd);
	while (map->map[i++] != NULL)
		map->map[i] = get_next_line(fd);
	return (map->map);
}
