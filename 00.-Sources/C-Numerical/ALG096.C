/*
*   QR ALGORITHM 9.6
*
*   To obtain the eigenvalues of a symmetric, tridiagonal n by n matrix
*
*            a(1)   b(2)
*            b(2)   a(2)   b(3)
*               .      .      .
*                 .      .      .
*                   .      .      .
*                   b(n-1)  a(n-1)  b(n)
*                              b(n)   a(n)
*
*
*   INPUT:   n; A(1),...,A(n) (diagonal of A); B(2),...,B(n)
*            (off-diagonal of A); maximum number of iterations M, 
*            tolerance TOL.
*
*   OUTPUT:  Eigenvalues of A or recommended splitting of A, or a 
*            message that the maximum number of iterations was 
*            exceeded.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
void INPUT(int *, double *, double *, int *, int *, double *);
void OUTPUT(FILE **);

main()
{
   double A[10], B[10], C[10], D[10], Q[10], S[10], X[10], R[9], Y[9], Z[9];
   double TOL,B1,C1,D1,X1,X2,SHIFT;
   int N,I,J,K,M,MM,L,OK;
   FILE *OUP[1];

   INPUT(&OK, A, B, &N, &L, &TOL);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      SHIFT = 0.0;
      K = 1;
      /* STEP 2 */
      while ((K <= L) && OK) {
         fprintf(*OUP, "Iteration number %d    N = %d\n", K, N);
         fprintf(*OUP, "The array A is now as follows:\n");
         fprintf(*OUP, "Diagonal:\n");
         for (I=1; I<=N; I++) fprintf(*OUP, " %11.8f", A[I-1]);
         fprintf(*OUP, "\nOff diagonal:\n");
         for (I=2; I<=N; I++) fprintf(*OUP, " %11.8f", B[I-1]);
         fprintf(*OUP, "\n");
         /* Steps 3-7 test for success  */
         /* STEP 3  */
         if (absval(B[N-1]) <= TOL) {
            A[N-1] = A[N-1] + SHIFT;
            fprintf(*OUP, "Eigenvalue = %12.8f\n", A[N-1]);
            N--;
         }  
         /* STEP 4   */
         if (absval(B[1]) <= TOL) {
            A[0] = A[0] + SHIFT;
            fprintf(*OUP, "Eigenvalue = %12.8f\n", A[0]);
            N--;
            A[0] = A[1];
            for (J=2; J<=N; J++) {
               A[J-1] = A[J];
               B[J-1] = B[J];
            }  
         }  
         /* STEP 5  */
         if (N == 0) OK = false;
         /* STEP 6   */
         if (N == 1) {
            A[0] = A[0] + SHIFT;
            fprintf(*OUP,"Eigenvalue = %12.8f\n", A[0]);
            OK = false;
         }
         /* STEP 7  */
         if (OK) {
            M = N - 1;
            if (M >= 2) {
               for (I=2; I<=M; I++) 
                  if (absval(B[I-1]) <= TOL) {
                     OK = false;
                     J = I;
                  }
               if (!OK) {
                  fprintf(*OUP, "Split the matrix into\n");
                  for (I=1; I<=J-1; I++) fprintf(*OUP,"%11.8f",A[I-1]);
                  fprintf(*OUP,"\n");
                  for (I=2; I<=J-1; I++) fprintf(*OUP,"%11.8f",B[I-1]);
                  fprintf(*OUP,"\n and \n");
                  for (I=J; I<=N; I++) fprintf(*OUP,"%11.8f",A[I-1]);
                  fprintf(*OUP,"\n");
                  for (I=J+1; I<=N; I++) fprintf(*OUP,"%11.8f",B[I-1]);
                  fprintf(*OUP,"\n");
               }
            }  
         }
         if (OK) {
            /* STEP 8 */
            /* compute shift */
            B1 = -(A[N-1] + A[N-2]);
            C1 = A[N-1] * A[N-2] - B[N-1] * B[N-1];
            D1 = B1 * B1 - 4.0 * C1;
            if (D1 < 0.0) {
               fprintf(*OUP, "Problem with complex roots, D1 = %.8e\n", D1);
               OK = false;
            }  
            else {
               D1 = sqrt( D1 );
               /*  STEP 9   */
               if (B1 > 0.0) {
                  X1 = -2.0 * C1 / (B1 + D1);
                  X2 = -(B1 + D1) / 2.0;
               }     
               else {
                  X1 = (D1 - B1) / 2.0;
                  X2 = 2.0 * C1 / (D1 - B1);
               }  
               /* if N = 2 then the 2 eigenvalues have
                  been computed */
               /*  STEP 10  */
               if (N == 2) {
                  X1 = X1 + SHIFT;
                  X2 = X2 + SHIFT;
                  fprintf(*OUP, "The last two eigenvalues ");
                  fprintf(*OUP, "are: %12.8f %11.8f\n", X1, X2);
                  OK = false;
               }  
               else {
                  /* STEP 11 */
                  if (absval(A[N-1]-X1) > absval(A[N-1]-X2)) X1 = X2;
                  /* STEP 12 */
                  /* accumulate shift */
                  SHIFT = SHIFT + X1;
                  /* STEP 13*/
                  /* perform shift */
                  for (I=1; I<=N; I++) D[I-1] = A[I-1] - X1;
                  /* STEP 14 and 15 compute R(K) */
                  /* STEP 14 */
                  X[0] = D[0];
                  Y[0] = B[1];
                  /* STEP 15 */
                  for (J=2; J<=N; J++) {
                     Z[J-2] = sqrt((X[J-2]*X[J-2])+(B[J-1]*B[J-1]));
                     C[J-1] = X[J-2]/Z[J-2];
                     S[J-1] = B[J-1]/Z[J-2];
                     Q[J-2] = C[J-1]*Y[J-2]+S[J-1]*D[J-1];
                     X[J-1] = C[J-1]*D[J-1]-S[J-1]*Y[J-2];
                     if (J != N) {
                        R[J-2] = S[J-1]*B[J];
                        Y[J-1] = C[J-1]*B[J];
                     }  
                  }  
                  M = N - 1;
                  MM = N - 2;
                  /* Steps 16-18 compute A(K+1) */
                  /* STEP 16 */
                  Z[N-1] = X[N-1];
                  A[0] = C[1]*Z[0]+S[1]*Q[0];
                  B[1] = S[1]*Z[1];
                  /* STEP 17 */
                  if (N > 2) {
                     for (J=2; J<=M; J++) {
                        A[J-1] = C[J]*C[J-1]*Z[J-1]+S[J]*Q[J-1];
                        B[J] = S[J]*Z[J];
                     }  
                  }  
                  /* STEP 18 */
                  A[N-1] = C[N-1] * Z[N-1];
               }  
            }  
         }  
         /* STEP 19 */
         K++;
      }
      /* STEP 20 */
      if (OK && (K > L)) 
        fprintf(*OUP, "Maximum Number of Iterations Exceeded.\n");
      /* the process is complete */
      fclose(*OUP);
   }
   return 0;
}

void INPUT(int *OK, double *A, double *B, int *N, int *L, double *TOL)
{
   int I, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the QR Method.\n");
   *OK = false;
   printf("The tridiagonal symmetric array A will be input from ");
   printf("a text file in the order:\n");
   printf("    (diagonal): A(1), A(2), ..., A(n),\n");
   printf("    (subdiagonal): B(2), B(3), ..., B(n).\n\n");
   printf("Place as many entries as desired on each line, but separate ");
   printf("entries with\n");
   printf("at least one blank.\n\n\n");
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
         if (*N > 1) {
            for (I=1; I<=*N; I++) fscanf(INP, "%lf", &A[I-1]);
            for (I=2; I<=*N; I++) fscanf(INP, "%lf", &B[I-1]);
            *OK = true;
         }  
         else printf("Dimension must be greater then 1.\n");
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input the tolerance.\n");
         scanf("%lf", TOL);
         if (*TOL > 0.0) *OK = true;
         else printf("Tolerance must be a positive real number.\n");
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input the maximum number of iterations.\n");
         scanf("%d", L);
         if (*L > 0) *OK = true;
         else printf("The number must be a positive integer.\n");
      }  
      fclose(INP); 
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
   fprintf(*OUP, "QR METHOD\n\n");
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
