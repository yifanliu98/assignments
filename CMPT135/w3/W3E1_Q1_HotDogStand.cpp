// CMPT135 J.Ye

// Week 2 Exercise 1 question 3

// hotdogs.cpp
// This program defines a class for tracking hot dog sales.

#include <iostream>
#include <cstdlib>
using namespace std;

class HotDogStand
{
public:
	HotDogStand();

	HotDogStand(int newID);
	// This constructor initializes the ID and initializes the number of hot dogs sold to be 0.

	int getID();
	// Returns the ID number of this stand.

	int getNumSold();
	// returns the number of hot dogs this stand has sold.

	void justSold();
	// Increments the number of hotdogs this stand has sold by one.

	static int getTotalNum();

private:

	int numSold;
	int ID;
	static int totalNum;

};

int HotDogStand::totalNum = 0;

int HotDogStand::getTotalNum()
{
	
	return totalNum;

}
HotDogStand::HotDogStand()
{
	numSold = 0;
	ID = 0;
}


HotDogStand::HotDogStand(int newID)
{
	numSold = 0;
	ID = newID;
}


int HotDogStand::getID()
{
	return ID;
}


void HotDogStand::justSold()
{
	numSold++;	// increment number sold at this stand
	totalNum++;
}


int HotDogStand::getNumSold()
{
	return numSold;
}



int main()
{
  // Test our code with three hot dog stands
  HotDogStand s1(1),s2(2),s3(3);

  // Sold at stand 1, 2
  s1.justSold();
  s2.justSold();
  s1.justSold();

  cout << "Stand " << s1.getID() << " sold " << s1.getNumSold() << endl;
  cout << "Stand " << s2.getID() << " sold " << s2.getNumSold() << endl;
  cout << "Stand " << s3.getID() << " sold " << s3.getNumSold() << endl;
  cout << endl;

  // Sold some more
  s3.justSold();
  s1.justSold();

  cout << "Stand " << s1.getID() << " sold " << s1.getNumSold() << endl;
  cout << "Stand " << s2.getID() << " sold " << s2.getNumSold() << endl;
  cout << "Stand " << s3.getID() << " sold " << s3.getNumSold() << endl;
  cout << endl;

  cout << "Total number sold " << HotDogStand::getTotalNum() << endl;

  system("pause");
  return 0;
}

