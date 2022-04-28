/*
*   GAUSSIAN ELIMINATION WITH BACKWARD SUBSTITUTION ALGOTITHM 6.1
*
*   To solve the n by n linear system
*
*   E1:  A[1,1] X[1] + A[1,2] X[2] +...+ A[1,n] X[n] = A[1,n+1]
*   E2:  A[2,1] X[1] + A[2,2] X[2] +...+ A[2,n] X[n] = A[2,n+1]
*   :
*   .
*   EN:  A[n,1] X[1] + A[n,2] X[2] +...+ A[n,n] X[n] = A[n,n+1]
*
*   INPUT:   number of unknowns and equations n; augmented
*            matrix A = (A(I,J)) where 1<=I<=n and 1<=J<=n+1.
*
*   OUTPUT:  solution x(1), x(2),...,x(n) or a message that the
*            linear system has no unique solution.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double [][13], int *);
void OUTPUT(int, int, int, double *, double [][13]);

main()
{
   double A[12][13], X[12];
   double C,XM,SUM;
   int N,M,I,J,ICHG,NN,IP,JJ,K,L,KK,OK;

   INPUT(&OK, A, &N);
   if (OK) {
      /* STEP 1 */
      NN = N - 1;
      M = N + 1;
      ICHG = 0;
      I = 1;
      while ((OK) && (I <= NN)) {
         /* STEP 2 */
         /* use IP instead of p */
         IP = I;
         while ((absval(A[IP-1][I-1]) <= ZERO) && (IP <= N))
            IP++;
         if (IP == M) OK = false;
         else {
            /* STEP 3 */
            if (IP != I) {
               for (JJ=1; JJ<=M; JJ++) {
                  C = A[I-1][JJ-1];
                  A[I-1][JJ-1] = A[IP-1][JJ-1];
                  A[IP-1][JJ-1] = C;
               }
               ICHG = ICHG + 1;
            }  
            /* STEP 4 */
            JJ = I + 1; 
            for (J=JJ; J<=N; J++) {
               /* STEP 5 */
               /* use XM in place of m(J,I) */
               XM = A[J-1][I-1] / A[I-1][I-1]; 
               /* STEP 6 */
               for (K=JJ; K<=M; K++)
                  A[J-1][K-1] = A[J-1][K-1] - XM * A[I-1][K-1];
               /*  Multiplier XM could be saved in A[J,I].  */
               A[J-1][I-1] = 0.0;
            }  
         }
         I = I + 1;
      }
      if (OK) {
         /* STEP 7 */
         if (absval(A[N-1][N-1]) <= ZERO) OK = false;
         else {
            /* STEP 8 */
            /* start backward substitution */
            X[N-1] = A[N-1][M-1] / A[N-1][N-1];
            /* STEP 9 */
            for (K=1; K<=NN; K++) {
               I = NN - K + 1;
               JJ = I + 1;
               SUM = 0.0;
               for (KK=JJ ; KK<=N; KK++)  
                  SUM = SUM - A[I-1][KK-1] * X[KK-1];
               X[I-1] = (A[I-1][M-1]+SUM) / A[I-1][I-1];
            }
            /* STEP 10 */
            /* procedure completed successfully */
            OUTPUT(N, M, ICHG, X, A);
         }  
      }
      if (!OK) printf("System has no unique solution\n");
   }
   return 0;
}

void INPUT(int *OK, double A[][13], int *N)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is Gaussian Elimination to solve a linear system.\n");
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,N+1), A(2,1), A(2,2), ..., A(2,N+1),\n");
   printf("..., A(N,1), A(N,2), ..., A(N,N+1)\n\n");
   printf("Place as many entries as desired on each line, but separate ");
   printf("entries with\n");
   printf("at least one blank.\n\n\n");
   printf("Has the input file been created? - enter Y or N.\n");
   scanf("%c",&AA);
   *OK = false;
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
            *OK = true;
            fclose(INP);
         }
         else printf("The number must be a positive integer.\n");
      }
   }
   else printf("The program will end so the input file can be created.\n");
}


void OUTPUT(int N, int M, int ICHG, double *X, double A[][13])
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
   fprintf(OUP, "GAUSSIAN ELIMINATION\n\n");
   fprintf(OUP, "The reduced system - output by rows:\n");
   for (I=1; I<=N; I++) {
      for (J=1; J<=M; J++) fprintf(OUP, " %11.8f", A[I-1][J-1]);
      fprintf(OUP, "\n");
   }
   fprintf(OUP, "\n\nHas solution vector:\n");
   for (I=1; I<=N; I++) fprintf(OUP, "  %12.8f", X[I-1]);
   fprintf (OUP, "\n\nwith %d row interchange(s)\n", ICHG);
   fclose(OUP);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
