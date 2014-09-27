/*
Practice 5: Dot Product
Name      : Obed N Munoz
/Lecturer  : 
*/

#include <stdio.h>
#include <omp.h>
#define SIZE 10000


int main ()
{
  int   i, size, chunk;
  float array_a[SIZE], array_b[SIZE], result;

  size = SIZE;
  chunk = 10;
  result = 0.0;

  printf("\n Initializing Vectors of size [%d]\n", size);
  for (i=0; i < size; i++) {
    array_a[i] = i * 3.0;
    array_b[i] = i * 7.0;
  }

  printf("\nStarting Dot Product ...\n");
  double start = omp_get_wtime();

  #pragma omp parallel for      \
    default(shared) private(i)  \
    schedule(static,chunk)      \
    reduction(+:result)
      for (i=0; i < size; i++)
        result += (array_a[i] * array_b[i]);

  double end = omp_get_wtime();
  printf("\nDot Product FINISHED\n");

  printf("\nFinal result= %f\n",result);
  printf("\nTime = %f\n",end - start);
  return 0; 
}
