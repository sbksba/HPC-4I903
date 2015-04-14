#include <sys/time.h>
#include <stdio.h> 

#include <immintrin.h>

//#define N 1024
#define N 16384
//#define N 1048576
//#define N 16777216
//#define NB_TIMES 1
#define NB_TIMES 1000000

double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

float A[N];
float B[N];
float C[N];

int main(){
  int i,k;
  double start, stop;
  float res = 0.0; 
  __m256 a;
  __m256 b;
  __m256 c;

  for (i=0;i<N;i++){
    A[i]=1.0;
    B[i]=1.0;
    C[i]=0.0;
  }

  start = my_gettimeofday();

  for (k=0; k<NB_TIMES;k++)
    { 
      for (i=0;i<N;i=i+8)
	{
	  a = __m256_load_ps(&A[i]);
	  b = __m256_load_ps(&B[i]);
	  c = _mm256_mul_ps(a,b);
	  _mm256_store_ps(&C[i],c);
	  res += A[i]*B[i]; 
	}
    }
    
  stop = my_gettimeofday(); 
  fprintf(stdout, "res = %f \n", C); 
  fprintf(stdout, "Temps total de calcul : %g sec\n", stop - start);

  return 0; 
}
