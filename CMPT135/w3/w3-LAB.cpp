// CMPT135 J. Ye

// Fraction VERSION 4:
// 1) operator + , operator == are overloaded as friend functions for this class
//    They can also be defined as member operators. (How to do it?) 
//    However, do not include both the member version and non-member version at the same time
// 2) main testing code is changed correspondingly
// 3) insertion operator (<<) is also overloaded for this class

// Please answer the questions at the end.


#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction();
	Fraction(int d);
	Fraction(int n, int d);
	Fraction operator * (const Fraction& num);



	friend bool operator == (const Fraction&, const Fraction&);
	friend Fraction operator + (const Fraction& num1, const Fraction& num2);
	friend ostream& operator << (ostream& outs, const Fraction& num);
	friend Fraction operator * (const Fraction& num1, const Fraction& num2);
	

private:
	int numerator;
	int denominator;

	Fraction simplify() const;
};

Fraction::Fraction()
{
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int d)
{
	numerator = 1;
	denominator = d;
}

Fraction::Fraction(int n, int d)
{
	numerator = n;
	denominator = d;
}

Fraction Fraction::simplify() const
{
	int gcd = 1;
	int divisor = (numerator <= denominator) ? numerator : denominator;
	while(divisor > 0){
		if(numerator % divisor == 0 && denominator % divisor == 0){
			gcd = divisor;
			break;
		}
		else
			divisor--;
	}
	int newNum = numerator / gcd;
	int newDen = denominator / gcd;
	return Fraction(newNum, newDen);
}

Fraction Fraction::operator * (const Fraction& num)
{
	int newNum = numerator * num.numerator;
	int newDen = denominator * num.denominator;
	Fraction newFra (newNum,newDen);
	return newFra.simplify();

}

bool operator == (const Fraction& num1, const Fraction& num2)
{
	Fraction n1 = num1.simplify();
	Fraction n2 = num2.simplify();
	return n1.numerator == n2.numerator && n1.denominator == n2.denominator;
}

Fraction operator + (const Fraction& num1, const Fraction& num2)
{
	int denom = num1.denominator * num2.denominator;
	int numer = num1.numerator * num2.denominator + num2.numerator * num1.denominator;
	return Fraction(numer, denom);
}

ostream& operator << (ostream& outs, const Fraction& num)
{
	outs << num.numerator << "/" << num.denominator << endl;
	return outs;
}

Fraction operator * (const Fraction& num1, const Fraction& num2)
{
	int newNum = num1.numerator * num2.numerator;
	int newDen = num1.denominator * num2.denominator;
	Fraction newFra(newNum,newDen);
	return newFra.simplify();
}


int main(){
	Fraction num1(3), num2(6), num3, num4;
	num3 = Fraction(4,12);
	num4 = Fraction(2,12);

	// Fraction objects are directly "inserted" into cout, then go to the screen
	cout << "num1 is " << num1;
	cout << "num2 is " << num2;
	cout << "num3 is " << num3;
	cout << "num4 is " << num4;

	if (num1 == num2)
		cout << "num1 and num2 are equal!" << endl;

	if(num1 == num3)
		cout << "num1 and num3 are equal!" << endl;

	if(num2 == num4)
		cout << "num2 and num4 are equal!" << endl;

	cout << "\n=============  Testing add functions  =============\n\n";

	Fraction sum = num2 + num4;
	if (sum == num1)
		cout << "sum and num1 are equal!" << endl;

	Fraction sum2 = num2 + num4;
	if (sum2 == num1)
		cout << "sum2 and num1 are equal!" << endl;

	Fraction base(1, 10), total;
	total = base + 2;  // How does this statement work? 
	cout << total;	   // The overloaded << operator makes this statement pretty neat!


	cout << (num1 * num2); // * by member function
	Fraction temp = num1 * num2; // * by friend function
	cout  << temp;


	
	system("pause");
	return 0;
}