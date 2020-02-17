
// This is the header file BankAccount.h. This is the interface for the class BankAccount

#ifndef BANKACCT_H
#define BANKACCT_H

class BankAccount
{
public:
	BankAccount(int, double);
	void deposit(double);
	void withdraw(double);
	double getBalance();

private:
	int acctNum;
	double balance;
};

#endif