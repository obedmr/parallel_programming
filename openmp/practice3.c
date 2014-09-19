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

  int size = 500000000; 
 
  int a[size];
  int b[size];
  int c[size];
  
    
  Suma_Vec(a, b, c, size);
  return 0;
}
