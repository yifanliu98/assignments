#include <iostream>
using namespace std;
class String
{
public:
	~String();
	String();
	String(const char* s);
	String(const String& s);
	bool empty() const;
	int length() const;
	char& operator[] (int index);
	String& operator= (const String& s);
	char* upper();
	int position(char ch);
	String& operator+= (const char& ch); 
	bool operator== (const char* ch) const; 
	String substr(int start, int size);
	int substring (const String& c);
	
	friend ostream& operator<< (ostream& outs,const String& s);
	friend bool operator== (const String& s1, const String& s2); 
	friend String operator+ (const String& s1, const String& s2);
	friend String& operator+= (String & s1, const String& s2); 
	friend int compareStrings (const String s1, const String& s2);
	friend String reversedString (const String& s);

private:
	char* str;
	int len;
};
String::~String()
{
	delete [] str;
}
String::String()
{
	len=0;
	str=new char[len+1];
	str[len]='\0';
}
String::String(const char* s)
{
	len=0;
	while (s[len]!='\0')
	{
		len++;
	}
	str=new char[len+1];
	for (int i=0;i<=len;i++)
	{
		str[i]=s[i];
	}
}
String::String (const String& s)
{
	len=s.len;
	str=new char[len+1];
	for (int i=0;i<len+1;i++)
	{
		str[i]=s.str[i];
	}
}
bool String::empty() const
{
	if (len==0)
		return true;
	else 
		return false;
}
int String::length() const
{
	return len;
}
char& String::operator[] (int index)
{
	if (index<0 || index>=len)
		throw "index out of range";
	return str[index];
}
String& String::operator= (const String& s)
{
	if (len<s.len)
	{
		delete [] str;
		str=new char[s.len+1];
	}
	len=s.len;
	for (int i=0;i<=len;i++)
	{
		str[i]=s.str[i];
	}
	return *this;
}
char* String::upper()
{
	char* temp=new char[len+1];
	for (int i=0;i<=len;i++)
	{
		if ('a'<=str[i] && str[i]<='z')
			temp[i]=str[i]-'a'+'A';
		else 
			temp[i]=str[i];
	}
	return temp;
}
int String::position(char ch)
{
	for (int i=0;i<len;i++)
	{
		if (str[i]==ch)
			return i;
	}
	return -1;
}
bool String::operator== (const char* ch) const
{
	int lenCh=0;
	while (ch[lenCh]!='\0')
	{
		lenCh++;
	}
	if (len!=lenCh)
		return false;
	for (int i=0;i<lenCh;i++)
	{
		if (str[i]!=ch[i])
			return false;
	}
	return true;
}
String String::substr(int start, int size)
{
	if (size >= len - start)
		size = len - start;
	if (start >= len)
	{
		char* null = new char[1];
		null[0] = '\0';
		return String(null);
	}
	char * temp = new char[size+1];
	for (int i = start; i < start+size; i++)
	{
		temp[i-start] = str[i];
	}
	temp[size] = '\0';

	return String(temp);
}
ostream& operator<< (ostream& outs,const String& s)
{
	for (int i=0;i<s.len;i++)
	{
		outs<<s.str[i];
	}
	return outs;
}

int String::substring (const String& c)
{
	if (c.len > len)
		return -1;
	if (c.empty())
		return 0;
	int temp = 0;
	for (int i = 0; i < len; i++)
	{
		if (str [i] == c.str[temp])
			temp ++;
		if (temp == c.len)
			return i - temp;
	}
	return -1;
}
bool operator== (const String& s1, const String& s2) 
{
	if (s1.len!=s2.len)
		return false;
	for (int i=0;i<s1.len;i++)
	{
		if (s1.str[i]!=s2.str[i])
			return false;
	}
	return true;
}
String operator+ (const String& s1, const String& s2)
{
	int len=s1.len+s2.len;
	char* temp=new char[len+1];
	for (int i=0;i<s1.len;i++)
	{
		temp[i]=s1.str[i];
	}
	for (int i=s1.len;i<=len;i++)
	{
		temp[i]=s2.str[i-s1.len];
	}
	return (String(temp));
}
String& String::operator+= (const char& ch)
{
	len++;
	char* temp = new char [len+1];
	for (int i = 0; i < len-1 ; i ++ )
	{
		temp[i] = str[i];
	}
	temp[len-1] = ch;
	temp[len] = '\0';
	delete [] str;
	str = temp;
	return *this;
}
String& operator+= (String & s1, const String& s2)
{
	s1 = s1 + s2;
	return s1;
}
int compareStrings (const String s1, const String& s2)
{
	if (s1.len == s2.len)
	{
		for (int i=0; i < s1.len; i++)
		{
			if (s1.str[i] > s2.str[i])
				return 1;
			else if (s1.str[i] < s2.str[i])
				return -1;
		}
		return 0;
	}
	else
	{
		int len = s1.len;
		if (s1.len > s2.len)
			len = s2.len;
		for (int i=0; i < len; i++)
		{
			if (s1.str[i] > s2.str[i])
				return 1;
			else if (s1.str[i] < s2.str[i])
				return -1;
		}
		if (len == s1.len)
			return -1;
		return 1;
	}
}
String reversedString (const String& s)
{
	char* temp = new char[s.len + 1];
	for (int i = 0; i < s.len ; i++)
	{
		temp[i] = s.str[s.len - i - 1];
	}
	temp[s.len] = '\0';
	return String(temp);
}

class Polynomial
{
private:
	double* arr;
	int size;

public:
	~Polynomial();
	Polynomial();
	Polynomial(const double& c);
	Polynomial(const Polynomial& p);
	Polynomial(const double* d,const int& s);
	
	void read ();
	int getSize() const;
	double evaluate (const double& d);
	double& operator[] (int index);
	Polynomial& operator= (const Polynomial& p);
	Polynomial operator+ (const Polynomial& p);
	Polynomial operator- (const Polynomial& p);
		
	friend Polynomial operator+ (double c, const Polynomial& p);
    friend Polynomial operator- (double c, const Polynomial& p);
	friend Polynomial operator* (const Polynomial& p1, const Polynomial& p2);
	friend ostream& operator<< (ostream& outs, const Polynomial& p);
};
Polynomial::~Polynomial()
{
	delete [] arr;
}
Polynomial::Polynomial()
{
	size = 1;
	arr = new double [1];
	arr[0] = 0;
}
Polynomial::Polynomial(const double& c)
{
	size = 1;
	arr = new double[1];
	arr[0] = c;
}
Polynomial::Polynomial(const Polynomial& p)
{
	size = p.size;
	arr = new double[size];
	for (int i = 0; i < size; i++)
		arr[i] = p.arr[i];
}
Polynomial::Polynomial(const double* d,const int& s)
{
	size = s;
	arr = new double[size];
	for (int i = 0; i < size; i++)
		arr[i] = d[i];
}

void Polynomial::read ()
{
	delete [] arr;
	cout << "Enter the biggest exponent: ";
	cin >> size;
	size ++;
	arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Enter the coefficient of term: ";
		cin >> arr[i];
	}
}
int Polynomial::getSize() const
{
	return size;
}
double Polynomial::evaluate (const double& d)
{
	double term,solution = arr[0];
	for (int i = 1; i < size; i++)
	{
		term = 1;
		for (int j = 1; j <= i; j++)
		{
			term *= d;
		}
		solution =solution + term * arr[i];
	}
	return solution;
}
Polynomial& Polynomial::operator= (const Polynomial& p)
{
	size = p.size;
	delete [] arr;
	arr = new double[size];
	for (int i=0; i < size; i++)
		arr[i] = p.arr[i];
	return *this;
}
Polynomial Polynomial::operator+ (const Polynomial& p)
{
	if (size > p.size)
	{
		double* temp = new double[size];
		for (int i = 0; i < p.size; i++)
			temp[i] = arr[i] + p.arr[i];
		for (int i = p.size; i < size; i++)
			temp[i] = arr[i];
		return Polynomial(temp,size);
	}
	else 
	{
		double* temp = new double[p.size];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i] + p.arr[i];
		for (int i = size; i < p.size; i++)
			temp[i] = p.arr[i];
		return Polynomial(temp,p.size);
	}
}
Polynomial Polynomial::operator- (const Polynomial& p)
{
	if (size >= p.size)
	{
		double* temp = new double[size];
		for (int i = 0; i < p.size; i++)
			temp[i] = arr[i] - p.arr[i];
		for (int i = p.size; i < size; i++)
			temp[i] = arr[i];
		return Polynomial(temp,size);
	}
	else 
	{
		double* temp = new double[p.size];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i] - p.arr[i];
		for (int i = size; i < p.size; i++)
			temp[i] = 0 - p.arr[i];
		return Polynomial(temp,p.size);
	}
}
double& Polynomial::operator[] (int index)
{
	if (index < 0 || index >= size)
		throw "index out of the range";
	else
		return arr[index];
}

Polynomial operator+ (double c, const Polynomial& p)
{
	Polynomial temp(p);
	temp.arr[0] += c;
	return temp;
}
Polynomial operator- (double c, const Polynomial& p)
{
	Polynomial temp(p);
	temp.arr[0] = c - temp.arr[0];
	for (int i = 1; i < p.size; i++ )
		temp[i] = 0 - temp[i];
	return temp;
}
Polynomial operator* (const Polynomial& p1, const Polynomial& p2)
{
	int size = p1.size + p2.size -1;
	double** temp = new double* [p2.size];
	for (int i = 0; i < p2.size; i++)
	{
		temp[i] = new double [size];
		for (int k = 0; k < size; k++)
		{
			temp[i][k] = 0;
		}
		for (int j = 0; j < p1.size; j++)
		{ 
			temp[i][i+j] = p2.arr[i] * p1.arr [j];
		}
	}
	double* arr = new double [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = temp[0][i];
	}
	for (int i = 1; i < p2.size; i++)
	{
		for (int j = 0; j < size; j++)
			arr[j] = arr[j] + temp[i][j];
	}
	for (int i = 0; i < p2.size; i++)
		delete [] temp[i];
	delete [] temp;
	return Polynomial(arr,size);
}
ostream& operator<< (ostream& outs, const Polynomial& p)
{
	outs << p.arr[0];
	outs << " ";
	for (int i = 1; i < p.size; i++)
	{	
		outs << "+" << " "; 
		outs << p.arr[i];
		outs << "x" << "^";
		outs<< i; 
	    outs << " ";
	}
	return outs;
}