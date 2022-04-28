/*
*   WAVE EQUATION FINITE-DIFFERENCE ALGORITHM 12.4
*
*   To approximate the solution to the wave equation:
*   subject to the boundary conditions
*                u(0,t) = u(l,t) = 0, 0 < t < T = max t
*   and the initial conditions
*                u(x,0) = F(x) and Du(x,0)/Dt = G(x), 0 <= x <= l:
*
*   INPUT:   endpoint l; maximum time T; constant ALPHA; integers m, N.
*
*   OUTPUT:  approximations W(I,J) to u(x(I),t(J)) for each I = 0, ..., m
*            and J=0,...,N.
*/

#include<stdio.h>
#include<math.h>
#define pi 4*atan(1)
#define true 1
#define false 0

double F(double X);
double G(double X);
void INPUT(int *, double *, double *, double *, int *, int *);
void OUTPUT(double, double, int, double [][21], double, int);

main()
{
   double W[21][21];
   double FT,FX,ALPHA,H,K,V,X;
   int N,M,M1,M2,N1,N2,I,J,OK;

   INPUT(&OK, &FX, &FT, &ALPHA, &N, &M);
   if (OK) {
      M1 = M + 1;
      M2 = M - 1;
      N1 = N + 1;
      N2 = N - 1;
      /* STEP 1 */
      /* V is used for lambda */
      H = FX / M;
      K = FT / N;
      V = ALPHA * K / H;
      /* STEP 2 */
      for (J=2; J<=N1; J++) {
         W[0][J-1] = 0.0;
         W[M1-1][J-1] = 0.0;
      }  
      /* STEP 3 */
      W[0][0] = F( 0.0 );
      W[M1-1][0] = F ( FX );
      /* STEP 4 */
      for (I=2; I<=M; I++) {
         W[I-1][0] = F( H * ( I - 1.0 ) );
         W[I-1][1] = (1.0-V*V)*F(H*(I-1.0))+V*V*(F(I*H)+
                     F(H*(I-2.0)))/2.0+K*G(H*(I-1.0));
      }  
      /* STEP 5 */ 
      for (J=2; J<=N; J++) 
         for (I=2; I<=M; I++) 
            W[I-1][J] = 2.0*(1.0-V*V)*W[I-1][J-1]+V*V*
                        (W[I][J-1]+W[I-2][J-1])-W[I-1][J-2];
      /* STEP 6 */
      OUTPUT(FT, X, M1, W, H, N1);
   }
   /* STEP 7 */
   return 0;
}

/* Change F for a new problem */
double F(double X)
{
   double f; 

   f =  sin(pi * X);
   return f;
}

/* Change function G for a new problem */
double G(double X)
{
   double g; 

   g =  0.0;
   return g;
}

void INPUT(int *OK, double *FX, double *FT, double *ALPHA, int *N, int *M)
{
   int FLAG;
   char AA;

   printf("This is the Finite-Difference Method for the Wave Equation.\n");
   printf("Have the functions F and G been created immediately\n");
   printf("preceding the INPUT function? Answer Y or N.\n");
   scanf("\n%c", &AA);
   if ((AA == 'Y') || (AA == 'y')) {
      printf("The lefthand endpoint on the X-axis is 0.\n");
      *OK =false;
      while (!(*OK)) {
         printf("Input the righthand endpoint on the X-axis.\n");
         scanf("%lf", FX);
         if (*FX <= 0.0) 
            printf("Must be a positive number.\n");
         else *OK = true;
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input the maximum value of the time variable T.\n");
         scanf("%lf", FT);
         if (*FT <= 0.0)
            printf("Must be a positive number.\n");
         else *OK = true;
      }  
      printf("Input the constant alpha.\n");
      scanf("%lf", ALPHA);
      *OK = false;
      while (!(*OK)) {
         printf("Input integer m = number of intervals on X-axis\n");
         printf("and N = number of time intervals - separated by a blank.\n");
         printf("Note that m must be 3 or larger.\n");
         scanf("%d %d", M, N);
         if ((*M <= 2) || (*N <= 0)) 
            printf("Numbers are not within correct range.\n");
         else *OK = true;
      }  
   }   
   else {
      printf("The program will end so that the functions ");
      printf("F and G can be created.\n");
      *OK = false;
   }   
}

void OUTPUT(double FT, double X, int M1, double W[][21], double H, int N1)
{
   int I, J, FLAG;
   char NAME[30];
   FILE *OUP;

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      OUP = fopen(NAME, "w");
   }
   else OUP = stdout;
   fprintf(OUP, "FINITE DIFFERENCE METHOD FOR THE WAVE EQUATION\n\n");
   fprintf(OUP, "  I        X(I)          W(X(I),%12.6e)\n", FT);
   for (I=1; I<=M1; I++) {
      X = (I - 1.0) * H;
      fprintf(OUP, "%3d %11.8f %13.8f\n", I, X, W[I-1][N1-1]);
   }
   fclose(OUP);
}
