/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 15:27:24 by amalliar          #+#    #+#             */
/*   Updated: 2021/05/06 23:13:44 by amalliar         ###   ########.fr       */
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
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void			Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:";
	if (deposit <= 0)
	{
		std::cout << "refused" << std::endl;
		return ;
	}
	std::cout << deposit << ";";
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool			Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal <= 0 || withdrawal >= _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";";
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int				Account::checkAmount(void) const
{
	const_cast<Account *>(this)->_nbCheckAmountCalls += 1;
	return (_amount);
}

int				Account::getNbCheckAmountCalls(void) const
{
	return (_nbCheckAmountCalls);
}

				Account::Account(int initial_deposit) :
				_amount(initial_deposit),
				_nbDeposits(0),
				_nbWithdrawals(0),
				_nbCheckAmountCalls(0)
{
	if (initial_deposit < 0)
		_amount = 0;
	_accountIndex = Account::_nbAccounts;
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts += 1;
	Account::_totalAmount += _amount;
}

				Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= _amount;
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
	_accountIndex = Account::_nbAccounts;
	_displayTimestamp();
	std::cout << " ";
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts += 1;
}
