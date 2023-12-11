/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:58:40 by abashir           #+#    #+#             */
/*   Updated: 2023/08/07 10:16:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_p(uintptr_t c, int *count, int *flag)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 16)
	{
		if (*flag == 0)
		{
			*count += ft_printf_str("0x");
			*flag = 1;
		}
		*count = *count + 1;
		write(1, &hex[c], 1);
	}
	else
	{
		ft_printf_p(c / 16, count, flag);
		ft_printf_p(c % 16, count, flag);
	}
	return (*count);
}
