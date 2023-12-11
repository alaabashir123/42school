/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:57:01 by abashir           #+#    #+#             */
/*   Updated: 2023/08/07 10:12:16 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_str(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		i = write(1, "(null)", 6);
	else
		i = write(1, s, ft_strlen(s));
	return (i);
}
