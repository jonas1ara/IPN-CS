/*
*   SECANT ALGORITHM 2.4
*
*   To find a solution to the equation f(x) = 0
*   given initial approximations p0 and p1:
*
*   INPUT:   initial approximation p0, p1; tolerance TOL;
*            maximum number of iterations N0.
*
*   OUTPUT:  approximate solution p or
*            a message that the algorithm fails.
*
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double P0,F0,P1,F1,P,FP,TOL;
   int I,NO,OK,FLAG;
   FILE *OUP[1];

   double absval(double);
   double F(double);
   void INPUT(int *, double *, double *, double *, int *);
   void OUTPUT(FILE **, int *);

   INPUT(&OK, &P0, &P1, &TOL, &NO);
   if (OK) {
      OUTPUT(OUP, &FLAG);
      /* STEP 1 */ 
      I = 2;      
      F0 = F(P0);
      F1 = F(P1);
      OK = true;                                
      /* STEP 2 */ 
      while ((I<=NO) && OK) {   
	 /* STEP 3 */ 
	 /* compute P(I) */ 
	 P = P1 - F1 * (P1 - P0) / (F1 - F0);

	 /* STEP 4 */  
	 FP = F(P);  
	 if (FLAG == 2) fprintf(*OUP,"%3d   %15.8e   %15.8e \n",I,P,FP); 
	 if (absval(P - P1) < TOL) {
	    /* procedure completed successfully */
	    fprintf(*OUP,"\nApproximate solution P = %12.8f\n",P);
	    fprintf(*OUP,"with F(P) = %12.8f\n",FP);
	    fprintf(*OUP,"Number of iterations = %3d",I);
	    fprintf(*OUP,"    Tolerance = %14.8e\n",TOL);
	    OK = false;
	 }
	 else {
	    /* STEP 5 */ 
	    I++; 
	    
	    /* STEP 6 */ 
	    /* update P0, F0, P1, F1 */ 
	    P0 = P1;
	    F0 = F1;
	    P1 = P;
	    F1 = FP;
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

   f = cos(X) - X;
   return f;
}

void INPUT(int *OK, double *P0, double *P1, double *TOL, int *NO)
{
   char AA;

   printf("This is the Secant Method.\n");
   printf("Has the function F been created in the program immediately preceding\n");
   printf("the INPUT function?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
	 printf("Input initial approximations P0 and P1 separated by blank\n");
	 scanf("%lf %lf", P0, P1);
	 if (*P0 == *P1) printf("P0 cannot equal P1\n");
	 else *OK = true;
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
   fprintf(*OUP,"Secant Method\n");
   if (*FLAG == 2) fprintf(*OUP, "  I                 P              F(P)\n");
}   
     

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
