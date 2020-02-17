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

	void output();

    friend bool operator== (const Fraction& f1,const Fraction& f2);
	friend Fraction operator+ (const Fraction& num1, const Fraction& num2);
	friend ostream& operator<< (ostream& River, const Fraction& num);




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
	while(divisor > 0){	// Try to find the greatest common divisor of numerator and denominator.
				// Euclidean algorithm is more efficient. But this one is easier to understand.
		if(numerator % divisor == 0 && denominator % divisor == 0){
			gcd = divisor;
			break; // At this point, the while loop must stop.
		}
		else
			divisor--;
	}
	Fraction temp(numerator/gcd,denominator/gcd);
	return temp;
	//numerator /= gcd;	// The function "simplify" possibly changes this Fraction object!!
	//denominator /= gcd;
}



bool operator== (const Fraction& f1,const Fraction& f2)// equal function
{
	Fraction A1=f1.simplify();	// Note: "simplify" function possibly changes the object.
	Fraction A2=f2.simplify();
	return A1.numerator == A2.numerator && A1.denominator == A2.denominator;
}


Fraction operator+ (const Fraction& num1, const Fraction& num2)
{
	Fraction newF1(num2.denominator * num1.numerator, num1.denominator * num2.denominator);
	Fraction newF2(num1.denominator * num2.numerator, num2.denominator * num1.denominator);
	Fraction sumF(newF1.numerator + newF2.numerator, newF1.denominator);
	return sumF.simplify();

}

void Fraction::output()
{
	cout << numerator << "/" << denominator << endl;
}

ostream& operator<< (ostream& dataRiver, const Fraction& num)
{
	dataRiver << num.numerator << "/" << num.denominator;
	return dataRiver;
}






int main()
{
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

	if (num1 == num2)
		cout << "num1 and num2 are equal!" << endl;

	if(num1 == num3)	// calling the member function equal
		cout << "num1 and num3 are equal!" << endl;
	if (num2 == num4)  // calling the friend function equal
		cout << "num2 and num4 are equal!" << endl;

	cout << "The sum of num1 and num3 is "; 
	(num1+num3).output();
	cout << "The sum of num2 and num4 is "; 
	(num2+num4).output();
	
	cout<<num2<<endl;
	cout<<5;
	system("pause");
	return 0;
}