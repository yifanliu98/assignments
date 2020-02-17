#include <iostream>
#include <string>
using namespace std;

class String
{
public:
	~String(){delete [] str;}
	String (const String& s); // copy constructor
	String (const char* s);
	//char operator [] (int index);
	friend ostream& operator <<(ostream& dataRiver,const String& s);

private:
	char* str;
	int length; // actual number of characters
};

String::String (const String& s)
{
	//str = s.str;  // copy constructor
	length=s.length;
	this->str=new char[length+1];
	strcpy(str,s.str);
}
String::String (const char* s)
{
	length=strlen(s);
	str=new char [length+1];
	for (int i=0;i<length+1;i++)
	{
		str[i]=s[i];
	}
}
//char String::operator [] (int index)

ostream& operator <<(ostream& dataRiver,const String& s)
{
	dataRiver<<s.str;
	return dataRiver;	
}



int main()
{
	String s1="hi";
	String s2=s1;
	cout<<s2;
	s2="Ho";s1="ho";
	cout<<s2;
	cout<<s1;
	system("pause");
	return 0;
}