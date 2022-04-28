/*
*   ADAMS VARIABLE STEP-SIZE PREDICTOR-CORRECTOR ALGORITHM 5.5
*
*   To approximate the solution of the initial value problem
*
*          y' = f( t, y ), a <= t <= b, y(a) = ALPHA,
*
*    with local truncation error within a given tolerance:
*
*    INPUT:   endpoints a, b; initial condition ALPHA; tolerance TOL;
*             maximum step size HMAX; minimum step size HMIN.
*
*    OUTPUT:  I, T(I), W(I), H where at the Ith step W(I) approximates
*             y(T(I)) and step size H was used or a message that the
*             minimum step size was exceeded.
*
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double T[100],W[100];
   double A,B,ALPHA,TOL,HMAX,HMIN,H,TT,WP,WC,SIG,Q;
   int I,K,J,KK,NFLAG,OK,DONE;
   FILE *OUP[1];

   double F(double, double);
   void RK4(double , double , double , double *, double *);
   void INPUT(int *, double *, double *, double *, double *, double *, double *);
   void OUTPUT(FILE **);
   double absval(double);

   INPUT(&OK, &A, &B, &ALPHA, &HMAX, &HMIN, &TOL);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 2 */
      T[0] = A;
      W[0] = ALPHA;
      H = HMAX;
      /*  OK is used in place of FLAG to exit the loop in Step 4.  */
      OK = true;
      /*  DONE is used in place of LAST to indicate when last value
          is calculated.  */
      DONE = false;
      /* STEP 3 */
      for (KK=1; KK<=3; KK++)  
         RK4(H, T[KK-1], W[KK-1], &T[KK], &W[KK]);
      /* NFLAG indicates computation from RK4 */
      NFLAG = 1;
      I = 5;
      /* use TT in place of t */
      TT = T[3] + H;
      /* STEP 4 */
      while (!DONE) {
         /* STEP 5 */
         /* predict W(I) */
         WP = W[I-2]+H*(55.0*F(T[I-2],W[I-2])-59.0*
                     F(T[I-3],W[I-3])+37.0*F(T[I-4],W[I-4])-
                     9.0*F(T[I-5],W[I-5]))/24.0;
         /* correct W(I) */
         WC = W[I-2]+H*(9.0*F(TT,WP)+19.0*
              F(T[I-2],W[I-2])-5.0*F(T[I-3],W[I-3])+
              F(T[I-4],W[I-4]))/24.0;
         SIG = 19.0*absval(WC-WP)/(270.0*H);
         /* STEP 6 */
         if (SIG <= TOL) {
            /* STEP 7 */
            /* result accepted */
            W[I-1] = WC;
            T[I-1] = TT;
            /* STEP 8 */
            if (NFLAG == 1) {
               K = I - 3;
               KK = I - 1;
               /*  Previous results are also accepted.  */
               for (J=K; J<=KK; J++) 
                   fprintf(*OUP, "%12.8f %11.8f %11.8f %11.8f\n", T[J-1], W[J-1], H, SIG);
               fprintf(*OUP, "%12.8f %11.8f %11.8f %11.8f\n", T[I-1], W[I-1], H, SIG);
            }
            else 
               /*  Previous results were already accepted.  */
               fprintf(*OUP, "%12.8f %11.8f %11.8f %11.8f\n", T[I-1], W[I-1], H, SIG);
            /* STEP 9 */
            if (!OK) DONE = true;
            else  {
               /* STEP 10 */
               I++;
               NFLAG = 0;
               /* STEP 11 */
               if ((SIG <= 0.1*TOL) || (T[I-2]+H > B)) {
                  /*  Increase H if more accuracy than required
                      has been obtained, or decrease H to include
                      b as a mesh point.  */
                  /* STEP 12 */
                  /* to avoid underflow */
                  if (SIG <= 1.0e-20) Q = 4.0;
                  else Q = exp(0.25*log(0.5*TOL/SIG)); 
                  /* STEP 13 */
                  if (Q > 4.0)  H = 4.0*H;
                  else H = Q * H;
                  /* STEP 14 */
                  if (H > HMAX) H = HMAX;
                  /* STEP 15 */
                  if (T[I-2]+4.0*H > B) {
                     H = 0.25*(B-T[I-2]);
                     if (H < TOL) DONE = true;
                     OK = false;
                  }
                  /* STEP 16 */
                  for (KK=I-1; KK<=I+2; KK++) 
                     RK4(H,T[KK-1],W[KK-1],&T[KK],&W[KK]);
                  NFLAG = 1;
                  I = I + 3;
               }  
            }
         }
         else {
            /*  False branch for Step 6 - result rejected.  */
            /* STEP 17 */
            Q = exp(0.25 * log(0.5 * TOL / SIG));
            /* STEP 18 */
            if (Q < 0.1) H = 0.1 * H;
            else H = Q * H;
            /* STEP 19 */
            if (H < HMIN) {
               fprintf(*OUP, "HMIN exceeded\n");
               DONE = true;
            }
            else {
               if (T[I-2]+4.0*H > B) H = 0.25*(B-T[I-2]);
               if (NFLAG == 1) I = I - 3;
               for (KK=I-1; KK<=I+2; KK++) 
                  RK4(H,T[KK-1],W[KK-1],&T[KK],&W[KK]);
               I = I + 3;
               NFLAG = 1;
            }  
         }
         /* STEP 20 */  
         TT = T[I-2] + H;
      }
      /* STEP 21 */
      fclose(*OUP);
   }
   return 0;
}
/*  Change function F for a new problem.   */
double F(double T, double Y)
{
   double f; 

   f = Y - T*T + 1.0;
   return f;
}

void RK4(double H, double X, double Y, double *T, double *W)
{
   double K1,K2,K3,K4;

   /* STEP 1 */
   K1 = H * F(X, Y);
   K2 = H * F(X + 0.5 * H, Y + 0.5 * K1);
   K3 = H * F(X + 0.5 * H, Y + 0.5 * K2);
   K4 = H * F(X + H, Y + K3);
   *W = Y + (K1 + 2.0 * (K2 + K3) + K4) / 6.0;
   *T = X + H;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, double *HMAX, double *HMIN, double *TOL)
{
   double X; 
   char AA;

   printf("This is the Adams Variable Step-size\n");
   printf("Predictor-Corrector Method\n");
   printf("Has the function F been created in the program?\n");
   printf("Enter Y or N\n");
   scanf("%c",&AA);
   *OK = false;
   if ((AA == 'Y') || (AA == 'y')) {
      *OK = false;
      while (!(*OK)) {
         printf("Input left and right endpoints separated by blank.\n");
         scanf("%lf %lf", A, B);
         if (*A >= *B) 
            printf("Left endpoint must be less than right endpoint.\n");
         else *OK = true;
      }
      *OK = false;
      printf("Input the initial condition.\n");
      scanf("%lf", ALPHA);
      while(!(*OK)) {
         printf("Input tolerance.\n");
         scanf("%lf", TOL);
         if (*TOL <= 0.0) printf("Tolerance must be positive.\n");
         else *OK = true;
      }
      *OK = false;
      while(!(*OK)) {
         printf("Input minimum and maximum mesh spacing  ");
         printf("separated by a blank.\n");
         scanf("%lf %lf", HMIN, HMAX);
         if ((*HMIN < *HMAX) && (*HMIN > 0.0)) *OK = true;
         else {
            printf("Minimum mesh spacing must be a  ");
            printf("positive real number and less than\n");
            printf("the maximum mesh spacing.\n");
         }
      }
   }
   else {
      printf("The program will end so that F can be created.\n");
      *OK = false;
   }
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
      printf("For example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "ADAMS VARIABLE STEP-SIZE PREDICTOR CORRECTOR METHOD\n\n");
   fprintf(*OUP, "           t           w           h       sigma\n");
}
   
/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
