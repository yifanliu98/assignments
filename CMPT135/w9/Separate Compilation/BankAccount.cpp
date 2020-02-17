
// BankAccount implementation
#include "BankAcct.h"

BankAccount::BankAccount(int acctNumber, double initialBalance)
{
	acctNum = acctNumber;
	balance = initialBalance;
}

void BankAccount::deposit(double amount) 
{
	balance += amount;
}

void BankAccount::withdraw(double amount) 
{
	if (balance >= amount) 
		balance -= amount;
}

double BankAccount::getBalance()
{
	return balance;
}