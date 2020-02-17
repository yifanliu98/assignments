
#include <iostream>
using namespace std;

// class declaration
class BankAccount
{
public:
	// member bariables
	int accountNum;
	double balance;
	// member functions
	void deposit(double amount);//{balance = balance + amount;}
	void withdraw(double amount);//{balance = balance - amount;}
};

BankAccount do_sth()
{
	BankAccount acct;
	acct.balance = 20.5;
	acct.accountNum = 2312;
	return acct;
}

int main()
{
	BankAccount Leo;
	Leo.accountNum = 1234;
	Leo.balance = 1000;
	Leo.deposit(4000);
	cout << Leo.balance<<endl;
	
	Leo = do_sth();
	cout << Leo.balance << endl;





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

