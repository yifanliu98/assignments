//Interface for the Derived Class TitledEmployee
//This is the header file titledemployee.h.
//This is the interface for the class HourlyEmployee.
#ifndef TITLEDEMPLOYEE_H
#define TITLEDEMPLOYEE_H

#include <string>
#include "salariedemployee.h"
#include "employee.h"

using namespace std;

namespace employeessavitch
{

    class TitledEmployee : public SalariedEmployee
    {
    public:
        TitledEmployee( );
        TitledEmployee(string the_name, string the_ssn, double the_weekly_salary, string s);
		void set_title (string s);
		string get_title () const;
		string get_name() const;
       

    private:
		string title;
    };

}//employeessavitch

#endif //TitledEMPLOYEE_H
