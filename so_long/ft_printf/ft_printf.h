/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:34:26 by amblanch          #+#    #+#             */
/*   Updated: 2024/10/16 15:34:27 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

int		ft_putchar_printf(int c);
int		ft_printf(const char *s, ...);
int		ft_itoa_printf(int n);
int		ft_putstr_printf(char *s);
int		ft_itoa_long(unsigned int n);
int		ft_putnbr_base(unsigned long long nbr, char *base, int count);
int		ft_putnbr_base_p(uintptr_t nbr, char *base, int is_rec);

#endif
