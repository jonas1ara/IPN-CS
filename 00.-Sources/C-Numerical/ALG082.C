/*
*   CHEBYSHEV RATIONAL APPROXIMATION ALGORITHM 8.2
*
*   To obtain the rational approximation
*
*   rT(x) = (p0*T0 + p1*T1 +...+ Pn*Tn) / (q0*T0 + q1*T1 +...+ qm*Tm)
*
*   for a given function f(x):
*
*   INPUT  nonnegative integers m and n.
*
*   OUTPUT  coefficients q0, q1, ... , qm, p0, p1, ... , pn.
*
*   The coefficients of the Chebyshev expansion a0, a1,  ... could
*   be calculated instead of input as is assumed in this program.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, int *, int *, int *, double *);
void OUTPUT(double *, double *, int, int);

main()
{
   double A[11][12],AA[11],P[7],Q[7];
   double AMAX,XM,SUM;
   int NROW[11];
   int LM,LN,BN,OK;
   int PP,FLAG,N,M,I,NN,IMAX,J,JJ,IP,JP,NCOPY,I1,J1,N1,K,N2,LL,KK;

   INPUT(&OK, &BN, &LM, &LN, AA);
   if (OK) {
      /* STEP 1 */
      N = BN;
      M = N + 1;
      /* STEP 2  -  performed in input */
      for (I=0; I<=N; I++) NROW[I] = I;
      /* initialize row pointer */
      NN = N - 1;
      /* STEP 3 */
      Q[0] = 1.0;
      /* STEP 4 */
      /* set up a linear system with matrix A instead of B  */
      for (I=0; I<=N; I++) {
         /* STEP 5 */
         for (J=0; J<=I; J++) 
            if (J <= LN) A[I][J] = 0.0;
         /* STEP 6 */
         if (I <= LN) A[I][I] = 1.0;
         /* STEP 7 */
         for (J=I+1; J<=LN; J++) A[I][J] = 0.0;
         /* STEP 8 */
         for (J=LN+1; J<=N; J++) {
            if (I != 0) {
               PP = I-J+LN;
               if (PP < 0) PP = -PP;
               A[I][J] = -(AA[I+J-LN]+AA[PP])/2.0;
            }  
            else A[I][J] = -AA[J-LN]/2.0;
         }  
         A[I][N+1] = AA[I];
      }  
      /* STEP 9 */
      A[0][N+1] = A[0][N+1]/2.0;
      /* STEPS 10-21 solve the linear system using partial pivoting */
      I = LN+1;
      /* STEP 10 */
      while (OK && (I <= NN)) {
         /* STEP 11 */
         IMAX = NROW[I];
         AMAX = absval(A[IMAX][I]);
         IMAX = I;
         JJ = I + 1;
         for (IP=JJ; IP<=N; IP++) {
            JP = NROW[IP];
            if (absval(A[JP][I]) > AMAX) {
               AMAX = absval(A[JP][I]);
               IMAX = IP;
            }  
         }  
         /* STEP 12 */
         if (AMAX <= ZERO) OK = false;
         else {
            /* STEP 13 */
            /* simulate row interchange */
            if (NROW[I] != NROW[IMAX]) {
               NCOPY = NROW[I];
               NROW[I] = NROW[IMAX];
               NROW[IMAX] = NCOPY;
            }  
            I1 = NROW[I];
            /* STEP 14 */
            /* Perform elimination. */
            for (J=JJ; J<=M; J++) {
               J1 = NROW[J];
               /* STEP 15 */
               XM = A[J1][I] / A[I1][I];
               /* STEP 16 */
               for (K=JJ; K<=M; K++) A[J1][K] = A[J1][K] - XM * A[I1][K];
               /* STEP 17 */
               A[J1][I] = 0.0;
            }  
         }  
         I++;
      }
      if (OK) {
         /* STEP 18 */
         N1 = NROW[N];
         if (absval(A[N1][N]) <= ZERO) OK = false;
         /* system has no unique solution */
         else {
            /* STEP 19 */
            /* start backward substitution */
            if (LM > 0) {
               Q[LM] = A[N1][M] / A[N1][N];
               A[N1][M] = Q[LM];
            }
            PP = 1;
            /* STEP 20 */
            for (K=LN+1; K<=NN; K++) {
               I = NN - K + LN+1;
               JJ = I + 1;
               N2 = NROW[I];
               SUM = A[N2][N+1];
               for (KK=JJ; KK<=N; KK++) {
                  LL = NROW[KK];
                  SUM = SUM - A[N2][KK] * A[LL][M];
               }  
               A[N2][M] = SUM / A[N2][I];
               Q[LM-PP] = A[N2][M];
               PP++;
            }  
            /* STEP 21 */
            for (K=0; K<=LN; K++) {
               I = LN - K;
               N2 = NROW[I];
               SUM = A[N2][N+1];
               for (KK=LN+1; KK<=N; KK++) {
                  LL = NROW[KK];
                  SUM = SUM - A[N2][KK] * A[LL][M];
               }  
               A[N2][M] = SUM;
               P[LN-K] = A[N2][M];
            }  
            /* STEP 22 */
            /* procedure completed successfully */
            OUTPUT(Q, P, LN, LM);
         }  
      }
      if (!OK) printf("System has no unique solution\n");
   }
   return 0;
}

void INPUT(int *OK, int *BN, int *LM, int *LN, double *AA)
{
   int I, FLAG;
   char AAA;
   char NAME[30];
   FILE *INP; 

   printf("This is Chebyshev Approximation.\n\n");
*OK = false;
   while(!(*OK)) {
      printf("The Chebyshev coefficients a[0], a[1], ... , a[N+m]\n");
      printf("are to be input.\n");
      printf("Choice of input method:\n");
      printf("1. Input entry by entry from keyboard\n");
      printf("2. Input data from a text file\n");
      printf("Choose 1 or 2 please\n");
      scanf("%d", &FLAG);
      if ((FLAG == 1) || (FLAG == 2)) *OK = true;
   }
   switch (FLAG) {
      case 1:
         *OK = false;
         while (!(*OK)) {
            printf("Input m and n\n");
            scanf("%d %d", LM, LN);
            *BN = *LM + *LN;
            if ((*LM >= 0) && (*LN >= 0)) *OK = true;
            else printf("m and n must both be nonnegative.\n");
            if ((*LM == 0) && (*LN == 0)) {
               *OK = false;
               printf("Not both m and n can be zero\n");
            }
         }
         printf("Input in order a[0] to a[N+m]\n");
         for (I=0; I<=(*BN+*LM); I++) {
         printf("Input A[ %d ]\n", I);
         scanf("%lf", &AA[I]);
         }
         break;
      case 2:
         printf("The text file may contain as many entries\n");
         printf("per line as desired each separated by blank.\n");
         printf("Has such a text file been created?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &AAA);
         if ((AAA == 'Y') || (AAA == 'y')) {
            printf("Input the file name in the form - ");
            printf("drive:name.ext\n");
            printf("for example:   A:DATA.DTA\n");
            scanf("%s", NAME);
            INP = fopen(NAME, "r");
            *OK = false;
            while (!(*OK)) {
            printf("Input m and n\n");
            scanf("%d %d", LM, LN);
            *BN = *LM + *LN;
            if ((*LM >= 0) && (*LN >= 0)) *OK = true;
            else printf("m and n must both be nonnegative.\n");
            if ((*LM == 0) && (*LN == 0)) {
              *OK = false;
              printf("Not both m and n can be zero\n");
              }
            } 
            for (I=0; I<=(*BN+*LM); I++) fscanf(INP, "%lf", &AA[I]);
            fclose(INP);
         }
         else {
            printf("Please create the input file.\n");
            printf("The program will end so the input file can ");
            printf("be created.\n");
            *OK = false;
         }  
         break;
   }
}

void OUTPUT(double *Q, double *P, int LN, int LM)
{
   int I, J, FLAG;
   char NAME[30];
   FILE *OUP;

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      OUP = fopen(NAME, "w");
   }
   else OUP = stdout;
   fprintf(OUP, "CHEBYSHEV RATIONAL APPROXIMATION\n\n");
   fprintf(OUP, "Denominator Coefficients Q[0], ..., Q[M] \n");
   for (I=0; I<=LM; I++) fprintf(OUP, " %11.8f", Q[I]);
   fprintf(OUP, "\n");
   fprintf(OUP, "Numerator Coefficients P[0], ..., P[N]\n");
   for (I=0; I<=LN; I++) fprintf(OUP, " %11.8f", P[I]);
   fprintf(OUP, "\n");
   fclose(OUP);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
