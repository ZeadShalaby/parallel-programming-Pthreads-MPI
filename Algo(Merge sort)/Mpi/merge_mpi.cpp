#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "mpi.h"
#include <time.h>

#define N 8

int numOfProc, idproc;


int compare(const void * a, const void * b) {
   const int *ia = (const int *)a;
    const int *ib = (const int *)b;
    return *ia  - *ib;
}



int main(int argc,char ** argv) {

   MPI_Init(&argc, &argv);
   MPI_Comm_size(MPI_COMM_WORLD, &numOfProc );
   MPI_Comm_rank(MPI_COMM_WORLD, &idproc);

   int * buf, * send_buf, * receive_buf, * sorted_buf, *displ, *sendcnts, *recvcnts;
   int count = N/numOfProc;
   int size, i;
   int temp, index;


   displ=(int*)malloc(numOfProc*sizeof(int));

   sendcnts=(int*)malloc(numOfProc*sizeof(int));

   recvcnts=(int*)malloc(numOfProc*sizeof(int));

   buf=(int*)malloc(count*sizeof(int));
  clock_t start_time = clock();

   for(i=0; i<numOfProc; i++){
       displ[i]=i*count;
       sendcnts[i]=count;
       recvcnts[i]=count;
   }



   if(idproc == 0) {
      size=N;
      send_buf=(int*)malloc(size*sizeof(int));
      receive_buf=(int*)malloc(size*sizeof(int));


      for (i=0;i<size;i++) {
         send_buf[i] = rand();
      }
      printf("\n\n");
      fflush(stdout);
   }

   MPI_Scatterv(send_buf, sendcnts, displ, MPI_INT, buf, count, MPI_INT, 0, MPI_COMM_WORLD);

   printf("proces %d: ", idproc);
   qsort(buf, count, sizeof(int), compare);
   for (int i = 0; i < count; i++) printf("%d ", buf[i]);
   printf("\n\n");
   fflush(stdout);

   MPI_Gatherv(buf, count, MPI_INT, receive_buf, recvcnts, displ, MPI_INT, 0, MPI_COMM_WORLD);

   if (idproc == 0) {
       //merge
       temp=INT_MAX;
       for(i=0; i<size; i++){
           for(int j=0; j<numOfProc; j++){

               if(temp>receive_buf[displ[j]]){
                   temp=receive_buf[displ[j]];
                   receive_buf[displ[j]]=receive_buf[i];
                   receive_buf[i]=temp;
               }

           }

           printf("%d ", receive_buf[i]);


       }


          printf("\n");
          fflush(stdout);
          clock_t end_time = clock();

    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n", execution_time);
   }

   MPI_Finalize();
}
