#ifdef _OPENMP
#include <omp.h>
#endif

#include <stdio.h>

#define N 1000000000

int main()
{
  double res=0;
  long i;
#pragma omp parallel
  {
#pragma omp for reduction(+:res) private(i)
    for (i=0; i<=N; i++)
      res += 4 / (1 + ((double)i/(double)N) * ((double)i/(double)N));
  }
  
  res *= 1/(double)N;
  printf ("[PI] %f\n",res);
  
  return 0;
}
