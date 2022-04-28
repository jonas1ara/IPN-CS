/*
*   NEWTON-RAPHSON ALGORITHM 2.3
*
*   To find a solution to f(x) = 0 given an
*   initial approximation p0:
*
*   INPUT:   initial approximation p0; tolerance TOL;
*            maximum number of iterations NO.
*
*   OUTPUT:  approximate solution p or a message of failure
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double TOL,P0,D,F0,FP0;
   int OK,I,NO,FLAG;
   FILE *OUP[1];

   double absval(double);
   double F(double);
   double FP(double);
   void INPUT(int *, double *, double *, int *);
   void OUTPUT(FILE **, int *);

   INPUT(&OK, &P0, &TOL, &NO);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      F0 = F(P0);
      /* STEP 1 */ 
      I = 1;      
      OK = true;        
      /* STEP 2 */ 
      while ((I<=NO) && OK) {  
	 /* STEP 3 */ 
	 /* compute P(I) */ 
	 FP0 = FP(P0);
	 D = F0/FP0;
	 /* STEP 6 */ 
	 P0 = P0 - D;  
	 F0 = F(P0);
	 if (FLAG == 2) fprintf(*OUP,"%3d   %14.8e   %14.7e\n",I,P0,F0); 
	 /* STEP 4 */ 
	 if (absval(D) < TOL) { 
	    /* procedure completed successfully */
	    fprintf(*OUP,"\nApproximate solution = %.10e\n",P0);
	    fprintf(*OUP,"with F(P) = %.10e\n",F0);
	    fprintf(*OUP,"Number of iterations = %d\n",I);
	    fprintf(*OUP,"Tolerance = %.10e\n",TOL);
	    OK = false;
	 }
	 /* STEP 5 */ 
	 else I++;      
      }
      if (OK) {
	 /* STEP 7 */ 
	 /* procedure completed unsuccessfully */
	 fprintf(*OUP,"\nIteration number %d",NO);
	 fprintf(*OUP," gave approximation %.10e\n",P0);
	 fprintf(*OUP,"with F(P) = %.10e not within tolerance  %.10e\n",F0,TOL);
      }
      fclose(*OUP);
   }
   return 0;
}

/* Change functions F and FP for a new problem */
double F(double X)
{
   double f; 

   f = cos(X) - X;
   return f;
}
/*  FP is the derivative of F */
double FP(double X)
{
   double fp; 

   fp = -sin(X) - 1;
   return fp;
}

void INPUT(int *OK, double *P0, double *TOL, int *NO)
{
   char AA;

   printf("This is Newtons Method.\n");
   printf("Have the functions F and F' been created in the program\n");
   printf("immediately preceding the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      printf("Input initial approximation\n");
      scanf("%lf", P0);
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
      printf("The program will end so that the functions F and F' can be created\n");
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
   fprintf(*OUP,"Newtons Method\n");
   if (*FLAG == 2) fprintf(*OUP, "  I                P             F(P)\n");
}   
     

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
