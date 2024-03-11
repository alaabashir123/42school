/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:12:50 by abashir           #+#    #+#             */
/*   Updated: 2024/02/08 09:45:49 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
Account::Account(int initial_deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_nbAccounts << ";";
	std::cout << "amount:" << initial_deposit << ";created" << std::endl;
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";closed" << std::endl;
}
int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
int Account::checkAmount(void) const
{
	return (_amount);
}
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t currentTime = std::time(nullptr);
	std::tm *localTime = std::localtime(&currentTime);

	int year = localTime->tm_year + 1900;
	int month = localTime->tm_mon + 1;
	int day = localTime->tm_mday;
	int hour = localTime->tm_hour;
	int minute = localTime->tm_min;
	int second = localTime->tm_sec;

	std::cout << "[";
	std::cout.fill('0');
	std::cout << year;
	std::cout.width(2);
	std::cout << month;
	std::cout.width(2);
	std::cout << day;
	std::cout << "_";
	std::cout.width(2);
	std::cout << hour;
	std::cout.width(2);
	std::cout << minute;
	std::cout.width(2);
	std::cout << second;
	std::cout << "] ";
}