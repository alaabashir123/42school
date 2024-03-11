/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:59:35 by abashir           #+#    #+#             */
/*   Updated: 2024/02/08 09:21:44 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->_fname = "";
	this->_lname = "";
	this->_index = 0;
	this->_nickname = "";
	this->_secret = "";
	this->_phone = "";
}
Contact::~Contact()
{
}

void Contact::_SetIndex(int index)
{
	this->_index = index;
}
void Contact::_SetFname(std::string fname)
{
	this->_fname = fname;
}

void Contact::_SetLname(std::string lname)
{
	this->_lname = lname;
}

void Contact::_SetNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::_SetSecret(std::string secret)
{
	this->_secret = secret;
}

void Contact::_SetPhone(std::string phone)
{
	this->_phone = phone;
}

int Contact::_GetIndex(void)
{
	return (this->_index);
}
std::string Contact::_GetFname(void)
{
	return (this->_fname);
}
std::string Contact::_GetLname(void)
{
	return (this->_lname);
}
std::string Contact::_GetNickname(void)
{
	return (this->_nickname);
}
std::string Contact::_GetSecret(void)
{
	return (this->_secret);
}

std::string Contact::_GetPhone(void)
{
	return (this->_phone);
}

void Contact::SetContact()
{
	this->_SetFname(checkInput("Enter First Name: "));
	this->_SetLname(checkInput("Enter Last Name: "));
	this->_SetNickname(checkInput("Enter NickName: "));
	this->_SetPhone(checkInput("Enter Phone Number: "));
	this->_SetSecret(checkInput("Enter Darkest Secret: "));
}

std::string checkInput(std::string message)
{
	int	i;

	std::string input;
	while (1)
	{
		i = 0;
		std::cout << message << std::endl;
		std::getline(std::cin, input);
		while (input[i] == ' ' || input[i] == '\t')
			i++;
		if (input[i] != '\0')
			break ;
	}
	return (input);
}
