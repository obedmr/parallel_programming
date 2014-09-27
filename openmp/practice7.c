/*
Parallel and Distributed Computing Class
OpenMP

Practice 6 : Matrix * Matrix
Name       : Obed N Munoz
*/

#include <stdio.h>
#include <omp.h>
#define ROWS_A 200
#define ROWS_B 200
#define COLS_A 200
#define COLS_B 200


int main ()
{
  // Counters
  int i, j, k;
  float sum;  
  // Working matrix and vectors
  float matrix_a[ROWS_A][COLS_B], matrix_b[ROWS_B][COLS_B], matrix_c[ROWS_A][COLS_B];

  // Initializing Matrix and Vector
  printf("\nInitializing Matrixes A[%d][%d] , B[%d][%d] ...\n", ROWS_A,COLS_A,ROWS_B,COLS_B);

  for (i=0; i<ROWS_A; i++)
    for (j=0; j<COLS_A; j++)
      matrix_a[i][j] = j * i % 100;

  for (i=0; i<ROWS_B; i++)
    for(j=0; j<COLS_B; j++)
      matrix_b[i][j] = j * i %100;  

  printf("\nStarting Multiplication MatrixA * MatrixB ...\n");
  double start = omp_get_wtime();

  // Parallelizing dot product for each column 
  
#pragma omp parallel shared(matrix_a,matrix_b,matrix_c) private(i,j,k)
  {
  for ( i = 0 ; i < ROWS_A ; i++ )
    for ( j = 0 ; j < COLS_B ; j++) {
      for ( k = 0 ; k < ROWS_B ; k++) 
        sum = sum + matrix_a[i][k]*matrix_b[k][j];

      matrix_c[i][j] = sum;
      sum = 0;
    }
  }
  double end = omp_get_wtime();

  printf("\nMultiplication Vector * Matrix has FINISHED\n");

  printf("\nExecution Time = %f\n",end - start);
  return 0; 
}
