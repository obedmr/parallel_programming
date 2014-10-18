#include<stdio.h>
#define N 40000

// Multiplicacion de matrices

__global__ void multiply_matrix(float *c, float *a, float *b, int rows, int cols){

  int N = rows * cols; 
  int col = blockIdx.x*blockDim.x + threadIdx.x;  
  int row = blockIdx.y*blockDim.y + threadIdx.y;
  int idx = row * N * col;
  c[idx] = a[idx] * b[idx];

}

//función principal
int main(void){
  float *A_h, *B_h, *C_h;
  float *A_d, *B_d, *C_d;

  int n_rows = 100;
  int n_cols = 100;
  int N = n_rows * n_cols;

  // Asignando memoria en Host
  A_h = (float *) * malloc(N * sizeof(float));
  B_h = (float *) * malloc(N * sizeof(float));
  C_h = (float *) * malloc(N * sizeof(float));

  //asignar memoria en la GPU
  cudaMalloc((void**)&A_d,N*sizeof(float));
  cudaMalloc((void**)&B_d,N*sizeof(float));
  cudaMalloc((void**)&C_d,N*sizeof(float));

  //Llenar datos a los arreglos 'a' y 'b' en la CPU
  for(int i=0; i<N;i++){
    A_h[i]=i;
    B_h[i]=i+1;
  }

  //copiar el arreglo 'a' y 'b' en la GPU
  cudaMemcpy(A_d,A_h,N*sizeof(float),cudaMemcpyHostToDevice);
  cudaMemcpy(B_d,B_h,N*sizeof(float),cudaMemcpyHostToDevice);


  dim3 block_size(BLOCK_SIZE,BLOCK_SIZE);
  dim3 n_blocks((ceil(float(block_size.x/n_cols)), ceil(float(block_size.y/n_rows)));

  //lanzar elkernel
  multiply_matrix<<<n_blocks, block_size>>>(C_d, A_d, B_d, n_rows, n_cols);

  //copiar el arreglo 'c' de la GPU a la CPU
  cudaMemcpy(C_h,C_d,N*sizeof(float),cudaMemcpyDeviceToHost);

  //Desplegar el resultado
  for(int i=0; i<N; i++){
    printf("%.2f*%.2f=%.2f\n",A_h[i],B_h[i],C_h[i]);
  }

  free(A_h);
  free(B_h);
  free(C_h);

  cudaFree(A_d);
  cudaFree(B_d);
  cudaFree(C_d);
  return 0;
  
} 