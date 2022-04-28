/*
*   SOR ALGORITHM 7.3
*
*   To solve Ax = b given the parameter w and an initial approximation
*   x(0):
*
*   INPUT:   the number of equations and unknowns n; the entries
*            A(I,J), 1<=I, J<=n, of the matrix A; the entries
*            B(I), 1<=I<=n, of the inhomogeneous term b; the
*            entries XO(I), 1<=I<=n, of x(0); tolerance TOL;
*            maximum number of iterations N; parameter w (omega).
*
*    OUTPUT:  the approximate solution X(1),...,X(n) or a message
*             that the number of iterations was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double *, double [][11], double *, double *, int *, int *);
void OUTPUT(int, double *, int, double, double);

main()
{
   double A[10][11],X1[10];
   double W,S,ERR,TOL;
   int N,I,J,NN,K,OK;

   INPUT(&OK, X1, A, &TOL, &W, &N, &NN);
   if (OK) {
      /* STEP 1 */
      K = 1;
      OK = false;
      /* STEP 2 */
      while ((!OK) && (K <= NN)) {
         /* err is used to test accuracy - it measures the  
         infinity-norm */
         ERR = 0.0; 
         /* STEP 3 */
         for (I=1; I<=N; I++) {
            S = 0.0;
            for (J=1; J<=N; J++) S = S - A[I-1][J-1] * X1[J-1];
            S = W * (S + A[I-1][N]) / A[I-1][I-1];
            if (absval(S) > ERR) ERR = absval(S);
            X1[I-1] = X1[I-1] + S;
         }


         /* STEP 4 */
         if (ERR <= TOL) OK = true;
         /* process is complete */
         else
            /* STEP 5 */
            K++;
         /* STEP 6 - is not used since only one vector is required */
      }
      if (!OK) printf("Maximum Number of Iterations Exceeded.\n");
      /* STEP 7 */
      /* procedure completed unsuccessfully */
      else OUTPUT(N, X1, K, TOL, W);
   }
   return 0;
}

void INPUT(int *OK, double *X1, double A[][11], double *TOL, double *W, int *N, int *NN)
{
   int I, J;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the SOR Method for Linear Systems.\n");
   *OK = false;
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,n+1), A(2,1), A(2,2), ..., A(2,n+1),\n");
   printf("..., A(n,1), A(n,2), ..., A(n,n+1)\n\n");
   printf("Place as many entries as desired on each line, but separate ");
   printf("entries with\n");
   printf("at least one blank.\n");
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
      printf("Input parameter w (omega)\n");
      scanf("%lf", W);
      /* use W for omega */
   }
   else printf("The program will end so the input file can be created.\n");
}


void OUTPUT(int N, double *X1, int K, double TOL, double W)
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
   fprintf(OUP, "SOR ITERATIVE METHOD FOR LINEAR SYSTEMS\n\n");
   fprintf(OUP, "The solution vector is :\n");
   for (I=1; I<=N; I++) fprintf(OUP, " %11.8f", X1[I-1]); 
   fprintf(OUP, "\nusing %d iterations with\n", K);
   fprintf(OUP, "Tolerance  %.10e in infinity-norm\n", TOL); 
   fprintf(OUP, "with Parameter %.10e\n", W);
   fclose(OUP);
}
/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
