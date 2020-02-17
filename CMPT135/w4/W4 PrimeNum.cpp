#include <iostream>
using namespace std;

class PrimeNum
{
private:
	int prime;
public:
	PrimeNum(){prime = 2;}
	PrimeNum(int num);
	int getPrime(){return prime;}
	void setPrime(int num){prime=num;}
	void output(){cout<<prime<<endl;}
	
	//PrimeNum operator ++ ();
    //PrimeNum operator -- ();
	
	friend void operator << (ostream& dataRiver,const PrimeNum& pn);
	
	
	friend PrimeNum operator ++ (PrimeNum& pn);
	friend PrimeNum operator -- (PrimeNum& pn);
	

};

PrimeNum::PrimeNum(int num)
{
	prime = num;
}

/*
PrimeNum PrimeNum::operator++()
{
	for (int i=prime+1;true;i++)
	{
		int count=0,j=2;
		for (j=2;j<i;j++)
			if (i%j==0)
			{
				count++;
				break;
			}
		if (count==0)
		{
			prime=j;
			return j;
		}
	}
}
PrimeNum PrimeNum::operator--()
{
	if (prime<=2)
	{
		cout<<"No prime smaller! "<<endl;
		return 2;
	}
	for (int i=prime-1; true; i--)
	{
		int count = 0,j=2; 
		for (j=2;j<i;j++)
			if (i % j == 0)
			{
				count++;
				break;
			}
		if (count==0)
		{
			prime=j;
			return j;
		}
	}
}

*/

PrimeNum operator ++ (PrimeNum& pn)
{
	for (int i=pn.getPrime()+1;true;i++)
	{
		int count=0,j=2;
		for (j=2;j<i;j++)
		{
			if (i%j==0)
			{
				count++;
				break;
			}
		}
		if (count==0)
		{
			pn.setPrime(j);
			return j;
		}
	}
}
PrimeNum operator--(PrimeNum& pn)
{
	if (pn.getPrime()<=2)
		cout<<"No prime smaller! "<<endl;
	for (int i=pn.getPrime()-1;i>2;i--)
	{
		int count=0,j=2;
		for (j=2;j<i;j++)
		{
			if (i%j==0)
			{
				count++;
				break;
			}
		}
		if (count==0)
		{
			pn.setPrime(j);
			return j;
		}
	}
}



void operator << (ostream& dataRiver, const PrimeNum& pn)
{
	cout<<pn.prime<<endl;
}

int main()
{

	PrimeNum temp(5);
	cout<<++temp;
	cout<<temp;
	cout<<++++temp;
	cout<<temp;



	system("PAUSE");
	return 0;
}