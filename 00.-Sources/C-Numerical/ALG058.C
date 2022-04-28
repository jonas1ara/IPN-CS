/*
*     TRAPEZOIDAL WITH NEWTON ITERATION ALGORITHM 5.8
*
*     TO APPROXIMATE THE SOLUTION OF THE INITIAL VALUE PROBLEM:
*                Y' = F(T,Y), A <= T <= B, Y(A) = ALPHA,
*     AT (N+1) EQUALLY SPACED NUMBERS IN THE INTERVAL [A,B].
*
*     INPUT:   ENDPOINTS A,B; INITIAL CONDITION ALPHA; INTEGER N;
*              TOLERANCE TOL; MAXIMUM NUMBER OF ITERATIONS M AT ANY ONE STEP.
*
*     OUTPUT:  APPROXIMATION W TO Y AT THE (N+1) VALUES OF T
*              OR A MESSAGE OF FAILURE.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double A,B,ALPHA,TOL,W,T,H,XK1,W0,Y;
   int N,M,I,J,IFLAG,OK;
   FILE *OUP[1];

   double F(double, double);
   double FYP(double, double);
   double absval(double);
   void INPUT(int *, double *, double *, double *, double *, int *, int *);
   void OUTPUT(FILE **);

   INPUT(&OK, &A, &B, &ALPHA, &TOL, &N, &M);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      W = ALPHA;
      T = A;
      H = (B - A) / N;
      fprintf(*OUP, "%5.3f %11.8f   0\n", T, W);
      I = 1;
      OK = true;
      /* STEP 2 */
      while ((I <= N) && OK) {
         /* STEP 3 */ 
         XK1 = W + 0.5 * H * F(T, W);
         W0 = XK1;
         J = 1;
         IFLAG = 0;
         /* STEP 4 */
         while ((IFLAG == 0) && OK) {
            /* STEP 5 */
            W = W0 - (W0 - XK1 - 0.5 * H * F(T + H, W0)) /
                (1.0 - 0.5 * H * FYP( T + H, W0));
            /* STEP 6 */
            if (absval(W-W0) < TOL) {
               IFLAG = 1;
               /* STEP 7 */
               T = A + I * H;
               fprintf(*OUP,"%5.3f %11.8f %3d\n", T, W, J);
               I++;
            }  
            else {
               J++;
               W0 = W;
               if (J > M) OK = false;    
            }   
         }  
      }
      if (!OK) fprintf(*OUP, "Maximum Number of Iterations Exceeded\n");
      /* STEP 8 */
      fclose(*OUP);
   }
   return 0;
}

/*  Change functions F and FYP for a new problem.   */
double F(double T, double Y)
{
   double f; 

   f = 5*exp(5*T)*(Y-T)*(Y-T)+1;
   return f;
}
/*  Function FYP is the partial derivative of F with respect to y.  */
double FYP(double T, double Y)                         
{
   double f; 

   f = 10*exp(5*T)*(Y-T); 
   return f;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, double *TOL, int *N, int *M)
{
   double X; 
   char AA;

   printf("This is the Implicit Trapezoidal Method.\n");
   *OK = false;
   printf("Have the functions F and FYP been defined?\n");
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
      printf("Input the initial condition.\n");
      scanf("%lf", ALPHA);
      *OK = false;
      while(!(*OK)) {
         printf("Input a positive integer for the number of subintervals\n");
         scanf("%d", N);
         if (*N <= 0) printf("Number must be a positive integer\n");
         else *OK = true;
      }
      *OK = false;
      while(!(*OK)) {
         printf("Input tolerance.\n");
         scanf("%lf", TOL);
         if (*TOL > 0.0) *OK = true;
         else printf("Tolerance must be a positve real number\n");
      }  
      *OK = false;
      while(!(*OK)) {
         printf("Input the maximum number of iterations\n");
         scanf("%d", M);
         if (*M > 0) *OK = true;
         else printf("Number of iterations must be positive\n");
      } 
   }
   else {
      printf("The program will end so that the functions can be created.\n");
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
      printf("For example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "IMPLICIT TRAPEZOIDAL METHOD USING NEWTONS METHOD\n\n");
   fprintf(*OUP, "    t           w #iter\n");
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
