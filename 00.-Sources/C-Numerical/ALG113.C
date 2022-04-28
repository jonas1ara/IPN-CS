/*
*   LINEAR FINITE-DIFFERENCE ALGORITHM 11.3
*
*   To approximate the solution of the boundary-value problem
*
*      Y'' = P(X)Y' + Q(X)Y + R(X), A<=X<=B, Y(A) = ALPHA, Y(B) = BETA:
*
*   INPUT:   Endpoints A, B; boundary conditions ALPHA, BETA;
*            integer N.
*
*   OUTPUT:  Approximations W(I) to Y(X(I)) for each I=0,1,...,N+1.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double A[24], B[24], C[24], D[24], L[24], U[24], Z[24], W[24];
   double AA,BB,ALPHA,BETA,X,H;
   int N,I,M,J,OK;
   FILE *OUP[1];

   double F(double, double);
   void INPUT(int *, double *, double *, double *, double *, int *);
   void OUTPUT(FILE **);
   double P(double);
   double Q(double);
   double R(double);

   INPUT(&OK, &AA, &BB, &ALPHA, &BETA, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      H = ( BB - AA ) / ( N + 1.0 );
      X = AA + H;
      A[0] = 2.0 + H * H * Q( X );
      B[0] = -1.0 + 0.5 * H * P( X );
      D[0] = -H*H*R(X)+(1.0+0.5*H*P(X))*ALPHA;
      M = N - 1;
      /* STEP 2 */
      for (I=2; I<=M; I++) {
         X = AA + I * H;
         A[I-1] = 2.0 + H * H * Q( X );
         B[I-1] = -1.0 + 0.5 * H * P( X );
         C[I-1] = -1.0 - 0.5 * H * P( X );
         D[I-1] = -H * H * R( X );
      }  
      /* STEP 3 */
      X = BB - H;
      A[N-1] = 2.0 + H * H * Q( X );
      C[N-1] = -1.0 - 0.5 * H * P( X );
      D[N-1] = -H*H*R(X)+(1.0-0.5*H*P(X))*BETA;
      /* STEP 4 */
      /* STEPS 4 through 8 solve a triagiagonal linear system using
         Algorithm 6.7 */
      L[0] = A[0];
      U[0] = B[0] / A[0];
      Z[0] = D[0] / L[0];
      /* STEP 5 */
      for (I=2; I<=M; I++) {
         L[I-1] = A[I-1] - C[I-1] * U[I-2];
         U[I-1] = B[I-1] / L[I-1];
         Z[I-1] = (D[I-1]-C[I-1]*Z[I-2])/L[I-1];
      }
      /* STEP 6 */
      L[N-1] = A[N-1] - C[N-1] * U[N-2];
      Z[N-1] = (D[N-1]-C[N-1]*Z[N-2])/L[N-1];
      /* STEP 7 */
      W[N-1] = Z[N-1];
      /* STEP 8 */
      for (J=1; J<=M; J++) {
         I = N - J;
         W[I-1] = Z[I-1] - U[I-1] * W[I];
      }
      I = 0;
      /* STEP 9 */
      fprintf(*OUP, "%3d %13.8f %13.8f\n", I, AA, ALPHA);
      for (I=1; I<=N; I++) {
         X = AA + I * H;
         fprintf(*OUP, "%3d %13.8f %13.8f\n", I, X, W[I-1]);
      }  
      I = N + 1;
      fprintf(*OUP, "%3d %13.8f %13.8f\n", I, BB, BETA);
      /* STEP 12 */
      fclose(*OUP);
   }
   return 0;
}

/* Change functions P, Q and R for a new problem */
double P(double X)
{
   double p; 

   p = -2/X;
   return p;
}

double Q(double X)
{
   double q; 

   q = 2/(X*X);
   return q;
}

double R(double X)
{
   double r; 

   r = sin(log(X))/(X*X);
   return r;
}

void INPUT(int *OK, double *AA, double *BB, double *ALPHA, double *BETA, int *N)
{
   double X; 
   char AB;

   printf("This is the Linear Finite-Difference Method.\n");
   *OK = true;
   printf("Have the functions P, Q, and R been created immediately\n");
   printf("preceding the INPUT procedure?\n");
   printf("Answer Y or N.\n");
   scanf("%c",&AB);
   *OK = false;
   if ((AB == 'Y') || (AB == 'y')) {
      *OK = false;
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank.\n");
         scanf("%lf %lf", AA, BB);
         if (*AA >= *BB) 
            printf("Left endpoint must be less than right endpoint.\n");
         else *OK = true;
      }
      printf("Input Y(  %.10e).\n", *AA);
      scanf("%lf", ALPHA);
      printf("Input Y(  %.10e).\n", *BB);
      scanf("%lf", BETA);
      *OK = false;
      while(!(*OK)) {
         printf("Input an integer > 1 for the number of\n");
         printf("subintervals.  Note that h = (b-a)/(n+1)\n");
         scanf("%d", N);
         if (*N <= 1) printf("Number must exceed 1.\n");
         else *OK = true;
      }
   }
   else printf("The program will end so that P, Q, R can be created.\n");
}

void OUTPUT(FILE **OUP)
{
   char NAME[30];
   int FLAG; 

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text File\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "LINEAR FINITE DIFFERENCE METHOD\n\n");
   fprintf(*OUP, "  I          X(I)          W(I)\n");
}   
