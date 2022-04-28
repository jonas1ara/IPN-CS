/*
*   NEWTON'S INTERPOLATORY DIVIDED-DIFFERENCE FORMULA ALGORITHM 3.2
*
*   To obtain the divided-difference coefficients of the interpolatory
*   polynomial P on the (n+1) distinct numbers x(0), x(1), ..., x(n)
*   for the function f:
*
*   INPUT:   numbers x(0), x(1), ..., x(n); values f(x(0)), f(x(1)), ...,
*            f(x(n)) as the first column Q(0,0), Q(1,0), ..., Q(N,0) OF Q,
*            or may be computed if function f is supplied.
*
*   OUTPUT:  the numbers Q(0,0), Q(1,1), ..., Q(N,N) where
*            P(x) = Q(0,0) + Q(1,1)*(x - x(0)) + Q(2,2)*(x - x(0))*(x - x(1))
*            +... + Q(N,N)*(x - x(0))*(x - x(1))*...*(x - x(N - 1)).
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double F(double);
void INPUT(int *, double *, double [][26], int *);
void OUTPUT(FILE **);

main()
{
   double Q[26][26],X[26];
   int I,J,N,OK;
   FILE *OUP[1];

   INPUT(&OK, X, Q, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      for (I=1; I<=N; I++)
         for (J=1; J<=I; J++)
            Q[I][J] = (Q[I][J-1] - Q[I-1][J-1]) / (X[I] - X[I-J]);
      /* STEP 2 */
      fprintf(*OUP, "Input data follows:\n");
      for (I=0; I<=N; I++)
          fprintf(*OUP, "X(%d) = %12.8f F(X(%d)) = %12.8f\n", I, X[I], I, Q[I][0]);
      fprintf(*OUP, "\nThe coefficients Q(0,0), ..., Q(N,N) are:\n");
      for (I=0; I<=N; I++) fprintf(*OUP, "%12.8f\n", Q[I][I]);
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

void INPUT(int *OK, double *X, double Q[][26], int *N)
{
   int I, FLAG;
   char A;
   char NAME[30];
   FILE *INP; 

   printf("Newtons form of the interpolation polynomial\n");
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
                  scanf("%lf %lf", &X[I], &Q[I][0]);
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
                     fscanf(INP, "%lf %lf", &X[I], &Q[I][0]);
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
                  *OK = true;
                  for (I=0; I<=*N; I++) {
                     printf("Input X(%d)\n", I);
                     scanf("%lf", &X[I]);
                     Q[I][0] = F(X[I]);
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
   }
}


void OUTPUT(FILE **OUP)
{
   int FLAG;
   char NAME[30];

   printf("Select output destination\n");
   printf("1. Screen\n");
   printf("2. Text file\n");
   printf("Enter 1 or 2\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("For example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "NEWTONS INTERPOLATION POLYNOMIAL\n\n");
}
