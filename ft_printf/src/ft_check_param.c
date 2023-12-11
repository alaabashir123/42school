/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:00:35 by abashir           #+#    #+#             */
/*   Updated: 2023/07/23 17:49:43 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_check_param(char str, int *count, va_list args)
{
	int	flag;

	flag = 0;
	if (str == 'c')
		*count += ft_putchar_fd(va_arg(args, int), 1);
	else if (str == 's')
		*count += ft_printf_str(va_arg(args, char *));
	else if (str == 'x' || str == 'X')
		ft_printf_x(va_arg(args, unsigned int), str, count);
	else if (str == 'p')
		ft_printf_p(va_arg(args, uintptr_t), count, &flag);
	else if (str == 'd' || str == 'i')
		*count = *count + ft_printf_dec(va_arg(args, int));
	else if (str == 'u')
		*count = *count + ft_printf_int(va_arg(args, unsigned int));
	else if (str == '%')
		*count = *count + ft_putchar_fd('%', 1);
}
