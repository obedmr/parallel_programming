/*                                                                                                                   
Parallel and Distributed Computing Class                                                                             
OpenMP                                                                                                               
                                                                                                                     
Practice 4 : Sum of 2 Vectors in Secuential Mode
Name       : Obed N Munoz                                                                                            
*/

#include <stdio.h>
#include <omp.h>

void Suma_Vec(int* a, int* b, int* c, int size)
{
  int i = 0;
  for (i = 0; i < size; ++i)
      c[i] = a[i] + b[i];
}



int main(){

  int size = 500000;

  int a[size];
  int b[size];
  int c[size];


  printf("\nSum of 2 vectors in Secuential mode\n");
  double start = omp_get_wtime();

  Suma_Vec(a, b, c, size);

  double end = omp_get_wtime();

  printf("\nExecution Time = %f\n",end - start);
  return 0;
}
