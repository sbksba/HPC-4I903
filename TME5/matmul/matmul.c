/*
 * Université Pierre et Marie Curie
 *
 * Programme de multiplication de deux matrices carrees :
 * dans le main vous trouverez deux jeux de test. 
*/
#ifdef _OPENMP
#include <omp.h>
#endif

#include <sys/time.h>

#include<stdio.h>
#include <stdlib.h>



double my_gettimeofday(){
  struct timeval tmp_time;
  gettimeofday(&tmp_time, NULL);
  return tmp_time.tv_sec + (tmp_time.tv_usec * 1.0e-6L);
}

void matmul(int n, double *a, double *b, double *r)
{
  int i,j,k;
  double s;
#pragma omp parallel
  {
#pragma omp for private(j,k,s)
    for(i=0; i<n ; i++){
      for(j=0; j<n ; j++){
	s=0;
	for(k=0; k<n ; k++)
	  s+=a[i*n+k]*b[k*n+j];
	r[i*n+j]=s;
      }
    }
  }
}

/* programme de test */

int main()
{
  int i,j,k,n;
  double t_start = 0.0, t_stop = 0.0;


  /******************************************************/
  /******************************************************/
  /* jeu de test 1*/
  
  /*   n=2; */
  /*   double a[]={1,2,2,1}, b[]={1,1,1,2},c[n*n]; */
  
  /* résultat sous forme matriciel */
  /*     c=  */
  /*     +3.000000e+00  +5.000000e+00 */
  /*     +3.000000e+00  +4.000000e+00 */



  /******************************************************/
  /******************************************************/
  /* jeu de test 2 */
  
      n=512;
      double *a,*b,*c;
      if (((a=malloc(n*n*sizeof(double)))==NULL)||
          ((b=malloc(n*n*sizeof(double)))==NULL)||
          ((c=malloc(n*n*sizeof(double)))==NULL)){
        fprintf(stderr,"erreur allocation memoire\n");
        exit(1);
      }
  
      for(i=0; i<n ; i++)
        for(j=0; j<n ; j++){
          a[i*n+j]=1/((double)(i+j+1));
          b[j*n+j]=a[i*n+j];
        }
  
      /* n=512 premier carré :  */
      /* +1.953125e-03  +9.746589e-04   */
      /* +9.765625e-04  +6.497726e-04   */

      /* n=512 deuxième carré: */
      /* +9.583483e-07  +9.564747e-07   */
      /* +9.574105e-07  +9.555397e-07   */
  


  /******************************************************/
  /******************************************************/
  
  t_start=my_gettimeofday();
  
  matmul(n,a,b,c);
  
  t_stop=my_gettimeofday();


  /* affichage du premier carre 2x2 de la matrice c*/
  for(i=0; i<2 ; i++){
    for(j=0; j<2 ; j++)
      printf("%+e  ",c[i*n+j]);
    printf("\n");
  }
  printf("\n");
  /* affichage du dernier carre 2x2 de la matrice c*/
  for(i=n-2; i<n ; i++){
    for(j=n-2; j<n ; j++)
      printf("%+e  ",c[i*n+j]);
    printf("\n");
  }

  printf("\nTemps de calcul : %gs\n", t_stop - t_start);
}
 

