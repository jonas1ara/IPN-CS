/*
*   SIMPSON'S COMPOSITE ALGORITHM 4.1
*
*   To approximate I = integral ( ( f(x) dx ) ) from a to b:
*
*   INPUT:   endpoints a, b; even positive integer n.
*
*   OUTPUT:  approximation XI to I.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double A,B,XI0,XI1,XI2,H,XI,X;
   int I,N,NN,OK;

   double F(double);
   void INPUT(int *, double *, double *, int *);
   void OUTPUT(double, double, double);

   INPUT(&OK, &A, &B, &N);
   if (OK) {
      /* STEP 1 */ 
      H = (B - A) / N; 
      /* STEP 2 */ 
      XI0 = F(A) + F(B);
      /* summation of f(x(2*I-1)) */
      XI1 = 0.0;
      /* summation of f(x(2*I)) */
      XI2 = 0.0;
      /* STEP 3 */ 
      NN = N - 1;       
      for (I=1; I<=NN; I++) {
	 /* STEP 4 */ 
	 X = A + I * H; 
	 /* STEP 5 */ 
	 if ((I%2) == 0) XI2 = XI2 + F(X); 
	 else XI1 = XI1 + F(X);
      }
      /* STEP 6 */ 
      XI = (XI0 + 2.0 * XI2 + 4.0 * XI1) * H / 3.0; 
      /* STEP 7 */   
      OUTPUT(A, B, XI); 
   }
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

   printf("This is Simpsons Method.\n\n");
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
	 printf("Input an even positive integer N.\n");
	 scanf("%d", N);
	 if ((*N > 0) && (((*N)%2) == 0)) *OK = true;
	 else printf("Input must be even and positive\n");
      }
   }
   else {
      printf("The program will end so that the function F can be created\n");
      *OK = false;
   }
}

void OUTPUT(double A, double B, double XI)
{
   printf("\nThe integral of F from %12.8f to %12.8f is\n", A, B);
   printf("%12.8f\n", XI);
}   
