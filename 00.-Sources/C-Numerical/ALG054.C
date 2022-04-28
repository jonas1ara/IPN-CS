/*
*   ADAMS-FORTH ORDER PREDICTOR-CORRECTOR ALGORITHM 5.4
*
*   To approximate the solution of the initial value problem
*          y' = f(t,y), a <= t <= b, y(a) = alpha,
*   at N+1 equally spaced points in the interval [a,b].
*
*   INPUT:   endpoints a,b; initial condition alpha; integer N.
*
*   OUTPUT:  approximation w to y at the (N+1) values of t.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double T[4],W[4];
   double A,B,ALPHA,H,T0,W0;
   int I,N,J,OK;
   FILE *OUP[1];

   double F(double, double);
   void RK4(double , double , double , double *, double *);
   void INPUT(int *, double *, double *, double *, int *);
   void OUTPUT(FILE **);

   INPUT(&OK, &A, &B, &ALPHA, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      H = (B - A) / N;
      T[0] = A;
      W[0] = ALPHA;
      fprintf(*OUP, "%5.3f %11.7f\n", T[0], W[0]);
      /* STEP 2 */
      for (I=1; I<=3; I++) {
         /* STEP 3 AND 4 */
         /* compute starting values using Runge-Kutta method */
         /* given in a subroutine */
         RK4(H, T[I-1], W[I-1], &T[I], &W[I]);
         fprintf(*OUP, "%5.3f %11.7f\n", T[I], W[I]);
         /* STEP 5 */
      }
      /* STEP 6 */
      for (I=4; I<=N; I++) {
         /* STEP 7 */
         /* T0, W0 will be used in place of t, w resp. */
         T0 = A + I * H;
         /* predict W(I) */
         W0 = W[3]+H*(55.0*F(T[3],W[3])-59.0*F(T[2],W[2])
              +37.0*F(T[1],W[1])-9.0*F(T[0],W[0]))/24.0;
         /* correct W(I) */
         W0 = W[3]+H*(9.0*F(T0,W0)+19.0*F(T[3],W[3])
              -5.0*F(T[2],W[2])+F(T[1],W[1]))/24.0;
         /* STEP 8 */
         fprintf(*OUP, "%5.3f %11.7f\n", T0, W0);
         /* STEP 9 */
         /* prepare for next iteration */
         for (J=1; J<=3; J++) {
            T[J-1] = T[J];
            W[J-1] = W[J];
         }
         /* STEP 10 */
         T[3] = T0;
         W[3] = W0;
      }
      /* STEP 11 */
      fclose(*OUP);
   }
   return 0;
}
/*  Change function F for a new problem    */
double F(double T, double Y)
{
   double f; 

   f = Y - T*T + 1.0;
   return f;
}

void RK4(double H, double T0, double W0, double *T1, double *W1)
{
   double K1,K2,K3,K4;
   
   *T1 = T0 + H;
   K1 = H * F(T0, W0);
   K2 = H * F(T0 + 0.5 * H, W0 + 0.5 * K1);
   K3 = H * F(T0 + 0.5 * H, W0 + 0.5 * K2);
   K4 = H * F(*T1, W0 + K3);
   *W1 = W0 + (K1 + 2.0 * (K2 + K3) + K4) / 6.0;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, int *N)
{
   double X; 
   char AA;

   printf("This is Adams-Bashforth Predictor Corrector Method\n");
   printf("Has the function F been created in the program \n");
   printf("preceding the INPUT procedure?  Enter Y or N.\n");
   scanf("%c",&AA);
   *OK = false;
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank.\n");
         scanf("%lf %lf", A, B);
         if (*A >= *B) 
            printf("Left endpoint must be less than right endpoint.\n");
         else *OK = true;
      }
      printf("Input the initial condition.\n");
      scanf("%lf", ALPHA);
      *OK = false;
      while(!(*OK)) {
         printf("Input an integer greater than or equal to 4 ");
         printf(" for the number of subintervals.\n");
         scanf("%d", N);
         if (*N < 4) printf("Number must be greater than or equal to 4.\n");
         else *OK = true;
      }
   }
   else {
      printf("The program will end so that F can be created.\n");
      *OK = false;
   }
}

void OUTPUT(FILE **OUP)
{
   char NAME[30];
   int FLAG; 

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("For example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "ADAMS-BASHFORTH FOURTH ORDER PREDICTOR CORRECTOR METHOD\n\n");
   fprintf(*OUP, "    t           w\n");
}   
