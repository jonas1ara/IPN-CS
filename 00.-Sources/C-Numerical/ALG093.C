/*
*   INVERSE POWER METHOD ALGORITHM 9.3
*
*   To approximate an eigenvalue and an associated eigenvector of the
*   n by n matrix A given a nonzero vector x:
*
*   INPUT:   Dimension n; matrix A; vector x; tolerance TOL;
*            maximum number of iterations N.
*
*   OUTPUT:  Approximate eigenvalue MU; approximate eigenvector x
*            or a message that the maximum number of iterations was
*            exceeded.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double [][10], double *, double *, int *, int *, double *);
void OUTPUT(FILE **);
void MULTIP(int, int *, int *, double *, double [][10]);
void SOLVE(int, double *, double [][10], double *, int *);

main()
{
   double A[10][10], X[10], Y[10], B[10];
   int NROW[10];
   double T,AMAX,YMU,ERR,TOL,Q,S;
   int N,I,J,NN,K,LP,OK;
   char AA; 
   FILE *OUP[1];

   INPUT(&OK, A, X, Y, &N, &NN, &TOL);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      /* Q could be input instead of computed by deleting
         the next 7 steps */
      Q = 0.0;
      S = 0.0;
      for (I=1; I<=N; I++) {
         S = S + X[I-1] * X[I-1];
         for (J=1; J<=N; J++) Q = Q + A[I-1][J-1] * X[I-1] * X[J-1];
      }  
      Q = Q / S;
      printf("Q is %.8e\n", Q);
      printf("Input new Q? Enter Y or N.\n");
      scanf("\n%c", &AA);
      if ((AA == 'Y') || (AA == 'y')) {
         printf("input new Q\n");
         scanf("%lf", &Q);
      } 
      fprintf(*OUP, "Iteration  Eigenvalue  Eigenvector\n");
      /* STEP 2 */
      K = 1;
      for (I=1; I<=N; I++) A[I-1][I-1] = A[I-1][I-1] - Q;
      /* Call subroutine to compute multipliers M(I,J) and
         upper triangular matrix for matrix A using Gauss
         elimination with partial pivoting.
         NROW holds the ordering of rows for interchanges */
      MULTIP(N, &OK, NROW, &Q, A);
      if (OK) {
         /* STEP 3 */
         LP = 1;
         for (I=2; I<=N; I++) 
            if (absval(X[I-1]) > absval(X[LP-1])) LP = I;
         /* STEP 4 */
         AMAX = X[LP-1];
         for (I=1; I<=N; I++) X[I-1] = X[I-1] / (AMAX);
         /* STEP 5 */
         while ((K <= NN) && OK) {
            /* STEPS 6 AND 7 */
            for (I=1; I<=N; I++) B[I-1] = X[I-1];
            /* Subroutine solve returns the solution of   
               ( A - Q * I )Y = B in Y */
            SOLVE(N, B, A, Y, NROW);
            /* STEP 8 */
            YMU = Y[LP-1];
            /* STEP 9 AND 10 */
            LP = 1;
            for (I=2; I<=N; I++) 
               if (absval(Y[I-1]) > absval(Y[LP-1])) LP = I;
            AMAX = Y[LP-1];
            ERR = 0.0;
            for (I=1; I<=N; I++) {
               T = Y[I-1] / AMAX;
               if (absval(X[I-1] - T) > ERR) 
                  ERR = absval(X[I-1] - T);
               X[I-1] = T;
            }  
            YMU = 1 / YMU + Q;
            /* STEP 11 */ 
            fprintf(*OUP, "%3d %12.8f\n", K, YMU);
            for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
            fprintf(*OUP, "\n");
            if (ERR < TOL) {
               OK = false;
               fprintf(*OUP, "Eigenvalue = %12.8f", YMU);
               fprintf(*OUP, " to tolerance = %.10e\n", TOL);
               fprintf(*OUP, "obtained on iteration number %d\n\n", K);
               fprintf(*OUP, "Unit eigenvector is :\n");
               for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", X[I-1]);
               fprintf(*OUP, "\n");
            }  
            else 
               /* STEP 12 */
               K++;
         }     
         if (K > NN) fprintf(*OUP, 
             "No convergence in %d iterations\n",NN);
      }  
      fclose(*OUP);
   }
   return 0;
   /* STEP 13 */
}

void INPUT(int *OK, double A[][10], double *X, double *Y, int *N, int *NN, double *TOL)
{
   int I, J, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the Inverse Power Method.\n");
   *OK = false;
   printf("The array will be input from a text file in the order:\n");
   printf("A(1,1), A(1,2), ..., A(1,n), A(2,1), A(2,2), ..., A(2,n),\n");
   printf("..., A(n,1), A(n,2), ..., A(n,n)\n\n\n");
   printf("Place as many entries as desired on each line, but separate ");
   printf("entries with\n");
   printf("at least one blank.\n");
   printf("The initial approximation should follow in same format.\n\n\n");
   printf("Has the input file been created? - enter Y or N.\n");
   scanf("%c",&AA);
   if ((AA == 'Y') || (AA == 'y')) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:DATA.DTA\n");
      scanf("%s", NAME);
      INP = fopen(NAME, "r");
      *OK = false;
      while (!(*OK)) {
         printf("Input the dimension n.\n");
         scanf("%d", N);
         if (*N > 0) {
            for (I=1; I<=*N; I++) 
               for (J=1; J<=*N; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &X[I-1]);
            fclose(INP);
            while (!(*OK)) {
               printf("Input the tolerance.\n");
               scanf("%lf", TOL);
               if (*TOL > 0.0) *OK = true;
               else  printf("Tolerance must be positive number.\n");
            }  
            *OK = false; 
            while (!(*OK)) {
               printf("Input maximum number of iterations ");
               printf("- integer.\n");
               scanf("\n%d", NN);
               /* Use NN for N */
               if (*NN > 0) *OK = true;
               else printf("Number must be positive integer.\n");
            }  
         }
         else printf("The dimension must be a positive integer.\n");
      }
   }
   else printf("The program will end so the input file can be created.\n");
}

void OUTPUT(FILE **OUP)
{
   int FLAG;
   char NAME[30];

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "INVERSE POWER METHOD\n\n");
}   

void MULTIP(int N, int *OK, int *NROW, double *Q, double A[][10])
/*  Procedure MULTIP determines the row ordering and multipliers
    for the matrix A - Q*I for use in Gaussian elimination with
    Partial Pivoting.    */
{
   int K,I,M,IMAX,J,IP,L1,L2,JJ,I1,J1,N1;

   for (I=1; I<=N; I++) NROW[I-1] = I;
   *OK = true;
   I = 1;
   M = N - 1;
   while ((I <= M) && OK) {
      IMAX = I;
      J = I + 1;
      for (IP=J; IP<=N; IP++) {
         L1 = NROW[IMAX-1];
         L2 = NROW[IP-1];
         if (absval(A[L2-1][I-1]) > absval(A[L1-1][I-1])) IMAX = IP;
      }  
      if (absval(A[NROW[IMAX-1]-1][I-1]) <= ZERO) {
         *OK = false;
         printf("'A - Q * I is singular, Q = %.8e is an eigenvalue\n", *Q);
      }
      else {
         JJ = NROW[I-1];
         NROW[I-1] = NROW[IMAX-1];
         NROW[IMAX-1] = JJ;
         I1 = NROW[I-1];
         for (JJ=J; JJ<=N; JJ++) {
            J1 = NROW[JJ-1];
            A[J1-1][I-1] = A[J1-1][I-1] / A[I1-1][I-1];
            for (K=J; K<=N; K++)
               A[J1-1][K-1] = A[J1-1][K-1] - A[J1-1][I-1] * A[I1-1][K-1];
         }  
      }  
      I++;
   }
   if (absval(A[NROW[N-1]-1][N-1]) <= ZERO) {
      *OK = false;
      printf("A - Q * I is singular, Q = %.8e is an eigenvalue\n", *Q);
   }  
}

void SOLVE(int N, double *B, double A[][10], double *Y, int *NROW)
/*  Procedure SOLVE solves the linear system (A - Q*I) Y = X
    given a new vector X and the row ordering and multipliers form
    procedure MULTIP   */
{
   int M,I,J,I1,JJ,J1,N1,N2,L,K,KK;
   
   M = N - 1;
   for (I=1; I<=M; I++) {
      J = I + 1;
      I1 = NROW[I-1];
      for (JJ=J; JJ<=N; JJ++) {
         J1 = NROW[JJ-1];
         B[J1-1] = B[J1-1] - A[J1-1][I-1] * B[I1-1];
      }  
   }
   N1 = NROW[N-1];
   Y[N-1] = B[N1-1] / A[N1-1][N-1];
   L = N - 1;
   for (K=1; K<=L; K++) {
      J = L - K + 1;
      JJ = J + 1;
      N2 = NROW[J-1];
      Y[J-1] = B[N2-1];
      for (KK=JJ; KK<=N; KK++) Y[J-1] = Y[J-1] - A[N2-1][KK-1] * Y[KK-1];
      Y[J-1] = Y[J-1] / A[N2-1][J-1];
   }   
}
  
/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
