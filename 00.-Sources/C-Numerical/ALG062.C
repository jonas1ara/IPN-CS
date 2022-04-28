/*
*   GAUSSIAN ELIMINATION WITH PARTIAL PIVOTING ALGORITHM 6.2
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
void INPUT(int *, double [][11], int *);
void OUTPUT(int, int, int, int *, double *, double [][11]);

main()
{
   double A[10][11], X[10];
   double AMAX,XM,SUM;
   int NROW[10];
   int N,M,ICHG,I,NN,IMAX,J,JJ,IP,JP,NCOPY,I1,J1,N1,K,N2,LL,KK,OK;

   INPUT(&OK, A, &N);
   if (OK) {
      M = N + 1;
      /* STEP 1 */
      for (I=1; I<=N; I++) NROW[I-1] = I;
      /* initialize row pointer */
      NN = N - 1;
      ICHG = 0;
      I = 1; 
      /* STEP 2 */
      while ((OK) && (I <= NN)) {
         /* STEP 3 */
         IMAX = NROW[I-1];
         AMAX = absval(A[IMAX-1][I-1]);
         IMAX = I;
         JJ = I + 1;
         for (IP=JJ; IP<=N; IP++) {
            JP = NROW[IP-1];
            if (absval(A[JP-1][I-1]) > AMAX) {
               AMAX = absval(A[JP-1][I-1]);
               IMAX = IP;
            }
         }  
         /* STEP 4 */
         if (AMAX <= ZERO) OK = false;
         else { 
            /* STEP 5 */
            /* simulate row interchange */
            if ( NROW[I-1] != NROW[IMAX-1]) {
               ICHG = ICHG + 1;
               NCOPY = NROW[I-1];
               NROW[I-1] = NROW[IMAX-1];
               NROW[IMAX-1] = NCOPY;
            }
            I1 = NROW[I-1];
            /* STEP 6 */
            for (J=JJ; J<=N; J++) {
               J1 = NROW[J-1];
               /* STEP  7 */
               XM = A[J1-1][I-1] / A[I1-1][I-1];
               /* STEP 8 */
               for (K=JJ; K<=M; K++) 
                  A[J1-1][K-1] = A[J1-1][K-1] - XM * A[I1-1][K-1];
               /* Multiplier XM could be saved in A[J1-1,I-1]  */
               A[J1-1][I-1] = 0.0;
            }  
         }  
         I++;
      }
      if (OK) {
         /* STEP 9 */
         N1 = NROW[N-1];
         if (absval(A[N1-1][N-1]) <= ZERO) OK = false;
         /* system has no unique solution */
         else {
            /* STEP 10 */
            /* start backward substitution */
            X[N-1] = A[N1-1][M-1] / A[N1-1][N-1];
            /* STEP 11 */
            for (K=1; K<=NN; K++) {
               I = NN - K + 1;
               JJ = I + 1;
               N2 = NROW[I-1];
               SUM = 0.0;
               for (KK=JJ; KK<=N; KK++) {
                  SUM = SUM - A[N2-1][KK-1] * X[KK-1];
               }  
               X[I-1] = (A[N2-1][N] + SUM) / A[N2-1][I-1];
            }  
            /* STEP 12 */
            /* procedure completed successfully */
            OUTPUT(N, M, ICHG, NROW, X, A);
         }  
      }
      if (!OK) printf("System has no unique solution\n");
   }
   return 0;
}

void INPUT(int *OK, double A[][11], int *N)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is Gauss Elimination with Partial Pivoting.\n");
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,N+1), A(2,1), A(2,2), ..., A(2,N+1),\n");
   printf("..., A(N,1), A(N,2), ..., A(N,N+1)\n\n");
   printf("Place as many entries as desired on each line, but separate ");
   printf("entries with\n");
   printf("at least one blank.\n\n\n");
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
            *OK = true;
            fclose(INP);
         }
         else printf("The number must be a positive integer.\n");
      }
   }
   else {
      printf("The program will end so the input file can be created.\n");
      *OK = false;
   }
}


void OUTPUT(int N, int M, int ICHG, int *NROW, double *X, double A[][11])
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
   fprintf(OUP, "GAUSSIAN ELIMINATION - PARTIAL PIVOTING\n\n");
   fprintf(OUP, "The reduced system - output by rows:\n");
   for (I=1; I<=N; I++) {
      for (J=1; J<=N; J++) fprintf(OUP, " %11.8f", A[I-1][J-1]);
      fprintf(OUP, "\n");
   }
   fprintf(OUP, "\n\nHas solution vector:\n");
   for (I=1; I<=N; I++) {
      fprintf(OUP, "  %12.8f", X[I-1]);
   }
   fprintf (OUP, "\nwith %d row interchange(s)\n", ICHG);
   fprintf(OUP, "\nThe rows have been logically re-ordered to:\n");
   for (I=1; I<=N; I++) fprintf(OUP, " %2d", NROW[I-1]); fprintf(OUP,"\n");
   fclose(OUP);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
