/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:58:43 by abashir           #+#    #+#             */
/*   Updated: 2023/07/23 17:12:26 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_int(unsigned int j)
{
	int	i;

	i = 0;
	i = ft_nbr_len(j);
	ft_putnbr_fd(j, 1);
	return (i);
}
