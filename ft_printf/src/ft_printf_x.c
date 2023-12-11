/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:58:40 by abashir           #+#    #+#             */
/*   Updated: 2023/07/23 17:49:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_x(unsigned int c, char x, int *count)
{
	char	*hex;

	if (x == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (c < 16)
	{
		*count = *count + 1;
		write(1, &hex[c], 1);
	}
	else
	{
		ft_printf_x(c / 16, x, count);
		ft_printf_x(c % 16, x, count);
	}
	return (*count);
}
