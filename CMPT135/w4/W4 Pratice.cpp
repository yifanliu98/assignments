#include <iostream>
using namespace std;
class Money
{
private:
	int dollars;
	int cents;
public:
	Money();
	Money(double amount);
	Money(int d,int c);
	int getDollars() const;
	int getCents() const;
	double toDouble() const ;
	friend Money addUp(const Money& M1,const Money& M2);
	friend ostream& operator<< (ostream& dataRiver,const Money& amount);
};
Money::Money()
{
	dollars=0;
	cents=0;
}
Money::Money(double amount)
{
	dollars=static_cast<int>(amount);
	cents=int(100*(amount-dollars));
}
Money::Money(int d, int c)
{
	dollars=d+c/100;
	cents=c%100;
}
int Money::getCents() const
{
	return cents;
}
int Money::getDollars() const
{
	return dollars;
}
double Money::toDouble() const
{
	double amount = dollars + static_cast<double>(cents)/100.0;
	return amount;
}
Money addUp(const Money& M1,const Money& M2)
{
	int temp_dollars=M1.dollars+M2.dollars;
	int temp_cents=M1.cents+M2.cents;
	if(temp_cents>=100)
	{
		temp_cents -= 100;
		temp_dollars ++;
	}
	Money temp(temp_dollars,temp_cents);
	return temp;
}
ostream& operator<< (ostream& dataRiver,const Money& amount)
{
	dataRiver<<amount.toDouble();
	return dataRiver;
}


int main()
{
	Money M1(7,99), M2(0,225);
	cout<<"M1: "<<M1.getDollars()<<" dollars "<<M1.getCents()<<" cents\n";
	cout<<"M2: "<<M2.getDollars()<<" dollars "<<M2.getCents()<<" cents\n\n";

	double amount=M1.toDouble();
	cout<<"M1 amount: "<<amount<<endl;
	amount=M2.toDouble();
	cout<<"M2 amount: "<<amount<<endl<<endl;

	Money M3(amount),M4;
	cout<<"M3: "<<M3.getDollars()<<" dollars "<<M3.getCents()<<" cents\n";
	cout<<"M4: "<<M4.getDollars()<<" dollars "<<M4.getCents()<<" cents\n\n";

	M4=(addUp(M1,M3));
	cout<<"M4: "<<M4.getDollars()<<" dollars "<<M4.getCents()<<" cents\n";

	cout <<"M4: " << M4 << endl;
	
	system("PAUSE");
	return 0;
}


