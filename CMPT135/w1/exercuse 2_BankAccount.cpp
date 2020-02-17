#include <iostream>
using namespace std;

class BankAccount
{
public:
	double accountNum;
	double balance;

	void deposit(double amount);
	void withdraw(double amount);
};


int main ()
{
	BankAccount Leo;
	Leo.accountNum = 1234;
	Leo.balance = 1000;
	Leo.deposit(4000);
	cout << Leo.balance<<endl;
	
	
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