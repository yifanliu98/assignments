#ifndef PFARRAYD_H
#define PFARRAYD_H


class PFArrayD
{
public:
	PFArrayD();
	PFArrayD(int capacityValue);
	PFArrayD(const PFArrayD& pfaobject);
	PFArrayD& operator = (const PFArrayD& rightSide);
	~PFArrayD();

	void addElement (double element);
	bool full() const;
	int getCapacity() const;
	int getNumberUsed() const;
	void emptyArray();
	double& operator[](int index);

protected:
	double* arr;
	int capacity;
	int used;
};

#endif