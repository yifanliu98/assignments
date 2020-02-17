// CMPT135 J.Ye
// Sorting an array in ascending order using Merge Sort algorithm
// Note: this version does not contain the implementation of the merge function, please
// try it on your own first.
#include <iostream>
using namespace std;

void mergeSort(int arr[], int start, int end);
//Precondition: The array elements arr[start] through arr[end] have values. start <= end
//Postcondition: The values of arr[start] through arr[end] have been rearranged so that
// arr[start] <= arr[start+1] <= ... <= arr[end].
void merge(int arr[], int start, int mid, int end);
//Precondition: The array elements arr[start] through arr[end] have values. start <= mid <= end
// subarray arr[start] to arr[mid] is sorted; subarray arr[mid+1] to arr[end] is sorted
//Postcondition: the entire array arr[start] to arr[end] is sorted
//


int main()
{
	int* arr = new int[8]; 
	for (int i=0;i<8;i++)
	{	
		arr[i]=rand()%20;
		cout << arr[i] << " ";
	}
	cout << endl;	
	mergeSort(arr,0,7);
	for (int i=0; i<8;i++)
		cout<<arr[i]<<" ";
	cout<<endl;


	system("Pause");
	return 0;
}


void mergeSort(int arr[], int start, int end)
{
	/*if (start == end)
		return;*/
	
	if (start == end-1) // size 2 array, base case. What about size 1 array?
	{
		// swap the two elements if they are out of order
		if(arr[start] > arr[end])
		{
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
		}
	}
	

	else if (start < end - 1) // size > 2 array
	{
		int mid = (start+end)/2; // "cut" the array in half
		mergeSort(arr, start, mid); // sort the first half
		mergeSort(arr, mid+1, end); // sort the 2nd half
		merge(arr, start, mid, end); // merge them back together
	}

}

// Now, please implement the merge function ...
void merge(int arr[], int start, int mid, int end)
{
	int size = end - start + 1, i_1 = start, i_2 = mid + 1, j = 0;
	int* temp = new int[size];
	while(i_1 != mid + 1 && i_2 != end + 1)
		if(arr[i_1] < arr[i_2])
			temp[j++] = arr[i_1++];
		else 
			temp[j++] = arr[i_2++];
	while (i_1 <= mid)
		temp[j++] = arr[i_1++]; 
	while (i_2 <= end)
		temp[j++] = arr[i_2 ++];
	for (int i = 0; i < size; i ++)
		arr[start + i] = temp[i];
	delete [] temp;
}
