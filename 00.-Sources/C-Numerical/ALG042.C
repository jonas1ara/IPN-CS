/*
*   ROMBERG ALGORITHM 4.2
*   
*   To approximate I = integral ( ( f(x) dx ) ) from a to b:
*   
*   INPUT:   endpoints a, b; integer n.
*
*   OUTPUT:  an array R. ( R(2,n) is the approximation to I. )
*
*   R is computed by rows; only 2 rows saved in storage   
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double R[2][15]; 
   double A,B,H,X,SUM;
   int I,J,K,L,M,N,OK;

   double F(double);
   void INPUT(int *, double *, double *, int *);

   INPUT(&OK, &A, &B, &N);
   /* STEP 1 */ 
   if (OK) { 
      H = (B - A);
      R[0][0] = (F(A) + F(B)) / 2.0 * H;
      /* STEP 2 */ 
      printf("Initial Data:\n"); 
      printf("Limits of integration = [%12.8f, %12.8f]\n", A, B);
      printf("Number of rows = %3d\n", N);
      printf("\nRomberg Integration Table:\n");
      printf("\n%12.8f\n\n", R[0][0]);
      /* STEP 3 */ 
      for (I=2; I<=N; I++) { 
	 /* STEP 4 */  
	 /* approximation from Trapezoidal method */ 
	 SUM = 0.0;
	 M =  exp((I - 2) * log(2.0)) + 0.5;
	 for (K=1; K<=M; K++) SUM = SUM + F(A + (K - 0.5) * H);
	 R[1][0] = (R[0][0] + H * SUM) / 2.0;
	 /* STEP 5 */ 
	 /* extrapolation */    
	 for (J=2; J<=I; J++) {
	    L = exp(2* (J - 1) * log(2.0)) + 0.5;
	    R[1][J-1] = R[1][J-2]+(R[1][J-2]-R[0][J-2])/(L - 1.0);
	 }
	 /* STEP 6 */ 
	 for (K=1; K<=I; K++) printf(" %11.8f",R[1][K-1]); 
	 printf("\n\n");
	 /* STEP 7 */ 
	 H = H / 2.0;   
	 /* since only two rows are kept in storage, this step */
	 /* is to prepare for the next row */
	 /* update row 1 of R */                
	 /* STEP 8 */ 
	 for (J=1; J<=I; J++) R[0][J-1] = R[1][J-1];
      }
   }
   /* STEP 9 */ 
   return 0; 
}

/* Change function F for a new problem */
double F(double X)
{
   double f; 

   f = sin(X);
   return f;
}

void INPUT(int *OK, double *A, double *B, int *N)
{
   char AA;

   printf("This is Romberg integration.\n\n");
   printf("Has the function F been created in the program immediately preceding\n");
   printf("the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input lower limit of integration and ");
	 printf("upper limit of integration\n");
	 printf("separated by a blank\n");
	 scanf("%lf %lf", A, B);
	 if (*A > *B) printf("Lower limit must be less than upper limit\n");
	 else *OK = true;
      } 
      *OK = false;
      while (!(*OK)) {
	 printf("Input number of rows - no decimal point\n");
	 scanf("%d", N);
	 if (*N > 0) *OK = true;
	 else printf("Number must be a positive integer\n");
      }
   }
   else {
      printf("The program will end so that the function F can be created\n");
      *OK = false;
   }
}
