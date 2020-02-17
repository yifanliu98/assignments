// CMPT135 J. Ye

// Fraction VERSION 2
// 1) simplify function is still a public member function that will change this Fraction object
// 2) two "equal" functions are included: one is a member function, the other is a friend function

// This is the soltion to Week 3 Exercise 1 Question 2 -- adding a friend function to Version 1 Fraction class

// This is also the starting file of Week 3 Exercise 2.


#include <iostream>
using namespace std;

class Fraction
{
public:
	Fraction();
	Fraction(int d);
	Fraction(int n, int d);
	void simplify(); // this function may change the object
	void output();

	bool equal(Fraction f); // // this function may change the object
friend bool equal(Fraction f1, Fraction f2);

private:
	int numerator;
	int denominator;
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

void Fraction::simplify()
{
	int gcd = 1;
	int divisor = (numerator <= denominator) ? numerator : denominator;
	while(divisor > 0){	// Try to find the greatest common divisor of numerator and denominator.
				// Euclidean algorithm is more efficient. But this one is easier to understand.
		if(numerator % divisor == 0 && denominator % divisor == 0){
			gcd = divisor;
			break; // At this point, the while loop must stop.
		}
		else
			divisor--;
	}
	numerator /= gcd;	// The function "simplify" possibly changes this Fraction object!!
	denominator /= gcd;
}

bool Fraction::equal(Fraction f)
{
	simplify(); // Note: "simplify" function possibly changes the object.
	f.simplify();
	return numerator == f.numerator && denominator == f.denominator;
}

bool equal(Fraction f1, Fraction f2) // equal function
{
	f1.simplify();	// Note: "simplify" function possibly changes the object.
	f2.simplify();
	return f1.numerator == f2.numerator && f1.denominator == f2.denominator;
}

void Fraction::output()
{
	cout << numerator << "/" << denominator << endl;
}


int main(){
	Fraction num1(3), num2(6), num3, num4;
	num3 = Fraction(4,12);
	num4 = Fraction(2,12);

	cout << "num1 is ";
	num1.output();
	cout << "num2 is ";
	num2.output();
	cout << "num3 is ";
	num3.output();
	cout << "num4 is ";
	num4.output();

	if (num1.equal(num2))
		cout << "num1 and num2 are equal!" << endl;

	num3.simplify();
	cout << "After simplifying, num3 is ";
	num3.output();

	if(num2.equal(num4))	// calling the member function equal
		cout << "num2 and num4 are equal!" << endl;

	if (equal(num2, num4))  // calling the friend function equal
		cout << "num2 and num4 are equal!" << endl;

	system("pause");
	return 0;
}