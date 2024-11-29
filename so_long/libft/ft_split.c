/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:11:18 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/14 13:11:19 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(int count_free, char **str)
{
	while (count_free + 1 > 0)
	{
		free(str[count_free]);
		count_free--;
	}
	free(str);
}

static char	**ft_string_new(size_t count, char const *s, char **str, char c)
{
	size_t	count_free;
	size_t	count_len;
	size_t	start;

	count_free = 0;
	count_len = 0;
	start = 0;
	while (count--)
	{
		start = start + count_len;
		count_len = 0;
		while (s[start] == c && s[start])
			start++;
		while (s[start + count_len] != c && s[start + count_len] != '\0')
			count_len++;
		str[count_free] = ft_substr(s, start, count_len);
		if (str[count_free] == 0)
		{
			ft_free(count_free, str);
			return (0);
		}
		count_free++;
	}
	return (str);
}

static int	ft_count_word(char const *s, char c, size_t i, size_t count)
{
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	count;

	if (s == 0)
		return (0);
	if (ft_strlen(s) == 0)
		return (ft_calloc(1, sizeof(char *)));
	count = ft_count_word(s, c, 0, 0);
	if (count == 0)
		return (ft_calloc(1, sizeof(char *)));
	str = ft_calloc(count + 1, sizeof(char *));
	if (str == 0)
		return (0);
	str = ft_string_new(count, s, str, c);
	return (str);
}
