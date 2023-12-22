// C++ program for Merge Sort
#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const low, int const mid,int const high)
{
    clock_t t1, t2;

    t1 = clock();
	 int* left = new int[mid - low + 1];
    int* right = new int[high - mid];

    // n1 is size of left part and n2 is size
    // of right part
    int n1 = mid - low + 1, n2 = high - mid, i, j;

    // storing values in left part
    for (i = 0; i < n1; i++)
        left[i] = array[i + low];

    // storing values in right part
    for (i = 0; i < n2; i++)
        right[i] = array[i + mid + 1];

    int k = low;
    i = j = 0;

    // merge left and right in ascending order
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < n1) {
        array[k++] = left[i++];
    }

    // insert remaining values from right
    while (j < n2) {
        array[k++] = right[j++];
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

// Driver code
int main()
{
    clock_t t1, t2;
    int arr[]={  45, 58, 61, 62, 64, 670, 5, 24, 27, 27, 34, 36, 41, 42,  69, 78, 81, 91, 95 };

	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

  t2 = clock();
	cout << "\nSorted array is \n";

	printArray(arr, arr_size);

	 // time taken by merge sort in seconds
    cout <<endl<< "Time taken: " <<(t2 - t1)*10 /
              (double)CLOCKS_PER_SEC<< " seconds"<< endl;
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
