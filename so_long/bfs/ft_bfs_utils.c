/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 09:16:11 by amblanch          #+#    #+#             */
/*   Updated: 2024/11/29 09:16:12 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_end_buf(t_bfs *buf)
{
	int	index;

	index = buf->tab[buf->front];
	buf->front = (buf->front + 1) % buf->capacity;
	if (buf->front < 0)
		buf->front += buf->capacity;
	return (index);
}

int	ft_start_buf(t_bfs *buf, int index)
{
	buf->tab[buf->last] = index;
	buf->last = (buf->last + 1) % buf->capacity;
	return (index);
}

void	ft_init_buf(t_bfs *buf, int capacity)
{
	buf->tab = (int *)malloc(sizeof(int) * capacity);
	buf->last = 0;
	buf->front = buf->last;
	buf->capacity = capacity;
}
