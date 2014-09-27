/*
Parallel and Distributed Computing Class
OpenMP

Practice 6 : Vector * Matrix
Name       : Obed N Munoz
*/

#include <stdio.h>
#include <omp.h>
#define SIZE 1000

// Function that Parallelize Dot product
float dot_product(float vector_a[], float vector_b[]) 
{
  int i;
  float result = 0.0;

#pragma omp parallel for reduction(+:result)
  for (i=0; i < SIZE; i++)
    result += (vector_a[i] * vector_b[i]);
   return result;
}

int main ()
{
  // Counters
  int i, j;  
  // Working matrix and vectors
  float matrix[SIZE][SIZE], vector[SIZE], result[SIZE];

  // Initializing Matrix and Vector
  printf("\nInitializing Matrix [%d][%d] and Vector[%d] ...\n", SIZE,SIZE,SIZE);
  for (i=0; i<SIZE; i++){
    vector[i] = i * 5.0;
  }

  for (i=0; i < SIZE; i++) {
    for (j=0; j < SIZE; j++) {
      matrix[i][j] = i * 3.0;
    }
  }

  printf("\nStarting Multiplication Vector * Matrix ...\n");
  double start = omp_get_wtime();

  // Parallelizing dot product for each column 
  for (i=0; i < SIZE; i++){
    result[i] = dot_product(vector, matrix[i]);
  }

  double end = omp_get_wtime();

  printf("\nMultiplication Vector * Matrix has FINISHED\n");
  printf("\nExecution Time = %f\n",end - start);
  return 0; 
}
