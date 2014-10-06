#include "omp.h"
#include "mpi.h" /* Include MPI header file */
#include <stdio.h>

int main(int argc, char **argv){

  int rnk, sz, n, I, info, i, chunk, my_id;

  double *x, *y, *buff;

  n = atoi(argv[1]); /* Get input size */
  
  //  for (i=0; i<n; i++) 
  //    buff[i] = 5.0;

  /* Initialize threaded MPI environment */
  MPI_Init_thread(&argc, &argv, MPI_THREAD_FUNNELED, &info);
  MPI_Comm_size(MPI_COMM_WORLD, &sz); /* Find out how many MPI procs */
  MPI_Comm_rank ( MPI_COMM_WORLD, &my_id );  

  
  if (my_id == 0){ 
    printf("Initializing");
    for (i=0; i<n; i++)
      buff[i] =5.0;

    chunk = n / sz; /* Assume sz divides n exactly */

    MPI_Scatter(buff,chunk,MPI_DOUBLE,x,chunk,MPI_DOUBLE,0,MPI_COMM_WORLD);
    MPI_Scatter(&buff[n],chunk,MPI_DOUBLE,y,chunk,MPI_DOUBLE,0,MPI_COMM_WORLD);
  } else {

#pragma omp parallel for private(i,chunk) shared(x, y)
  for (i=0; i<chunk; i++) 
      x[i] = x[i] + y[i];
  }

  MPI_Gather(x,chunk,MPI_DOUBLE,buff,chunk,MPI_DOUBLE,0,MPI_COMM_WORLD);

  MPI_Finalize(); 
  printf("Helloooooooooooooooooo");
  return 0;
}
