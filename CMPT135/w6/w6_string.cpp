#include <iostream>
#include <string>
using namespace std;

class String
{
public:
	~String(){delete [] str;}
	String ();
	String (const String& s); // copy constructor
	String (const char* s);
	int length(){return len;}
	char& operator [] (int index);
	String& operator = (const String& s);
	friend ostream& operator <<(ostream& dataRiver,const String& s);

private:
	char* str;
	int len; // actual number of characters
};
String::String()
{
	len=0;
	str=new char[len+1];
	str[len]='\0';
}
String::String (const String& s)
{
	//str = s.str;  // copy constructor
	len=s.len;
	this->str=new char[len+1];
	for (int i=0;i<len+1;i++)
	{
		str[i]=s.str[i];
	}
}
String::String (const char* s)
{
	len=strlen(s);
	str=new char [len+1];
	for (int i=0;i<len+1;i++)
	{
		str[i]=s[i];
	}
}
char& String::operator [] (int index)
{
	if (index<0 || index>=len)
		throw "index out of range";
	return str[index];

}
String& String::operator = (const String& s)
{
	len=s.len;
	if (len<s.len)
	{
		delete [] str;
		str=new char[s.len+1];
	}
	for (int i=0;i<len+1;i++)
	{
		str[i]=s.str[i];
	}
	return *this; 
	// return s;
}
ostream& operator <<(ostream& dataRiver,const String& s)
{
	dataRiver<<s.str;
	return dataRiver;	
}

int main()
{

	
	system("PAUSE");
	return 0;
}
