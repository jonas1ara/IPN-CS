/*
*   HORNER'S ALGORITHM 2.7
*
*   To evaluate the polynomial
*   p(x) = a(n) * x^n + a(n-1) * x^(n-1) + ... + a(1) * x + a(0)
*   and its derivative p'(x) at x = x0;
*
*   INPUT:   degree n; coefficients aa(0),aa(1),...,aa(n);
*            value of x0.
*
*   OUTPUT:  y = p(x0), z = p'(x0).
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double AA[51];
   double X0,Y,Z;
   int OK,N,MM,I,J;

   void INPUT(int *, int *, int *, double *, double *);

   INPUT(&OK, &I, &N, AA, &X0);
   /* STEP 1 */ 
   /* compute b(n) and for p(x) */ 
   Y = AA[N];
   /* compute b(n-1) for q(x) = p'(x) */
   if (N == 0)  Z = 0;
   else Z = AA[N];
   MM = N-1;
   /* STEP 2 */ 
   for (I=1; I<=MM; I++) {
      J = N-I;
      /* compute b(j) for p(x) */
      Y = Y * X0 + AA[J];
      /* compute b(j-1) for q(x) */
      Z = Z * X0 + Y;
   }
   /* STEP 3 */ 
   /* compute b(0) for p(x) */ 
   if (N != 0) Y = Y * X0 + AA[0];
   printf("Coefficients of polynominal P :\n");
   /* STEP 4 */ 
   for (I=0;I<=N;I++)   
      printf("Exponent = %3d    Coefficient = %12.8f\n", I, AA[I]);
   printf("\n P ( %.10e ) = %12.8f\n", X0, Y);
   printf(" P' ( %.10e ) = %12.8f\n", X0, Z);
}

void INPUT(int *OK, int *I, int *N, double *AA, double *X0)
{
   printf("This is Horners Method\n");
   *OK = false;
   while(!(*OK)) {
      printf("Input degree n of polynomial - no decimal point\n");
      scanf("%d", N);
      if (*N < 0) printf("Incorrect input - degree must be positive.\n");
      else *OK = true;
   }
   printf("Input coefficients of P(X) in ascending order\n");
   for (*I=0; *I<=*N; (*I)++) {
      printf("Input coefficient of X** %d\n", *I);
      scanf("%lf", &AA[*I]);
   }
   printf("Input argument X0 at which to evaluate P(X)\n");
   scanf("%lf", X0);
}
