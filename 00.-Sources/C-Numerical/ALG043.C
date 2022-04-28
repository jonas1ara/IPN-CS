/*
*   ADAPTIVE QUADRATURE ALGORITM  4.3
*    
*   To approximate I = integral ( ( f(x) dx ) ) from a to b to within
*   a given tolerance TOL:
*
*   INPUT:    endpoints a, b; tolerance TOL; limit N to number of levels
*
*   OUTPUT:   approximation APP or message that N is exceeded.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double TOL[20], A[20], H[20], FA[20], FC[20], FB[20], S[20], V[7]; 
   int L[20]; 
   double AA,BB,EPS,APP,FD,FE,S1,S2; 
   int CNT,N,I,LEV,OK; 

   double F(double, int *); 
   double absval(double);
   void INPUT(int *, double *, double *, double *, int *); 
   void OUTPUT(double, double, double, double, int);

   INPUT(&OK, &AA, &BB, &EPS, &N); 
   if (OK) {
      CNT = 0;
      OK = true;
      /* STEP 1 */ 
      APP = 0.0; 
      I = 1;
      TOL[I] = 10.0 * EPS;
      A[I] = AA;
      H[I] = 0.5 * (BB - AA);
      FA[I] = F(AA, &CNT);
      FC[I] = F((AA+H[I]), &CNT);
      FB[I] = F(BB, &CNT);
      /* Approximation from Simpsons method for entire interval. */
      S[I] = H[I] * (FA[I] + 4.0 * FC[I] + FB[I]) / 3.0;
      L[I] = 1;
      /* STEP 2 */ 
      while ((I > 0) && OK) {   
	 /* STEP 3 */ 
	 FD = F((A[I] + 0.5 * H[I]), &CNT);     
	 FE = F((A[I] + 1.5 * H[I]), &CNT);
	 /* Approximation from Simpsons method for halves of intervals.*/
	 S1 = H[I] * (FA[I] + 4.0 * FD + FC[I]) / 6.0;
	 S2 = H[I] * (FC[I] + 4.0 * FE + FB[I]) / 6.0;
	 /* Save data at this level */
	 V[0] = A[I];
	 V[1] = FA[I];
	 V[2] = FC[I];
	 V[3] = FB[I];
	 V[4] = H[I];
	 V[5] = TOL[I];
	 V[6] = S[I];
	 LEV = L[I];
	 /* STEP 4 */ 
	 /* Delete the level */
	 I--;   
	 /* STEP 5 */ 
	 if (absval(S1 + S2 - V[6]) < V[5])     
	    APP = APP + (S1 + S2);
	 else {
	    if (LEV >= N) OK = false;   /* procedure fails */
	    else {
	       /* Add one level */
	       /* Data for right half subinterval */
	       I++;
	       A[I] = V[0] + V[4];
	       FA[I] = V[2]; 
	       FC[I] = FE;
	       FB[I] = V[3];
	       H[I] = 0.5 * V[4]; 
	       TOL[I] = 0.5 * V[5];
	       S[I] = S2;
	       L[I] = LEV + 1;
	       /* Data for left half subinterval */  
	       I++;
	       A[I] = V[0];
	       FA[I] = V[1];
	       FC[I] = FD;
	       FB[I] = V[2];
	       H[I] = H[I-1];
	       TOL[I] = TOL[I-1];
	       S[I] = S1;
	       L[I] = L[I-1];
	    }
	 }
      }
      if (!OK)
  printf("Level exceeded.  Method failed to give accurate approximation\n");
      else OUTPUT(AA, BB, APP, EPS, CNT); 
   }
   return 0;
}

/* Change function F for a new problem */
double F(double X, int *CNT)
{
   double f; 

   *CNT = *CNT + 1; 
   f = 100.0 / (X * X) * sin(10.0 / X); 
   return f;
}

void INPUT(int *OK, double *AA, double *BB, double *EPS, int *N)
{
   char AB;

   printf("This is Adaptive Quadrature with Simpsons Method.\n\n");
   printf("Has the function F been created in the program immediately preceding\n");
   printf("the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AB);
   if ((AB == 'Y') || (AB == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input lower limit of integration and ");
	 printf("upper limit of integration\n");
	 printf("separated by a blank\n");
	 scanf("%lf %lf", AA, BB);
	 if (*AA > *BB) printf("Lower limit must be less than upper limit\n");
	 else *OK = true;
      } 
      *OK = false;
      while (!(*OK)) {
	 printf("Input tolerance\n");
	 scanf("%lf", EPS);
	 if ((*EPS) > 0.0) *OK = true; 
	 else printf("Tolerance must be positive\n");
      }
      *OK = false;
      while (!(*OK)) {
	 printf("Input the maximum number of levels\n");
	 scanf("%d", N);
	 if (*N > 0) *OK = true;
	 else printf("Number must be positive.\n");
      }
   }
   else {
      printf("The program will end so that the function F can be created\n");
      *OK = false;
   }
}

void OUTPUT(double AA, double BB, double APP, double EPS, int CNT)
{
   printf("\nThe integral of F from %12.8f to %12.8f is\n", AA, BB);
   printf("%12.8f to within %14.8e\n", APP, EPS);
   printf("The number of function evaluations is: %d\n", CNT); 
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
