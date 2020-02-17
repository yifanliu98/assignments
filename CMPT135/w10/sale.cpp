// testing virtual functions
// Display 15.9, 15.10, 15.11, 15.12 combined
#include <iostream>
using namespace std;

class Sale
{
public:
	Sale();
	Sale(double the_price);
	virtual double bill() const;
	/*double bill() const;*/
	double savings(const Sale& other) const;
protected:
	double price;
};

bool operator < (const Sale& first, const Sale& second);

class DiscountSale : public Sale
{
public:
	DiscountSale();
	DiscountSale(double the_price, double the_discount);
	//Discount is expressed as a percent of the price.
	double bill() const;
protected:
	double discount;
};

Sale::Sale() : price(0) {cout << "Base default\n";}

Sale::Sale(double the_price) : price(the_price) {cout << "Base constructor\n";}

double Sale::bill() const { cout << "Base bill\n"; return price; }

double Sale::savings(const Sale& other) const
{	cout << "Base savings\n";
	return ( bill() - other.bill() );
}

bool operator < (const Sale& first, const Sale& second)
{
	cout << "now ... " << endl;
	cout << first.bill() << endl ;
	cout << second.bill() << endl;
	return (first.bill() < second.bill());
}

DiscountSale::DiscountSale() : Sale(), discount(0) {cout << "derived default\n";}

DiscountSale::DiscountSale(double the_price, double the_discount) 
	: Sale(the_price), discount(the_discount)
{cout << "derived constructor\n";}

double DiscountSale::bill() const
{
	cout << "derived bill\n";
	double fraction = discount/100;
	return (1 - fraction)*price;
}

int main()
{
	Sale simple(10.00);//One item at $10.00.
	DiscountSale discount(11.00, 10);//One item at $11.00 with a 10% discount.

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	if (discount < simple)
	{
		cout << "Discounted item is cheaper.\n";
		cout << "Savings is $" << simple.savings(discount) << endl;
	}
	else
		cout << "Discounted item is not cheaper.\n";
	
	system("pause");
	return 0;
}
