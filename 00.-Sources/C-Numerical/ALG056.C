/*
*   EXTRAPOLATION ALGORITHM 5.6
*
*   To approximate the solution of the initial value problem:
*                 y' = f(t,y), a <= t <= b, y(a) = ALPHA,
*   with local truncation error within a given tolerance:
*
*   INPUT:   endpoints a,b; initial condition ALPHA; tolerance TOL;
*            maximum stepsize HMAX; minimum stepsize HMIN.
*
*   OUTPUT:  T, W, H where W approximates y(T) and stepsize H was
*            used or a message that minimum stepsize was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

main()
{
   double Q[7][7], Y[9]; 
   double TOL,ALPHA,A,B,HMIN,HMAX,T0,W0,H,HK,W2,W3,T,W1,V;
   int NK[8];
   int P,I,K,J,KK,NFLAG,M,N,OK,DONE;
   FILE *OUP[1];

   double F(double, double);
   double absval(double);
   void INPUT(int *, double *, double *, double *, double *, double *, double *);
   void OUTPUT(FILE **);

   INPUT(&OK, &A, &B, &ALPHA, &HMAX, &HMIN, &TOL);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      NK[0] = 2;
      NK[1] = 4;
      for (J=1; J<=3; J++) {
         I = 2*J;
         NK[I] = 3 * NK[I-1] / 2;
         NK[I+1] = 2 * NK[I-1];
      }
      /* STEP 2 */
      T0 = A;
      W0 = ALPHA;
      H = HMAX;
      /*  DONE is used in place of FLAG to exit the loop in Step 4  */
      DONE = false;
      /* STEP 3 */
      for (I=1; I<=7; I++)
         for (J=1; J<=I; J++)
            Q[I-1][J-1] = (NK[I] * 1.0 / NK[J-1])*(NK[I] * 1.0 / NK[J-1]);
      /* STEP 4 */
      while (!DONE) {
         /* STEP 5 */
         K = 1;
         /* when desired accuracy achieved, NFLAG is set to 1 */
         NFLAG = 0;
         /* STEP 6 */
         while ((K <= 8) && (NFLAG == 0)) {
            /* STEP 7 */
            HK = H / NK[K-1];
            T = T0;
            W2 = W0;
            /* Euler first step */
            W3 = W2 + HK * F(T, W2);
            T = T0 + HK;
            /* STEP 8 */
            M = NK[K-1] - 1;
            for (J=1; J<=M; J++) {
               W1 = W2;
               W2 = W3;
               /* midpoint method */
               W3 = W1 + 2.0 * HK * F(T, W2);
               T = T0 + (J + 1) * HK;
            }  
            /* STEP 9 */
            /* endpoint correction to compute Y(K,1) */
            Y[K] = (W3 + W2 + HK * F(T, W3)) / 2.0;
            /* STEP 10 */
            /* NOTE: Y(K-1)=Y(K-1,1),Y(K-2)=Y(K-1,2),..., */
            /* Y(1)=Y(K-1,K-1) since only previous row of table */
            /* is saved  */
            if (K >= 2) {
               /* STEP 11 */
               J = K;
               /*  save Y(K-1,K-1)  */
               V = Y[1];
               /* STEP 12 */
               while (J >= 2) {
                  /* extrapolation to compute */ 
                  /* Y(J-1) = Y(K,K-J+2) */
                  Y[J-1] = Y[J] + ( Y[J] - Y[J-1] ) /
                           ( Q[K-2][J-2] - 1.0 );
                  J--;
               }  
               /* STEP 13 */
               if (absval(Y[1] - V) <= TOL) NFLAG = 1;
               /* Y(1) accepted as new w */
            }  
            /* STEP 14 */
            K++;
         }
         /* STEP 15 */
         K--;
         /* STEP 16 */
         if (NFLAG == 0) {
            /* STEP 17 */
            /* new value for w rejected, decrease H */
            H = H / 2.0;
            /* STEP 18 */
            if (H < HMIN) {
               fprintf(*OUP, "HMIN exceeded\n");
               DONE = true;
            }  
         }  
         else {
            /* STEP 19 */
            /* new value for w accepted */
            W0 = Y[1];
            T0 = T0 + H;
            fprintf(*OUP, "%12.8f %11.8f %11.8f %6d\n", T0, W0, H, K);
            /* STEP 20 */
            /* increase H if possible */
            if (T0 >= B) DONE = true;
            else if (T0 + H > B) H = B - T0;
            else if (K <= 3) H = 2.0 * H;
            if (H > HMAX) H = H / 2.0;
         }
      }     
      /* STEP 21 */
      fclose(*OUP);
   }
   return 0;
}
/*  Change function F for a new problem.    */
double F(double T, double Y)
{
   double f; 

   f = Y - T*T + 1.0;
   return f;
}

void INPUT(int *OK, double *A, double *B, double *ALPHA, double *HMAX, double *HMIN, double *TOL)
{
   double X; 
   char AA;

   printf("This is Gragg Extrapolation\n");
   printf("Has the function F been created in the program immediately\n");
   printf("preceding the INPUT procedure?  Enter Y or N.\n");
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
   printf("2. Output to text File\n");
   printf("Please enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("For example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "GRAGG EXTRAPOLATION\n\n");
   fprintf(*OUP, "           T           W           H      K\n\n");
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
