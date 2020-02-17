#include <iostream>
using namespace std;

class PrimeNumber
{
public:
	PrimeNumber(){prime=2;}
	PrimeNumber(int num){prime=num;}
	int getPrime () const {return prime;}
	PrimeNumber operator ++ ();
	PrimeNumber operator -- ();

	friend void operator << (ostream& x, const PrimeNumber& p);

private:
	int prime;

};


PrimeNumber PrimeNumber::operator++()
{
	for (int i=prime+1; true; i++)
	{
		int count = 0; 
		for (int j=2;j<i;j++)
		{
			if (i % j == 0)
			{
				count++;
				break;
			}
		}
		if (count==0)
			return i;
	}

}

PrimeNumber PrimeNumber::operator--()
{
	for (int i=prime-1; true; i--)
	{
		int count = 0; 
		for (int j=2;j<i;j++)
		{
			if (i % j == 0)
			{
				count++;
				break;
			}
		}
		if (count==0)
		{
			
			return i;
		}
	}
}

void operator << (ostream& x, const PrimeNumber& p)
{
	x << p.getPrime() << endl;
}

int main ()
{
	PrimeNumber p(13);
	PrimeNumber pn= ++p;
	cout<<pn;
	cout<<++(++pn);
	cout<<pn;

	system ("PAUSE");
	return 0;
}




