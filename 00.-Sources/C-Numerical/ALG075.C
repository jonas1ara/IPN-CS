/*
*   CONJUGATE GRADIENT ALGORITHM 7.5
*
*   To solve Ax = b given the preconditioning matrix C inverse and
*   an initial approximation x(0):
*
*   INPUT:   the number of equations and unknowns n; the entries
*            A(I,J), 1<=I, J<=n, of the matrix A; the entries
*            B(I), 1<=I<=n, of the inhomogeneous term b; the
*            entries C(I,J), 1<=I, J<=n, of the matrix C inverse,
*            the entries XO(I), 1<=I<=n, of x(0); tolerance TOL;
*            maximum number of iterations N.
*
*    OUTPUT:  the approximate solution X(1),...,X(n) or a message
*             that the number of iterations was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double *, double [][10], double [][11], double *, int *, int *);
void OUTPUT(int, double *, double *, int, double);

main()
{
   double A[10][11],CI[10][10],CT[10][10];
   double X1[10],R[10],V[10],W[10],U[10],Z[10];
   double ALPHA,BETA,T,S,SS,QERR,ERR,TOL;
   int N,I,J,NN,K,OK;

   INPUT(&OK, X1, CI, A, &TOL, &N, &NN);
   if (OK) {
      /* STEP 1 */
      for (I=1; I<=N; I++)
        { for (J=1; J<=N; J++) CT[I-1][J-1] = CI[J-1][I-1];
        }
      for (I=1; I<=N; I++)
        { R[I-1] = A[I-1][N];
         for (J=1; J<=N; J++) R[I-1] = R[I-1] - A[I-1][J-1]*X1[J-1];
        }
      for (I=1; I<=N; I++)
        { W[I-1] = 0.0;
         for (J=1; J<=N; J++) W[I-1] = W[I-1] + CI[I-1][J-1]*R[J-1];
        }
      for (I=1; I<=N; I++)
        { V[I-1] = 0.0;
         for (J=1; J<=N; J++) V[I-1] = V[I-1] + CT[I-1][J-1]*W[J-1];
        }
      ALPHA = 0.0;
      for (I=1; I<=N; I++) ALPHA = ALPHA + W[I-1] * W[I-1];
      /* STEP 2 */
      K = 1;
      OK = false;
      /* STEP 3 */
      while ((!OK) && (K <= NN)) {
         /* err is used to test accuracy - it measures the  
         2-norm */
         ERR = 0.0; 
         /* STEP 4 */
         for (I=1; I<=N; I++)  ERR = ERR + V[I-1] * V[I-1];
         if (sqrt(ERR) <= TOL) {
            OK = true;
            K = K - 1;
         }
         /* process is complete */
         else
            /* STEP 5 */
          {  for (I=1; I<=N; I++)
              { U[I-1] = 0.0;
              for (J=1; J<=N; J++) U[I-1] = U[I-1] + A[I-1][J-1]*V[J-1];
            }
            S = 0.0;
            for (I=1; I<=N; I++) S = S + V[I-1] * U[I-1];
            T = ALPHA/S;
            for (I=1; I<=N; I++)
              { X1[I-1] = X1[I-1] + T * V[I-1];
                R[I-1] = R[I-1] - T * U[I-1];
            }
            for (I=1; I<=N; I++)
              { W[I-1] = 0.0;
              for (J=1; J<=N; J++) W[I-1] = W[I-1] + CI[I-1][J-1]*R[J-1];
            }
            BETA = 0.0;
            for (I=1; I<=N; I++) BETA = BETA + W[I-1] * W[I-1];
            /* STEP 6 */ 
            if ( sqrt(BETA) <= TOL)
             {
               ERR = 0.0;
               for (I=1; I<=N; I++) ERR = ERR + R[I-1]*R[I-1];
               if (sqrt(ERR) < TOL ) {
                  OK = true;
               }
             }
            if (!OK)
             {
             /* STEP 7 */
              K = K +1;
              S = BETA/ALPHA;
            for (I=1; I<=N; I++)
              { Z[I-1] = 0.0;
              for (J=1; J<=N; J++) Z[I-1] = Z[I-1] + CT[I-1][J-1]*W[J-1];
            }
            for (I=1; I<=N; I++) V[I-1] = Z[I-1] + S * V[I-1];
            ALPHA = BETA;
            }
         }
      }
      if (!OK) printf("Maximum Number of Iterations Exceeded.\n");
      /* STEP 8 */
      /* procedure completed unsuccessfully */
      else OUTPUT(N, X1, R, K, TOL);
   }
   return 0;
}

void INPUT(int *OK, double *X1, double CI [][10], double A[][11],double *TOL, int *N, int *NN)
{
   int I, J;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the Conjugate Gradient Method for Linear Systems.\n");
   *OK = false;
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,n+1), A(2,1), A(2,2), ..., A(2,n+1),\n");
   printf("..., A(n,1), A(n,2), ..., A(n,n+1)\n\n");
   printf("Place as many entries as desired on each line, but separate ");
   printf("entries with\n");
   printf("at least one blank.\n");
   printf("The preconditioner, C inverse, should follow in the same way.\n");
   printf("The initial approximation should follow in same format.\n\n\n");
   printf("Has the input file been created? - enter Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:DATA.DTA\n");
      scanf("%s", NAME);
      INP = fopen(NAME, "r");
      *OK = false;
      while (!(*OK)) {
         printf("Input the number of equations - an integer.\n");
         scanf("%d", N);
         if (*N > 0) {
            for (I=1; I<=*N; I++) {
               for (J=1; J<=*N+1; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
               fscanf(INP, "\n");
            }
            for (I=1; I<=*N; I++) {
               for (J=1; J<=*N; J++) fscanf(INP, "%lf", &CI[I-1][J-1]);
               fscanf(INP, "\n");
            }
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &X1[I-1]);
            /* use X1 for XO */
            *OK = true;
            fclose(INP);
         }
         else printf("The number must be a positive integer.\n");
      }
      *OK = false;
      while(!(*OK)) {
         printf("Input the tolerance.\n");
         scanf("%lf", TOL);
         if (*TOL > 0) *OK = true;
         else printf("Tolerance must be a positive number.\n");
      }
      *OK = false;
      while(!(*OK)) {
         printf("Input maximum number of iterations.\n");
         scanf("%d", NN);
         if (*NN > 0) *OK = true;
         else printf("Number must be a positive integer.\n"); 
      }
   }
   else printf("The program will end so the input file can be created.\n");
}


void OUTPUT(int N, double *X1, double *R, int K, double TOL)
{
   int I, J, FLAG;
   char NAME[30];
   FILE *OUP;

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      OUP = fopen(NAME, "w");
   }
   else OUP = stdout;
   fprintf(OUP, "CONJUGATE GRADIENT METHOD FOR LINEAR SYSTEMS\n\n");
   fprintf(OUP, "The solution vector is :\n");
   for (I=1; I<=N; I++) fprintf(OUP, " %11.8f", X1[I-1]);
   fprintf(OUP, "\n with residual vector :\n");
   for (I=1; I<=N; I++) fprintf(OUP, " %11.8f", R[I-1]);
   fprintf(OUP, "\nusing %d iterations with\n", K);
   fprintf(OUP, "Tolerance  %.10e in infinity-norm\n", TOL); 
   fclose(OUP);
}
/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
