
#include <iostream>
using namespace std;

// class declaration
class BankAccount
{
private:
	// member bariables
	int accountNum;
	double balance;

public:	
	// member functions
	
	// constructors
	BankAccount(int acctNum, double initBal);// parameterized constructor
	BankAccount();// default construtor



	void deposit(double amount);
	void withdraw(double amount);

/*
	void setBalance(double initBal){balance = initBal;}
	void setAcctNum(int initAcctNum){accountNum = initAcctNum;}
*/

	// getters/accessors
	double getBalance(){return balance;}

};

BankAccount::BankAccount (int acctNum,double initBal)
{

	accountNum = acctNum;
	balance = initBal;

}

int main()
{
	BankAccount Leo(1111,10.5);
	cout << Leo.getBalance()<<endl;
	
	Leo.deposit(4000);
	BankAccount Amber;// to call default constructor

	


	system("Pause");
	return 0;
}

void BankAccount::deposit(double amount)
{
	balance = balance + amount;
}

void BankAccount::withdraw(double amount)
{
	balance = balance - amount;
}

