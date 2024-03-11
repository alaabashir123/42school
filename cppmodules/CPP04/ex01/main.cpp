/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:57:57 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 16:30:04 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
	
	Animal* array[4];
	for (int i = 0; i < 2; i++)
		array[i] = new Cat();
	for (int i = 2; i < 4; i++)
		array[i] = new Dog();
    Dog* copiedDog = new Dog(*dynamic_cast<Dog*>(array[3]));
	for (int i = 0; i < 4; i++)
		delete array[i];
	copiedDog->makeSound();
	delete copiedDog;
}