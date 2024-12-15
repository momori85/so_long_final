/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaury <amaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:39:01 by amblanch          #+#    #+#             */
/*   Updated: 2024/12/15 19:17:59 by amaury           ###   ########.fr       */
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

char	**ft_so_long_map_create(char **tmp, int fd)
{
	int	i;

	i = 0;
	tmp[i] = get_next_line(fd);
	while (tmp[i++] != NULL)
		tmp[i] = get_next_line(fd);
	return (tmp);
}
