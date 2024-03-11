/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:52:14 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/31 15:52:17 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (size >= SIZE_MAX || size * count >= INT_MAX)
		return (NULL);
	if ((int)count < 0 || (int)size < 0)
		return (NULL);
	new = (char *)malloc(size * count);
	if (new == NULL)
		return (NULL);
	while (i < count * size)
	{
		new[i] = 0;
		i++;
	}
	return (new);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_str(const char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		{
			while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
				i++;
			if (str[i] != '\0')
				return (error_exit(6, NULL), 1);
		}
		else
			return (error_exit(6, NULL), 1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long long	ft_atol(const char *str)
{
	long long	result;
	int			nagetive;

	result = 0;
	nagetive = 1;
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && *str)
		str++;
	if (ft_strncmp(str, "-9223372036854775808", 21) == 0)
		return (error_exit(6, NULL), -1);
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			return (error_exit(6, NULL), -1);
	}
	while (*str && ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	if (check_str(str))
		return (-1);
	if (result > INT_MAX || result < 0)
		return (error_exit(6, NULL), -1);
	return (result * nagetive);
}
