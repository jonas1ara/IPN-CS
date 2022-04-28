/*
*   NEWTON'S METHOD FOR SYSTEMS ALGORITHM 10.1
*
*   To approximate the solution of the nonlinear system F(X)=0 given
*   an initial approximation X:
*
*   INPUT:   Number n of equations and unknowns; initial approximation
*            X=(X(1),...,X(n)); tolerance TOL; maximum number of
*            iterations N.
*
*   OUTPUT:  Approximate solution X=(X(1),...,X(n)) or a message
*            that the number of iterations was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define pi 4*atan(1)
#define true 1
#define false 0

double absval(double);
void LINSYS(int, int *, double [][11], double *);

main()
{
   double A[10][11], X[10], Y[10];
   double TOL,R;
   int N,NN,I,J,K,OK,FLAG;
   FILE *OUP[1];

   double F(int, double *);
   double P(int, int, double *);
   void INPUT(int *, int *, double *, int *, double *);
   void OUTPUT(FILE **, int *);

   INPUT(&OK, &N, &TOL, &NN, X);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      /* STEP 1 */
      K = 1;
      /* STEP 2 */
      while (OK && (K <= NN)) {
         /* STEP 3 */
         for (I=1; I<=N; I++) {
            for (J=1; J<=N; J++) A[I-1][J-1] = P(I, J, X);
            A[I-1][N] = -F(I, X);
         }  
         /* STEP 4 */
         LINSYS(N, &OK, A, Y);
         if (OK) {
            /* STEP 5 */
            R = 0.0;
            for (I=1; I<=N; I++) {
               if (absval(Y[I-1]) > R) R = absval(Y[I-1]);
               X[I-1] = X[I-1] + Y[I-1];
            }  
            if (FLAG == 2) {
               fprintf(*OUP, " %2d", K);
               for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
               fprintf(*OUP, "\n%12.6e\n", R);
            }   
            /* STEP 6 */
            if (R < TOL) {
               OK = false;
               fprintf(*OUP, "Iteration %d gives solution:\n\n", K);
               for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
               fprintf(*OUP, "\n\nto within tolerance %.10e\n", TOL);
            }   
            /* STEP 7 */
            else K++;
         }  
      }  
      if (K > NN) 
         /* STEP 8 */
         fprintf(*OUP, "Procedure does not converge in %d iterations\n", NN);
      fclose(*OUP);
   }
   return 0;
}

/* Change function F for a new problem */
double F(int I, double *X)
{
   double f; 

   switch (I) {
      case 1:
         f = 3*X[0] - cos(X[1]*X[2]) -0.5;
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
/*  P is the Jacobian Matrix  J(X)  */
double P(int I, int J, double *X)
{
   double p;

   switch (I) {
      case 1: 
         switch (J) {
            case 1:
               p = 3;
               break;
            case 2:
               p = X[2]*sin(X[1]*X[2]);       
               break;
            case 3:
               p = X[1]*sin(X[1]*X[2]);
               break;
         }     
         break;
      case 2:
         switch (J) {
            case 1:
               p = 2*X[0];
               break;
            case 2:
               p = -162*(X[1]+0.1);       
               break;
            case 3:
               p = cos(X[2]);
               break;
         }     
         break;
      case 3:
         switch (J) {
            case 1:
               p = -X[1]*exp(-X[0]*X[1]);
               break;
            case 2:
               p = -X[0]*exp(-X[0]*X[1]);       
               break;
            case 3:
               p = 20;
               break;
         }     
         break;
   }
   return p;
}
   
void INPUT(int *OK, int *N, double *TOL, int *NN, double *X)
{
   int I;
   char AA;

   printf("This is the Newton Method for Nonlinear Systems.\n");
   *OK = false;
   printf("Has the function F been defined and have the partial ");
   printf("derivatives been\n");
   printf("defined as follows:\n\n");
   printf("   1. function F:  double F( int I, double *X ) \n");
   printf("      where I is the number of the component function;\n");
   printf("\n   2. function P:  double P(int I,int J, double *X)\n");
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
         printf("Input the Tolerance.\n");
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
      printf("for example  A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   printf("Select amount of output\n");
   printf("1. Answer only\n");
   printf("2. All intermeditate approximations\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   fprintf(*OUP, "NEWTONS METHOD FOR NONLINEAR SYSTEMS\n\n");
   if (*FLAG == 2) fprintf(*OUP, "Iteration, Approximation, Error\n");
}   
/*  LINSYS solves the linear system J(X) Y = -F(X) using 
    Gaussian elimination with partial pivoting.  */
void LINSYS(int N, int *OK, double A[][11], double *Y)
{
   int L,I,K,IR,IA,J,JA;
   double Z,C;

   K = N - 1;
   *OK = true;
   I = 1;
   while (OK && (I <= K)) {
      Z = absval(A[I-1][I-1]);
      IR = I;
      IA = I + 1;
      for (J=IA; J<=N; J++) 
         if (absval(A[J-1][I-1]) > Z) {
            IR = J;
            Z = absval(A[J-1][I-1]);
         }   
      if (Z <= ZERO) *OK = false;
      else {
         if (IR != I) 
            for (J=I; J<=N+1; J++) {
               C = A[I-1][J-1];
               A[I-1][J-1] = A[IR-1][J-1];
               A[IR-1][J-1] = C;
            }
         for (J=IA; J<=N; J++) {
            C = A[J-1][I-1] / A[I-1][I-1];
            if (absval(C) <= ZERO) C = 0.0;
            for (L=I; L<=N+1; L++) 
               A[J-1][L-1] = A[J-1][L-1] - C * A[I-1][L-1];
         }     
      }
      I++;
   }
   if (OK) {
      if (absval(A[N-1][N-1]) <= ZERO) *OK = false;
      else {
         Y[N-1] = A[N-1][N] / A[N-1][N-1];
         for (I=1; I<=K; I++) {
            J = N - I;
            JA = J + 1;
            C = A[J-1][N];
            for (L=JA; L<=N; L++) C = C - A[J-1][L-1] * Y[L-1];
            Y[J-1] = C / A[J-1][J-1];
         }  
      }  
   }
   if (!(*OK)) printf("Linear system is singular\n");
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
