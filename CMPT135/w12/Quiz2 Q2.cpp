#include <iostream>
using namespace std;

class M
{
public:
	M(){cout<<"M\n";}
	virtual void die(){cout<<"Die\n";}
};

class H : public M
{
public:
	H(){cout<<"H\n";}
	void die(){cout<<"Die H\n";}
};

class P : public M
{
public:
	P(){cout<<"P\n";}
	void die(){cout<<"Die P\n";}
};

void kill1(M* thing){
	thing->die();
}

void kill2(M thing){
	thing.die();
}

void kill3(M& thing){
	thing.die();
}

int main()
{
	M* m=new H;
	cout<<"1\n";
	kill1(m);

	cout<<"2\n";
	kill2(*m);

	cout<<"3\n";
	P* p = new P;
	kill3(*p);

	cout<<"4\n";
	m=p;
	kill1(m);

	cout<<"5\n";
	kill2(*m);

	cout<<"6\n";
	kill2(*p);



	system("PAUSE");
	return 0;
}