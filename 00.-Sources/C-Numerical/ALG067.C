/*
*   CROUT REDUCTION FOR TRIDIAGONAL LINEAR SYSTEMS ALGORITHM 6.7
*
*   To solve the n x n linear system
*
*   E1:  A[1,1] X[1] + A[1,2] X[2]                  = A[1,n+1]
*   E2:  A[2,1] X[1] + A[2,2] X[2] + A[2,3] X[3]    = A[2,n+1]
*   :
*   .
*   E(n):          A[n,n-1] X[n-1] + A[n,n] X[n]    = A[n,n+1]
*
*   INPUT:   the dimension n; the entries of A.
*
*   OUTPUT:  the solution X(1), ..., X(N).
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

void INPUT(int *, double *, double *, double *, double *, int *, int *);
void OUTPUT(int, double *);

main()
{
   double A[10],B[10],C[10],BB[10],Z[10],X[10];
   int N,I,J,NN,II,OK;

   INPUT(&OK, A, B, C, BB, &N, &NN);
   if (OK) {
      /* Steps 1-3 set up and solve LZ = B   */
      /* STEP 1 */
      /* the entries of U overwrite C and
            the entries of L overwrite A */
      C[0] = C[0] / A[0]; 
      Z[0] = BB[0] / A[0];
      /* STEP 2 */
      for (I=2; I<=NN; I++) {
         A[I-1] = A[I-1] - B[I-1] * C[I-2];
         C[I-1] = C[I-1] / A[I-1];
         Z[I-1] = (BB[I-1]-B[I-1]*Z[I-2])/A[I-1];
      }
      /* STEP 3 */
      A[N-1] = A[N-1] - B[N-1] * C[N-2];
      Z[N-1] = (BB[N-1]-B[N-1]*Z[N-2])/A[N-1];
      /* STEP 4 */
      /* STEPS 4, 5 solve UX = Z */
      X[N-1] = Z[N-1];
      /* STEP 5 */
      for (II=1; II<=NN; II++) {
         I = NN - II + 1;
         X[I-1] = Z[I-1] - C[I-1] * X[I];
      }
      /* STEP 6 */
      OUTPUT(N, X);
   }
   return 0;
}

void INPUT(int *OK, double *A, double *B, double *C, double *BB, int *N, int *NN)
{
   int I, J;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is Crout Method for tridiagonal linear systems.\n");
   printf("The array will be input from a text file in the order:\n");
   printf("all diagonal entries, all lower sub-diagonal entries, all ");
   printf("upper sub-diagonal\n");
   printf("entries, inhomogeneous term.\n\n");
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
            /* A(I,I) is stored in A(I), 1 <= I <= n */
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &A[I-1]);
            fscanf(INP, "\n");
            /* the lower sub-diagonal A(I,I-1) is stored
               in B(I), 2 <= I <= n */ 
            for (I=2; I<=*N; I++) fscanf(INP, "%lf", &B[I-1]);
            fscanf(INP, "\n");
            /* the upper sub-diagonal A(I,I+1) is stored
               in C(I), 1 <= I <= n-1 */ 
            *NN = *N - 1;
            for (I=1; I<=*NN; I++) fscanf(INP, "%lf", &C[I-1]);
            fscanf(INP, "\n");
            /* A(I,N+1) is stored in BB(I), 1 <= I <= n */
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &BB[I-1]);
            *OK = true;
            fclose(INP);
         }
         else printf("The number must be a positive integer.\n");
      }
   }
   else printf("The program will end so the input file can be created.\n");
}


void OUTPUT(int N, double *X)
{
   int I, FLAG;
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
   fprintf(OUP, "CROUT METHOD FOR TRIDIAGONAL LINEAR SYSTEMS\n\n");
   fprintf(OUP, "The solution is\n");
   for (I=1; I<=N; I++) fprintf(OUP, "  %12.8f", X[I-1]);
   fprintf(OUP, "\n");
   fclose(OUP);
}
