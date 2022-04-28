/*
*   PADE' RATIONAL APPROXIMATION ALGORITHM 8.1
*
*   To obtain the rational approximation
*
*       r(x) = p(x) / q(x)
*            = (p0 + p1*x + ... + Pn*x^n) / (q0 + q1*x + ... + qm*x^m)
*
*   for a given function f(x):
*
*   INPUT  nonnegative integers m and n.
*
*   OUTPUT  coefficients q0, q1, ... , qm, p0, p1, ... , pn.
*/

/* 
*   The coefficients of the Maclaurin polynomial a0, a1,  ... could
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
   double A[10][11],AA[11],P[7],Q[7];
   double AMAX,XM,SUM;
   int NROW[10];
   int LM,LN,BN,OK;
   int PP,FLAG,N,M,I,NN,IMAX,J,JJ,IP,JP,NCOPY,I1,J1,N1,K,N2,LL,KK;

   INPUT(&OK, &BN, &LM, &LN, AA);
   if (OK) {
      /* STEP 1 */
      N = BN;
      M = N + 1;
      /* STEP 2  -  performed in input */
      for (I=1; I<=N; I++) NROW[I-1] = I;
      /* initialize row pointer for linear system */
      NN = N - 1;
      /* STEP 3 */
      Q[0] = 1.0;
      P[0] = AA[0];
      /* STEP 4 */
      /* Set up a linear system, but use A[i,j] instead of B[i,j]. */
      for (I=1; I<=N; I++) {
         /* STEP 5 */
         for (J=1; J<=I-1; J++) 
             if (J <= LN) A[I-1][J-1] = 0.0;
         /* STEP 6 */
         if (I <= LN) A[I-1][I-1] = 1.0;
         /* STEP 7 */
         for (J=I+1; J<=N; J++) A[I-1][J-1] = 0.0;
         /* STEP 8 */
         for (J=1; J<=I; J++) 
            if  (J <= LM) A[I-1][LN+J-1] = -AA[I-J];
         /* STEP 9 */
         for (J=LN+I+1; J<=N; J++) A[I-1][J-1] = 0.0;
         /* STEP 10 */
         A[I-1][N] = AA[I];
      }  
      /* Solve the linear system using partial pivoting. */
      I = LN+1;
      /* STEP 11 */
      while (OK && (I <= NN)) {
         /* STEP 12 */
         IMAX = NROW[I-1];
         AMAX = absval(A[IMAX-1][I-1]);
         IMAX = I;
         JJ = I + 1;
         for (IP=JJ; IP<=N; IP++) {
            JP = NROW[IP-1];
            if (absval(A[JP-1][I-1]) > AMAX) {
               AMAX = absval(A[JP-1][I-1]);
               IMAX = IP;
            }  
         }  
         /* STEP 13 */
         if (AMAX <= ZERO) OK = false;
         else {
            /* STEP 14 */
            /* simulate row interchange */
            if (NROW[I-1] != NROW[IMAX-1]) {
               NCOPY = NROW[I-1];
               NROW[I-1] = NROW[IMAX-1];
               NROW[IMAX-1] = NCOPY;
            }  
            I1 = NROW[I-1];
            /* STEP 15 */
            /* Perform elimination. */
            for (J=JJ; J<=M; J++) {
               J1 = NROW[J-1];
               /* STEP 16 */
               XM = A[J1-1][I-1] / A[I1-1][I-1];
               /* STEP 17 */
               for (K=JJ; K<=M; K++) 
                  A[J1-1][K-1] = A[J1-1][K-1] - XM * A[I1-1][K-1];
               /* STEP 18 */
               A[J1-1][I-1] = 0.0;
            }  
         }  
         I++;
      }  
      if (OK) {
         /* STEP 19 */
         N1 = NROW[N-1];                              
         if (absval(A[N1-1][N-1]) <= ZERO) OK = false;
         /* system has no unique solution */
         else {
            /* STEP 20 */
            /* Start backward substitution. */
            if (LM > 0) {
               Q[LM] = A[N1-1][M-1] / A[N1-1][N-1];
               A[N1-1][M-1] = Q[LM];
            }
            PP = 1;
            /* STEP 21 */
            for (K=LN+1; K<=NN; K++) {
               I = NN - K + LN+1;
               JJ = I + 1;
               N2 = NROW[I-1];
               SUM = A[N2-1][N];
               for (KK=JJ; KK<=N; KK++) {
                  LL = NROW[KK-1];
                  SUM = SUM - A[N2-1][KK-1] * A[LL-1][M-1];
               }  
               A[N2-1][M-1] = SUM / A[N2-1][I-1];
               Q[LM-PP] = A[N2-1][M-1];
               PP++;
            }
            /* STEP 22 */
            for (K=1; K<=LN; K++) {
               I = LN - K + 1;
               N2 = NROW[I-1];
               SUM = A[N2-1][N];
               for (KK=LN+1; KK<=N; KK++) {
                  LL = NROW[KK-1];
                  SUM = SUM - A[N2-1][KK-1] * A[LL-1][M-1];
               }
               A[N2-1][M-1] = SUM;
               P[LN-K+1] = A[N2-1][M-1];
            }
            /* STEP 23 */
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

   printf("This is Pade Approximation.\n\n");
   *OK = false;
   while(!(*OK)) {
      printf("The McLaurin coefficients a[0], a[1], ... , a[N]\n");
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
         printf("Input in order a[0] to a[N]\n");
         for (I=0; I<=*BN; I++) {
         printf("Input A[ %d ] \n",I); 
         scanf("%lf", &AA[I]);
         }
         break;
      case 2:
         printf("As many entries as desired can be placed\n");
         printf("on each line of the file each separated by blank.");
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
            for (I=0; I<=*BN; I++) fscanf(INP, "%lf", &AA[I]);
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
   fprintf(OUP, "PADE RATIONAL APPROXIMATION\n\n");
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
