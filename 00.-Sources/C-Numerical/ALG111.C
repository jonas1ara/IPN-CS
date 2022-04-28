/*
*   LINEAR SHOOTING ALGORITHM 11.1
*
*   To approximate the solution of the boundary-value problem
*
*   -Y'' + P(X)Y' + Q(X)Y + R(X) = 0, A<=X<=B, Y(A)=ALPHA, Y(B)=BETA:
*
*
*   INPUT: Endpoints A,B; boundary conditions ALPHA, BETA; number of
*          subintervals N.
*
*   OUTPUT: Approximations W(1,I) to Y(X(I)); W(2,I) to Y'(X(I))
*           for each I=0,1,...,N.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double U[2][25], V[2][25];
   double T,A,B,ALPHA,BETA,X,H,U1,U2,V1,V2,W1,W2,Z;
   double K11,K12,K21,K22,K31,K32,K41,K42;
   int I,N,OK;
   FILE *OUP[1];

   double F(double, double);
   void INPUT(int *, double *, double *, double *, double *, int *);
   void OUTPUT(FILE **);
   double P(double);
   double Q(double);
   double R(double);

   INPUT(&OK, &A, &B, &ALPHA, &BETA, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      H = (B - A) / N;
      U1 = ALPHA;
      U2 = 0.0;
      V1 = 0.0;
      V2 = 1.0;
      /* STEP 2 */
      for (I=1; I<=N; I++) {
         /* STEP 3 */
         X = A + (I - 1.0) * H;
         T = X + 0.5 * H;
         /* STEP 4 */ 
         K11 = H * U2;
         K12 = H * ( P( X ) * U2 + Q( X ) * U1 + R( X ) );
         K21 = H * ( U2 + 0.5 * K12 );
         K22 = H * ( P( T ) * ( U2 + 0.5 * K12 ) + Q( T ) *
                ( U1 + 0.5 * K11 ) + R( T ) );
         K31 = H * ( U2 + 0.5 * K22 );
         K32 = H * ( P( T ) * ( U2 + 0.5 * K22 ) + Q( T ) *
                ( U1 + 0.5 * K21 ) + R( T ) );
         T = X + H;
         K41 = H * ( U2 + K32 );
         K42 = H * ( P( T ) * ( U2 + K32 ) + Q(T) * ( U1 + K31 ) +
                R( T ) );
         U1 = U1 + ( K11 + 2.0 * ( K21 + K31 ) + K41 ) / 6.0;
         U2 = U2 + ( K12 + 2.0 * ( K22 + K32 ) + K42 ) / 6.0;
         K11 = H * V2;
         K12 = H * ( P( X ) * V2 + Q( X ) * V1 );
         T = X + 0.5 * H;
         K21 = H * ( V2 + 0.5 * K12 );
         K22 = H * ( P( T ) * ( V2 + 0.5 * K12 ) + Q( T ) *
                ( V1 + 0.5 * K11 ) );
         K31 = H * ( V2 + 0.5 * K22 );
         K32 = H * ( P( T ) * ( V2 + 0.5 * K22 ) + Q( T ) *
                ( V1 + 0.5 * K21 ) );
         T = X + H;
         K41 = H * ( V2 + K32 );
         K42 = H * ( P( T ) * ( V2 + K32 ) + Q(T) * ( V1 + K31 ));
         V1 = V1 + ( K11 + 2.0 * ( K21 + K31 ) + K41 ) / 6.0;
         V2 = V2 + ( K12 + 2.0 * ( K22 + K32 ) + K42 ) / 6.0;
         U[0][I-1] = U1;
         U[1][I-1] = U2;
         V[0][I-1] = V1;
         V[1][I-1] = V2;
      }  
      /* STEP 5 */
      W1 = ALPHA;
      Z = (BETA - U[0][N-1]) / V[0][N-1];
      X = A;
      I = 0;
      fprintf(*OUP, "%3d %11.8f %11.8f %11.8f\n", I, X, W1, Z);
      for (I=1; I<=N; I++) {
         X = A + I * H;
         W1 = U[0][I-1] + Z * V[0][I-1];
         W2 = U[1][I-1] + Z * V[1][I-1];
         fprintf(*OUP, "%3d %11.8f %11.8f %11.8f\n", I, X, W1, W2);
      }  
      fclose(*OUP);
   }
   /* STEP 7 */
   return 0;
}
/*  Change functions P, Q, and R for a new problem.   */
double P(double X)
{
   double p; 

   p = -2/X;
   return p;
}

double Q(double X)
{
   double q; 

   q = 2/(X*X);
   return q;
}

double R(double X)
{
   double r; 

   r = sin(log(X))/(X*X);
   return r;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, double *BETA, int *N)
{
   double X; 
   char AA;

   printf("This is the Linear Shooting Method.\n");
   *OK = false;
   printf("Have the functions P, Q, and R been created immediately\n");
   printf("preceding the INPUT procedure?\n");
   printf("Answer Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank.\n");
         scanf("%lf %lf", A, B);
         if (*A >= *B) 
            printf("Left endpoint must be less than right endpoint.\n");
         else *OK = true;
      }
      printf("Input Y(  %.10e).\n", *A);
      scanf("%lf", ALPHA);
      printf("Input Y(  %.10e).\n", *B);
      scanf("%lf", BETA);
      *OK = false;
      while(!(*OK)) {
         printf("Input a positive integer for the number of subintervals.\n");
         scanf("%d", N);
         if (*N <= 0.0) printf("Number must be a positive integer.\n");
         else *OK = true;
      }
   }
   else printf("The program will end so that P, Q, R can be created.\n");
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
   fprintf(*OUP, "LINEAR SHOOTING METHOD\n\n");
   fprintf(*OUP, "  I        X(I)      W(1,I)      W(2,I)\n");
}   
