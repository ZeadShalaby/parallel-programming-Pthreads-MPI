// Binary Search in C++

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
clock_t t1, t2;

  t1 = clock();
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
 clock_t t1, t2;

  int array[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  t2 = clock();

  if (result == -1){
    printf("Not found");
     // time taken by merge sort in seconds
    cout <<endl<< "Time taken: " << (t2 - t1) /
              (double)CLOCKS_PER_SEC << endl;
  }
  else{
    cout<< x <<": is found at index :"<<result<<endl;
     // time taken by merge sort in seconds
    cout <<endl<< "Time taken: " <<(t2 - t1)*1000 /
              (double)CLOCKS_PER_SEC<< " seconds"<< endl;
  }
}
