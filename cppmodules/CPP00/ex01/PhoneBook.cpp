/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:42 by abashir           #+#    #+#             */
/*   Updated: 2024/02/08 09:39:47 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::nbrContacts = 0;

PhoneBook::PhoneBook()
{
	std::cout << "Welcome to your PhoneBook" << std::endl;
}
PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook is destructed" << std::endl;
}

void PhoneBook::add()
{
	Contact	temp;

	temp.SetContact();
	this->conts[PhoneBook::nbrContacts % 8] = temp;
	this->conts[PhoneBook::nbrContacts % 8]._SetIndex(PhoneBook::nbrContacts
		% 8);
	PhoneBook::nbrContacts++;
}

void	printTrim(std::string input)
{
	int	j;
	int	len;

	j = 0;
	len = input.length();
	if (len > 10)
	{
		input.resize(10);
		input[input.size() - 1] = '.';
	}
	else
	{
		while (len < 10)
		{
			input.insert(0, " ");
			len++;
		}
	}
	std::cout << input;
}

void PhoneBook::print()
{
	int	i;

	std::string temp;
	i = 0;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (conts[i]._GetFname() != "" && i < 8)
	{
		std::cout << "|         " << this->conts[i]._GetIndex() << "|";
		printTrim(this->conts[i]._GetFname());
		std::cout << "|";
		printTrim(this->conts[i]._GetLname());
		std::cout << "|";
		printTrim(this->conts[i]._GetNickname());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
}

int PhoneBook::checkIndex(std::string message)
{
	int	i;
	int	index;

	std::string input;
	while (1)
	{
		i = 0;
		std::cout << message << std::endl;
		std::getline(std::cin, input);
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] == '\0')
		{
			std::cout << "Invalid Index" << std::endl;
			continue ;
		}
		if (isdigit(input[i]))
			i++;
		if (input[i] == '\0')
		{
			index = std::stoi(input);
			if (index < 0 || index > 7 || conts[index]._GetFname() == "")
			{
				std::cout << "Index out of range" << std::endl;
				continue ;
			}
			else
				return (index);
		}
	}
}

void PhoneBook::search()
{
	int	index;

	if (PhoneBook::nbrContacts == 0)
	{
		std::cout << "PhoneBook is empty" << std::endl;
		return ;
	}
	this->print();
	index = checkIndex("Enter an Index:");
	std::cout << "First Name: " << this->conts[index]._GetFname() << std::endl;
	std::cout << "Last Name: " << this->conts[index]._GetLname() << std::endl;
	std::cout << "NickName: " << this->conts[index]._GetNickname() << std::endl;
	std::cout << "Phone Number: " << this->conts[index]._GetPhone() << std::endl;
	std::cout << "Darkest Secret: " << this->conts[index]._GetSecret() << std::endl;
}
