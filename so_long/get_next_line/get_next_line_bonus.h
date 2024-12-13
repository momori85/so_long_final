/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:05:43 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/29 13:05:45 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

char	*get_next_line(int fd);
char	*ft_invalid(char *line, int bytesread);
void	free_buffer(char **buf, int fd);
int		ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *str, char *src, int len);

#endif
