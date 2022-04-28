/*
*     RUNGE-KUTTA FOR SYSTEMS OF DIFFERENTIAL EQUATIONS ALGORITHM 5.7
*
*     TO APPROXIMATE THE SOLUTION OF THE MTH-ORDER SYSTEM OF FIRST-
*     ORDER INITIAL-VALUE PROBLEMS
*                UJ' = FJ( T, U1, U2, ..., UM ), J = 1, 2, ..., M
*                 A <= T <= B, UJ(A) = ALPHAJ, J = 1, 2, ..., M
*     AT (N+1) EQUALLY SPACED NUMBERS IN THE INTERVAL [A,B].
*
*     INPUT:   ENDPOINTS A,B; NUMBER OF EQUATIONS M; INITIAL
*              CONDITIONS ALPHA1, ..., ALPHAM; INTEGER N.
*
*     OUTPUT:  APPROXIMATION WJ TO UJ(T) AT THE (N+1) VALUES OF T.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double A,B,ALPHA1,ALPHA2,H,T,W1,W2,X11,X12,X21,X22,X31,X32,X41,X42;
   int I,N,OK;
   FILE *OUP[1];

   double F1(double, double, double);
   double F2(double, double, double);
   double absval(double);
   void INPUT(int *, double *, double *, double *, double *, int *);
   void OUTPUT(FILE **);

   INPUT(&OK, &A, &B, &ALPHA1, &ALPHA2, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      H = (B - A) / N;
      T = A;
      /* STEP 2 */
      W1 = ALPHA1;
      W2 = ALPHA2;
      /* STEP 3 */
      fprintf(*OUP, "%5.3f %11.8f %11.8f\n", T, W1, W2);
      /* STEP 4 */
      for (I=1; I<=N; I++) {
         /* STEP 5 */
         X11 = H * F1(T, W1, W2);
         X12 = H * F2(T, W1, W2);
         /* STEP 6 */
         X21 = H * F1(T + H / 2.0, W1 + X11 / 2.0, W2 + X12 / 2.0);
         X22 = H * F2(T + H / 2.0, W1 + X11 / 2.0, W2 + X12 / 2.0);
         /* STEP 7 */
         X31 = H * F1(T + H / 2.0, W1 + X21 / 2.0, W2 + X22 / 2.0);
         X32 = H * F2(T + H / 2.0, W1 + X21 / 2.0, W2 + X22 / 2.0);
         /* STEP 8  */
         X41 = H * F1(T + H, W1 + X31, W2 + X32);
         X42 = H * F2(T + H, W1 + X31, W2 + X32);
         /* STEP 9 */
         W1 = W1 + (X11 + 2.0 * X21 + 2.0 * X31 + X41) / 6.0;
         W2 = W2 + (X12 + 2.0 * X22 + 2.0 * X32 + X42) / 6.0;
         /* STEP 10 */
         T = A + I * H;
         /* STEP 11 */
         fprintf(*OUP, "%5.3f %11.8f %11.8f\n", T, W1, W2);
      }  
      /* STEP 12 */
      fclose(*OUP);
   }
   return 0;
}

/*  Change functions F1 and F2 for a new problem.  */
double F1(double T, double X1, double X2)
{
   double f; 

   f = -4*X1+3*X2+6;
   return f;
}

double F2(double T, double X1, double X2)
{
   double f; 

   f = -2.4*X1+1.6*X2+3.6;
   return f;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA1, double *ALPHA2, int *N)
{
   double X; 
   char AA;

   printf("This is the Runge-Kutta Method for Systems with m = 2.\n");
   *OK = false;
   printf("Have the functions F1 and F2 been defined? ");
   printf("Answer Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank\n");
         scanf("%lf %lf", A, B);
         if (*A >= *B) 
            printf("Left endpoint must be less than right endpoint\n");
         else *OK = true;
      }
      printf("Input the two initial conditions, separated by blank.\n");
      scanf("%lf %lf", ALPHA1, ALPHA2);
      *OK = false;
      while(!(*OK)) {
         printf("Input a positive integer for the number of subintervals\n");
         scanf("%d", N);
         if (*N <= 0) printf("Number must be a positive integer\n");
         else *OK = true;
      }
   }
   else {
      printf("The program will end so that the functions can be created.\n");
      *OK = false;
   }
}

void OUTPUT(FILE **OUP)
{
   char NAME[30];
   int FLAG; 

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text File\n");
   printf("Please enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("For example  A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "RUNGE-KUTTA METHOD FOR SYSTEMS WITH m = 2.\n");
   fprintf(*OUP, "    T          W1          W2\n\n");
}   
