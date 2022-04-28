/*
*   GAUSSIAN TRIPLE INTEGRAL ALGORITHM 4.6
* 
*   To approximate I = triple integral ( ( f(x,y,z) dz dy dx ) ) with limits
*   of integration from a to b for x, from c(x) to d(x) for y, and from
*   alpha(x,y) to beta(x,y) for z.
*
*   INPUT:   endpoints a, b; postive integers m, n, p. (Assume that the
*            roots r(i,j) and coefficients c(i,j) are available for i
*            equals m, n, and p and for 1 <= j <= i.
*
*   OUTPUT:  approximation J TO I. 
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double r[5][5],co[5][5];
   double A,B,H1,H2,AJ,JX,D1,C1,K1,K2,JY,Z1,Z2,L1,L2,X,Y,Z,Q; 
   int N,M,I,J,P,K,OK; 

   double F(double, double, double);
   double C(double); 
   double D(double); 
   double ALPHA(double, double);
   double BETA(double, double); 
   void INPUT(int *, double *, double *, int *, int *, int *); 
   void OUTPUT(double, double, double, int, int, int); 

   INPUT(&OK, &A, &B, &M, &N, &P); 
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
      AJ = 0.0;                         /* Use AJ instead of J. */ 
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
	    /* STEP 5 */ 
	    Y = K1 * r[N-1][J-1] + K2;  
	    JY = 0.0;
	    /* use Z1 for Beta and Z2 for Alpha */
	    Z1 = BETA(X, Y);
	    Z2 = ALPHA(X, Y); 
	    L1 = (Z1 - Z2) / 2.0;
	    L2 = (Z1 + Z2) / 2.0;
	    /* STEP 6 */ 
	    for (K=1; K<=P; K++) { 
	       Z = L1 * r[P-1][K-1] + L2;
	       Q = F(X, Y, Z);
	       JY = JY + co[P-1][K-1] * Q;
	    }
	    /* STEP 7 */ 
	    JX = JX + co[N-1][J-1] * L1 * JY;
	 }
	 /* STEP 8 */ 
	 AJ = AJ + co[M-1][I-1] * K1 * JX; 
      }
      /* STEP 9 */ 
      AJ = AJ * H1; 
      /* STEP 10 */ 
      OUTPUT(A, B, AJ, M, N, P);                
   } 
   return 0;
}

/* Change functions F,C,D,ALPHA,BETA for a new problem */
double F(double X, double Y, double Z)
{  /* F is the integrand */ 
   double f; 

   f = sqrt(X * X + Y * Y); 
   return f;
}

double C(double X)
{  /* C is the lower limit of Y */ 
   double f; 

   f = 0.0; 
   return f;
}

double D(double X)
{  /* D is the upper limit of Y */
   double f; 

   f = sqrt(4 - X * X); 
   return f;
}

double ALPHA(double X, double Y)
{  /* ALPHA is the lower limit for Z */ 
   double f; 

   f = sqrt(X * X + Y * Y); 
   return f;
}

double BETA(double X, double Y)
{  /* BETA is the upper limit for Z */ 
   double f; 

   f = 2; 
   return f;
}

void INPUT(int *OK, double *A, double *B, int *M, int *N, int *P)
{
   char AA;

   printf("This is Gaussian Quadrature for triple integrals.\n");  
   printf("Have the functions F, C, D, ALPHA, ");
   printf("and BETA been created in\n");
   printf("the program immediately preceding the INPUT function?\n");
   printf("Enter Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input lower and upper limits of integration ");
	 printf("of the outer integral separated\n"); 
	 printf("by a blank.\n");
	 scanf("%lf %lf", A, B);
	 if (*A > *B) printf("Lower limit must be less than upper limit.\n");
	 else *OK = true;
      } 
      *OK = false;
      while (!(*OK)) {
         printf("Input three integers M, N, P. This\n");
	 printf("implementation of Gaussian quadrature requires\n");
         printf("that they are greater than 1 and\n");
         printf("less than or equal to 5.\n");
	 printf("They will be used in ");  
	 printf("first, second, and third dimensions, resp.\n");
	 printf(" - separate with blank.\n");
	 scanf("%d %d %d", M, N, P);
         if ((*M <= 1) || (*N <= 1) || (*P <= 1)) 
            printf("Integers must be > 1.\n");
	 else
	    if ((*M > 5) || (*N > 5) || (*P > 5))
	       printf("Integers must be less than or equal to 5.\n");
	 else *OK = true;
      }
   }
   else {
      printf("The program will end so that the functions F,C,D,ALPHA,BETA can be created.\n");
      *OK = false;
   }
}

void OUTPUT(double A, double B, double AJ, int M, int N, int P)
{
   printf("\nThe integral of F from %12.8f to %12.8f is   ", A, B);
   printf("%.10e\n", AJ);
   printf(" obtained with M = %3d , N = %3d and P = %3d\n", M, N, P);
}
