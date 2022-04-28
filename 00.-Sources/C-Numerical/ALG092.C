/*
*   SYMMETRIC POWER METHOD ALGORITHM 9.2
*
*   To approximate the dominant eigenvalue and an associated
*   eigenvector of the n by n symmetric matrix A given a nonzero vector x:
*
*   INPUT:   Dimension n; matrix A; vector x; tolerance TOL;
*            maximum number of iterations N.
*
*   OUTPUT:  Approximate eigenvalue MU; approximate eigenvector x or
*            a message that the maximum number of iterations was
*            exceeded.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double [][10], double *, double *, int *, int *, double *);
void OUTPUT(FILE **);
void NORM(int *, int, double *, double *, double *);

main()
{
   double A[10][10], X[10], Y[10];
   double YMU,ERR,TOL;
   int N,I,J,NN,K,OK;
   FILE *OUP[1];

   INPUT(&OK, A, X, Y, &N, &NN, &TOL);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      K = 1;
      /* Norm computes the norm of the vector X and
         returns X divided by its norm in the variable Y */
      NORM(&OK, N, Y, X, &ERR);
      if (OK) {
         /* STEP 2 */
         while ((K <= NN) && OK) {
            /* STEPS 3 AND 4 */
            YMU = 0.0;
            for (I=1; I<=N; I++) {
               Y[I-1] = 0.0;
               for (J=1; J<=N; J++)  
                  Y[I-1] = Y[I-1] + A[I-1][J-1] * X[J-1];
               YMU = YMU + X[I-1] * Y[I-1];
            }  
            /* STEP 5 (This step is accomplished in
                       subroutine norm.) */
            /* STEP 6 */
            NORM(&OK, N, Y, X, &ERR);
            fprintf(*OUP, "%d %12.8f   ", K, YMU);
            for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
            fprintf(*OUP, "\n");
            if (OK) {
               /* STEP 7 */
               if ( ERR < TOL ) {
                  /* procedure completed successfully */
                  fprintf(*OUP, "\n\nThe eigenvalue = %12.8f",YMU);
                  fprintf(*OUP, " to tolerance = %.10e\n", TOL);
                  fprintf(*OUP, "obtained on iteration number = %d\n\n", K);
                  fprintf(*OUP, "Unit eigenvector is :\n\n");
                  for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
                  fprintf(*OUP, "\n");
                  OK = false;
               }  
               else {
                  /* STEP 8 */
                  K++;
               }  
            }     
         }  
         /* STEP 9 */
         if (K > NN) 
            printf("No convergence within %d iterations\n", NN);
      }  
   }
   fclose(*OUP);
   return 0;
}

void INPUT(int *OK, double A[][10], double *X, double *Y, int *N, int *NN, double *TOL)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the Symmetric Power Method.\n");
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
            /* Because of the way in which the subroutine
               norm computes the l2 norm of a vector,
               the initial input of X is into Y and X
               is initialized at the zero vector. */
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &Y[I-1]);
            for (I=1; I<=*N; I++) X[I-1] = 0.0;
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
               /* Use NN for capital N for the maximum number of iterations */
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
   fprintf(*OUP, "SYMMETRIC POWER METHOD\n\n");
   fprintf(*OUP, "iter  approx        approx eigenvector\n");
   fprintf(*OUP, "      eigenvalue\n");
}   

void NORM(int *OK, int N, double *Y, double *X, double *ERR)
{
   double XL,T; 
   int I;
 
   XL = 0.0;
   for (I=1; I<=N; I++) XL = XL + Y[I-1] * Y[I-1];
   /*  2-norm of Y */
   XL = sqrt(XL);
   *ERR = 0.0;
   if (XL > ZERO) {
      for (I=1; I<=N; I++) {
         T = Y[I-1] / XL;
         *ERR = *ERR + (X[I-1]-T) * (X[I-1]-T);
         X[I-1] = T;
      }  
      /*  X has 2-norm of 1.0  */
      *ERR = sqrt(*ERR);
   }  
   else {
     printf("A has a zero eigenvalue - select new vector and begin ");
     printf("again\n");
     *OK = false;
   }
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
