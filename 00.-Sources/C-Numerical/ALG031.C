/*
*   NEVILLE'S ITERATED INTERPOLATION ALGORITHM 3.1
*
*   To evaluate the interpolating polynomial P on the
*   (n+1) distinct numbers x(0), ..., x(n) at the number x
*   for the function f:
*
*   INPUT:   numbers x(0),..., x(n) as XX(0),...,XX(N);
*            number x; values of f as the first column of Q
*            or may be computed if function f is supplied.
*
*   OUTPUT:  the table Q with P(x) = Q(N+1,N+1). 
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double F(double);
void INPUT(int *, double *, double [][26], double *, int *);
void OUTPUT(int, double, double *, double [][26]);

main()
{
   double Q[26][26],XX[26],D[26];
   double X;
   int I,J,N,OK;

   INPUT(&OK, XX, Q, &X, &N);
   if (OK) {
      /* STEP 1 */
      D[0] = X - XX[0];
      for (I=1; I<=N; I++) {
         D[I] = X - XX[I];
         for (J=1; J<=I; J++) 
            Q[I][J] = (D[I] * Q[I-1][J-1] - D[I-J] * 
                      Q[I][J-1]) / (D[I] - D[I-J]); 
      }
      /* STEP 2 */
      OUTPUT(N, X, XX, Q);
   }
   return 0;
}

/* Change F if program is to calculate the first column of Q */
double F(double X)
{
   double f; 

   f =  1.0/X;
   return f;
}

void INPUT(int *OK, double *XX, double Q[][26], double *X, int *N)
{
   int I, FLAG;
   char A;
   char NAME[30];
   FILE *INP; 

   printf("This is Nevilles Method.\n");
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
            printf("Input n\n");
            scanf("%d", N);
            if (*N > 0) {
               *OK = true;
               for (I=0; I<=*N; I++) {
                  printf("Input X(%d) and F(X(%d)) ", I, I);
                  printf("separated by space\n");
                  scanf("%lf %lf", &XX[I], &Q[I][0]);
               }
            }
            else printf("Number must be a positive integer\n");
         }
         break;
      case 2:
         printf("Has a text file been created with the data in two columns ?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &A);
         if ((A == 'Y') || (A == 'y')) {
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
                     fscanf(INP, "%lf %lf", &XX[I], &Q[I][0]);
                  fclose(INP);
                  *OK = true;
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("Please create the input file in two column ");
            printf("form with the X values and\n");
            printf("F(X) values in the corresponding columns.\n");
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
         scanf("\n%c", &A);
         if ((A == 'Y') || (A == 'y')) {
            *OK = false;
            while (!(*OK)) {
               printf("Input n\n");
               scanf("%d", N);
               if (*N > 0) {
                  for (I=0; I<=*N; I++) {
                     printf("Input X(%d)\n", I);
                     scanf("%lf", &XX[I]);
                     Q[I][0] = F(XX[I]);
                  }
                  *OK = true;
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("The program will end so that the function F ");
            printf("can be created.\n");
            *OK = false;
         }
         break; 
   }
   if (*OK) {
      printf("Input the point at which the polynomial is to be ");
      printf("evaluated\n");
      scanf("%lf", X);
   }
}


void OUTPUT(int N, double X, double *XX, double Q[][26])
{
   int I, J, FLAG;
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
   fprintf(OUP, "NEVILLES METHOD\n");
   fprintf(OUP, "Table for P evaluated at X = %12.8f follows: \n", X);
   fprintf(OUP, "Entries are XX(I), Q(I,0), ..., Q(I,I) ");
   fprintf(OUP, "for each I = 0, ..., N where N = %3d\n\n", N); 
   for (I=0; I<=N; I++) {
      fprintf(OUP, "%11.8f ", XX[I]);
      for (J=0; J<=I; J++) fprintf(OUP, "%11.8f ", Q[I][J]);
      fprintf(OUP, "\n");
   }
   fclose(OUP);
}
