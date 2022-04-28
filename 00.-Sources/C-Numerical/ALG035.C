/*
*   CLAMPED CUBIC SPLINE ALGORITHM 3.5
*
*   To construct the cubic spline interpolant S for the function f,
*   defined at the numbers x(0) < x(1) < ... < x(n), satisfying
*   S'(x(0)) = f'(x(0)) and S'(x(n)) = f'(x(n)):
*
*   INPUT:   n; x(0), x(1), ..., x(n); either generate A(I) = f(x(I))
*            for i = 0, 1, ..., n or input A(I) for I = 0, 1, ..., n;
*            FPO = f'(x(0)); FPN = f'(x(n)).
*
*    OUTPUT:  A(J), B(J), C(J), D(J) for J = 0, 1, ..., n - 1.
*
*    NOTE:    S(x) = A(J) + B(J) * ( x - x(J) ) + C(J) * ( x - x(J) )**2 +
*             D(J) * ( x - x(J) )**3 for x(J) <= x < x(J + 1)
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double F(double);
void INPUT(int *, double *, double *, int *, double *, double *);
void OUTPUT(int, int, double *, double *, double *, double *, double *);

main()
{
   double X[26],A[26],B[26],C[26],D[26],H[26],XA[26],XL[26],XU[26],XZ[26];
   double XX,S,Y, FP0, FPN;
   int I,J,N,M,OK;

   INPUT(&OK, X, A, &N, &FP0, &FPN);
   if (OK) {
      /* STEP 1 */
      M = N - 1;
      for (I=0; I<=M; I++) H[I] = X[I+1] - X[I];
      /* STEP 2 */
      /* use XA instead of alpha */
      XA[0] = 3.0 * (A[1] - A[0]) / H[0] - 3.0 * FP0;
      XA[N] = 3.0 * FPN - 3.0 * (A[N] - A[N-1]) / H[N-1];
      /* STEP 3 */
      for (I=1; I<=M; I++) 
         XA[I] = 3.0 * (A[I+1] * H[I-1] - A[I] *
                  (X[I+1] - X[I-1]) + A[I-1] * H[I])  /
                  (H[I] * H[I-1]);
      /* STEP 4 */
      /* STEPS 4, 5, 6 and part of 7 solve the tridiagonal system using */
      /* Algorithm 6.7 */
      /* use XL, XU, XZ in place of L, MU, Z resp. */
      XL[0] = 2.0 * H[0]; XU[0] = 0.5; XZ[0] = XA[0] / XL[0];
      /* STEP 5 */
      for (I=1; I<=M; I++) {
         XL[I] = 2.0 * (X[I+1] - X[I-1]) - H[I-1] * XU[I-1];
         XU[I] = H[I] / XL[I];
         XZ[I] = (XA[I] - H[I-1] * XZ[I-1]) / XL[I];
      }
      /* STEP 6 */
      XL[N] = H[N-1] * (2.0 - XU[N-1]);
      XZ[N] = (XA[N] - H[N-1] * XZ[N-1]) / XL[N];
      C[N] = XZ[N];
      /* STEP 7 */
      for (I=1; I<=N; I++) {
         J = N - I;
         C[J] = XZ[J] - XU[J] * C[J+1];
         B[J] = (A[J+1] - A[J]) / H[J] - H[J] * (C[J+1] + 2.0 * C[J]) / 3.0;
         D[J] = (C[J+1] - C[J]) / (3.0 * H[J]);
      } 
      /* STEP 8 */
      OUTPUT(N, M, X, A, B, C, D);
   }
   return 0;
}

/* Change function F to solve a new problem */
double F(double X)
{
   double f; 

   f =  1/X;

   return f;
}
  
void INPUT(int *OK, double *X, double *A, int *N, double *FP0, double *FPN)
{
   int I, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is Clamped Cubic Spline Interpolation.\n");
   *OK = false;
   while (!(*OK)) {
      printf("Choice of input method:\n");
      printf("1. Input entry by entry from keyboard\n");
      printf("2. Input data from a text file\n");
      printf("3. Generate data using a function F with nodes entered ");
      printf("from keyboard\n");
      printf("4. Generate data using a function F with nodes from ");
      printf("a text file\n");
      printf("Choose 1, 2, 3, or 4 please\n");
      scanf("%d", &FLAG);
      if ((FLAG >= 1) && (FLAG <= 4)) *OK = true;
   }
   switch (FLAG) {
      case 1:
         *OK = false;
         while (!(*OK)) { 
            printf("Input n\n");
            scanf("%d", N);
            if (*N > 0) {
               *OK = true;
               for (I=0; I<=*N; I++) {
                  printf("Input X(%d) and F(X(%d)) ", I, I);
                  printf("separated by a space\n");
                  scanf("%lf %lf", &X[I], &A[I]);
               }
            }
            else printf("Number must be a positive integer\n");
         }
         break;
      case 2:
         printf("Has a text file been created with the data in two ");
         printf("columns ?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &AA);
         if ((AA == 'Y') || (AA == 'y')) {
            printf("Input the file name in the form - ");
            printf("drive:name.ext\n");
            printf("For example:   A:DATA.DTA\n");
            scanf("%s", NAME);
            INP = fopen(NAME, "r");
            *OK = false;
            while (!(*OK)) {
               printf("Input n\n");
               scanf("%d", N);
               if (*N > 0) {
                  for (I=0; I<=*N; I++) 
                     fscanf(INP, "%lf %lf", &X[I], &A[I]);
                  fclose(INP);
                  *OK = true;
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("Please create the input file in two column ");
            printf("form with the\n");
            printf("X values and F(X) values in the corresponding columns.\n");
            printf("The program will end so the input file can ");
            printf("be created.\n");
            *OK = false;
         }
         break;
      case 3:
         printf("Has the function F been created in the program ");
         printf("immediately preceding\n");
         printf("the INPUT function?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &AA);
         if ((AA == 'Y') || (AA == 'y')) {
            *OK = false;
            while (!(*OK)) {
               printf("Input n\n");
               scanf("%d", N);
               if (*N > 0) {
                  *OK = true;
                  for (I=0; I<=*N; I++) {
                     printf("Input X(%d)\n", I);
                     scanf("%lf", &X[I]);
                     A[I] = F(X[I]);
                  }
               }
               else printf("Number must be a postive integer\n");
            }
         }
         else {
            printf("The program will end so that the function F ");
            printf("can be created.\n");
            *OK = false;
         }
         break; 
      case 4:
         printf("Has the text file with X-values been created and ");
         printf("has the function F been created in the program\n");
         printf("immediately preceding the INPUT procedure?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &AA);
         if ((AA == 'Y') || (AA == 'y')) {
            printf("Input the file name in the form - ");
            printf("drive:name.ext\n");
            printf("For example:   A:DATA.DTA\n"); 
            scanf("%s", NAME);
            INP = fopen(NAME, "r");
            *OK = false;
            while (!(*OK)) {
               printf("Input n\n");
               scanf("%d", N);
               if (*N > 0) {
                  *OK = true;
                  for (I=0; I<=*N; I++) {
                     fscanf(INP, "%lf", &X[I]);
                     A[I] = F(X[I]);
                  }
                  fclose(INP);
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("The program will end so the input file and ");
            printf("F can be created.\n");
            *OK = false;
         }
         break;
   }
   if ( *OK ) {
      printf ("Enter F'(X(0)) and F'(X(N)) separated by blank\n");
      scanf("%lf %lf", FP0, FPN);
   }
}

void OUTPUT(int N, int M, double *X, double *A, double *B, double *C, double *D)
{
   int I, FLAG;
   char NAME[30];
   FILE *OUP;

   printf("Select output destination\n");
   printf("1. Screen\n");
   printf("2. Text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("For example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      OUP = fopen(NAME, "w");
   }
   else OUP = stdout;
   fprintf(OUP, "CLAMPED CUBIC SPLINE INTERPOLATION\n\n");
   fprintf(OUP, "The numbers X(0), ..., X(N) are:\n");
   for (I=0; I<=N; I++) fprintf(OUP, " %11.8f", X[I]);
   fprintf(OUP,"\n\nThe coefficients of the spline on the subintervals are:\n");
   fprintf(OUP, "for I = 0, ..., N-1\n");
   fprintf(OUP, "     A(I)          B(I)           C(I)         D(I)\n");
   for (I=0; I<=M; I++) 
      fprintf(OUP, " %13.8f %13.8f %13.8f %13.8f\n", A[I], B[I], C[I], D[I]);  
   fclose(OUP);
}
