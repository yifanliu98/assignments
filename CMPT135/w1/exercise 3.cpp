#include <iostream>
using namespace std;

class Temperature
{
public:
	void set (double newDegrees,char newScale);
	double degrees; 
	char scale;
};

void Temperature::set(double newDegrees,char newScale)
{
	degrees = newDegrees;
	scale = newScale;

}


struct ShoeType
{
	char style; 
	double price;

};

ShoeType discount (ShoeType oldRecord)
{
	ShoeType newRecord;
	newRecord.style = oldRecord.style;
	newRecord.price = oldRecord.price * 0.9;
	return newRecord;
}




int main()
{




	system("pause");
	return 0;
}