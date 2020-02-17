#include <iostream>
#include "pfarrayd.h"
#include "pfarraydbak.h"

using namespace std;
// include necessary directives

void testPFArrayDBak( );
//Conducts one test of the class PFArrayDBak.

int main( )
{
    cout << "This program tests the class PFArrayDBak.\n";

    char ans;
    do
    {
        testPFArrayDBak( );
        cout << "Test again? (y/n) ";
        cin >> ans;
    }while ((ans == 'y') || (ans == 'Y'));

    return 0; 
}

void testPFArrayDBak( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayDBak a(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";

    double next;

    cin >> next;
    while ((next >= 0) && (!a.full( )))
    {
        a.addElement(next);
        cin >> next;
    }

    if (next >= 0)
    {
        cout << "Could not read all numbers.\n";
        //Clear the unread input:
        while (next >= 0)
            cin >> next;
    }
 
    int count = a.getNumberUsed( );
    cout << "The following " << count 
         << " numbers read and stored:\n";
    int index;
    for (index = 0; index < count; index++)
        cout << a[index] << " ";
    cout << endl;

    cout << "Backing up array.\n";
    a.backup( );

    cout << "emptying array.\n";
    a.emptyArray( ); 
    cout << a.getNumberUsed( ) 
         << " numbers are now stored in the array.\n";

    cout << "Restoring array.\n";
    a.restore( );   
    count = a.getNumberUsed( );
    cout << "The following " << count 
         << " numbers are now stored:\n";
    for (index = 0; index < count; index++)
        cout << a[index] << " ";
    cout << endl;
}

/* A sample run:

This program tests the class PFArrayDBak.
Enter capacity of this super array:  10
Enter up to 10 nonnegative numbers.
Place a negative number at the end.
1 2 3 4 5 -1
The following 5 numbers read and stored:
1 2 3 4 5
Backing up array.
0 numbers are now stored in the array.
Restoring array.
The following 5 numbers are now stored:
1 2 3 4 5
Test again? (y/n): y
Enter capacity of this super array:  5
Enter up to 5 nonnegative numbers.
Place a negative number at the end.
1 2 3 4 5 6 7 -1
Could not read all numbers.
The following 5 numbers read and stored:
1 2 3 4 5
Backing up array.
0 numbers are now stored in the array.
Restoring array.
The following 5 numbers are now stored:
1 2 3 4 5
Test again? (y/n): n

*/