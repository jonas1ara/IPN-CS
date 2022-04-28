/*
*   BEZIER CURVE ALGORITHM 3.6
*
*   To construct the cubic Bezier curves C0, ..., Cn-1 in
*   parameter form, where Ci is represented by
*
*   (xi(t),yi(t)) = ( a0(i) + a1(i)*t + a2(i)*t^2 + a3(i)*t^3,
*                     b0(i) + b1(i)*t + b2(i)*t^2 + b3(i)*t^3)
*
*   for 0 <= t <= 1 as determined by the left endpoint (x(i),y(i)),
*   left guidepoint (x+(i),y+(i)), right endpoint (x(i+1),y(i+1)) and
*   right guidepoint (x-(i+1),y-(i+1)) for each i = 0, 1, ... , n-1;
*
*   INPUT  n, ( (x(i),y(i)), i = 0,...,n ),
*             ( (x+(i),y+(i)), i = 0,...,n-1 ),
*             ( (x-(i),y-(i)), i = 1,...,n ).
*
*   OUTPUT coefficients ( a0(i), a1(i), a2(i), a3(i),
*                         b0(i), b1(i), b2(i), b3(i), i = 0, ... , n-1 ).
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

void INPUT(int *, double *, double *, double *, double *, 
           double *, double *, int *); 
void OUTPUT(FILE **);

main()
{
   double A0[25],A1[25],A2[25],A3[25],B0[25],B1[25],B2[25],B3[25],X[26],Y[26];
   double XPL[25],YPL[25],XMI[25],YMI[25];
   int I,N,OK;
   FILE *OUP[1];

   INPUT(&OK, X, Y, XMI, YMI, XPL, YPL, &N);
   if (OK) {
      OUTPUT(OUP);
      /* STEP 1 */
      for (I=0; I<=N-1; I++) {
         /* STEP 2 */
         A0[I] = X[I];
         B0[I] = Y[I];
         A1[I] = 3*(XPL[I] - X[I]);
         B1[I] = 3*(YPL[I] - Y[I]);
         A2[I] = 3*(X[I]+XMI[I]-2*XPL[I]);
         B2[I] = 3*(Y[I]+YMI[I]-2*YPL[I]);
         A3[I] = X[I+1]-X[I]+3*XPL[I]-3*XMI[I];
         B3[I] = Y[I+1]-Y[I]+3*YPL[I]-3*YMI[I];
         /* STEP 3 */
         fprintf(*OUP," %11.6f %11.6f %11.6f %11.6f\n", 
              A0[I], A1[I], A2[I], A3[I]);
         fprintf(*OUP," %11.6f %11.6f %11.6f %11.6f\n", 
              B0[I], B1[I], B2[I], B3[I]);
         fprintf(*OUP, "\n");
      }
      fclose(*OUP);
   }
   /* STEP 4 */
   return 0;
}

void INPUT(int *OK, double *X, double *Y, double *XMI, 
     double *YMI, double *XPL, double *YPL, int *N)
{
   int I, FLAG;
   char A;
   char NAME[30];
   FILE *INP; 

   printf("This is the Bezier Curve Algorithm.\n");
   *OK = false;
   while (!(*OK)) {
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
            printf("Input n\n");
            scanf("%d", N);
            if (*N > 0) {
               *OK = true;
               printf("Input X[0],Y[0],X+[0],Y+[0]\n");
               printf("separated by a space\n");
               scanf("%lf %lf %lf %lf", &X[0], &Y[0], &XPL[0], &YPL[0]); 
               for (I=1; I<=*N-1; I++) {
                  printf("Input X(%d),Y(%d)\n", I, I);
                  printf("separated by a space\n");
                  scanf("%lf %lf", &X[I], &Y[I]);
                  printf("Input X-(%d),Y-(%d)\n", I, I);
                  printf("separated by a space\n");
                  scanf("%lf %lf", &XMI[I-1], &YMI[I-1]);
                  printf("Input X+(%d),Y+(%d)\n", I, I);
                  printf("separated by a space\n");
                  scanf("%lf %lf", &XPL[I], &YPL[I]);
               }
               printf("Input X[n],Y[n],X-[n],Y-[n]\n");
               printf("separated by a space\n");
               scanf("%lf %lf %lf %lf", 
                  &X[*N], &Y[*N], &XMI[*N-1], &YMI[*N-1]);
            }
            else printf("Number must be a positive integer\n");
         }
         break;
      case 2:
         printf("Has a text file been created with the data as follows?\n\n");
         printf("X[0]    Y[0]    X+[0]    Y+[0]\n");
         printf("X[1]    Y[1]    X-[1]    Y-[1]    X+[1]    Y+[1]\n");
         printf("...\n");
         printf("X[n-1]  Y[n-1]  X-[n-1]  Y-[n-1]  X+[n-1]  Y+[n-1]\n");
         printf("X[n]    Y[n]    X-[n]    Y-[n]\n\n");
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
               scanf("\n%d", N);
               if (*N > 0) {
                  *OK = true;
                  fscanf(INP, "%lf %lf %lf %lf", 
                         &X[0], &Y[0], &XPL[0], &YPL[0]); 
                  for (I=1; I<=*N-1; I++)
                     fscanf(INP, "%lf %lf %lf %lf %lf %lf", 
                      &X[I], &Y[I], &XMI[I-1], &YMI[I-1], &XPL[I], &YPL[I]); 
                  fscanf(INP,"%lf %lf %lf %lf", 
                     &X[*N], &Y[*N], &XMI[*N-1], &YMI[*N-1]);
                  fclose(INP);
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("Please create the input file as indicated.\n");
            printf("The program will end so the input file can ");
            printf("be created.\n");
            *OK = false;
         }
         break;
   }
}


void OUTPUT(FILE **OUP)
{
   int I, J, FLAG;
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
   fprintf(*OUP, "BEZIER CURVE ALGORITHM\n\n");
   fprintf(*OUP, "          A0          A1          A2          A3");
   fprintf(*OUP,"  on the first line\n");
   fprintf(*OUP, "          B0          B1          B2          B3");
   fprintf(*OUP,"  on the second line\n");
}
