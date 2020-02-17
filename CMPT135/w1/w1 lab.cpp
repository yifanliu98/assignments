#include<iostream>

using namespace std;
class student_info
{
private:
	string student_id;
	char gender;
public:
	date birthday;
	student_info(string id,char g);
	string address;

};

struct date
{
	int month;
	int day;
	int year;
};

student_info::student_info(string id,char g)
{
	student_id = id;
	gender = g;

}

int main()
{



	system("PAUSE");
	return 0;
}