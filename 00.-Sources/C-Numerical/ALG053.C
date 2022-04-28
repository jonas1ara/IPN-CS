/*
*    RUNGE-KUTTA-FEHLBERG ALGORITHM 5.3
*
*    TO APPROXIMATE THE SOLUTION OF THE INITIAL VALUE PROBLEM:
*               Y' = F(T,Y), A<=T<=B, Y(A) = ALPHA,
*    WITH LOCAL TRUNCATION ERROR WITHIN A GIVEN TOLERANCE.
*
*    INPUT:   ENDPOINTS A,B; INITIAL CONDITION ALPHA; TOLERANCE TOL;
*             MAXIMUM STEPSIZE HMAX; MINIMUM STEPSIZE HMIN.
*
*    OUTPUT:  T, W, H WHERE W APPROXIMATES Y(T) AND STEPSIZE H WAS
*             USED OR A MESSAGE THAT MINIMUM STEPSIZE WAS EXCEEDED.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double A,B,TOL,ALPHA,HMAX,HMIN,H,T,W,K1,K2,K3,K4,K5,K6,R,DELTA;
   int I,N,OK;
   FILE *OUP[1];

   double absval(double);
   double F(double, double);
   void INPUT(int *, double *, double *, double *, double *L, double *, double *, int *); 
   void OUTPUT(FILE **);

   INPUT(&OK, &A, &B, &ALPHA, &TOL, &HMIN, &HMAX, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      H = HMAX;
      T = A;
      W = ALPHA;
      fprintf(*OUP, "%12.7f %11.7f           0           0\n", T, W);
      OK = true;
      /* STEP 2 */
      while ((T < B) && OK) {
         /* STEP 3 */
         K1 = H*F(T,W);
         K2 = H*F(T+H/4,W+K1/4);
         K3 = H*F(T+3*H/8,W+(3*K1+9*K2)/32);
         K4 = H*F(T+12*H/13,W+(1932*K1-7200*K2+7296*K3)/2197);
         K5 = H*F(T+H,W+439*K1/216-8*K2+3680*K3/513-845*K4/4104);
         K6 = H*F(T+H/2,W-8*K1/27+2*K2-3544*K3/2565
                   +1859*K4/4104-11*K5/40);
         /* STEP 4 */
         R = absval(K1/360-128*K3/4275-2197*K4/75240.0
                    +K5/50+2*K6/55)/H;
         /* STEP 5 */
         if (R <= TOL) {
            /* STEP 6 */
            /* APPROXIMATION ACCEPTED */
            T = T + H;
            W = W+25*K1/216+1408*K3/2565+2197*K4/4104-K5/5;
            /* STEP 7 */
            fprintf(*OUP, "%12.7f %11.7f %11.7f %11.7f\n", T, W, H, R);
         }
         /* STEP 8 */
         /* TO AVOID UNDERFLOW */
         if (R > 1.0E-20) DELTA = 0.84 * exp(0.25 * log(TOL / R));
         else DELTA = 10.0;
         /* STEP 9 */
         /* CALCULATE NEW H */
         if (DELTA <= 0.1) H = 0.1 * H;
         else {
            if (DELTA >= 4.0) H = 4.0 * H;
            else H = DELTA * H;
         }
         /* STEP 10 */
         if (H > HMAX) H = HMAX;
         /* STEP 11 */
         if (H < HMIN) OK = false;
         else {
            if (T+H > B)
               if (absval(B-T) < TOL) T = B;
               else H = B - T;
         }
      }   
      if (!OK) fprintf(*OUP, "Minimal H exceeded\n");
      /* STEP 12 */
      /* PROCESS IS COMPLETE */
      fclose(*OUP);
   }
   return 0;
}
/*  Change function F for a new problem   */
double F(double T, double Y)
{
   double f; 

   f = Y - T*T + 1.0;
   return f;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, double *TOL, double *HMIN, double *HMAX, int *N)
{
   double X; 
   char AA;

   printf("This is the Runge-Kutta-Fehlberg Method.\n");
   *OK = false;
   printf("Has the function F been defined?\n");
   printf("Enter Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank\n");
         scanf("%lf %lf", A, B);
         if (*A >= *B) 
            printf("Left endpoint must be less than right endpoint\n");
         else *OK = true;
      }
      printf("Input the initial condition\n");
      scanf("%lf", ALPHA);
      *OK = false;
      while(!(*OK)) {
         printf("Input tolerance\n");
         scanf("%lf", TOL);
         if (*TOL <= 0.0) printf("Tolerance must be positive.\n");
         else *OK = true;
      }
      *OK = false;
      while(!(*OK)) {
         printf("Input minimum and maximum mesh spacing separated by a ");
         printf("blank\n");
         scanf("%lf %lf", HMIN, HMAX);
         if ((*HMIN < *HMAX) && (*HMIN > 0.0)) *OK = true;
         else {
            printf("Minimum mesh spacing must be a positive real ");
            printf("number and less than\n");
            printf("the maximum mesh spacing\n");
         }
      }
   }
   else 
      printf("The program will end so that the functions can be created.\n");
}

void OUTPUT(FILE **OUP)
{
   char NAME[30];
   int FLAG; 

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "RUNGE-KUTTA-FEHLBERG METHOD\n\n");
   fprintf(*OUP, "        T(I)        W(I)           H           R\n\n");
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
