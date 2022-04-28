/*
*   WIELANDT'S DEFLATION ALGORITHM 9.4
*
*   To approximate the second most dominant eigenvalue and an
*   associated eigenvector of the n by n matrix A given an
*   approximation LAMBDA to the dominant eigenvalue, an
*   approximation V to a corresponding eigenvector and a vector X
*   belonging to R**(n-1), tolerance TOL, maximum number of
*   iterations N.
*
*   INPUT:   Dimension n; matrix A; approximate eigenvalue LAMBDA;
*            approximate eigenvector V belonging to R**n; vector X
*            belonging to R**(n-1).
*
*   OUTPUT:  Approximate eigenvalue MU; approximate eigenvector U or
*            a message that the method fails.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double [][10], double *, double *, int *, int *, int *, double *, double *);
void OUTPUT(FILE **);
void POWER(double *, int, int *, double *, double [][9], double *, double, int, FILE **);

main()
{
   double A[10][10], B[9][9], V[10], W[10], VV[10], X[10], Y[10];
   double S,AMAX,YMU,XMU,ERR,TOL;
   int NUM,FLAG,N,I,J,K,M,I1,N1,I2,L1,L2,NN,OK;
   FILE *OUP[1];

   INPUT(&OK, A, X, V, &N, &NN, &M, &TOL, &XMU);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      I = 1;
      AMAX = absval(V[0]);
      for (J=2; J<=N; J++) {
         if (absval(V[J-1]) > AMAX) {
            I = J;
            AMAX = absval(V[J-1]);
         }  
      }  
      /* STEP 2 */
      if (I != 1) {
         for (K=1; K<=I-1; K++)
            for (J=1; J<=I-1; J++) 
               B[K-1][J-1] = A[K-1][J-1] - V[K-1] * A[I-1][J-1] / V[I-1];
      }        
      /* STEP 3 */
      if ((I != 1) && (I != N)) {
         for (K=I; K<=N-1; K++)
            for (J=1; J<=I-1; J++) {
               B[K-1][J-1] = A[K][J-1]-V[K]*A[I-1][J-1]/V[I-1];
               B[J-1][K-1] = A[J-1][K]-V[J-1]*A[I-1][K]/V[I-1];
            }  
      }     
      /* STEP 4 */
      if (I != N) {
         for (K=I; K<=N-1; K++)
            for (J=I; J<=N-1; J++)
               B[K-1][J-1] = A[K][J]-V[K]*A[I-1][J]/V[I-1];
      }        
      /* STEP 5 */
      POWER(X, M, &OK, Y, B, &YMU, TOL, NN, OUP);
      if (OK) {
         /* STEP 6 */
         if (I != 1)
            for (K=1; K<=I-1; K++) W[K-1] = Y[K-1];
         /* STEP 7 */
         W[I-1] = 0.0;
         /* STEP 8 */
         if (I != N)
            for (K=I+1; K<=N; K++) W[K-1] = Y[K - 2]; 
         /* STEP 9 */
         S = 0.0;
         for (J=1; J<=N; J++) S = S + A[I-1][J-1] * W[J-1];
         S = S / V[I-1];
         for (K=1; K<=N; K++) 
            /* Compute eigenvector
               VV is used in place of U here */
            VV[K-1] = (YMU - XMU) * W[K-1] + S * V[K-1];
         fprintf(*OUP, "The reduced matrix B:\n");
         for (L1=1; L1<=M; L1++) {
            for (L2=1; L2<=M; L2++) fprintf(*OUP, "%.10e  ", B[L1-1][L2-1]);
            fprintf(*OUP, "\n");
         }  
         fprintf(*OUP, "\nThe Eigenvalue = %12.8f", YMU);
         fprintf(*OUP, " to Tolerance = %.10e\n\n", TOL);
         fprintf(*OUP, "Eigenvector is:\n");
         for (I=1; I<=N; I++) fprintf(*OUP," %11.8f", VV[I-1]);
         fprintf(*OUP, "\n");
      }  
      fclose(*OUP);
   }
   return 0;
}

void INPUT(int *OK, double A[][10], double *X, double *V, int *N, int *NN, int *M, double *TOL, double *XMU)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is Wielandt Deflation.\n");
   *OK = false;
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,n), A(2,1), A(2,2), ..., A(2,n),\n");
   printf("..., A(n,1), A(n,2), ..., A(n,n)\n\n");
   printf("Next place the approximate eigenvector V(1), ..., ");
   printf("V(n) and follow it\n");
   printf("by the approximate eigenvalue. Finally, an ");
   printf("initial approximate\n");
   printf("eigenvector of dimension n-1: X(1), ..., X(n-1) ");
   printf("should follow.\n\n");
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
         printf("Input the dimension n.\n");
         scanf("%d", N);
         if (*N > 1) *OK = true;
         else printf("Dimension must be greater then 1.\n");
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input a positive tolerance for the power method.\n");
         scanf("%lf", TOL);
         if (*TOL > 0.0) *OK = true;
         else printf("Tolerance must be a positive number.\n");
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input the maximum number of iterations for the ");
         printf("power method.\n");
         scanf("%d", NN);
         if (*NN > 0) *OK = true;
         else printf("The number must be a positive integer.\n");
      }  
      for (I=1; I<=*N; I++) {
         for (J=1; J<=*N; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
         fscanf(INP, "\n");
      }
      *OK = false; 
      for (I=1; I<=*N; I++) {
         fscanf(INP, "%lf", &V[I-1]);
         if (absval(V[I-1]) > ZERO) *OK = true;
      }  
      fscanf(INP, "%lf", XMU);
      *M = *N - 1;
      if (*OK) {
         *OK = false;
         for (I=1; I<=*M; I++) {
            fscanf(INP, "%lf", &X[I-1]);
            if (absval(X[I-1]) > ZERO) *OK = true;
         }
      }  
      if (!(*OK)) printf("All vectors must be nonzero.\n");
      fclose(INP); 
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
   fprintf(*OUP, "WIELANDT DEFLATION\n\n");
}   

void POWER(double *X, int M, int *OK, double *Y, double B[][9], double *YMU, double TOL, int NN, FILE **OUP)
{
   double AMAX,T,ERR;
   int K,LP,I,J,DONE;
   
   K=1;
   LP=1;
   AMAX = absval(X[0]);
   for (I=2; I<=M; I++)
      if (absval(X[I-1]) > AMAX) {
         AMAX = absval(X[I-1]);
         LP = I;
      }  
   DONE = false;
   for (I=1; I<=M; I++) X[I-1] = X[I-1] / AMAX;
   while ((K <= NN) && *OK && !DONE) {
      for (I=1; I<=M; I++) {
         Y[I-1] = 0.0;
         for (J=1; J<=M; J++) Y[I-1] = Y[I-1] + B[I-1][J-1] * X[J-1];
      }
      *YMU = Y[LP-1];
      LP = 1;
      AMAX = absval(Y[0]);
      for (I=2; I<=M; I++) {
         if (absval(Y[I-1]) > AMAX) {
            AMAX = absval(Y[I-1]);
            LP = I;
         }  
      }  
      if (AMAX <= ZERO) {
         printf("Zero eigenvalue - B is singular\n");
         *OK = false;
      }  
      else {
         ERR = 0.0;
         for (I=1; I<=M; I++) {
            T = Y[I-1] / Y[LP-1];
            if (absval(X[I-1] - T) > ERR)
               ERR = absval(X[I-1] - T);
            X[I-1] = T;
         }  
         if (ERR < TOL) {
            for (I=1; I<=M; I++) Y[I-1] = X[I-1];
            DONE = true;
         }  
         else K++;
      }  
   }
   if ((K > NN) && *OK) {
      printf("Power Method did not converge in %d iterations.\n",NN);
      *OK = false;
   }  
   else
      fprintf(*OUP, "Number Iterations for Power Method = %d\n", K);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
