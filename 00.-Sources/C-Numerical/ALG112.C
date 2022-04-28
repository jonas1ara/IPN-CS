/*
*   NONLINEAR SHOOTING ALGORITHM 11.2
*
*   To approximate the solution of the nonlinear boundary-value problem
*
*          Y'' = F(X,Y,Y'), A<=X<=B, Y(A) = ALPHA, Y(B) = BETA:
*
*
*   INPUT:   Endpoints A,B; boundary conditions ALPHA, BETA; number of
*            subintervals N; tolerance TOL; maximum number of iterations M.
*
*   OUTPUT:  Approximations W(1,I) TO Y(X(I)); W(2,I) TO Y'(X(I))
*            for each I=0,1,...,N or a message that the maximum
*            number of iterations was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double W1[26], W2[26];
   double X,T,A,B,ALPHA,BETA,TOL,H,TK,U1,U2;
   double K11,K12,K21,K22,K31,K32,K41,K42;
   int NN,K,N,J,I,OK;
   FILE *OUP[1];

   void INPUT(int *, double *, double *, double *, double *, double *, double *, int *, int *);
   void OUTPUT(FILE **);
   double F(double, double, double);
   double FY(double, double, double);
   double FYP(double, double, double);
   double absval(double);

   INPUT(&OK, &A, &B, &ALPHA, &BETA, &TK, &TOL, &NN, &N);
   if (OK) {
      /* STEP 1 */
      OUTPUT(OUP);
      H = (B - A) / N;
      K = 1;
      /*  TK already computed.   */
      OK = false;
      /* STEP 2 */
      while ((K <= NN) && !OK) {
         /* STEP 3 */
         W1[0] = ALPHA;
         W2[0] = TK;
         U1 = 0.0 ;
         U2 = 1.0;
         /* STEP 4 */
         /* Runge-Kutta method for systems is used in STEPS 5, 6 */
         for (I=1; I<=N; I++) {
            /* STEP 5 */
            X = A + ( I - 1.0 ) * H;
            T = X + 0.5 * H;
            /* STEP 6 */
            K11 = H * W2[I-1];
            K12 = H * F( X, W1[I-1], W2[I-1] );
            K21 = H * ( W2[I-1] + 0.5 * K12 );
            K22 = H * F( T, W1[I-1] + 0.5 * K11, W2[I-1] +
                   0.5 * K12);
            K31 = H * ( W2[I-1] + 0.5 * K22 );
            K32 = H * F( T, W1[I-1] + 0.5 * K21, W2[I-1] +
                   0.5 * K22 );
            K41 = H * ( W2[I-1] + K32 );
            K42 = H * F( X + H, W1[I-1] + K31, W2[I-1] + K32 );
            W1[I] = W1[I-1] + ( K11 + 2.0 * ( K21 + K31 ) +
                       K41 ) / 6.0;
            W2[I] = W2[I-1] + ( K12 + 2.0 * ( K22 + K32 ) +
                       K42 ) / 6.0;
            K11 = H * U2;
            K12 = H * ( FY( X, W1[I-1], W2[I-1] ) * U1 +
                   FYP( X, W1[I-1], W2[I-1] ) * U2 );
            K21 = H * ( U2 + 0.5 * K12 );
            K22 = H*(FY(T,W1[I-1],W2[I-1])*
                   (U1+0.5*K11)+FYP(T,W1[I-1],W2[I-1])*
                   (U2+0.5*K21));
            K31 = H * ( U2 + 0.5 * K22 );
            K32 = H * ( FY( T, W1[I-1], W2[I-1] ) *
                   (U1+0.5*K21)+FYP(T,W1[I-1],W2[I-1])*
                   (U2+0.5*K22));
            K41 = H * ( U2 + K32 );
            K42 = H*(FY(X+H,W1[I-1],W2[I-1])*(U1+K31)+
                   FYP(X+H,W1[I-1],W2[I-1])*(U2+K32));
            U1 = U1+(K11+2.0*(K21+K31)+K41)/6.0;
            U2 = U2+(K12+2.0*(K22+K32)+K42)/6.0;
         }  
         /* STEP 7 */
         /* test for accuracy */
         if (absval(W1[N] - BETA) < TOL) {
            /* STEP 8 */
            I = 0;
            fprintf(*OUP, "%3d %13.8f %13.8f %13.8f\n", I, A, ALPHA, TK);
            for (I=1; I<=N; I++) {
               J = I + 1;
               X = A + I * H;
               fprintf(*OUP, "%3d %13.8f %13.8f %13.8f\n", I, X, W1[J-1], W2[J-1]);
            }  
            fprintf(*OUP, "Convergence in %d iterations\n", K);
            fprintf(*OUP, " t = %14.7e\n", TK);
            /* STEP 9 */
            OK = true;
         }  
         else {
            /* STEP 10 */
            /* Newton's method applied to improve TK */
            TK = TK - ( W1[N] - BETA ) / U1;
            K = K + 1;
         }  
      }   
      /* STEP 11 */  
      /* method failed */
      if (!OK) fprintf(*OUP, "Method failed after %d iterations\n", NN);
   }
   fclose(*OUP);
   return 0;
}

/* Change functions F, FY and FYP for a new problem */
double F(double X, double Y, double Z)
{
   double f; 

   f = (32+2*X*X*X-Y*Z)/8;
   return f;
}

/* FY REPRESENTS PARTIAL OF F WITH RESPECT TO Y */
double FY(double X, double Y, double Z)
{
   double fy; 

   fy = -Z/8;
   return fy;
}

/* FYP REPRESENTS PARTIAL OF F WITH RESPECT TO Y' */
double FYP(double X, double Y, double Z)
{
   double fyp; 

   fyp = -Y/8;
   return fyp;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, double *BETA, double *TK, double *TOL, int *NN, int *N)
{
   double X; 
   char AA;

   printf("This is the Nonlinear Shooting Method.\n");
   *OK = false;
   printf("Have the functions F, FY ( partial of F with respect to y ),\n");
   printf("FYP ( partial of F with respect to y')\n");
   printf("been created immediately preceding the INPUT procedure?\n");
   printf("Answer Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank.\n");
         scanf("%lf %lf", A, B);
         if (*A >= *B) 
            printf("Left endpoint must be less than right endpoint.\n");
         else *OK = true;
      }
      printf("Input Y(%.10e).\n", *A);
      scanf("%lf", ALPHA);
      printf("Input Y(%.10e).\n", *B);
      scanf("%lf", BETA);
      *TK = (*BETA - *ALPHA) / (*B - *A);
      printf("TK = %.8e\n", *TK);
      printf("Input new TK? Enter Y or N.\n");
      scanf("\n%c", &AA);
      if ((AA == 'Y') || (AA == 'y')) {
         printf("input new TK\n");
         scanf("%lf", TK);
      }
      *OK = false;
      while(!(*OK)) {
         printf("Input an integer > 1 for the number of subintervals.\n");
         scanf("%d", N);
         if (*N <= 1) printf("Number must exceed 1.\n");
         else *OK = true;
      }
      *OK = false;
      while (!(*OK)) {
         printf("Input Tolerance.\n");
         scanf("%lf", TOL);
         if (*TOL <= 0.0) printf("Tolerance must be positive.\n");
         else *OK = true;
      }
      *OK = false;
      while (!(*OK)) {
         printf("Input maximum number of iterations.\n");
         scanf("%d", NN);
         if (*NN <= 0) printf("Must be positive integer.\n");
         else *OK = true; 
      }  
   }
   else printf("The program will end so that F, FP, FPY can be created.\n");
}

void OUTPUT(FILE **OUP)
{
   char NAME[30];
   int FLAG; 

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text File\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "NONLINEAR SHOOTING METHOD\n\n");
   fprintf(*OUP, "  I          X(I)         W1(I)         W2(I)\n");
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
