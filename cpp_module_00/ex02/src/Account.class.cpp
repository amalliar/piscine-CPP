/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:27:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/04/20 20:27:57 by amalliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.class.hpp"

int				Account::_nbAccounts = 0;
int				Account::_totalAmount = 0;
int				Account::_totalNbDeposits = 0;
int				Account::_totalNbWithdrawals = 0;

void			Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void			Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:";
	if (deposit <= 0)
	{
		std::cout << "refused" << std::endl;
		return ;
	}
	std::cout << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool			Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal <= 0 || withdrawal >= this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int				Account::checkAmount(void) const
{
	const_cast<Account *>(this)->_nbCheckAmountCalls += 1;
	return (this->_amount);
}

int				Account::getNbCheckAmountCalls(void) const
{
	return (this->_nbCheckAmountCalls);
}

				Account::Account(int initial_deposit) :
				_amount(initial_deposit),
				_nbDeposits(0),
				_nbWithdrawals(0),
				_nbCheckAmountCalls(0)
{
	if (initial_deposit < 0)
		this->_amount = 0;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	Account::_totalAmount += this->_amount;
}

				Account::~Account(void)
{
	Account::_nbAccounts -= 1;
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void			Account::displayAccountsInfos(void)
{
	time_t		rawtime;
	struct tm 	*timeinfo;
  	char 		buffer[32];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 32, "[%Y%m%d_%H%M%S]",timeinfo);
	std::cout << buffer;
	std::cout << " ";
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

int				Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int				Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int				Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

int				Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

void			Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm 	*timeinfo;
  	char 		buffer[32];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 32, "[%Y%m%d_%H%M%S]",timeinfo);
	std::cout << buffer;
}

				Account::Account(void) :
				_amount(0),
				_nbDeposits(0),
				_nbWithdrawals(0),
				_nbCheckAmountCalls(0)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	this->_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}
