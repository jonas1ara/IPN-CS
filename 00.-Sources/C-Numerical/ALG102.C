/*
*   BROYDEN ALGORITHM 10.2
*
*   To approximate the solution of the nonlinear system F(X) = 0
*   given an initial approximation X.
*
*   INPUT:   Number n of equations and unknowns; initial
*            approximation X = (X(1),...,X(n)); tolerance TOL;
*            maximum number of iterations N.
*
*   OUTPUT:  Approximate solution X = (X(1),...,X(n)) or a message
*            that the number of iterations was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define pi 4*atan(1)
#define true 1
#define false 0

double absval(double);
void INVERT(int, double [][10], int *, double [][10]);

main()
{
   double A[10][10], B[10][10], U[10], X[10], V[10], S[10], Y[10], Z[10];
   double SN,TOL,VV,ZN,P;
   int N,NN,I,J,L,K,KK,OK,FLAG;
   FILE *OUP[1];

   double F(int, double *);
   double PD(int, int, double *);
   void INPUT(int *, int *, double *, int *, double *);
   void OUTPUT(FILE **, int *);
   void MULT(int, double *, double *, double *, double [][10]);

   INPUT(&OK, &N, &TOL, &NN, X);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      /* STEP 1 */
      /* A will hold the Jacobian for the initial approximation
         the subprogram PD computes the entries of the Jacobian */
      for (I=1; I<=N; I++) {
         for (J=1; J<=N; J++) A[I-1][J-1] = PD(I, J, X);
         /* Compute V = F( X(0) )
            The subprogram F( I ) computes the Ith
            component of F at X */
         V[I-1] = F(I, X);
      }  
      /* STEP 2 */
      INVERT(N, B, &OK, A);
      /* INVERT finds the inverse of the N by N matrix A and
         returns it in A */
      if (OK) {
         /* STEP 3 */
         K = 2;
         /* NOTE: S = S(1) */
         MULT(N, &SN, V, S, A);
         /* MULT computes the product S = -A * V
            and the L2-norm SN of S */
         for (I=1; I<=N; I++) X[I-1] = X[I-1] + S[I-1];
         if (FLAG == 2) {
            fprintf(*OUP,"%d",K-1);
            for (I=1;I<=N;I++) fprintf(*OUP,"%11.8f",X[I-1]);
            fprintf(*OUP,"\n %12.6e\n",SN);
         }
         /* STEP 4 */
         while ((K < NN) && OK) {
            /* STEP 5 */
            /* The vector W is not used since the
               function F is evaluated component
               by component */
            for (I=1; I<=N; I++) {
               VV = F(I, X);
               Y[I-1] = VV - V[I-1];
               V[I-1] = VV;
            }  
            /* NOTE: V = F( X(K) ) AND Y = Y(K) */
            /* STEP 6 */
            MULT(N, &ZN, Y, Z, A);
            /* NOTE : Z = -A(K-1)**-1 * Y(K) */
            /* STEP 7 */
            P = 0.0;
            /* P WILL BE S(K)**T * A(K-1)**-1 * Y(K) */
            for (I=1; I<=N; I++) {
               P = P - S[I-1] * Z[I-1];
            }
            /* STEP 8 */
            for (I=1; I<=N; I++) { 
               U[I-1] = 0.0;
               for (J=1;J<=N;J++)
                  U[I-1] = U[I-1]+S[J-1]*A[J-1][I-1];
            }
            /* STEP 9 */
            for (I=1;I<=N;I++) {
               for (J=1;J<=N;J++)
                  A[I-1][J-1] = A[I-1][J-1]+(S[I-1]+Z[I-1])*U[J-1]/P;
            }
            /* STEP 10 */
            MULT(N, &SN, V, S, A);
            /* NOTE: A = A(K)**-1 and S = -A(K)**-1 * F( X(K) ) */
            /* STEP 11 */
            for (I=1; I<=N; I++) X[I-1] = X[I-1] + S[I-1];
            /* NOTE: X = X(K+1) */
            KK = K + 1;
            if (FLAG == 2) {
               fprintf(*OUP, " %2d", K);
               for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
               fprintf(*OUP, "\n%12.6e\n", SN);
            }  
            if (SN <= TOL) {
               /* procedure completed successfully */
               OK = false;
               fprintf(*OUP, "Iteration number %d", K);
               fprintf(*OUP, " gives solution:\n\n");
               for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
               fprintf(*OUP, "\n\nto within tolerance %.10e\n\n", TOL);
               fprintf(*OUP, "Process is complete\n");
            }  
            else 
               /* STEP 13 */
               K = KK;
         }  
         if (K >= NN)
            /* STEP 14 */
            fprintf(*OUP, "Procedure does not converge in %d iterations\n", NN);
      }  
      fclose(*OUP);
   }
   return 0;
}

/* Change functions F and PD for a new problem */
double F(int I, double *X)
{
   double f; 

   switch (I) {
      case 1:
         f = 3*X[0] - cos(X[1]*X[2]) - 0.5;
         break;
      case 2:
         f = X[0]*X[0] - 81*(X[1]+0.1)*(X[1]+0.1) + sin(X[2]) + 1.06;
         break;
      case 3:
         f = exp(-X[0]*X[1]) + 20*X[2] + (10*pi-3)/3;
         break;
   }   
   return f;
}
/*  PD represents the Jacobian J(X).  */
double PD(int I, int J, double *X)
{
   double pd;

   switch (I) {
      case 1: 
         switch (J) {
            case 1:
               pd = 3;
               break;
            case 2:
               pd = X[2]*sin(X[1]*X[2]);       
               break;
            case 3:
               pd = X[1]*sin(X[1]*X[2]);
               break;
         }     
         break;
      case 2:
         switch (J) {
            case 1:
               pd = 2*X[0];
               break;
            case 2:
               pd = -162*(X[1]+0.1);       
               break;
            case 3:
               pd = cos(X[2]);
               break;
         }     
         break;
      case 3:
         switch (J) {
            case 1:
               pd = -X[1]*exp(-X[0]*X[1]);
               break;
            case 2:
               pd = -X[0]*exp(-X[0]*X[1]);       
               break;
            case 3:
               pd = 20;
               break;
         }     
         break;
   }
   return pd;
}
   
void INPUT(int *OK, int *N, double *TOL, int *NN, double *X)
{
   int I;
   char AA;

   printf("This is the Broyden Method for Nonlinear Systems.\n");
   *OK = false;
   printf("Has the function F been defined and have the partial ");
   printf("derivatives been\n");
   printf("defined as follows:\n\n");
   printf("   1. function F:  double F(int I, double *X)\n");
   printf("      where I is the number of the component function;\n");
   printf("\n   2. function PD(X): double PD(int I, int J, double *X)\n");
   printf("      where I is the number of the component function\n");
   printf("      and J is the number of the variable with respect\n");
   printf("      to which partial differentiation is performed;\n\n");
   printf("Answer Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      while (!(*OK)) {
         printf("Input the number n of equations.\n");
         scanf("%d", N);
         if (*N >= 2) *OK = true;
         else printf("N must be an integer greater than 1.\n");
      }  
      *OK = false;
      while(!(*OK)) {
         printf("Input tolerance\n");
         scanf("%lf", TOL);
         if (*TOL > 0.0) *OK = true;
         else printf("Tolerance must be positive.\n");
      }
      *OK = false;
      while (!(*OK)) {
         printf("Input the maximum number of iterations.\n");
         scanf("%d", NN);
         if (*NN > 0) *OK = true;
         else printf("Must be a positive integer.\n");
      }
      for (I=1; I<=*N; I++) {
         printf("Input initial approximation X(%d).\n", I);
         scanf("%lf", &X[I-1]);
      }
   }
   else 
      printf("The program will end so that the functions can be created.\n");
}

void OUTPUT(FILE **OUP, int *FLAG)
{
   char NAME[30];

   printf("Select output destination\n");
   printf("1. Screen\n");
   printf("2. Text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   if (*FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   printf("Select amount of output\n");
   printf("1. Answer only\n");
   printf("2. All intermeditate approximations\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   fprintf(*OUP, "BROYDENS METHOD FOR NONLINEAR SYSTEMS\n\n");
   if (*FLAG == 2) fprintf(*OUP, "Iteration, Approximation, Error\n");
}   
/*  MULT computes S = -A*V and SN = 2-norm of S  */ 
void MULT(int N, double *SN, double *V, double *S, double A[][10])
{
   int I, J;

   *SN = 0.0;
   for (I=1; I<=N; I++) {
      S[I-1] = 0.0;
      for (J=1; J<=N; J++) S[I-1] = S[I-1] - A[I-1][J-1] * V[J-1];
      *SN = *SN + S[I-1] * S[I-1];
   }
   *SN = sqrt(*SN);
}
/*  INVERT finds the inverse, if possible, of the matrix A and
    returns it in A.  It uses the Gauss-Jordan method with
    partial pivoting and is called only once in this program.  */
void INVERT(int N, double B[][10], int *OK, double A[][10])
{
   int I,J,I1,I2,K;
   double C;
   
   for (I=1; I<=N; I++) {
      for (J=1; J<=N; J++) B[I-1][J-1] = 0.0;
      B[I-1][I-1] = 1.0;
   }
   I = 1;
   while ((I <= N) && OK) {
      I1 = I + 1;
      I2 = I;
      if (I != N) {
         C = absval(A[I-1][I-1]);
         for (J=I1; J<=N; J++) 
            if (absval(A[J-1][I-1]) > C) {
               I2 = J;
               C = absval(A[J-1][I-1]);
            }  
         if (C <= ZERO) *OK = false;
         else {
            if (I2 != I) 
               for (J=1; J<=N; J++) {
                  C = A[I-1][J-1];
                  A[I-1][J-1] = A[I2-1][J-1];
                  A[I2-1][J-1] = C;
                  C = B[I-1][J-1];
                  B[I-1][J-1] = B[I2-1][J-1];
                  B[I2-1][J-1] = C;
               }  
         }  
      }
      else if (absval(A[N-1][N-1]) <= ZERO) *OK = false;
      if (*OK) 
         for (J=1; J<=N; J++) {
            if (J != I) {
               C = A[J-1][I-1] / A[I-1][I-1];
               for (K=1; K<=N; K++) {
                  A[J-1][K-1] = A[J-1][K-1] - C * A[I-1][K-1];
                  B[J-1][K-1] = B[J-1][K-1] - C * B[I-1][K-1];
               }  
            }  
         }  
      I++;
   }  
   if (*OK) 
      for (I=1; I<=N; I++) {
         C = A[I-1][I-1];
         for (J=1; J<=N; J++) A[I-1][J-1] = B[I-1][J-1] / C;
      }  
   else printf("Jacobian has no inverse\n");
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
