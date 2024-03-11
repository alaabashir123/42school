/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:57:57 by abashir           #+#    #+#             */
/*   Updated: 2024/02/14 15:45:01 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	meta->makeSound();
	delete meta;
	std::cout << std::endl;
	
	const Animal* i = new Cat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	delete i;
	std::cout << std::endl;
	
	const Animal* j = new Dog();
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	delete j;
	std::cout << std::endl;

    const WrongAnimal *wrong = new WrongAnimal();
    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
    wrong->makeSound();
    delete  wrong;
	std::cout << std::endl;

    const WrongAnimal *wrongCat = new WrongCat();
    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    delete  wrongCat;
	std::cout << std::endl;

}