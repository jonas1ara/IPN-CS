/*
*   METHOD OF FALSE POSITION ALGORITHM 2.5
*
*   To find a solution to f(x) = 0 given the continuous function
*   f on the interval [p0,p1], where f(p0) and f(p1) have
*   opposite signs:
*
*   INPUT:   endpoints p0, p1; tolerance TOL;
*            maximum number of iterations N0.
*
*   OUTPUT:  approximate solution p or
*            a message that the algorithm fails.
*
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

main()
{
   double Q,P0,Q0,P1,Q1,C,P,FP,TOL;
   int I,NO,OK,FLAG;
   FILE *OUP[1];

   double absval(double);
   double F(double);
   void INPUT(int *, double *, double *, double *, double *, double *, int *);
   void OUTPUT(FILE **, int *);

   INPUT(&OK, &P0, &P1, &Q0, &Q1, &TOL, &NO);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      /* STEP 1 */ 
      I = 2;      
      OK = true;                        
      Q0 = F(P0);
      Q1 = F(P1);
      /* STEP 2 */ 
      while ((I<=NO) && OK) {   
	 /* STEP 3 */ 
	 /* compute P(I) */ 
	 P = P1 - Q1 * (P1 - P0) / (Q1 - Q0);
	 Q = F(P);
	 if (FLAG == 2) fprintf(*OUP,"%3d   %15.8e   %15.8e\n",I,P,Q); 
	 /* STEP 4 */
	 if (absval(P-P1) < TOL) {
	    /* procedure completed successfully */
	    fprintf(*OUP,"\nApproximate solution P = %12.8f\n",P);
	    fprintf(*OUP,"with F(P) = %12.8f\n",Q);
	    fprintf(*OUP,"Number of iterations = %3d",I);
	    fprintf(*OUP,"    Tolerance = %15.8e\n",TOL);
	    OK = false;
	 }
	 else {
	    /* STEP 5 */ 
	    I++;        
	    
	    /* STEP 6 */ 
	    /* compute P0(I) and P1(I) */ 
	    if ((Q*Q1) < 0.0) {
	       P0 = P1; Q0 = Q1;
	    }
	    /* STEP 7 */ 
	    P1 = P; Q1 = Q;     
	 }
      }
      if (OK) {
	 /* procedure completed unsuccessfully */
	 fprintf(*OUP,"\nIteration number %3d",NO);
	 fprintf(*OUP," gave approximation %12.8f\n",P);
	 fprintf(*OUP,"F(P) = %12.8f not within tolerance : %15.8e\n",Q,TOL);
      }
      fclose(*OUP);
   }
   return 0;
}

/* Change function F for a new problem */
double F(double X)
{
   double f; 

   f = cos(X) - X;
   return f;
}

void INPUT(int *OK, double *P0, double *P1, double *Q0, double *Q1, double *TOL, int *NO)
{
   double X; 
   char AA;

   printf("This is the Method of False Position.\n");
   printf("Has the function F been created in the program immediately preceding\n");
   printf("the INPUT function?\n");
   printf("Enter Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input endpoints P0 < P1 separated by blank.\n");
	 scanf("%lf %lf", P0, P1);
	 if (*P0 > *P1) {
	    X = *P0; *P0 = *P1; *P1 = X;
	 }
	 if (*P0 == *P1) printf("P0 cannot equal P1.\n");
	 else {
	    *Q0 = F(*P0);
	    *Q1 = F(*P1);
	    if (*Q0*(*Q1) > 0.0) printf("F(P0) and F(P1) have same sign.\n");
	    else *OK = true;
	 }
      } 
      *OK = false;
      while(!(*OK)) {
	 printf("Input tolerance.\n");
	 scanf("%lf", TOL);
	 if (*TOL <= 0.0) printf("Tolerance must be positive.\n");
	 else *OK = true;
      }
      *OK = false;
      while (!(*OK)) {
	 printf("Input maximum number of iterations - no decimal point.\n");
	 scanf("%d", NO);
	 if (*NO <= 0) printf("Must be positive integer.\n");
	 else *OK = true;
      }
   }
   else {
      printf("The program will end so that the function F can be created.\n");
      *OK = false;
   }
}

void OUTPUT(FILE **OUP, int *FLAG)
{
   char NAME[30];

   printf("Choice of output method\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   if (*FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("For example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   printf("Select amount of output\n");
   printf("1. Answer only\n");
   printf("2. All intermeditate approximations\n");
   printf("Enter 1 or 2\n");
   scanf("%d", FLAG);
   fprintf(*OUP, "METHOD OF FALSE POSITION OR REGULA FALSII\n\n");
   if (*FLAG == 2) fprintf(*OUP, "  I                 P              F(P)\n");
}   
     

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
