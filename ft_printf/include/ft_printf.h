/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:39:49 by abashir           #+#    #+#             */
/*   Updated: 2023/08/07 10:14:40 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_nbr_len(long n);
int		ft_printf_x(unsigned int c, char x, int *count);
int		ft_printf_p(uintptr_t c, int *count, int *f);
int		ft_printf(const char	*str, ...);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(long n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_printf_str(char *s);
int		ft_printf_dec(int n);
int		ft_printf_int(unsigned int j);
void	ft_check_param(char str, int *count, va_list args);

#endif