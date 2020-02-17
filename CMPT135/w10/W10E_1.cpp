#include <iostream>
using namespace std;

class A
{
public:
	virtual void display() { cout << "A display\n"; }
};

class B : public A
{
public:
	virtual void display() { cout << "B display\n"; }
};

class C : public B
{
public:
	C() { cout << "C constructor\n"; }
	virtual void display() { cout << "C display\n"; }
};

void do_sth (A* obj)
{
	obj->display();
}

int main()
{
	A* ptA = new A;
	B* ptB = new B;
	C* ptC = new C;

	ptA->display();
	
	ptA = ptB;
	ptA->display();
	do_sth(ptA);

	ptA = new C;
	ptB = dynamic_cast<B*>(ptA);
	ptB->display();

	return 0;
	}