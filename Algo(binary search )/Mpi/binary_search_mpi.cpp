#include <bits/stdc++.h>
#include <mpi.h>
#include<cstdlib>
using namespace std;
bool found = false;

int binarySearch(int array[],int start, int end,int key,int rank)
{

	while(start<=end)
	{
		int mid=(end-start)/2+start;
		if(array[mid]==key)
		{
            found = true;
			return mid;
		}
		else if(array[mid]<key)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}


}
int main(int argc, char **argv) {
  int array[] = { 1, 5, 7, 10, 12, 14, 15, 18,20, 22, 25, 27, 30, 64, 110, 220 };

  int n = sizeof(array) / sizeof(array[0])-1 ;


	cout<<"here ";
	int key=220; //element to search
	MPI_Init(&argc, &argv);

	int rank,size;

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	cout<<"Processor rank: "<<rank<<"\nSize : "<<size<<endl;
	int blocks=2;
	int blockSize=2*n/blocks;


	if(rank==0)
	{
		double start=MPI_Wtime();
		int result = binarySearch(array, rank*blockSize, (rank+1)*blockSize-1, key, rank);
		double end=MPI_Wtime();
		if(result >= 0){
        cout<<key<<" : is  Found by processor : "<<rank<<" index : "<<result<<" .\n";
		cout<<"Execution time of Processor "<<rank<<" is "<<(end-start)*1000<<endl;}
		else{
        cout<< key <<": is Not found "<<endl;}

	}

    else{
        double start=MPI_Wtime();
        int result =binarySearch(array, rank*blockSize, (rank+1)*blockSize-1, key, rank);
        double end=MPI_Wtime();
        if(result >=0){
        cout<<key<<" : is  Found by processor : "<<rank<<" index : "<<result<<" .\n";
        cout<<"Execution time of Processor "<<rank<<" is "<<(end-start)*1000<<endl;}
        else{
        cout<< key <<": is Not found "<<endl;
        cout<<"Execution time of Processor "<<rank<<" is "<<(end-start)*1000<<endl;}
        }

	MPI_Finalize();

	return 0;
}
