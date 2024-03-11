/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:23:47 by abashir           #+#    #+#             */
/*   Updated: 2024/02/07 17:02:59 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
  private:
	Contact conts[8];
	int	checkIndex(std::string message);

  public:
	static int nbrContacts;
	PhoneBook();
	~PhoneBook();
	void add();
	void search();
	void print();
};
void	printTrim(std::string input);