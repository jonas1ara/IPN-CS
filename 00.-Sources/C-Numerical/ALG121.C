/*
*   POISSON EQUATION FINITE-DIFFERENCE ALGORITHM 12.1
*
*   To approximate the solution to the Poisson equation
*              DEL(u) = F(x,y), a <= x <= b, c <= y <= d,
*   SUBJECT TO BOUNDARY CONDITIONS:
*                   u(x,y) = G(x,y),
*       if x = a or x = b for c <= y <= d,
*       if y = c or y = d for a <= x <= b
*
*   INPUT:   endpoints a, b, c, d; integers m, n; tolerance TOL;
*            maximum number of iterations M
*
*   OUTPUT:  approximations W(I,J) to u(X(I),Y(J)) for each
*            I = 1,..., n-1 and J=1,..., m-1 or a message that the
*            maximum number of iterations was exceeded.
*/

#include<stdio.h>
#include<math.h>
#define true 1
#define false 0

double F(double X, double Y);
double G(double X, double Y);
double absval(double);
void INPUT(int *, double *, double *, double *, double *, int *, int *, double *, int *);
void OUTPUT(int, int, double *, double *, double [][26], int);

main()
{
   double W[26][26], X[26], Y[26];
   double TOL,A,B,C,D,H,K,V,VV,Z,E,ALPHA,BETA;
   int M,N,NN,M1,M2,N1,N2,I,J,L,LL,OK;

   INPUT(&OK, &A, &B, &C, &D, &M, &N, &TOL, &NN);
   if (OK) {
      M1 = M - 1;
      M2 = M - 2;
      N1 = N - 1;
      N2 = N - 2;
      /* STEP 1 */
      H = (B - A) / N;
      K = (D - C) / M;
      /* STEPS 2 and 3 construct mesh points */
      /* STEP 2 */
      for (I=0; I<=N; I++) X[I] = A + I * H; 
      /* STEP 3 */
      for (J=0; J<=M; J++) Y[J] = C + J * K;
      /* STEP 4 */
      for (I=1; I<=N1; I++) {
         W[I][0] = G(X[I],Y[0]);
         W[I][M] = G(X[I],Y[M]);
      }  
      for (J=0; J<=M; J++) {
         W[0][J] = G(X[0],Y[J]);
         W[N][J] = G(X[N],Y[J]);
      }  
      for (I=1; I<=N1; I++) 
         for (J=1; J<=M1; J++) W[I][J] = 0.0;
      /* STEP 5 */
      /* use V for lambda, VV for mu */
      V = H * H / ( K * K );
      VV = 2.0 * ( 1.0 + V );
      L = 1;
      OK = false;
      /* Z is a new value of W(I,J) to be used in computing
         the norm of the error E used in place of NORM */
      /* STEP 6 */
      while ((L <= NN) && (!OK)) {
         /* STEPS 7 through 20 perform Gauss-Seidel iterations */
         /* STEP 7 */
         Z = (-H*H*F(X[1],Y[M1])+G(A,Y[M1])+V*
              G(X[1],D)+V*W[1][M2]+W[2][M1])/VV;
         E = absval( W[1][M1] - Z );
         W[1][M1] = Z;
         /* STEP 8 */
         for (I=2; I<=N2; I++) {
            Z = (-H*H*F(X[I],Y[M1])+V*G(X[I],D)+
                 W[I-1][M1]+W[I+1][M1]+V*W[I][M2])/VV;
            if ( absval( W[I][M1] - Z ) > E ) 
               E = abs( W[I][M1] - Z );
            W[I][M1] = Z;
         }  
         /* STEP 9 */
         Z = (-H*H*F(X[N1],Y[M1])+G(B,Y[M1])+V*
              G(X[N1],D)+W[N2][M1]+V*W[N1][M2])/VV;
         if ( absval( W[N1][M1] - Z ) > E ) 
            E = abs( W[N1][M1] - Z );
         W[N1][M1] = Z;
         /* STEP 10 */
         for (LL=2; LL<=M2; LL++) {
            J = M2 - LL + 2; 
            /* STEP 11 */
            Z = (-H*H*F(X[1],Y[J])+G(A,Y[J])+
                V*W[1][J+1]+V*W[1][J-1]+W[2][J])/VV;
            if ( absval( W[1][J] - Z ) > E ) 
               E = absval( W[1][J] - Z );
            W[1][J] = Z;
            /* STEP 12 */
            for (I=2; I<=N2; I++) {
               Z = (-H*H*F(X[I],Y[J])+W[I-1][J]+
                   V*W[I][J+1]+V*W[I][J-1]+W[I+1][J])/VV;
               if ( absval( W[I][J] - Z ) > E ) 
                  E = absval( W[I][J] - Z );
               W[I][J] = Z;
            }  
            /* STEP 13 */
            Z = (-H*H*F(X[N1],Y[J])+G(B,Y[J])+
                 W[N2][J]+V*W[N1][J+1]+V*W[N1][J-1])/VV;
            if ( absval( W[N1][J] - Z ) > E )
               E = absval( W[N1][J] - Z );
            W[N1][J] = Z;
         }  
         /* STEP 14 */
         Z = ( -H * H * F( X[1],Y[1] ) + V * G( X[1], C ) +
              G( A, Y[1] ) + V * W[1][2] + W[2][1] ) / VV;
         if ( absval( W[1][1] - Z ) > E ) 
            E = absval( W[1][1] - Z );
         W[1][1] = Z;
         /* STEP 15 */
         for (I=2; I<=N2; I++) {
            Z = (-H*H*F(X[I],Y[1])+V*G(X[I],C)+
                 W[I+1][1]+W[I-1][1]+V*W[I][2])/VV;
            if ( absval( W[I][1] - Z ) > E )
               E = absval( W[I][1] - Z );
            W[I][1] = Z;
         }  
         /* STEP 16 */
         Z = (-H*H*F(X[N1],Y[1])+V*G(X[N1],C)+
              G(B,Y[1])+W[N2][1]+V*W[N1][2])/VV;
         if ( absval( W[N1][1] - Z ) > E ) 
            E = absval( W[N1][1] - Z );
         W[N1][1] = Z;
         /* STEP 17 */
         if (E<=TOL) {
            /* STEP 18 */ 
            OUTPUT(N1, M1, X, Y, W, L);
            /* STEP 19 */
            OK = true;
         }  
         else 
            /* STEP 20 */
            L++;
      }  
      /* STEP 21 */
      if (L > NN) 
         printf("Method fails after iteration number %d\n", NN);
   }
   return 0;
}

/* Change F for a new problem */
double F(double X, double Y)
{
   double f; 

   f =  X*exp(Y);
   return f;
}

/* Change G for a new problem */
double G(double X, double Y)
{
   double g; 

   g = X*exp(Y);
   return g;
}

void INPUT(int *OK, double *A, double *B, double *C, double *D, int *M, int *N, double *TOL, int *NN)
{
   int I, FLAG;
   char AA;
   char NAME[30];
   FILE *INP; 

   printf("This is the Finite-Difference Method for Elliptic Equations.\n");
   *OK = false;
   printf("Have the functions F(x,y) and G(x,y) been created\n");
   printf("immediately preceding the INPUT procedure? Answer Y or N.\n");
   scanf("\n%c", &AA);
   if ((AA == 'Y') || (AA == 'y')) {
      *OK =false;
      while (!(*OK)) {
         printf("Input endpoints of interval [A,B] on X-axis\n");
         printf("separated by a blank.\n");
         scanf("%lf %lf", A, B);
         printf("Input endpoints of interval [C,D] on Y-axis\n");
         printf("separated by a blank.\n");
         scanf("%lf %lf", C, D);
         if ((*A >= *B) || (*C >= *D)) 
            printf("Left endpoint must be less than right endpoint.\n");
         else *OK = true;
      }  
      *OK = false;
      while (!(*OK)) {
          printf("Input number of intervals n on the X-axis and m\n");
          printf("on the Y-axis separated by a blank\n");
          printf("Note that both n and m should be larger than 2.\n");
          scanf("%d %d", N, M);
          if ((*M <= 2) || (*N <= 2))
             printf("Numbers must exceed 2.\n");
          else *OK = true;
      }   
      *OK = false;
      while (!(*OK)) {
         printf("Input the Tolerance.\n");
         scanf("%lf", TOL);
         if (*TOL <= 0.0)
            printf("Tolerance must be positive.\n");
         else *OK = true;
      }  
      *OK = false;
      while (!(*OK)) {
         printf("Input the maximum number of iterations.\n");
         scanf("%d", NN);
         if (*NN <= 0) 
            printf ("Number must be a positive integer.\n");
         else *OK = true;
      }  
   }
   else {
      printf("The program will end so that the functions ");
      printf("F and G can be created.\n");
      *OK = false;
   }  
}

void OUTPUT(int N1, int M1, double *X, double *Y, double W[][26], int L)
{
   int I, J, FLAG;
   char NAME[30];
   FILE *OUP;

   printf("Choice of output method:\n");
   printf("1. Output to screen\n");
   printf("2. Output to text file\n");
   printf("Please enter 1 or 2.\n");
   scanf("%d", &FLAG);
   if (FLAG == 2) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      OUP = fopen(NAME, "w");
   }
   else OUP = stdout;
   fprintf(OUP, "POISSON EQUATION FINITE-DIFFERENCE METHOD\n\n");
   fprintf(OUP, "  I  J        X(I)        Y(J)        W(I,J)\n\n");
   for (I=1; I<=N1; I++)
      for (J=1; J<=M1; J++) 
         fprintf(OUP, "%3d %2d %11.8f %11.8f %13.8f\n", I, J, X[I], Y[J], W[I][J]);
   fprintf(OUP, "Convergence occurred on iteration number: %d\n", L); 
   fclose(OUP);
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
