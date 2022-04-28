/*
*   FAST FOURIER TRANSFORM ALGORITHM 8.3
*
*   To compute the coefficients in the discrete approximation
*   for the data (x(J),y(J)), 0<=J<=2m-1 where m=2**p and
*   x(J)=-pi+J*pi/m for 0<=J<=2m-1.
*
*   INPUT:  m; y(0),y(1),...y(2m-1).
*
*   OUTPUT: complex numbers c(0),...,c(2m-1); real numbers
*           a(0),...,a(m); b(1),...,b(m-1).
*
*   NOTE:   The multiplication by EXP(-K*PI*I) is done within the
*           program.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define pi 4*atan(1)
#define true 1
#define false 0

double absval(double);
double F(double);
void INPUT(int *, double *, double *, int *, int *);
void OUTPUT(FILE **);
int IBR(int, int);
void CMULT(double, double, double, double, double *, double *);
void CEXP(double, double, double *, double *);

main()
{
   double CR[64],CI[64],WR[64],WI[64],Y[64];
   double WWR, WWI, T1R, T1I, T3R, T3I, Z, XR, XI, YR, YI, TW;
   int NG,N, N2, NU1, I, K, L, M, NP, J, M1, OK;
   FILE *OUP[1];

   INPUT(&OK, Y, &Z, &N, &M);
   if (OK) {
      OUTPUT(OUP);
      TW = log(2.0);
      /* STEP 1 */
      /* use N2 for m, NG for p, NU1 for q, WW for zeta */
      N2 = N / 2;
      /* STEP 2 */
      for (I=1; I<=N; I++) {
         CR[I-1] = Y[I-1];
         CI[I-1] = 0.0;
      }  
      Z = N;
      NG = log(Z)/TW+.5;
      NU1 = NG - 1;
      YR = 0.0;
      YI = 2.0*pi/N;
      CEXP(YR,YI,&WWR,&WWI);
      /* STEP 3 */
      for (I=1; I<=N2; I++) {
         XR = 1.0;
         XI = 0.0;
         YR = 1.0;
         YI = 0.0;
         for (J=1; J<=I; J++) {
            CMULT(XR,XI,WWR,WWI,&YR,&YI);
            XR = YR;
            XI = YI;
         }
         WR[I-1] = XR;
         WI[I-1] = XI;
         WR[N2+I-1] = -XR;
         WI[N2+I-1] = -XI;
      }  
      /* STEP 4 */
      K = 0;
      /* STEP 5 */
      for (L=1; L<=NG; L++) {
         /* STEP 6 */
         while (K < N-1) {
            /* STEP 7 */
            for (I=1; I<=N2; I++) {
               /* STEP 8 */
               Z = exp(NU1*TW);
               M1 = Z+.5;
               M1 = K/M1;
               /* IBR does the bit reversal */
               NP = IBR(M1,NG);
               /* T1 = T1R + T1i is eta */
               T1R = CR[K+N2];
               T1I = CI[K+N2];
               /* STEP 9 */
               if (NP != 0) {
                  XR = T1R;
                  XI = T1I;
                  CMULT(XR,XI,WR[NP-1],WI[NP-1],&T1R,&T1I);
               }  
               CR[K+N2] = CR[K] - T1R;
               CI[K+N2] = CI[K] - T1I;
               CR[K] = CR[K] + T1R;
               CI[K] = CI[K] + T1I;
               /* STEP 10 */
               K++;
            }  
            /* STEP 11 */
            K = K+N2;
         }  
         /* STEP 12 */
         K = 0;
         N2 = N2/2;
         NU1--;
      }  
      /* STEP 13 */
      while (K < N-1) {
         /* STEP 14 */
         I = IBR(K,NG);
         /* STEP 15 */
         if (I > K) {
            T3R = CR[K];
            CR[K] = CR[I];
            CR[I] = T3R;
            T3I = CI[K];
            CI[K] = CI[I];
            CI[I] = T3I;
         }  
         /* STEP 16 */
         K++;
      }  
      /* STEPS 17 and 18 */
      fprintf(*OUP, "Coefficients c(0), ... , c(2m-1)\n\n");
      for (I=1; I<=N; I++) {
         YR = 0.0;
         YI = -(I-1)*pi;
         CEXP(YR,YI,&XR,&XI);
         CMULT(XR,XI,CR[I-1],CI[I-1],&YR,&YI);
         CR[I-1] = YR/(0.5*N);
         CI[I-1] = YI/(0.5*N);
         K = I - 1;
         fprintf(*OUP, "%3d %14.8f %13.8f\n", K, CR[I-1], CI[I-1]);
      }  
      fprintf(*OUP, "\nCoefficients a(0), ..., a(m)\n\n");
      for (I=1; I<=M+1; I++) fprintf(*OUP, "%.8e\n", CR[I-1]);
      fprintf(*OUP, "\nCoefficients b(1), ..., b(m-1)\n\n");
      for (I=2; I<=M; I++) fprintf(*OUP, "%.8e\n", CI[I-1]);
      fclose(*OUP);
   }
   return 0;
}

/* Change F if program is to calculate Y */
double F(double Z)
{
   double f,x; 
   f = ((Z-3)*Z+2)*Z*Z-sin(Z*(Z-2))/cos(Z*(Z-2));
   return f;
}

void INPUT(int *OK, double *Y, double *Z, int *N, int *M)
{
   int I, J, FLAG;
   char A;
   char NAME[30];
   FILE *INP; 

   printf("This is the Fast Fourier Transform.\n\n");
   printf("The user must make provisions if the\n");
   printf("interval is not [-pi,pi].\n");
   printf("The example illustrates the required\n");
   printf("provisions under input method 3.\n");
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
            printf("Input m\n");
            scanf("%d", M);
            if (*M > 0) {
               *OK = true;
               *N = 2*(*M);
               for (I=1; I<=*N; I++) {
                  J = I - 1;
                  printf("Input y(%d).\n", J);
                  scanf("%lf", &Y[I-1]);
               }
            }
            else printf("Number must be a positive integer.\n");
         }
         break;
      case 2:
         printf("Has a text file been created with the ");
         printf("entries y(0),...,y(2m-1)\n");
         printf("separated by a blank?\n");
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
               printf("Input number m.\n");
               scanf("%d", M);
               *N = 2*(*M);
               if (*N > 0) {
                  for (I=1; I<=*N; I++) 
                     fscanf(INP, "%lf", &Y[I-1]);
                  fclose(INP);
                  *OK = true;
               }
               else printf("Number must be a positive integer.\n");
            }
         }
         else {
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
               printf("Input the number m.\n");
               scanf("%d", M);
               *N = 2*(*M);
               if (*N > 0) {
                  for (I=1; I<=*N; I++) {
                     *Z = (I-1.0)/(*M);
                     Y[I-1] = F(*Z);
                  }
                  *OK = true;
               }
               else printf("Number must be a postive integer.\n");
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
   int I, J, FLAG;
   char NAME[30];

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "FAST FOURIER TRANSFORM\n\n");
}

int IBR(int J, int NU)
{
   int K, I, J2, J1;

   J1 = J;
   K = 0;
   for (I=1; I<=NU; I++) {
      J2 = J1 / 2;
      K = 2*K+(J1-2*J2);
      J1 = J2;
   }
   return K; 
}

void CMULT(double A, double B, double C, double D, double *E, double *F)
/*  Performs complex multiplication:
       (A + Bi) * (C + Di) -> E + Fi         */
{
   double A1, B1, C1, D1;

   if (absval(A) <= ZERO) A1 = 0.0;
   else A1 = A;
   if (absval(B) <= ZERO) B1 = 0.0;
   else B1 = B; 
   if (absval(C) <= ZERO) C1 = 0.0;
   else C1 = C;
   if (absval(D) <= ZERO) D1 = 0.0;
   else D1 = D;
   *E = (A1*C1) - (B1*D1);
   *F = A1*D1 + B1*C1;
}

void CEXP(double A, double B, double *C, double *D)
/*  Performs complex exponentiation:
       exp(A + Bi) -> C + Di      */
{
   double E;

   E = exp(A);
   *C = E * cos(B);
   *D = E * sin(B);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
