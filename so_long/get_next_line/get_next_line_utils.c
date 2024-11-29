/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:05:53 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/29 13:05:54 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i] != '\0' && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return (i + 1);
	return (-1);
}

char	*ft_strjoin_gnl(char *str, char *src, int len)
{
	int		i;
	int		j;
	char	*new;

	if (!str)
		return (str = ft_calloc(1, sizeof(char)));
	if (!src)
		return (str);
	new = ft_calloc((ft_strlen(str) + len + 1), sizeof(char));
	if (new == 0)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	while (src[j] && j < len)
	{
		new[i + j] = src[j];
		j++;
	}
	free(str);
	return (new);
}
