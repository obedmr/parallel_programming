/*                                                                                                                   
Parallel and Distributed Computing Class                                                                             
OpenMP                                                                                                               
                                                                                                                     
Practice 1 : First example with OpenMP
Name       : Obed N Munoz                                                                                            
*/

#include <omp.h>
#include <stdio.h>
int main(){

  printf("Este  es nuestro primer ejemplo en openMP\n");
  #pragma omp parallel
  {
    printf("\nHola mundo\n");
  }
  printf("\nLa version instalada de OpenMP es: %d\n\n",_OPENMP);
  return 0;
}

