/*
*   BISECTION ALGORITHM 2.1
*
*   To find a solution to f(x) = 0 given the continuous function
*   f on the interval [a,b], where f(a) and f(b) have
*   opposite signs:
*
*   INPUT:   endpoints a,b; tolerance TOL;
*            maximum number of iterations N0.
*
*   OUTPUT:  approximate solution p or
*            a message that the algorithm fails.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

main()
{
   double A,FA,B,FB,C,P,FP,TOL;
   int I,NO,OK,FLAG;
   FILE *OUP[1];

   double absval(double);
   double F(double);
   void INPUT(int *, double *,  double *, double *, double *, double *, int *);
   void OUTPUT(FILE **, int *);

   INPUT(&OK, &A, &B, &FA, &FB, &TOL, &NO);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      /* STEP 1 */
      I = 1;     
      /* STEP 2 */ 
      OK = true; 
      while ((I<=NO) && OK) {
	 /* STEP 3 */ 
	 /* compute P(I) */     
	 C = (B - A) / 2.0;
	 P = A + C;

	 /* STEP 4 */ 
	 FP = F(P);  
	 if (FLAG == 2) fprintf(*OUP,"%3d   %15.8e   %15.7e \n",I,P,FP); 
	 if ((absval(FP)<ZERO) || (C<TOL)) {
	    /* procedure completed successfully */
	    fprintf(*OUP,"\nApproximate solution P = %11.8f \n",P);
	    fprintf(*OUP,"with F(P) = %12.8f\n",FP);
	    fprintf(*OUP,"Number of iterations = %3d",I);
	    fprintf(*OUP,"    Tolerance = %15.8e\n",TOL);
	    OK = false;
	 }
	 else {
	    /* STEP 5 */ 
	    I++; 
	    
	    /* STEP 6 */ 
	    /* compute A(I) and B(I) */ 
	    if ((FA*FP) > 0.0) {
	       A = P; FA = FP;
	    }
	    else {
	       B = P; FB = FP;
	    }
	 }
      }
      if (OK) {
	 /* STEP 7 */ 
	 /* procedure completed unsuccessfully */
	 fprintf(*OUP,"\nIteration number %3d",NO);
	 fprintf(*OUP," gave approximation %12.8f\n",P);
	 fprintf(*OUP,"F(P) = %12.8f not within tolerance : %15.8e\n",FP,TOL);
      }
      fclose(*OUP);
   }
   return 0;
}

/* Change function F for a new problem */
double F(double X)
{
   double f; 

   f = ( X + 4.0 ) * X * X - 10.0;
   return f;
}

void INPUT(int *OK, double *A, double *B, double *FA, double *FB, double *TOL, int *NO)
{
   double X; 
   char AA;

   printf("This is the Bisection Method.\n");
   printf("Has the function F been created in the program immediately preceding\n");
   printf("the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input endpoints A < B separated by blank\n");
	 scanf("%lf %lf", A, B);
	 if (*A > *B) {
	    X = *A; *A = *B; *B = X;
	 }
	 if (*A == *B) printf("A cannot equal B\n");
	 else {
	    *FA = F(*A);
	    *FB = F(*B);
	    if (*FA*(*FB) > 0.0) printf("F(A) and F(B) have same sign\n");
	    else *OK = true;
	 }
      } 
      *OK = false;
      while(!(*OK)) {
	 printf("Input tolerance\n");
	 scanf("%lf", TOL);
	 if (*TOL <= 0.0) printf("Tolerance must be positive\n");
	 else *OK = true;
      }
      *OK = false;
      while (!(*OK)) {
	 printf("Input maximum number of iterations - no decimal point\n");
	 scanf("%d", NO);
	 if (*NO <= 0) printf("Must be positive integer\n");
	 else *OK = true;
      }
   }
   else {
      printf("The program will end so that the function F can be created\n");
      *OK = false;
   }
}

void OUTPUT(FILE **OUP, int *FLAG)
{
   char NAME[30];

   printf("Select output destination\n");
   printf("1. Screen\n");
   printf("2. Text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   if (*FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP,"Bisection Method\n");
   printf("Select amount of output\n");
   printf("1. Answer only\n");
   printf("2. All intermeditate approximations\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   if (*FLAG == 2) fprintf(*OUP, "  I                 P              F(P)\n");
}   
     

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
