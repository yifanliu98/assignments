#include <iostream>
#include "pfarrayd.h"
using namespace std;

PFArrayD::PFArrayD()
{
	arr = new double [50];
	capacity = 50;
	used = 0;
}

PFArrayD::PFArrayD(int capacityValue)
{
	capacity = capacityValue;
	arr = new double [capacity];
	used = 0;
}

PFArrayD::PFArrayD(const PFArrayD& pfaobject)
{
	capacity = pfaobject.capacity;
	used = pfaobject.used;
	for (int i = 0; i < used; i++)
	{
		arr[i] = pfaobject.arr[i];
	}
}

PFArrayD& PFArrayD::operator= (const PFArrayD& rightSide)
{
	PFArrayD temp(rightSide.capacity);
	temp.used = rightSide.used;
	for (int i = 0; i < temp.used; i++)
	{
		temp.arr[i] = rightSide.arr[i];
	}
	return temp;
}

PFArrayD::~PFArrayD()
{
	delete [] arr;
}

void PFArrayD::addElement(double element)
{
	if (used == capacity)
		return;
	arr[used] = element;
	used++;
}

bool PFArrayD::full() const
{
	if (used == capacity)
		return true;
	else
		return false;
}

int PFArrayD::getCapacity() const
{
	return capacity;
}

int PFArrayD::getNumberUsed() const
{
	return used;
}

void PFArrayD::emptyArray()
{
	used = 0;
}

double& PFArrayD::operator[] (int index)
{
	if (index >= used)
		throw "index out of range";
	return arr[index];
}


