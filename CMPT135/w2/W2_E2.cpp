#include<iostream>
#include<ctime>
using namespace std;

class Fraction
{
private:

	int numerator;
	int denominator;

public:

	Fraction();
	Fraction(int d);
	Fraction(int n,int d);
	void output();
	bool equal(Fraction num);
	void simplify();
};

Fraction::Fraction()
{
	numerator = 0;
	denominator = 1;
}
Fraction::Fraction(int d)
{
	numerator = 1;
	denominator = d;
}
Fraction::Fraction(int n,int d)
{
	numerator = n;
	denominator = d;
}
void Fraction::output()
{
	cout << numerator << "/" << denominator << endl;
}
bool Fraction::equal(Fraction num)
{
	simplify();
	num.simplify();
	if (numerator == num.numerator && denominator == num.denominator)
	{
		return true;
	}
	else 
		return false;
}
void Fraction::simplify()
{
	int temp = numerator;
	if (numerator>denominator)
		temp = denominator;
	for (int i = temp;i>0;i--)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator = numerator / i;
			denominator = denominator / i;
			break;
		}
	}
}

class Die
{
public:
    Die();
    int roll();
    int getFaceValue();
	void setFaceValue(int value);
	int getFaceDown(){return 7-faceValue;}
private:
    int faceValue;
};

int Die::roll()
{
	faceValue = rand() % 6 + 1;
	return faceValue;
}
Die::Die()
{
	faceValue = 1;
}
void Die::setFaceValue(int value)
{
	while(value >= 1 && value <= 6)
	{
		faceValue = value;
	}
}
int Die::getFaceValue()
{
	return faceValue;
}

class PairOfDice
{
private:
	Die die1;
	Die die2;

public:
	void roll();
	int sum();
};

void PairOfDice::roll()
{
	die1.roll();
    die2.roll();
}
int PairOfDice::sum()
{
	int sum=die1.getFaceValue()+die2.getFaceValue();
	return sum;
}




int main()
{

	// Q1

	Fraction num1(3),num2(6),num3,num4;
	num3=Fraction(4,12);
	num4=Fraction(2,12);

	cout<<"num1 is ";
	num1.output();
	cout<<"num2 is ";
	num2.output();
	cout<<"num3 is ";
	num3.output();
	cout<<"num4 is ";
	num4.output();

	if (num1.equal(num2))
		cout << "num1 and num2 are equal!" << endl;

	num3.simplify();
	cout << "After simplifying, num3 is ";
	num3.output();

	if(num2.equal(num4))
		cout << "num2 and num4 are equal!" << endl;
	
	Fraction a(24,36);
	a.output();
	a.simplify();
	a.output();


	// Q2
	srand(time(0));
	int n;
	cout<<"Enter a positive integer: ";
	cin>>n;
	PairOfDice* arr=new PairOfDice[n];
	int i=0;
	int biggest=0;
	do
	{
		arr[i].roll();
		if (arr[i].sum()>biggest)
			biggest=arr[i].sum();
		i++;
	}while(i!=n);
	cout<<biggest<<endl;
	
	system("PAUSE");
	return 0;
}