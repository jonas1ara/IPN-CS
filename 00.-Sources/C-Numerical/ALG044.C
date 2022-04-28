/*
*   DOUBLE INTEGAL ALGORITHM 4.4
*
*   To approximate I = double integral ( ( f(x,y) dy dx ) ) with limits
*   of integration from a to b for x and from c(x) to d(x) for y:
*
*   INPUT:    endpoints a, b; positive integers m, n.
*
*   OUTPUT:   approximation J to I. 
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double A,B,H,AN,AE,AO,X,HX,BN,YA,YB,BE,BO,Y,Z,A1,AC; 
   int N,M,NN,MM,I,J,OK; 

   double F(double, double);
   double C(double); 
   double D(double); 
   void INPUT(int *, double *, double *, int *, int *);
   void OUTPUT(double, double, double, int, int); 

   INPUT(&OK, &A, &B, &N, &M); 
   if (OK) {
      NN = 2 * N;
      MM = 2 * M - 1;
      /* STEP 1 */ 
      H = (B - A) / NN;         
      /* use AN, AE, AO for J(1), J(2), J(3) resp. */ 
      /* end terms */ 
      AN = 0.0;
      /* even terms */
      AE = 0.0;
      /* odd terms */
      AO = 0.0;
      /* STEP 2 */ 
      for (I=0; I<=NN; I++) { 
	 /* STEP 3 */ 
	 /* Composite Simpson's Method for X */ 
	 X = A + I * H;                 
	 YA = C(X);
	 YB = D(X);
	 HX = (YB - YA) / (2.0 * M);
	 /* use BN, BE, BO for K(1), K(2), K(3) resp. */
	 /* end terms */
	 BN = F(X, YA) + F(X, YB);
	 /* even terms */
	 BE = 0.0;
	 /* odd terms */
	 BO = 0.0;
	 /* STEP 4 */ 
	 for (J=1; J<=MM; J++) {
	    /* STEP 5 */ 
	    Y = YA + J * HX; 
	    Z = F(X, Y);
	    /* STEP 6 */ 
	    if ((J%2) == 0) BE = BE + Z; 
	    else BO = BO + Z; 
	 }
	 /* STEP 7 */ 
	 /* use A1 for L, which is the integral of F(X(I), Y) from */
	 /* C(X(I)) to D(X(I)) by Composite Simpson's Method */ 
	 A1 = (BN + 2.0 * BE + 4.0 * BO) * HX / 3.0;
	 /* STEP 8 */ 
	 if ((I == 0) || (I == NN)) AN = AN + A1; 
	 else {
	    if ((I%2) == 0) AE = AE + A1;
	    else AO = AO + A1;
	 }
      } 
      /* STEP 9 */ 
      /* Use AC for J */ 
      AC = (AN + 2.0 * AE + 4.0 * AO) * H /3.0;
      /* STEP 10 */ 
      OUTPUT(A, B, AC, N, M);           
   }
   return 0;
}

/* Change function F,C,D for a new problem */
double F(double X, double Y)
{  /* F is the integrand */ 
   double f; 

   f = exp(Y / X); 
   return f;
}

double C(double X)
{  /* C(X) is the lower limit of Y */ 
   double f; 

   f = X * X * X; 
   return f;
}

double D(double X)
{  /* D(X) is the upper limit of Y */
   double f; 

   f = X * X; 
   return f;
}

void INPUT(int *OK, double *A, double *B, int *N, int *M)
{
   char AA;

   printf("This is Simpsons Method for double integrals.\n\n");
   printf("Have the functions F, C and D been created in the program immediately\n");
   printf("preceding the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input lower and upper limits of integration ");
	 printf("for the outer integral separated\n");
	 printf("by a blank\n");
	 scanf("%lf %lf", A, B);
	 if (*A > *B) printf("Lower limit must be less than upper limit\n");
	 else *OK = true;
      } 
      *OK = false;
      while (!(*OK)) {
	 printf("Input two positive integers N, M ; there will");
	 printf(" be 2N subintervals for outer\n");
	 printf("integral and 2M subintervals for inner ");
	 printf("integral - separate with blank\n");
	 scanf("%d %d",N, M);
	 if ((*M <= 0) || (*N <= 0)) printf("Integers must be positive\n");
	 else *OK = true;
      }
   }
   else {
      printf("The program will end so that the functions F,C,D can be created\n");
      *OK = false;
   }
}

void OUTPUT(double A, double B, double AC, int N, int M)
{
   printf("\nThe integral of F from %12.8f to %12.8f is\n", A, B);
   printf("%12.8f", AC);
   printf(" obtained with N = %3d and M = %3d\n", N, M);
}   
