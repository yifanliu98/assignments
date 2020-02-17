#include <iostream>
using namespace std;

template <class T>
class Pair
{
public:
	Pair();
	Pair( T first_value, T second_value);

	void set_element (int position,const T& value);
	T get_element(int position) const;

private:
	T first;
	T second;
};

template <class T>
Pair<T>::Pair()
{

}

template <class T>
Pair<T>::Pair(T first_value, T second_value)
{
	first = first_value;
	second = second_value;
}

template <class T>
void Pair<T>::set_element(int position,const T& value)
{
	if (position == 1)
		first = value;
	else if(position == 2) 
		second = value;
}

template <class T>
T Pair<T>::get_element(int position) const
{
	if (position == 1)
		return first;
	else if (position == 2)
		return second;
}


int main()
{
	char c1='a', c2='b';
	int i1=1, i2=2;
	Pair<char> pair1(c1,c2);
	Pair<int> pair2(i1,i2);
	pair1.set_element(1,'c');
	cout << pair1.get_element(1) << endl;
	cout << pair2.get_element(2) << endl;

	system("PAUSE");
	return 0;
}