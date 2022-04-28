/*
*   LDL-t ALGORITHM 6.5
*
*   To factor the positive definite n by n matrix A into LDL**T,
*   where L is a lower triangular matrix with ones along the diagonal
*   and D is a diagonal matrix with positive entries on the
*   diagonal.
*
*   INPUT:   the dimension n; entries A(I,J), 1<=I, J<=n of A.
*
*   OUTPUT:  the entries L(I,J), 1<=J<I, 1<=I<=N of L and D(I),
*            1<=I<=n of D.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

void INPUT(int *, double [][11], int *);
void OUTPUT(int, double *, double [][11]);

main()
{
   double A[10][11],D[10],V[10];
   double S;
   int N,I,J,K,NN,JJ,KK,OK;

   INPUT(&OK, A, &N);
   if (OK) {
      /* STEP 1 */
      for (I=1; I<=N; I++) { 
         /* STEP 2 */
         for (J=1; J<=I-1; J++) V[J-1] = A[I-1][J-1] * D[J-1];
         /* STEP 3 */
         D[I-1] = A[I-1][I-1];
         for (J=1; J<=I-1; J++) D[I-1] = D[I-1] - A[I-1][J-1] * V[J-1];
         /* STEP 4 */
         for (J=I+1; J<=N; J++) {
            for (K=1; K<=I-1; K++)
               A[J-1][I-1] = A[J-1][I-1] - A[J-1][K-1] * V[K-1];
            A[J-1][I-1] = A[J-1][I-1] / D[I-1];
         }  
      }  
      /* STEP 5 */
      OUTPUT(N, D, A);
   }
   return 0;
}

void INPUT(int *OK, double A[][11], int *N)
{
   int I, J;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the LDL^t Method for Positive Definite Matrices.\n");
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
   }
   else {
       printf("The program will end so the input file can be created.\n");
       *OK = false;
   }
}


void OUTPUT(int N, double *D, double A[][11])
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
   fprintf(OUP, "LDL^t FACTORIZATION\n\n");
   fprintf(OUP, "The matrix L output by rows:\n");
   for (I=1; I<=N; I++) {
      for (J=1; J<=I-1; J++) fprintf(OUP, "  %12.8f", A[I-1][J-1]);
      fprintf(OUP, "\n");
   }
   fprintf(OUP, "The diagonal of D:\n");
   for (I=1; I<=N; I++) fprintf(OUP, "  %12.8f", D[I-1]);
   fprintf(OUP, "\n");
   fclose(OUP);
}
