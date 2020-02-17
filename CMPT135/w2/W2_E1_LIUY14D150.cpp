#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
 
class HotDogStand
{
private:

	int id_num;
	int sold_num;

public:
	HotDogStand ();
	HotDogStand (int id);
	void justSold (int amount) { sold_num = sold_num + amount;}
	int getId(){ return id_num;}
	int getNum() { return sold_num;}
};

HotDogStand::HotDogStand ()
{
	id_num=0;
	sold_num=0;
}
HotDogStand::HotDogStand (int id)
{
	id_num=id;
	sold_num=0;
}

class Die // Represents a 6-face die object
{
public:

    Die();
	// initialize the die's face value to be 1
    int roll();
    // roll the die and returns the resulted face value
    int getFaceValue();
	void setFaceValue(int value);
	// if the value is valid (between 1 and 6), set the face value to be the value
	// otherwise, do nothing
	int getFaceDown(){return 7-faceValue;}

private:
    int faceValue;	// stores the current face value of the die
};

// Complete the implementation of the Die class. Member function roll is already provided

int Die::roll()
{
	// faceValue is randomly generated between 1 and 6
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

// Q 7
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

// Complete the main function as required in the exercise
int main()
{
	srand((unsigned)time(NULL)); // Keep this statement!

	// Your code for Question 3 go here ...

	Die roll1;
	Die roll2;
	Die roll3;
	int count = 0;
	
	while (roll1.getFaceValue()!=5 || roll2.getFaceValue()!=5 || roll3.getFaceValue()!=5)
	{
		roll1.roll();
		roll2.roll();
		roll3.roll();
	    count++;
	
	}

	cout <<"Number of Rolls: " << count << endl;


	// Q 7

	PairOfDice a;
	cout << a.sum()<<endl;
	a.roll();
	cout << a.sum()<<endl;

	system("pause");
	return 0;
}


