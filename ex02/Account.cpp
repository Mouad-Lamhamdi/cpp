#include "Account.hpp"

// Initialize static member variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// --PRIVATE STATIC HELPER FUNCTION--
void Account::_displayTimestamp(void){

	std::time_t raw_time = std::time(0);
	std::tm *time_info = std::localtime(&raw_time);

	std::cout << "[" << (time_info->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << (time_info->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << time_info->tm_mday

			  << "_"

			  << std::setfill('0') << std::setw(2) << time_info->tm_hour
			  << std::setfill('0') << std::setw(2) << time_info->tm_min
			  << std::setfill('0') << std::setw(2) << time_info->tm_sec

			  << "] ";
}

//getters

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

//-------CONSTRUCTOR-------

Account::Account(int initial_deposit)
{
	//1.set all individual (non-static) members for this new object
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	//2.Update static (class-wide) members
	_nbAccounts++;
	_totalAmount += initial_deposit;

	//3.print the log message
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _totalAmount
			  << ";created" << std::endl;
}

//-------DESTRUCTOR-------
Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount;

	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		p_amount = _amount;
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals += 1;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << _amount
				  << ";nb_withdrawals:" << _nbWithdrawals
				  << std::endl;
		return true;
	}
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}

int Account::checkAmount(void) const
{
    return _amount;
}