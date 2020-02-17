#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream ofile;
	ofile.open("today.txt");
	for (int i=1; i<=3; i++)
		ofile << rand()%100+1 << " " << endl;
	ofile.close();
	ifstream infile("today.txt");
	int sum = 0, num;
	while (infile >> num)
		sum += num;
	cout << sum << endl;
	
	system("Pause");
	return 0;
}