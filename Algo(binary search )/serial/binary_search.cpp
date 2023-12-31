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

  int array[] = { 1, 5, 7, 10, 12, 14, 15, 18,20, 22, 25, 27, 30, 64, 110, 220 };
  int x = 220;
  int n = sizeof(array) / sizeof(array[0]);
  int result = binarySearch(array, x, 0, n - 1);
  t2 = clock();

  if (result == -1){
    printf("Not found");
     // time taken by merge sort in seconds
    cout <<endl<< "Time taken: " << (t2 - t1)*10 /
              (double)CLOCKS_PER_SEC << endl;
  }
  else{
    cout<< x <<": is found at index :"<<result<<endl;
     // time taken by merge sort in seconds
    cout <<endl<< "Time taken: " <<(t2 - t1)*10 /
              (double)CLOCKS_PER_SEC<< " seconds"<< endl;
  }
}
