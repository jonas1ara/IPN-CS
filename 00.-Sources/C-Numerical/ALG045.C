/*
*   GAUSSIAN DOUBLE INTEGRAL ALGORITHM 4.5 
*
*   To approximate I = double integration ( ( f(x, y) dy dx ) ) with limits
*   of integration from a to b for x and from c(x) to d(x) for y:
*
*   INPUT:    endpoints a, b; positive integers m, n. (Assume that the
*             roots r(i,j) and coefficients c(i,j) are available for 
*             i equals m and n for 1<= j <= i.
* 
*   OUTPUT:   approximation J to I. 
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double r[5][5],co[5][5];
   double A,B,H1,H2,AJ,JX,D1,C1,K1,K2,X,Y,Q; 
   int N,M,I,J,OK; 

   double F(double, double);
   double C(double); 
   double D(double); 
   void INPUT(int *, double *, double *, int *, int *);
   void OUTPUT(double, double, double, int, int); 

   INPUT(&OK, &A, &B, &M, &N); 
   if (OK) {
      r[1][0] = 0.5773502692; r[1][1] = -r[1][0]; co[1][0] = 1.0;
      co[1][1] = 1.0; r[2][0] = 0.7745966692; r[2][1] = 0.0;
      r[2][2] = -r[2][0]; co[2][0] = 0.5555555556; co[2][1] = 0.8888888889;
      co[2][2] = co[2][0]; r[3][0] = 0.8611363116; r[3][1] = 0.3399810436;
      r[3][2] = -r[3][1]; r[3][3] = -r[3][0]; co[3][0] = 0.3478548451;
      co[3][1] = 0.6521451549; co[3][2] = co[3][1]; co[3][3] = co[3][0];
      r[4][0] = 0.9061798459; r[4][1] = 0.5384693101; r[4][2] = 0.0;
      r[4][3] = -r[4][1]; r[4][4] = -r[4][0]; co[4][0] = 0.2369268850;
      co[4][1] = 0.4786286705; co[4][2] = 0.5688888889; co[4][3] = co[4][1];
      co[4][4] = co[4][0];
      /* STEP 1 */ 
      H1 = (B - A) / 2.0; 
      H2 = (B + A) / 2.0;
      /* use AJ in place of J */
      AJ = 0.0;
      /* STEP 2 */ 
      for (I=1; I<=M; I++) { 
	 /* STEP 3 */ 
	 X = H1 * r[M-1][I-1] + H2;     
	 JX = 0.0;
	 C1 = C(X);
	 D1 = D(X);
	 K1 = (D1 - C1) / 2.0;
	 K2 = (D1 + C1) / 2.0;
	 /* STEP 4 */ 
	 for (J=1; J<=N; J++) { 
	    Y = K1 * r[N-1][J-1] + K2;
	    Q = F(X, Y);
	    JX = JX + co[N-1][J-1] * Q;
	 }
	 /* STEP 5 */ 
	 AJ = AJ + co[M-1][I-1] * K1 * JX; 
      }
      /* STEP 6 */ 
      AJ = AJ * H1;
      /* STEP 7 */ 
      OUTPUT(A, B, AJ, M, N);           
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

void INPUT(int *OK, double *A, double *B, int *M, int *N)
{
   char AA;

   printf("This is Gaussian Quadrature for double integrals.\n");  
   printf("Have the functions F, C and D been created in the program immediately\n");
   printf("preceding the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input lower and upper limits of integration of ");
	 printf("the outer integral separated\n");
	 printf("by a blank.\n");
	 scanf("%lf %lf", A, B);
	 if (*A > *B) printf("Lower limit must be less than upper limit.\n");
	 else *OK = true;
      } 
      *OK = false;
      while (!(*OK)) {
         printf("Input two integers M,N.\n");
	 printf("This implementation of Gaussian quadrature\n");
         printf("requires both to be greater than 1 and\n");
         printf("less than or equal to 5\n");
	 printf("M is used for the outer integral and N for the inner\n"); 
	 printf("integral - separate with blank.\n");
	 scanf("%d %d", M, N);
         if ((*M <= 1) || (*N <= 1)) printf("Integers must > 1.\n");
	 else 
	    if ((*M >= 6) || (*N >= 6)) 
	       printf("Integers must be less then or equal to 5.\n");
	    else *OK = true;
      }
   }
   else {
      printf("The program will end so that the functions F,C,D can be created\n");
      *OK = false;
   }
}

void OUTPUT(double A, double B, double AJ, int M, int N)
{
   printf("\nThe integral of F from %12.8f to %12.8f is\n", A, B);
   printf("  %.10e", AJ);
   printf(" obtained with M = %3d and N = %3d\n", M, N);
}
