/*
*   POWER METHOD ALGORITHM 9.1
*
*   To approximate the dominant eigenvalue and an associated
*   eigenvector of the n by n matrix A given a nonzero vector x:
*
*   INPUT:   Dimension n; matrix A; vector x; tolerance TOL; maximum
*            number of iterations N.
*
*   OUTPUT:  Approximate eigenvalue MU; approximate eigenvector x
*            or a message that the maximum number of iterations was
*            exceeded. 
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double [][10], double *, int *, int *, double *);
void OUTPUT(FILE **);

main()
{
   double A[10][10], X[10], Y[10];
   double T,AMAX,YMU,ERR,TOL;
   int N,I,J,NN,K,LP,OK;
   FILE *OUP[1];

   INPUT(&OK, A, X, &N, &NN, &TOL);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      K = 1;
      /* STEP 2 */
      LP = 1;
      AMAX = absval(X[0]);
      for (I=2; I<=N; I++) {
         if (absval(X[I-1]) > AMAX) {
            AMAX = absval(X[I-1]);
            LP = I;
         }  
      }  
      /* STEP 3 */
      for (I=1; I<=N; I++) X[I-1] = X[I-1] / AMAX;
      /* STEP 4 */
      while ((K <= NN) && OK) {
         /* STEP 5 */
         for (I=1; I<=N; I++) {
            Y[I-1] = 0.0;
            for (J=1; J<=N; J++) Y[I-1] = Y[I-1] + A[I-1][J-1] * X[J-1];
         }  
         /* STEP 6 */
         YMU = Y[LP-1];
         /* STEP 7 */
         LP = 1;
         AMAX = absval(Y[0]);
         for (I=2; I<=N; I++) {
            if (absval(Y[I-1]) > AMAX) {
               AMAX = absval(Y[I-1]);
               LP = I;
            }  
         }  
         /* STEP 8 */
         if (AMAX <= ZERO) {
            printf("Zero eigenvalue - select another ");
            printf("initial vector and begin again\n");
            OK = false;
         }  
         else {
            /* STEP 9 */
            ERR = 0.0;
            for (I=1; I<=N; I++) {
               T = Y[I-1] / Y[LP-1];
               if (absval(X[I-1] - T) > ERR) 
                  ERR = absval(X[I-1] - T);
               X[I-1] = T;
            }  
            fprintf(*OUP, "%d %12.8f", K, YMU);
            for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
            fprintf(*OUP, "\n");
            /* STEP 10 */
            if (ERR <= TOL) {
               fprintf(*OUP, "\n\nThe eigenvalue = %12.8f",YMU);
               fprintf(*OUP, " to tolerance = %.10e\n", TOL);
               fprintf(*OUP, "obtained on iteration number = %d\n\n", K);
               fprintf(*OUP, "Unit eigenvector is :\n\n");
               for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
               fprintf(*OUP, "\n");
               OK = false;
            }  
            /* STEP 11 */
            K++;
         }  
      }  
      /* STEP 12 */
      if (K > NN) 
         printf("Method did not converge within %d iterations\n", NN);
   }
   fclose(*OUP);
   return 0;
}

void INPUT(int *OK, double A[][10], double *X, int *N, int *NN, double *TOL)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the Power Method.\n");
   *OK = false;
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,n), A(2,1), A(2,2), ..., A(2,n),\n");
   printf("..., A(n,1), A(n,2), ..., A(n,n)\n\n");
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
         printf("Input the dimension n.\n");
         scanf("%d", N);
         if (*N > 0) {
            for (I=1; I<=*N; I++) {
               for (J=1; J<=*N; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
               fscanf(INP, "\n");
            }
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &X[I-1]);
            fclose(INP);
            while (!(*OK)) {
               printf("Input the tolerance.\n");
               scanf("%lf", TOL);
               if (*TOL > 0.0) *OK = true;
               else  printf("Tolerance must be positive number.\n");
            }  
            *OK = false; 
            while (!(*OK)) {
               printf("Input maximum number of iterations ");
               printf("- integer.\n");
               scanf("%d", NN);
               /* use NN for  N */
               if (*NN > 0) *OK = true;
               else printf("Number must be positive integer.\n");
            }  
         }
         else printf("The dimension must be a positive integer.\n");
      }
   }
   else printf("The program will end so the input file can be created.\n");
}

void OUTPUT(FILE **OUP)
{
   int FLAG;
   char NAME[30];

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "POWER METHOD\n\n");
   fprintf(*OUP, "iter  approx        approx eigenvector\n");
   fprintf(*OUP, "      eigenvalue\n");
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
