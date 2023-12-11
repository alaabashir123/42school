/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 13:43:55 by abashir           #+#    #+#             */
/*   Updated: 2023/07/19 12:08:57 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	sum;
	int		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = sign * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	sum = 0;
	while (ft_isdigit(str[i]) == 1)
	{
		if ((sum * 100 < sum) && sign == 1)
			return (-1);
		else if ((sum * 100 < sum) && sign == -1)
			return (0); 
		sum = sum * 10 + (str[i] - '0');
		i++;
	}
	return (sum * sign);
}
