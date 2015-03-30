#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <mpi.h>

#define SIZE_H_N 50

int main (int argc, char **argv)
{
  int rang, p, valeur, tag=0, source, dest;
  char message[100];
  char hostname[SIZE_H_N];
  MPI_Status status;

  gethostname(hostname,SIZE_H_N);

  MPI_Init (&argc, &argv);
  MPI_Comm_size (MPI_COMM_WORLD, &p);
  MPI_Comm_rank (MPI_COMM_WORLD, &rang);

  sprintf(message,"[PROC] #%d depuis %s.",rang,hostname);

  if (rang != 0)
    {
      MPI_Ssend(message, strlen(message) + 1, MPI_CHAR, (rang + 1) % p, tag, MPI_COMM_WORLD);
      MPI_Recv(message, SIZE_H_N, MPI_CHAR, (rang - 1) % p, tag, MPI_COMM_WORLD, &status);
      printf("[HOSTNAME #%s] proc #%d -> message : %s.\n",hostname,rang,message);
    }
  else
    { 
      MPI_Recv(message, SIZE_H_N, MPI_CHAR, p-1, tag, MPI_COMM_WORLD, &status);
      printf("[HOSTNAME #%s] proc #%d -> message : %s.\n",hostname,rang,message);
      MPI_Ssend(message, strlen(message) + 1, MPI_CHAR, (rang + 1) % p, tag, MPI_COMM_WORLD);
    }

  MPI_Finalize();
}
