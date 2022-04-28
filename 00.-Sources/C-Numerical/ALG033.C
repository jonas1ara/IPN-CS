/*
*      HERMITE INTERPOLATION ALGORITHM 3.3
*
*      TO OBTAIN THE COEFFICIENTS OF THE HERMITE INTERPOLATING
*      POLYNOMIAL H ON THE (N+1) DISTINCT NUMBERS X(0), ..., X(N)
*      FOR THE FUNCTION F:
*
*      INPUT:   NUMBERS X(0), X(1), ..., X(N); VALUES F(X(0)), F(X(1)),
*               ..., F(X(N)) AND F'(X(0)), F'(X(1)), ..., F'(X(N)).
*
*      OUTPUT:  NUMBERS Q(0,0), Q(1,1), ..., Q(2N + 1,2N + 1) WHERE
*
*               H(X) = Q(0,0) + Q(1,1) * ( X - X(0) ) + Q(2,2) *
*                      ( X - X(0) )**2 + Q(3,3) * ( X - X(0) )**2 *
*                      ( X - X(1) ) + Q(4,4) * ( X - X(0) )**2 *
*                      ( X - X(1) )**2 + ... + Q(2N + 1,2N + 1) *
*                      ( X - X(0) )**2 * ( X - X(1) )**2 * ... *
*                      ( X - X(N - 1) )**2 * (X - X(N) ).
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double F(double);
void INPUT(int *, double *, double [][26], int *);
void OUTPUT(FILE **);
void OUTPUT2(FILE **, int, int, double *, double [][26]);

main()
{
   double Q[26][26],X[13],Z[26];
   double XX,S;
   int I,J,K,N,OK;
   char A; 
   FILE *OUP[1];

   INPUT(&OK, X, Q, &N);
   if (OK) {
      /* STEP 1 */
      for (I=0; I<=N; I++) {
         /* STEP 2 */
         Z[2*I] = X[I];
         Z[2*I+1] = X[I];
         Q[2*I+1][0] = Q[2*I][0];
         /* STEP 3 */
         if (I != 0) 
            Q[2*I][1] = (Q[2*I][0] - Q[2*I-1][0]) / (Z[2*I] -Z[2*I-1]);
      }    
      /* STEP 4 */
      K = 2 * N + 1;
      for (I=2; I<=K; I++)
         for (J=2; J<=I; J++)
            Q[I][J] = ( Q[I][J - 1] - Q[I - 1][J - 1] ) / ( Z[I] - Z[I - J] );
      /* STEP 5 */
      OUTPUT(OUP);
      OUTPUT2(OUP, K, N, X, Q);
      printf("Do you wish to evaluate this polynomial?\n");
      printf("Enter Y or N\n");
      scanf("\n%c", &A);
      if ((A == 'Y') || (A == 'y')) {
         printf("Enter a point at which to evaluate\n");
         scanf("%lf", &XX);
         S = Q[K][K] * (XX - Z[K-1]);
         for (I=2; I<=K; I++) {
            J = K - I + 1;
            S = (S + Q[J][J]) * (XX - Z[J-1]);
         }
         S = S + Q[0][0];
         fprintf(*OUP, "x-value and interpolated-value\n");
         fprintf(*OUP, "  %12.10e %12.10e\n", XX, S);
      }      
   }
   fclose(*OUP);
   return 0;
}
/* Change functions F and FP if program is to calculate the
   first column and part of the second column of Q  */
double F(double X)
{
   double f; 

   f =  1.0/X;
   return f;
}

/*  Note:  Function FP is the derivative of F  */
double FP(double X)
{
   double f; 

   f =  -1.0/(X*X);
   return f;
}

void OUTPUT(FILE **OUP)
{
   int FLAG;
   char NAME[30];

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "HERMITE INTERPOLATING POLYNOMIAL\n\n");
}

void INPUT(int *OK, double *X, double Q[][26], int *N)
{
   int I, FLAG;
   char A;
   char NAME[30];
   FILE *INP; 

   printf("This is Hermite interpolation.\n");
   *OK = false;
   while (!(*OK)) {
      printf("Choice of input method:\n");
      printf("1. Input entry by entry from keyboard\n");
      printf("2. Input data from a text file\n");
      printf("3. Generate data using a function F\n");
      printf("Choose 1, 2, or 3 please\n");
      scanf("%d", &FLAG);
      if ((FLAG == 1) || (FLAG == 2) || (FLAG == 3)) *OK = true;
   }
   switch (FLAG) {
      case 1:
         *OK = false;
         while (!(*OK)) { 
            printf("Input the number of data points minus 1\n");
            scanf("%d", N);
            if (*N > 0) {
               *OK = true;
               for (I=0; I<=*N; I++) {
                  printf("Input X(%d), F(X(%d)), and ", I, I);
                  printf("F'(X(%d)) separated by space\n ", I);
                  scanf("%lf %lf %lf", &X[I], &Q[2*I][0], &Q[2*I+1][1]);
               }
            }
            else printf("Number must be a positive integer\n");
         }
         break;
      case 2:
         printf("Has a text file been created with the data in three ");
         printf("columns?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &A);
         if ((A == 'Y') || (A == 'y')) {
            printf("Input the file name in the form - ");
            printf("drive:name.ext\n");
            printf("for example:   A:DATA.DTA\n");
            scanf("%s", NAME);
            INP = fopen(NAME, "r");
            *OK = false;
            while (!(*OK)) {
               printf("Input the number of data points minus 1\n");
               scanf("%d", N);
               if (*N > 0) {
                  for (I=0; I<=*N; I++) 
                     fscanf(INP, "%lf %lf %lf", &X[I], &Q[2*I][0],
                            &Q[2*I+1][1]);
                  fclose(INP);
                  *OK = true;
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("Please create the input file in three column ");
            printf("form with the X values, F(X), and\n");
            printf("F'(X) values in the corresponding columns.\n");
            printf("The program will end so the input file can ");
            printf("be created.\n");
            *OK = false;
         }
         break;
      case 3:
         printf("Have the functions F and FP been created in the program ");
         printf("immediately preceding\n");
         printf("the INPUT function?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &A);
         if ((A == 'Y') || (A == 'y')) {
            *OK = false;
            while (!(*OK)) {
               printf("Input the number of data points minus 1\n");
               scanf("%d", N);
               if (*N > 0) {
                  for (I=0; I<=*N; I++) {
                     printf("Input X(%d) \n", I);
                     scanf("%lf", &X[I]);
                     Q[2*I][0] = F(X[I]);
                     Q[2*I+1][1] = FP(X[I]); 
                  }
                  *OK = true;
               }
               else printf("Number must be a postive integer\n");
            }
         }
         else {
            printf("The program will end so that the functions F ");
            printf("and FP can be created.\n");
            *OK = false;
         }
         break; 
   }
}

void OUTPUT2(FILE **OUP, int K, int N, double *X, double Q[][26])
{
   int I; 

   fprintf(*OUP, "The input data follows:\n");
   fprintf(*OUP, "  X, F(X), F''(X)\n");
   for (I=0; I<=N; I++) 
      fprintf(*OUP, "  %12.10e %12.10e %12.10e\n", X[I], Q[2*I][0], Q[2*I+1][1]);
   fprintf(*OUP, "\nThe Coefficients of the Hermite Interpolation Polynomial\n");
   fprintf(*OUP, "in order of increasing exponent follow:\n\n");
   for (I=0; I<=K; I++) fprintf(*OUP, " %12.10e\n", Q[I][I]);
} 
