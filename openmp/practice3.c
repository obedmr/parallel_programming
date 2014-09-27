/*                                                                                                                   
Parallel and Distributed Computing Class                                                                             
OpenMP                                                                                                               
                                                                                                                     
Practice 3 :Parallelizing the Sum of 2 vectors
Name       : Obed N Munoz                                                                                            
*/

#include <stdio.h>
#include <omp.h>

void Suma_Vec(int* a, int* b, int* c, int size)
{
  int i = 0;
#pragma omp parallel for
  for (i = 0; i < size; ++i)
    {
      c[i] = a[i] + b[i];
    }
 }
 


int main(){

  int size = 500000; 
 
  int a[size];
  int b[size];
  int c[size];
  
  printf("\nParallelizing the Sum of 2 vectors\n");
  double start = omp_get_wtime();
  
  Suma_Vec(a, b, c, size);

  double end = omp_get_wtime();

  printf("\nExecution Time = %f\n",end - start);
  return 0;
}
