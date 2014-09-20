/*
Practice 6: Vector * Matrix
Name      : Obed N Munoz
Lecturer  : 
*/

#include <stdio.h>
#include <omp.h>

float dot_product(float array_a[], float array_b[], int size) 
{
  int  chunk;
  int i;
  float result;

#pragma omp for reduction(+: result)
  for(size_t i=0; i<size; i++){
    result += array_a[i]*array_b[i];
  }

/*  #pragma omp parallel for      \
    default(shared) private(i)  \
    schedule(static,chunk)      \
    reduction(+:result)
    for (i=0; i < size; i++)
      result += (array_a[i] * array_b[i]);
*/ 

  return result;
}

int main ()
{
  int size;
  float array_a[100], array_b[100], result;

  size = 100;
  result = 0.0;
  

  for (i=0; i < size; i++) {
    array_a[i] = i * 3.0;
    array_b[i] = i * 7.0;
  }

  double start = omp_get_wtime();

  dot_product(array_a, array_b, size);

  double end = omp_get_wtime();

  printf("Final result= %f\n",result);
  printf("Time = %f\n",end - start);
  return 0; 
}
