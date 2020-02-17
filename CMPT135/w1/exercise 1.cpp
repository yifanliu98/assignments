// Name: Yifan Liu (Leo)  ID:LIUY14D150

#include <iostream>
#include <ctime>
using namespace std;

int* fill_array_with_randint(int* arr, int s)
{
	for (int i=0;i<s;i++)
	{
		arr[i]=rand()%100+1;
	}
	return arr;
}

void printArray (int* arr, int s)
{
	cout << "[ ";
	for (int i=0;i<s;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<< " ]\n";
}

int* sort(int* arr, int s )
{
	int* sarr=new int[s];
	for (int i=0;i<s;i++)
	{
		sarr[i]=arr[i];
	}
	for (int i=0;i<s;i++)
	{
		for (int j=i+1;j<s;j++)
		{

			if (sarr[i]>sarr[j])
			{
				int temp=sarr[i];
				sarr[i]=sarr[j];
				sarr[j]=temp;
			}
		}
	}
	return sarr;
}

int main()
{
	srand((unsigned)time(0));
	cout<<"Step 1:\n";
	int size;
	cout<<"How many random integers";
	cin>>size;

	int* arr=new int [size];
	fill_array_with_randint(arr,size);

	cout<<"\nStep 2: \n";
	printArray(arr,size);

	cout<<"\nStep 3:\n";
	int* sortedArr=sort(arr,size);
	cout<< "The new sorted array is ";
	printArray(sortedArr,size);
	cout<<"The old array is ";
	printArray(arr,size);

	system("Pause");
	return 0;
}