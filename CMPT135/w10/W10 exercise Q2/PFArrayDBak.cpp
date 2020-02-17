#include <iostream>
#include "pfarraydbak.h"
using namespace std;

PFArrayDBak::PFArrayDBak() : PFArrayD(), usedB(0)
{
	arr_B = new double[50];
}

PFArrayDBak::PFArrayDBak(int capacityValue) : PFArrayD(capacityValue), usedB(0)
{
	arr_B = new double[capacity];
}

PFArrayDBak::PFArrayDBak(const PFArrayDBak& object)
{
	capacity = object.capacity;
	used = object.used;
	usedB = object.usedB;
	for (int i = 0; i < used; i++)
	{
		arr[i] = object.arr[i];
	}
	for (int i = 0; i < usedB; i++)
	{
		arr_B[i] = object.arr_B[i];
	}
}

PFArrayDBak& PFArrayDBak::operator= (const PFArrayDBak& rightSide)
{
	PFArrayDBak temp(rightSide);
	return temp;
}

PFArrayDBak::~PFArrayDBak()
{
	delete [] arr_B;
}

void PFArrayDBak::backup()
{
	usedB = used;
	for (int i = 0; i < usedB; i++)
		arr_B[i] = arr[i];
}

void PFArrayDBak::restore()
{
	used = usedB;
	for (int i = 0; i < used; i++)
		arr[i] = arr_B[i];
}





