
#include "BankAcct.h"
#include <iostream>
using namespace std;

int main()
{
	BankAccount joe(1234, 100);
	joe.deposit(55);
	joe.withdraw(150);
	cout << joe.getBalance() << endl;

	system("pause");
	return 0;
}
