/*
*   CHOLESKI'S ALGORITHM 6.6
*
*   To factor the positive definite n by n matrix A into LL**T,
*   where L is lower triangular.
*
*   INPUT:   the dimension n; entries A(I,J), 1<=I, J<=n of A.
*
*   OUTPUT:  the entries L(I,J), 1<=J<=I, 1<=I<=n of L.
*
*   the entries of U = L**T are U(I,J) = L(J,I), I<=J<=n, 1<=I<=n
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

void INPUT(int *, double [][10], int *);
void OUTPUT(int, double [][10]);

main()
{
   double A[10][10];
   double S;
   int N,I,J,K,NN,JJ,KK,OK;

   INPUT(&OK, A, &N);
   if (OK) {
      /* STEP 1 */
      A[0][0] = sqrt(A[0][0]);
      /* STEP 2 */
      for (J=2; J<=N; J++)  A[J-1][0] = A[J-1][0] / A[0][0];
      /* STEP 3 */
      NN = N - 1;
      for (I=2; I<=NN; I++) {
         /* STEP 4 */
         KK = I - 1;
         S = 0.0;
         for (K=1; K<=KK; K++)  S = S - A[I-1][K-1] * A[I-1][K-1];
         A[I-1][I-1] = sqrt(A[I-1][I-1] + S);
         /* STEP 5 */
         JJ = I + 1;
         for (J=JJ; J<=N; J++) {
            S = 0.0;
            KK = I - 1;
            for (K=1; K<=KK; K++) S = S - A[J-1][K-1] * A[I-1][K-1];
            A[J-1][I-1] = (A[J-1][I-1] + S) / A[I-1][I-1]; 
         }  
      }
      /* STEP 6 */
      S = 0.0;
      for (K=1; K<=NN; K++)  S = S - A[N-1][K-1] * A[N-1][K-1];
      A[N-1][N-1] = sqrt( A[N-1][N-1] + S);
      /* STEP 7 */
      OUTPUT(N, A);
   }
   return 0;
}

void INPUT(int *OK, double A[][10], int *N)
{
   int I, J;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is Choleski Factorization Method.\n");
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
         printf("Input the dimension - an integer.\n");
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


void OUTPUT(int N, double A[][10])
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
   fprintf(OUP, "CHOLESKI FACTORIZATION\n\n");
   fprintf(OUP, "The matrix L output by rows:\n");
   for (I=1; I<=N; I++) {
      for (J=1; J<=I; J++) fprintf(OUP, "  %12.8f", A[I-1][J-1]);
      fprintf(OUP, "\n");
   }
   fclose(OUP);
}
