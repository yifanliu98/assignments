#include <iostream>
using namespace std;
int add(int x, int y)
{
	if (x<=y)
	{
		return x+add(x+1,y);
	}
	else
		return 0;
}
void print (int n)
{
	if (n>=0)
	{
		cout<<n;
		print (n-1);
	}
}
void odd (int n)
{
	if (n%2==0)
		n--;
	if (n>=1)
	{
		odd(n-2);
		cout<<n;
	}
}
int binary_search(int arr[], int begin, int end, int target)
{
	if (begin > end)
		return -1;
	int mid = (begin + end ) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return binary_search(arr,begin,mid-1,target);
	else 
		return binary_search(arr,mid+1,end,target);
}
int binary_search_loop(int arr[],int start, int end, int target)
{
	while (start <= end)
	{
		int mid = (start + end)/2;
		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			end = mid - 1;
		else 
			start = mid + 1;
	}
	return -1;
}

int main()
{

	//print(3);
	//odd(8);
	//cout<<add(1,5)<<endl;
	int arr[5] = {1,2,3,4,5};
	cout<<binary_search (arr,0,4,6)<<endl;
	cout<<binary_search_loop (arr,0,4,6)<<endl;

	system("PAUSE");
	return 0;
}
