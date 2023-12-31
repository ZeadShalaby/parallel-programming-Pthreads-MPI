// CPP Program to perform binary search using pthreads
#include <bits/stdc++.h>
//#include <pthread.h>
//#include <time.h>
using namespace std;

// size of array
#define MAX 16

// maximum number of threads
#define MAX_THREAD 4

// array to be searched
int a[] = { 1, 5, 7, 10, 12, 14, 15, 18,20, 22, 25, 27, 30, 64, 110, 220 };

// key that needs to be searched
int key = 110; //12 1 14//
bool found = false;
int part = 0;
int index =0;
void* binary_search(void* arg)
{

	// Each thread checks 1/4 of the array for the key
	int thread_part = part++;
	int mid;

	int low = thread_part * (MAX / 4);
	int high = (thread_part + 1) * (MAX / 4);

	// search for the key until low < high
	// or key is found in any portion of array
	while (low < high && !found) {

		// normal iterative binary search algorithm
		mid = (high - low) / 2 + low;

		if (a[mid] == key) {
			found = true;
			index = mid;
			break;
		}
		else if (a[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
}

// Driver Code
int main()
{
     // t1 and t2 for calculating time for
    // binary_search
    clock_t t1, t2;

    t1 = clock();
	pthread_t threads[MAX_THREAD];

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, binary_search,
					(void*)NULL);

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

       t2 = clock();

	// key found in array
	if (found){
		cout << key << " found in array & index is :"<< index << endl;
	// time taken by merge sort in seconds
    cout <<endl<< "Time taken: " << (t2 - t1) /
              (double)CLOCKS_PER_SEC << endl;

	}

	// key not found in array
	else{
		cout << key << " not found in array" << endl;
		 cout <<endl<< "Time taken: " << (t2 - t1) /
              (double)CLOCKS_PER_SEC << endl;
	}
	return 0;
}
