/*
*   MULLER'S ALGORITHM 2.8
*
*   To find a solution to f(x) = 0 given three approximations x0, x1
*   and x2:
*
*   INPUT:  x0,x1,x2; tolerance TOL; maximum number of iterations NO.
*
*   OUTPUT: approximate solution p or message of failure.
*
*   This implementation allows for a switch to complex arithmetic.
*   The coefficients are stored in the vector A, so the dimension
*   of A may have to be changed.
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define pi 3.141592654
#define true 1
#define false 0

double absval(double);
void CADD(double, double, double, double, double *, double *); 
void CMULT(double, double, double, double, double *, double *); 
void CDIV(double, double, double, double, double *, double *); 
double CABS(double, double);
void CSQRT(double, double, double *, double *);
void CSUB(double, double, double, double, double *, double *);
void INPUT(int *, double *, double *, double *, int *, int *);
void OUTPUT(FILE **);

main()
{
   double A[50],ZR[4],ZI[4],GR[4],GI[4],F[4],X[4],CH1R[3],CH1I[3],H[3];
   double CDEL1R[2],CDEL1I[2],DEL1[2];
   double CDELR,CDELI,CBR,CBI,CDR,CDI,CER,CEI,DEL,B,D,E,TOL,QR,QI,ER,EI,FR,FI;
   int N,M,I,J,K,ISW,KK,OK;
   FILE *OUP[1];

   printf("This is Mullers Method.\n");
   INPUT(&OK, A, X, &TOL, &M, &N);
   if (OK) {
      OUTPUT(OUP);
      /* Evaluate F using Horner's Method and save in the vector F */
      for (I=1; I<=3; I++) {
         F[I-1] = A[N-1];
         for (J=2; J<=N; J++) {
            K = N-J+1;
            F[I-1] = F[I-1]*X[I-1]+A[K-1];
         }
      }
      /* Variable ISW is used to note a switch to complex arithmetic
         ISW=0 means real arithmetic, and ISW=1 means complex arithmetic */
      ISW = 0;
      /* STEP 1 */ 
      H[0] = X[1]-X[0];
      H[1] = X[2]-X[1];
      DEL1[0] = (F[1]-F[0])/H[0];
      DEL1[1] = (F[2]-F[1])/H[1];
      DEL = (DEL1[1]-DEL1[0])/(H[1]+H[0]);
      I = 3;
      OK = true;
      /* STEP 2 */ 
      while ((I <= M) && OK) {
         /* STEPS 3-7 for real arithmetic */ 
         if (ISW == 0) {
            /* STEP 3 */ 
            B = DEL1[1]+H[1]*DEL;
            D = B*B-4.0*F[2]*DEL;
            /* test to see if need complex arithmetic */
            if (D >= 0.0) {
               /* real arithmetic - test to see if straight line */
               if (absval(DEL) <= ZERO) {
                  /* straight line - test if horizontal line */
                  if (absval(DEL1[1]) <= ZERO) {
                     printf("Horizontal Line\n");
                     OK = false;
                  }  
                  else {
                     /* straight line but not horizontal */
                     X[3] = (F[2]-DEL1[1]*X[2])/DEL1[1];
                     H[2] = X[3]-X[2];
                  }  
               }
               else {
                  /* not straight line */
                  D = sqrt(D);
                  /* STEP 4 */ 
                  E = B+D;
                  if (absval(B-D) > absval(E)) E = B-D;
                  /* STEP 5 */
                  H[2] = -2.0*F[2]/E;
                  X[3] = X[2]+H[2];
               }  
               if (OK) {
                  /* evaluate f(x(I))=F[3] by Horner's method */ 
                  F[3] = A[N-1];
                  for (J=2; J<=N; J++) {
                     K = N-J+1;
                     F[3] = F[3]*X[3]+A[K-1];
                  }   
                  fprintf(*OUP, "%d %f %f\n",I,X[3],F[3]);
                  /* STEP 6 */
                  if (absval(H[2]) < TOL) {
                     fprintf(*OUP, "\nMethod Succeeds\n");
                     fprintf(*OUP, "Approximation is within %.10e\n",TOL);
                     fprintf(*OUP, "in %d iterations\n", I);
                     OK = false;
                  }  
                  else {
                     /* STEP 7 */ 
                     for (J=1; J<=2; J++) {
                        H[J-1] = H[J];
                        X[J-1] = X[J];
                        F[J-1] = F[J];
                     }  
                     X[2] = X[3];
                     F[2] = F[3];
                     DEL1[0] = DEL1[1];
                     DEL1[1] = (F[2]-F[1])/H[1];
                     DEL = (DEL1[1]-DEL1[0])/(H[1]+H[0]);
                  }  
               }  
            }  
            else {
               /* switch to complex arithmetic */
               ISW = 1;
               for (J=1; J<=3; J++) {
                  ZR[J-1] = X[J-1]; ZI[J-1] = 0.0;
                  GR[J-1] = F[J-1]; GI[J-1] = 0.0;
               }  
               for (J=1; J<=2; J++) {
                  CDEL1R[J-1] = DEL1[J-1]; CDEL1I[J-1] = 0.0;
                  CH1R[J-1] = H[J-1]; CH1I[J-1] = 0.0;
               }
               CDELR = DEL; CDELI = 0.0;
            }  
         }  
         if ((ISW == 1) && OK) {
            /* STEPS 3-7 complex arithmetic */
            /* test if straight line */
            if (CABS(CDELR,CDELI) <= ZERO) {
               /* straight line - test if horizontal line */
               if (CABS(CDEL1R[0],CDEL1I[0]) <= ZERO) {
                  printf("horizontal line - complex\n");
                  OK = false;
               }  
               else {
                  /* straight line but not horizontal */
                  printf("line - not horizontal\n");
                  CMULT(CDEL1R[1],CDEL1I[1],ZR[2],ZI[2],&ER,&EI);
                  CSUB(GR[2],GI[2],ER,EI,&FR,&FI);
                  CDIV(FR,FI,CDEL1R[1],CDEL1I[1],&ZR[3],&ZI[3]); 
                  CSUB(ZR[3],ZI[3],ZR[2],ZI[2],&CH1R[2],&CH1I[2]);
               }  
            }  
            else {
               /* not straight line */
               /* STEP 3 */
               CMULT(CH1R[1],CH1I[1],CDELR,CDELI,&ER,&EI);
               CADD(CDEL1R[1],CDEL1I[1],ER,EI,&CBR,&CBI);
               CMULT(GR[2],GI[2],CDELR,CDELI,&ER,&EI);
               CMULT(ER,EI,4.0,0.0,&FR,&FI);
               QR = CBR; QI = CBI;
               CMULT(CBR,CBI,QR,QI,&ER,&EI);
               CSUB(ER,EI,FR,FI,&CDR,&CDI);
               CSQRT(CDR,CDI,&FR,&FI);
               /* STEP 4 */
               CDR = FR; CDI = FI;
               CADD(CBR,CBI,CDR,CDI,&CER,&CEI);
               CSUB(CBR,CBI,CDR,CDI,&FR,&FI);
               if (CABS(FR,FI) > CABS(CER,CEI))
                  CSUB(CBR,CBI,CDR,CDI,&CER,&CEI);
               /* STEP 5 */
               CDIV(GR[2],GI[2],CER,CEI,&ER,&EI);
               CMULT(ER,EI,-2.0,0.0,&CH1R[2],&CH1I[2]);
               CADD(ZR[2],ZI[2],CH1R[2],CH1I[2],&ZR[3],&ZI[3]);
            }  
            if (OK) {
               /* evaluate f(x(i))=f(3) by Horner's method */
               GR[3] = A[N-1]; GI[3] = 0.0;
               for (J=2; J<=N; J++) {
                  K = N-J+1;
                  CMULT(GR[3],GI[3],ZR[3],ZI[3],&ER,&EI);
                  GR[3] = ER+A[K-1];
                  GI[3] = EI;
               }  
               fprintf(*OUP, "%4d %14.8f %14.8f %14.8f %14.8f\n", I, ZR[3], ZI[3], GR[3], GI[3]);
               /* STEP 6*/ 
               if (CABS(CH1R[2],CH1I[2]) <= TOL) {
                  fprintf(*OUP, "\nMethod Succeeds\n");
                  fprintf(*OUP, "Approximation is within %.8e\n", TOL);
                  fprintf(*OUP, "in %d iterations\n", I);
                  OK = false;
               }  
               else {
                  /* STEP 7 */
                  for (J=1; J<=2; J++) {
                     CH1R[J-1] = CH1R[J];
                     CH1I[J-1] = CH1I[J];
                     ZR[J-1] = ZR[J];
                     ZI[J-1] = ZI[J];
                     GR[J-1] = GR[J];
                     GI[J-1] = GI[J];
                  } 
                  ZR[2] = ZR[3];
                  ZI[2] = ZI[3];
                  GR[2] = GR[3];
                  GI[2] = GI[3];
                  CDEL1R[0] = CDEL1R[1];
                  CDEL1I[0] = CDEL1I[1];
                  CSUB(GR[2],GI[2],GR[1],GI[1],&ER,&EI);
                  CDIV(ER,EI,CH1R[1],CH1I[1],&CDEL1R[1],&CDEL1I[1]);
                  CSUB(CDEL1R[1],CDEL1I[1],CDEL1R[0],CDEL1I[0],&ER,&EI);
                  CADD(CH1R[1],CH1I[1],CH1R[0],CH1I[0],&FR,&FI);
                  CDIV(ER,EI,FR,FI,&CDELR,&CDELI);
               }  
            }  
         }  
         /* STEP 7 CONTINUED */
         I++;
      }  
      /* STEP 8 */
      if ((I > M) && OK)
       fprintf(*OUP, "Method failed to give accurate approximation.\n");
      fclose(*OUP);
   }
   return 0;
}


void CADD(double A, double B, double C, double D, double *E, double *F) 
/* Procedure to perform complex addition:
   (A + Bi) + (C + Di) -> E + Fi  */
{
   *E = A + C;
   *F = B + D;
}

void CMULT(double A, double B, double C, double D, double *E, double *F) 
/*  Procedure to perform complex multiplication:
    (A + Bi) * (C + Di) -> E + Fi   */
{
   *E = (A * C) - (B * D);
   *F = A * D + B * C;
}

void CDIV(double A, double B, double C, double D, double *E, double *F) 
/*  Procedure to perform complex division:
    (A + Bi) / (C + Di) -> E + Fi    */
{
   double G;
   
   G = C * C + D * D;
   *E = (A * C + B * D) / G;
   *F = (B * C - A * D) / G;
}

double CABS(double A, double B)
/*   Function to compute complex absolute value:
     | A + Bi | = sqrt(A*A + B*B)   */
{
   double C;

   C = sqrt(A * A + B * B);
   return C;
}

void CSQRT(double A, double B, double *C, double *D)
/*   Procedure to compute complex square root:
     sqrt(A + Bi) -> E + Fi    */
{
   double G,R,T,HP;

   HP = 0.5*pi;
   if (absval(A) <= ZERO) {
      if (abs(B) <= ZERO) {
         R = 0.0;
         T = 0.0;
      }
      else {
         T = HP;
         if (B < 0.0) T = -T;
         R = absval(B);
      }
   }
   else {
      R = sqrt(A * A + B * B) ;
      if (abs(B) < ZERO) {
         T = 0.0;
         if (A < 0.0) T = pi;
      }
      else {
         T = atan( B / A );
         if (A < 0.0) T = T + pi;
      }
   }
   G = sqrt(R);
   *C = G * cos(0.5 * T);
   *D = G * sin(0.5 * T);
}

void CSUB(double A, double B, double C, double D, double *E, double *F)
/*  Procedure to perform complex subtraction:
    (A + Bi) - (C + Di) -> E + Fi    */
{
   *E = A - C;
   *F = B - D;
}

void INPUT(int *OK, double *A, double *X, double *TOL, int *M, int *N)
{
   int I, J, FLAG;
   double P;
   char AA;
   char NAME[30];
   FILE *INP; 

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
            printf("Input the degree n of the polynomial\n");
            scanf("%d", N);
            if (*N > 0) {
               *OK = true;
               printf("Input the coefficients of the");
               printf(" polynomial in ascending order\n");
               printf("of exponent at the prompt\n");
               *N = *N + 1;
               for (I=1; I<=*N; I++) {
                  J = I - 1;
                  printf("Input A( %d )\n", J);
                  scanf("%lf", &A[I-1]);
               }
            }
            else printf("n must be a positive integer\n");
         }
         break;
      case 2:
         printf("Is there a text file containing the coefficients\n");
         printf("in ascending order of exponent?\n");
         printf("Enter Y or N\n");
         scanf("\n%c", &AA);
         if ((AA == 'Y') || (AA == 'y')) {
            *OK = true;
            printf("Input the file name in the form - ");
            printf("drive:name.ext\n");
            printf("for example:   A:DATA.DTA\n");
            scanf("%s", NAME);
            INP = fopen(NAME, "r");
            *OK = false;
            while (!(*OK)) {
               printf("Input n\n");
               scanf("%d", N);
               if (*N > 0) {
                  *OK = true;
                  *N = *N + 1;
                  for (I=1; I<=*N; I++) 
                     fscanf(INP, "%lf", &A[I-1]);
                  fclose(INP);
               }
               else printf("Number must be a positive integer\n");
            }
         }
         else {
            printf("Please create the input file.\n");
            printf("The program will end so the input file can\n");
            printf("be created.\n");
            *OK = false;
         }
         break;
   }
   if (A[*N-1] ==0) {
      printf("Leading coefficient is 0 - error in input\n");
      *OK = false;
   }
   if (*N == 2) {
      P = -A[0]/A[1];
      printf("Polynomial is linear: root is %11.8f\n",P);
      *OK = false;
   }
   if (*OK) {
      *OK = false;
      while(!(*OK)) {
         printf("Input tolerance\n");
         scanf("%lf", TOL);
         if (*TOL <= 0.0) 
            printf("Tolerance must be positive\n");
         else *OK = true;
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input maximum number of iterations ");
         printf("- no decimal point\n");
         scanf("%d", M);
         if (*M <= 0) 
            printf("Must be positive integer\n");
         else *OK = true;
      }  
      printf("Input the first of three starting values\n");
      scanf("%lf", &X[0]);
      printf("Input the second of three starting values\n");
      scanf("%lf", &X[1]);
      printf("Input the third starting value\n");
      scanf("%lf", &X[2]);
   }
}

void OUTPUT(FILE **OUP)
{
   char NAME[30];
   int FLAG;

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
   fprintf(*OUP, "MULLERS METHOD\n");
   fprintf(*OUP, "The output is i, approximation x(i), f(x(i))\n\n");
   fprintf(*OUP,"Three columns means the results are real numbers,\n");
   fprintf(*OUP,"Five columns means the results are complex\n");
   fprintf(*OUP,"numbers with real and imaginary parts of x(i)\n");
   fprintf(*OUP,"followed by real and imaginary parts of f(x(i)).\n\n");
}   

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
