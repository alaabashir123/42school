/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:15:27 by abashir           #+#    #+#             */
/*   Updated: 2024/04/17 12:22:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	size_t size = 4;
	int array[] = {1, 2, 3, 4};
	iter(array, size, f);

	std::string array_string[] = {"a", "b", "c", "d"};
	iter(array_string, size, f);
}