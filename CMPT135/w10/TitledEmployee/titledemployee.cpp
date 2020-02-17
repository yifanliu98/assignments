#include <iostream>
#include <string>
#include "titledemployee.h"


using namespace std;

namespace employeessavitch
{
    TitledEmployee::TitledEmployee( ) : SalariedEmployee( ), title(NULL)
    {
        //deliberately empty
    }
    TitledEmployee::TitledEmployee(string the_name, string the_ssn, double the_weekly_salary, string s) : SalariedEmployee(the_name, the_ssn,the_weekly_salary) , title(s)
    {
      
	}

	void TitledEmployee::set_title(string s) 
	{
		title = s;
    }

	string TitledEmployee::get_title() const
	{
		return title;
	}

	string TitledEmployee::get_name() const
	{
		string new_name = title + SalariedEmployee::get_name();
		return new_name;
	}

}//employeessavitch