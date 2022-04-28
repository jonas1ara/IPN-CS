/*
*   DIRECT FACTORIZATION ALGORITHM 6.4
*
*   To factor the n by n matrix A = (A(I,J)) into the product of the
*   lower triangular matrix L = (L(I,J)) and U = (U(I,J)), that is
*   A = LU, where the main diagonal of either L or U consists of all ones:
*
*   INPUT:   dimension n; the entries A(I,J), 1<=I, J<=n, of A;
*            the diagonal L(1,1), ..., L(N,N) of L or the diagonal
*            U(1,1), ..., U(N,N) of U.
*
*   OUTPUT:  the entries L(I,J), 1<=J<=I, 1<=I<=n of L and the entries
*            U(I,J), I<=J<=n, 1<=I<=n of U.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double [][10], int *, int *);
void OUTPUT(int, double [][10], int);

main()
{
   double A[10][10],XL[10];
   double S,SS;
   int N,M,I,J,ISW,JJ,K,KK,OK;

   INPUT(&OK, A, &N, &ISW);
   if (OK) {
      for (I=1; I<=N; I++) XL[I-1] = 1.0;
      /* STEP 1 */
      if (absval(A[0][0]) <= ZERO) OK = false;
      else {
         /* the entries of L below the main diagonal will be
            placed in the corresponding entries of A; the
            entries of U above the main diagonal will be
            placed in the corresponding entries of A; the
            main diagonal which was NOT input will become
            the main diagonal of A; the input main diagonal
            of L or U is, of course, placed in XL.           */
         A[0][0] = A[0][0] / XL[0];
         /* STEP 2 */
         for (J=2; J<=N; J++) {
            if (ISW == 0) {
               /* first row of U */
               A[0][J-1] = A[0][J-1] / XL[0];
               /* first column of L */
               A[J-1][0] = A[J-1][0] / A[0][0];
            }
            else {
               /* first row of U */
               A[0][J-1] = A[0][J-1] / A[0][0];
               /* first column of L */
               A[J-1][0] = A[J-1][0] / XL[0];
            }
         }
         /* STEP 3 */
         M = N - 1;
         I = 2;
         while ((I <= M) && OK) {
            /* STEP 4 */
            KK = I - 1;
            S = 0.0;
            for (K=1; K<=KK; K++) S = S - A[I-1][K-1] * A[K-1][I-1];
            A[I-1][I-1] = ( A[I-1][I-1] + S ) / XL[I-1];
            if (absval(A[I-1][I-1]) <= ZERO) OK = false;
            else { 
               /* STEP 5 */
               JJ = I + 1;
               for (J=JJ; J<=N; J++) {
                  SS = 0.0;
                  S = 0.0;
                  for (K=1; K<=KK; K++) {
                     SS = SS - A[I-1][K-1] * A[K-1][J-1];
                     S = S - A[J-1][K-1] * A[K-1][I-1];
                  }  
                  if (ISW == 0) {
                     /* Ith row of U */
                     A[I-1][J-1] = (A[I-1][J-1] + SS) / XL[I-1];
                     /* Ith column of L */
                     A[J-1][I-1] = (A[J-1][I-1] + S) / A[I-1][I-1];
                  }
                  else {
                     /* Ith row of U */
                     A[I-1][J-1] = (A[I-1][J-1] + SS) / A[I-1][I-1];
                     /* Ith column of L */
                     A[J-1][I-1] = (A[J-1][I-1] + S) / XL[I-1];
                  }  
               }  
            }  
            I++;
         }  
         if (OK) {
            /* STEP 6 */
            S = 0.0;
            for (K=1; K<=M; K++)  S = S - A[N-1][K-1] * A[K-1][N-1];
            A[N-1][N-1] = (A[N-1][N-1] + S) / XL[N-1];
            /* If A(N-1,N-1) = 0 then A = LU but the matrix is singular.
               Process is complete, all entries of A have been
               determined. */
            /* STEP 7 */
            OUTPUT(N, A, ISW);
         }  
      }  
      if (!OK) printf("System has no unique solution\n");
   }
   return 0;
}

void INPUT(int *OK, double A[][10], int *N, int *ISW)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the general LU factorization method.\n");
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,N), A(2,1), A(2,2), ..., A(2,N),\n");
   printf("..., A(N,1), A(N,2), ..., A(N,N)\n\n");
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
         printf("Input the dimension n - an integer.\n");
         scanf("%d", N);
         if (*N > 0) {
            for (I=1; I<=*N; I++) {
               for (J=1; J<=*N; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
               fscanf(INP, "\n");
            }
            *OK = true;
            fclose(INP);
         }
         else printf("The number must be a positive integer.\n");
      }
      printf("Choice of diagonals:\n");
      printf("1. Diagonal of L consists of ones\n"); 
      printf("2. Diagonal of U consists of ones\n");
      printf("Please enter 1 or 2.\n");
      scanf("%d", &FLAG);
      if (FLAG == 1) *ISW = 0;
      else *ISW = 1;
   }
   else printf("The program will end so the input file can be created.\n");
}


void OUTPUT(int N, double A[][10], int ISW)
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
   fprintf(OUP, "GENERAL LU FACTORIZATION\n\n");
   if (ISW == 0) 
      fprintf(OUP, "The diagonal of L consists of all entries = 1.0\n");
   else
      fprintf(OUP, "The diagonal of U consists of all entries = 1.0\n");
   fprintf(OUP, "\nEntries of L below/on diagonal and entries of U above");
   fprintf(OUP, "/on diagonal\n");
   fprintf(OUP, "- output by rows in overwrite format:\n");
   for (I=1; I<=N; I++) {
      for (J=1; J<=N; J++) fprintf(OUP, " %11.8f", A[I-1][J-1]);
      fprintf(OUP, "\n");
   }
   fclose(OUP);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
