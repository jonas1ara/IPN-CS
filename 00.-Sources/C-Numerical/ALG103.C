/*
*   STEEPEST DESCENT ALGORITHM 10.3
*
*   To approximate a solution P to the minimization problem
*                  G(P) = MIN( G(X) : X in R(n) )
*   given an initial approximation X:
*
*   INPUT:   Number n of variables; initial approximation X;
*            tolerance TOL; maximum number of iterations N.
*
*   OUTPUT:  Approximate solution X or a message of failure.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define pi 4*atan(1)
#define true 1
#define false 0

double absval(double);

main()
{
   double X[10], Z[10], C[10], G[4], A[4];
   double Z0,X0,G0,H1,H2,H3,A0,TOL;
   int N,NN,K,I,OK,FLAG,FLAG1;
   FILE *OUP[1];

   double CF(int, double *);
   double P(int, double *);
   double F(double *, int);
   void INPUT(int *, int *, double *, int *, double *);
   void OUTPUT(FILE **, int *);

   INPUT(&OK, &N, &TOL, &NN, X);
   if (OK) {
      OUTPUT(OUP, &FLAG1);
      /* STEP 1 */
      K = 1;
      /* STEP 2 */
      while (OK && (K <= NN)) {
         /* STEP 3 */
         G[0] = F(X, N);
         Z0 = 0.0;
         for (I=1; I<=N; I++) {
            Z[I-1] = P( I, X );
            Z0 = Z0 + ( Z[I-1] ) * ( Z[I-1] );
         }  
         Z0 = sqrt( Z0 );
         /* STEP 4 */
         if (Z0 <= ZERO) {
            OK = false;
            fprintf(*OUP, "Zero qradient - may have a minimum\n");
         }  
         else { 
            /* STEP 5 */
            for (I=1; I<=N; I++) Z[I-1] = Z[I-1] / Z0;
            A[0] = 0.0;
            X0 = 1.0;
            for (I=1; I<=N; I++) C[I-1] = X[I-1] - X0 * Z[I-1];
            G0 = F(C, N);
            /* STEP 6 */
            FLAG = true;
            if (G0 < G[0]) FLAG = false;
            while (FLAG && OK) {
               /* STEPS 7 AND 8 */
               X0 = 0.5 * X0;
               if ( X0 <= ZERO ) {
                  OK = false;
                  fprintf(*OUP, "No likely improvement - may\n");
                  fprintf(*OUP, "have a minimum\n");
               }  
               else {
                  for (I=1; I<=N; I++) C[I-1] = X[I-1]-X0*Z[I-1];
                  G0 = F(C, N);
               }  
               if (G0 < G[0]) FLAG = false;
            }  
            if (OK) {
               A[2] = X0;
               G[2] = G0;
               /* STEP 9 */
               X0 = 0.5 * X0;
               for (I=1; I<=N; I++) C[I-1] = X[I-1]-X0*Z[I-1];
               A[1] = X0;
               G[1] = F(C, N);
               /* STEP 10 */
               H1 = (G[1]-G[0])/(A[1]-A[0]);
               H2 = (G[2]-G[1])/(A[2]-A[1]);
               H3 = (H2-H1)/(A[2]-A[0]);
               /* STEP 11 */
               X0 = 0.5*(A[0]+A[1]-H1/H3);
               for (I=1; I<=N; I++) C[I-1] = X[I-1]-X0*Z[I-1];
               G0 = F(C, N);
               /* STEP 12 */
               A0 = X0;
               for (I=1; I<=N; I++) 
                  if (absval(G[I-1]) < absval(G0)) {
                     A0 = A[I-1];
                     G0 = G[I-1];
                  }  
               if (absval(A0) <= ZERO) {
                  OK = false;
                  fprintf(*OUP, "No change likely\n");
                  fprintf(*OUP, "- probably rounding error problems\n");
               }  
               else {
                  /* STEP 13 */
                  for (I=1; I<=N; I++) X[I-1] = X[I-1]-A0*Z[I-1];
                  /* STEP 14 */
                  if (FLAG1 == 2) {
                     fprintf(*OUP, " %2d", K);
                     for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
                     fprintf(*OUP, "\n");
                  }  
                  if ((absval(G0) < TOL) || (absval(G0-G[0]) < TOL)) {
                     OK = false;
                     fprintf(*OUP, "Iteration number %d\n", K);
                     fprintf(*OUP, "gives solution\n\n");
                     for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
                     fprintf(*OUP, "\n\nto within %.10e\n\n", TOL);
                     fprintf(*OUP, "Process is complete\n");
                  }  
                  else 
                     /* STEP 15 */
                     K++;
               }  
            }  
         }
      }  
      if (K > NN) {
         /* STEP 16 */
         fprintf(*OUP, "Process does not converge in %d\n", NN);
         fprintf(*OUP, " iterations\n");
      }  
      fclose(*OUP);
   }  
}

/* Change procedures CF and P for a new problem */
double CF(int I, double *X)
{
   double cf; 

   switch (I) {
      case 1:
         cf = 3*X[0] - cos(X[1]*X[2]) - 0.5;
         break;
      case 2:
         cf = X[0]*X[0] - 81*(X[1]+0.1)*(X[1]+0.1) + sin(X[2]) + 1.06;
         break;
      case 3:
         cf = exp(-X[0]*X[1]) + 20*X[2] + (10*pi-3)/3;
         break;
   }   
   return cf;
}

double P(int I, double *X)
{
   double p;

   switch (I) {
      case 1: 
         p = 2 * ( 3 ) * CF( 1, X )
            + 2 * ( 2*X[0] ) * CF( 2, X )
            + 2 * ( -X[1]*exp(-X[0]*X[1]) ) * CF( 3, X );
         break;
      case 2:
         p = 2 * ( X[2]*sin(X[1]*X[2]) ) * CF( 1, X )
            + 2 * ( -162*(X[1]+0.1) ) * CF( 2, X )
            + 2 * ( -X[0]*exp(-X[0]*X[1]) ) * CF( 3, X );
         break;
      case 3:
         p = 2 * ( X[1]*sin(X[1]*X[2]) ) * CF( 1, X )
            + 2 * ( cos(X[2]) ) * CF( 2, X )
            + 2 * 20 * CF( 3, X );
         break;
   }  
   return p;
}  

double F(double *X, int N)  
{
   double f, D;
   int I;
 
   D = 0.0;
   for (I=1; I<=N; I++) D = D + ( CF( I, X ) ) * ( CF( I, X ) );
   f = D;
   return f;
}

   
void INPUT(int *OK, int *N, double *TOL, int *NN, double *X)
{
   int I;
   char AA;

   printf("This is the Steepest Descent Method.\n");
   *OK = false;
   printf("\nNOTE THAT THE FUNCTION DEFINITIONS ARE VERY COMPLICATED\n");
   printf("Have the functions been set up as follows:\n\n");
   printf("   1. double F(double *X, int N)\n");
   printf("        which is the function to be minimized ( function G )\n");
   printf("        or the sum of the squares of the component\n");
   printf("        functions in a nonlinear system;\n\n");
   printf("   2. double CF(int I, double *X)\n");
   printf("        which is the Ith component function of a nonlinear\n");
   printf("        system - not used for simple minimization problems\n\n");
   printf("   3. double P(int I, double *X)\n");
   printf("        which is the partial derivative of F with respect\n");
   printf("        to the Ith variable\n\n");
   printf("Answer Y or N.\n\n");
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

void OUTPUT(FILE **OUP, int *FLAG1)
{
   char NAME[30];

   printf("Select output destination\n");
   printf("1. Screen\n");
   printf("2. Text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG1);
   if (*FLAG1 == 2) {
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
   scanf("%d", FLAG1);
   fprintf(*OUP, "STEEPEST DESCENT METHOD FOR NONLINEAR SYSTEMS\n\n");
   if (*FLAG1 == 2) fprintf(*OUP, "Iteration, Approximation\n");
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
