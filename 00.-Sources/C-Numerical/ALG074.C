/*
*   ITERATIVE REFINEMENT ALGORITHM 7.4
*
*   To approximate the solution to the linear system Ax=b when A is
*   suspected to be ill-conditioned:
*
*   INPUT:  The number of equations and unknowns n; the entries
*           A(i,j), 1<=i, j<=n, of the matrix A; the entries b(i),
*           1<=i<=n, of the inhomogeneous term b; the maximum number
*           of iterations N.
*
*   OUTPUT: The approximation XX(1),...,XX(n) or a message that the
*           number of iterations was exceeded. 
*/

#include<stdio.h>
#include<math.h>
#define ZERO 1.0E-20
#define true 1
#define false 0

double absval(double);
double CHIP(int RND, int R, double X);
void INPUT(int *, double [][11], double *, int*, int *, int *, int *);
void OUTPUT(FILE **);

main()
{
   double A[10][11],B[10][11],X[10],XX[10],R[10];
   double S,C,TOL,COND,XXMAX,YMAX,ERR1,TEMP;
   int NROW[10];
   int IS,FLAG,N,M,I,J,NN,K,L,KK,LL,D,I1,J1,OK,RND;
   FILE *OUP[1];

   INPUT(&OK, A, &TOL, &D, &RND, &N, &NN);
   if (OK) {
      OUTPUT(OUP);
      M = N + 1;
      fprintf(*OUP, "Original system\n");
      for (I=1; I<=N; I++) {
	 for (J=1; J<=M; J++) 
	    fprintf(*OUP," %.10e",A[I-1][J-1]);
	 fprintf(*OUP,"\n");
      }
      if (RND == 1) fprintf(*OUP,"Rounding to %d Digits.\n",D);
      else fprintf(*OUP,"Chopping to %d Digits.\n",D);
      fprintf(*OUP,"\n Modified System \n");
      for (I=1; I<=N; I++) {
	 NROW[I-1] = I;
	 for (J=1; J<=M; J++) {
	    A[I-1][J-1] = CHIP(RND,D,A[I-1][J-1]);
	    B[I-1][J-1] = A[I-1][J-1];
	    fprintf(*OUP,"  %.10e", A[I-1][J-1]);
	 }
	 fprintf(*OUP, "\n");
      }  
      /* NROW and B have been initialized,
	 Gauss elimination will begin */
      /* STEP 0 */
      I = 1;
      while ((I <= N-1) && OK) {
	 KK = I;
	 while ((absval(A[KK-1][I-1]) < ZERO) && (KK <= N))  
	    KK++;
	 if (KK > N) {
	    OK = false;
	    fprintf(*OUP, "System does not have a unique solution.\n");
	 }  
	 else { 
	    if (KK != I) {
	       /* Row interchange necessary */
	       IS = NROW[I-1];
	       NROW[I-1] = NROW[KK-1];
	       NROW[KK-1] = IS;
	       for (J=1; J<=M; J++) {
		  C = A[I-1][J-1];
		  A[I-1][J-1] = A[KK-1][J-1];
		  A[KK-1][J-1] = C;
	       }  
	    }  
	    for (J=I+1; J<=N; J++) {
	       A[J-1][I-1] = CHIP(RND,D,A[J-1][I-1]/A[I-1][I-1]);
	       for (L=I+1; L<=M; L++)
		  A[J-1][L-1] = CHIP(RND,D,A[J-1][L-1]-
			    CHIP(RND,D,A[J-1][I-1]*A[I-1][L-1]));
	    }
	 }
	 I++;
      }
      if ((absval(A[N-1][N-1]) < ZERO) && OK) {
	  OK = false;
	  fprintf(*OUP, "System has singular matrix\n");
      }
      if (OK) {
	 fprintf(*OUP, "Reduced system\n");
	 for (I=1; I<=N; I++) {
	    for (J=1; J<=M; J++) fprintf(*OUP, "  %.10e", A[I-1][J-1]); 
	    fprintf(*OUP, "\n");
	 }
	 X[N-1] = CHIP(RND,D,A[N-1][M-1]/A[N-1][N-1]); 
	 for (I=1; I<=N-1; I++) {
	    J = N-I;
	    S = 0.0;
	    for (L=J+1; L<=N; L++) 
		S = CHIP(RND,D,S-CHIP(RND,D,A[J-1][L-1]*X[L-1]));
	    S = CHIP(RND,D,A[J-1][M-1]+S);
	    X[J-1] = CHIP(RND,D,S/A[J-1][J-1]);
	 }  
      }
      fprintf(*OUP, "Initial solution\n"); 
      for (I=1; I<=N; I++) fprintf(*OUP,"  %.10e", X[I-1]);
      fprintf(*OUP, "\n"); 
      /* Refinement begins */
      /* STEP 1 */
      if (OK) {
	 K = 1;
	 for (I=1; I<=N; I++) XX[I-1] = X[I-1];
      }
      /* STEP 2 */
      while (OK && (K <= NN)) {
	 /* LL is set to 1 if the desired accuracy in any component
	    is not achieved.  Thus, LL is initially 0 for each
	    iteration. */
	 LL = 0;
	 /* STEP 3 */
	 for (I=1; I<=N; I++) {
	    R[I-1] = 0.0;
	    for (J=1; J<=N; J++) 
	       R[I-1] = CHIP(RND,2*D,R[I-1]-
			   CHIP(RND,2*D,B[I-1][J-1]*XX[J-1]));
	    R[I-1] = CHIP(RND,2*D,B[I-1][M-1]+R[I-1]);
	 }  
	 fprintf(*OUP, "Residual number %d\n", K);
	 for (I=1; I<=N; I++) { 
	    R[I-1] = CHIP(RND,D,R[I-1]);
	    fprintf(*OUP, "%18.10e ", R[I-1]);
	 }
	 fprintf(*OUP, "\n");
	 /* STEP 4 */ 
	 /* Solve the linear system in the same order as in
	    step 0.  The solution will be placed in X instead
	    of in Y */ 
	 for (I=1; I<=N-1; I++) {
	    I1 = NROW[I-1];
	    for (J=I+1; J<=N; J++) {
	       J1 = NROW[J-1];
	       R[J1-1] = CHIP(RND,D,R[J1-1]-
			    CHIP(RND,D,A[J-1][I-1]*R[I1-1]));
	    }  
	 }  
	 X[N-1] = CHIP(RND,D,R[NROW[N-1]-1]/A[N-1][N-1]);
	 for (I=1; I<=N-1 ; I++) {
	    J = N-I;
	    S = 0.0;
	    for (L=J+1; L<=N; L++)
	       S = CHIP(RND,D,S-CHIP(RND,D,A[J-1][L-1]*X[L-1]));
	    S = CHIP(RND,D,S+R[NROW[J-1]-1]);
	    X[J-1] = CHIP(RND,D,S/A[J-1][J-1]);
	 }  
	 fprintf(*OUP, "Vector Y\n");
	 for (I=1; I<=N; I++) fprintf(*OUP,"%18.10e ", X[I-1]);
	 fprintf(*OUP, "\n");
	 /* Steps 5 and 6 */
	 XXMAX = 0.0;
	 YMAX = 0.0;
	 ERR1 = 0.0;
	 for (I=1; I<=N; I++) {
	    /* If not accurate set LL to 1 */
	    if (absval(X[I-1]) > TOL) LL = 1; 
	    if (K == 1) {
	       if (absval(X[I-1]) > YMAX) 
		  YMAX = absval(X[I-1]);
	       if (absval(XX[I-1]) > XXMAX)
		  XXMAX = absval(XX[I-1]);
	    }
	    TEMP = XX[I-1];
	    XX[I-1] = CHIP(RND,D,XX[I-1]+X[I-1]);
	    TEMP = absval(TEMP-XX[I-1]);
	    if (TEMP > ERR1) ERR1 = TEMP;
	 }  
	 if (ERR1 <= TOL) LL = 2;
	 if (K == 1) COND = YMAX/XXMAX*exp(D*log(10.0));
	 fprintf(*OUP, "New approximation\n");
	 for (I=1; I<=N; I++) fprintf(*OUP, "%18.10e ", XX[I-1]);
	 fprintf(*OUP, "\n");
	 /* STEP 7 */
	 if (LL == 0) {
	    fprintf(*OUP, "The above vector is the solution.\n");
	    OK = false;
	 }
	 else if (LL == 2) {
	    fprintf(*OUP,"The above vector is the best possible\n");
	    fprintf(*OUP,"with TOL = %18.10e \n",TOL);
	    OK = false;
	 }
	 else K++;
	 /* Step 8 is not used in this implementation */
      }  
      if (K > NN) 
	 fprintf(*OUP, "Maximum Number of Iterations Exceeded.\n");
      fprintf(*OUP, "Condition number is %.10e\n", COND);
      fclose(*OUP);
   }
   return 0;
}

void INPUT(int *OK,double A[][11],double *TOL,int *D,int *RND,int *N,int *NN)
{
   int I, J;
   char A1;
   char NAME[30];
   FILE *INP; 

   printf("This is the Iterative Refinement Method.\n");
   printf("The array will be input from a text file in the order\n");
   printf("A(1,1), A(1,2), ..., A(1,n+1), A(2,1), A(2,2), ..., A(2,n+1),\n");
   printf("..., A(n,1), A(n,2), ..., A(n,n+1)\n");
   printf("Place as many entries as desired on each line, but separate\n");
   printf("entries with ");
   printf("at least one blank.\n\n\n");
   printf("Has the input file been created? - enter Y or N.\n");
   scanf("%c",&A1);
   *OK = false;
   if ((A1 == 'Y') || (A1 == 'y')) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:DATA.DTA\n");
      scanf("%s", NAME);
      INP = fopen(NAME, "r");
      *OK = false;
      while (!(*OK)) {
	 printf("Input the number of equations - an integer.\n");
	 scanf("%d", N);
	 if (*N > 0) {
	    for (I=1; I<=*N; I++) {
	       for (J=1; J<=*N+1; J++) fscanf(INP, "%lf", &A[I-1][J-1]);
	       fscanf(INP, "\n");
	    }
	    *OK = true;
	    fclose(INP);
	 }
	 else printf("The number must be a positive integer\n");
      }
      /* NN is used for the maximum number of iterations */
      *OK = false;
      while(!(*OK)) {
	 printf("Input maximum number of iterations.\n");
	 scanf("%d", NN);
	 if (*NN > 0) *OK = true;
	 else printf("Number must be a positive integer.\n"); 
      }
      *OK = false;
      printf("Choice of rounding or chopping:\n");
      printf("1. Rounding\n");
      printf("2. Chopping\n");
      printf("Enter 1 or 2.\n");
      scanf("%d", RND);
      while (!(*OK)) {
	 printf("Input number of digits D <= 8 of rounding\n");
	 scanf("%d", D);
	 if (*D > 0) *OK = true;
	 else printf("D must be a positive integer.\n");
      }
      *OK = false;
      while(!(*OK)) {
	 printf("Input tolerance, which is usually 10 ** (-D).\n");
	 scanf("%lf", TOL);
	 if (*TOL > 0.0) *OK = true;
	 else printf("Tolerance must be a positive.\n");
      }
   }
   else printf("The program will end so the input file can be created.\n");
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
   fprintf(*OUP, "ITERATIVE REFINEMENT METHOD\n\n");
}

double CHIP(int RND, int R, double X)
{
   /* The function chip rounds or chops the number x to r digits. */
   double TEMP1[5], TN[5];
   double SL, Z, Z1, Z2, Y, TEMP, TT;
   int ZZ[5];
   int NN, MM, J, I, OK;

   if (absval(X) < ZERO) return 0.0;
   else {
      I = 0;
      Y = X;
      OK = true;
      Z1 = exp(R*log(10.0));
      Z2 = exp((R-1.0)*log(10.0));
      if (absval(X) >= Z1) {
	 while (OK) {
	    Y = Y/10.0;
	    I++;
	    if (absval(Y) < Z1) OK = false;
	 }  
      }  
      else 
	 if (absval(X) < Z2) {
	    while (OK) { 
	       Y = Y*10.0;
	       I--;
	       if (absval(Y) >= Z2) OK = false;
	    }
	 }  
      SL = exp(-R*log(10.0));
      if (RND == 1) {
	 if (Y >= 0.0) {
	    TEMP = Y+0.5+0.1*SL;
	  }  
	  else {
	     TEMP = Y-0.5-0.1*SL;
	   }  
      }
      else {     
	 if (Y >= 0.0) {
	    TEMP = Y+0.1*SL;
	 }
	 else {
	    TEMP = Y-0.1*SL;
	 }
      }
      NN = R/4;
      MM = 4*NN;
      TT = TEMP;
      for (J=1; J<=NN; J++) {
	 TN[J] = exp(MM*log(10.0));
	 TEMP1[J] = TT/TN[J];
	 ZZ[J] = TEMP1[J];
	 TT = TT - ZZ[J]*TN[J];
	 MM = MM - 4;
      }
      ZZ[NN+1] = TT;
      TN[NN+1] = 1;
      Z = ZZ[1]*TN[1];
      for (J=2; J<=NN+1; J++)
	 Z = Z + ZZ[J]*TN[J];
      Z = Z*exp(I*log(10.0));
      return Z;
   }
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
