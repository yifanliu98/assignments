#ifndef PFARRAYDBAK_H
#define PFARRAYDBAK_H
#include "pfarrayd.h"

class PFArrayDBak : public PFArrayD
{
public:
	PFArrayDBak();
	PFArrayDBak(int capacityValue);
	PFArrayDBak(const PFArrayDBak& obj);
	PFArrayDBak& operator = (const PFArrayDBak& rightSide);
	~PFArrayDBak();
	
	void backup();
	void restore();

private:
	double* arr_B;
	int usedB;
};

#endif