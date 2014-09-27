/*                                                                                                      
Parallel and Distributed Computing Class                                                                   
OpenMP                                                                                    
 Practice 3 :Parallelizing the Sum of 2 vectors
Name       : Obed N Munoz                                           
*/

#include <stdio.h>
#include <omp.h>
#include "mpi.h"


int main(int argc, char *argv[])
{

  int size = 1000; 
 
  int a[size];
  int b[size];
  int c[size];
  
  int numprocs, rank, namelen;
  char processor_name[MPI_MAX_PROCESSOR_NAME];
  int soy = 0, np = 1;
  MPI_Init(&argc, &argv); //inicia el paralelismo con mpi
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs); //obtiene el número de proceso
  MPI_Comm_rank(MPI_COMM_WORLD, &rank); // rango. Cantidad de procesos totales
  MPI_Get_processor_name(processor_name, &namelen); //nombre de la computadora

  printf("\nParallelizing the Sum of 2 vectors\n");
  double start = omp_get_wtime();

  int i; 

#pragma omp parallel for //default(shared) private(soy, np)
    for (i = 0; i < size; ++i)
	c[i] = a[i] + b[i];

  double end = omp_get_wtime();

  printf("\nExecution Time = %f\n",end - start);
  return 0;
}
