/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:59:01 by abashir           #+#    #+#             */
/*   Updated: 2024/02/07 13:15:17 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contact
{
  public:
	Contact();
	~Contact();
	void SetContact();
	void _SetIndex(int index);
	void _SetFname(std::string fname);
	void _SetLname(std::string lname);
	void _SetNickname(std::string nickname);
	void _SetSecret(std::string secret);
	void _SetPhone(std::string phone);
	int _GetIndex(void);
	std::string _GetFname(void);
	std::string _GetLname(void);
	std::string _GetNickname(void);
	std::string _GetSecret(void);
	std::string _GetPhone(void);

  private:
	int _index;
	std::string _fname;
	std::string _lname;
	std::string _nickname;
	std::string _secret;
	std::string _phone;
};

std::string	checkInput(std::string message);
