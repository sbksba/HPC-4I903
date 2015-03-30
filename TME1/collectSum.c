#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <mpi.h>

#define SIZE_H_N 50

int rand_a_b(int a, int b) {return rand()%(b-a) +a;}

int main (int argc, char **argv)
{
  int rang,size,source;
  int sum=0,somme=0;
  char hostname[SIZE_H_N];

  gethostname(hostname,SIZE_H_N);

  MPI_Init(&argc, &argv);

  MPI_Comm_rank(MPI_COMM_WORLD, &rang);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  if (rang != 0)
    {
      srand(getpid());
      sum = rand_a_b(1,10);
      printf("[HOSTNAME #%s] proc #%d -> value : %d.\n",hostname,rang,sum);
    }

  MPI_Reduce(&sum, &somme, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

  if (rang == 0)
    {
      printf("\n[HOSTNAME #%s] proc #%d -> total : %d.\n",hostname,rang,somme);
    }

  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
}
