#include <stdio.h>
#include <mpi.h>

int main (int argc, char **argv)
{
  int rang, p, valeur, tag=10;
  MPI_Status status;

  MPI_Init (&argc, &argv);
  MPI_Comm_size (MPI_COMM_WORLD, &p);
  MPI_Comm_rank (MPI_COMM_WORLD, &rang);

  if (rang == 1)
    {
      valeur = 10;
      MPI_Send (&valeur, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }
  else if (rang == 0)
    {
      MPI_Recv (&valeur, 1, MPI_INT, 1, tag, MPI_COMM_WORLD, &status);
      printf("[RECV] rang #%d valeur %d -> processus de rang #1.\n",rang,valeur);
    }

  MPI_Finalize();
}
