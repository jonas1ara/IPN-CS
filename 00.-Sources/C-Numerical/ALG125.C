/*
*   Finite Element Algorithm 12.5
*
*   To approximate the solution to an elliptic partial-differential
*   equation subject to Dirichlet, mixed, or Neumann boundary
*   conditions:
*
*   Input:   see STEP 0
*
*   Output:  description of triangles, nodes, line integrals, basis
*            functions, linear system to be solved, and the
*            coefficients of the basis functions
*
*
*   Step 0
*   General outline
*
*      1. Triangles numbered: 1 to K for triangles with no edges on
*         Script-S-1 or Script-S-2, K+1 to N for triangles with
*         edges on script-S-2, N+1 to M for remaining triangles.
*         Note: K=0 implies that no triangle is interior to D.
*         Note: M=N implies that all triangles have edges on
*         script-S-2.
*
*      2. Nodes numbered: 1 to LN for interior nodes and nodes on
*         script-S-2, LN+1 to LM for nodes on script-S-1.
*         Note: LM and LN represent lower case m and n resp.
*         Note: LN=LM implies that script-S-1 contains no nodes.
*         Note: If a node is on both script-S-1 and script-S-2, then
*         it should be treated as if it were only on script-S-1.
*
*      3. NL=number of line segments on script-S-2
*         line(I,J) is an NL by 2 array where
*         line(I,1)= first node on line I and
*         line(I,2)= second node on line I taken
*         in positive direction along line I
*
*      4. For the node labelled KK,KK=1,...,LM we have:
*         A) coordinates XX(KK),YY(KK)
*         B) number of triangles in which KK is a vertex= LL(KK)
*         C) II(KK,J) labels the triangles KK is in and
*         NV(KK,J) labels which vertex node KK is for
*         each J=1,...,LL(KK)
*
*      5. NTR is an M by 3 array where
*         NTR(I,1)=node number of vertex 1 in triangle I
*         NTR(I,2)=node number of vertex 2 in triangle I
*         NTR(I,3)=node number of vertex 3 in triangle I
*
*      6. Function subprograms:
*         A) P,Q,R,F,G,G1,G2 are the functions specified by
*            the particular differential equation
*         B) RR is the integrand
*            R*N(J)*N(K) on triangle I in step 4
*         C) FFF is the integrand F*N(J) on triangle I in step 4
*         D) GG1=G1*N(J)*N(K)
*            GG2=G2*N(J)
*            GG3=G2*N(K)
*            GG4=G1*N(J)*N(J)
*            GG5=G1*N(K)*N(K)
*            integrands in step 5
*         E) QQ(FF) computes the double integral of any
*            integrand FF over a triangle with vertices given by
*            nodes J1,J2,J3 - the method is an O(H**2) approximation
*            for triangles
*         F) SQ(PP) computes the line integral of any integrand PP
*            along the line from (XX(J1),YY(J1)) to (XX(J2),YY(J2))
*            by using a parameterization given by:
*            X=XX(J1)+(XX(J2)-XX(J1))*T
*            Y=YY(J1)+(YY(J2)-YY(J1))*T
*            for 0 <= t <= 1
*            and applying Simpson's composite method with H=.01
*
*      7. Arrays:
*         A) A,B,C are M by 3 arrays where the basis function N
*            for the Ith triangle, Jth vertex is
*            N(X,Y)=A(I,J)+B(I,J)*X+C(I,J)*Y
*            for J=1,2,3 and i=1,2,...,M
*         B) XX,YY are LM by 1 arrays to hold coordinates of nodes
*         C) line,LL,II,NV,NTR have been explained above
*         D) Gamma and Alpha are clear
*
*      8. Note that A,B,C,XX,YY,I,I1,I2,J1,J2,J3,Delta are reserved
*         storage so that in any subprogram we know that
*         triangle I has vertices (XX(J1),YY(J1)),(XX(J2),YY(J2)),
*         (XX(J3),YY(J3)). That is, vertex 1 is node J1, vertex 2 is
*         node J2, vertex 3 is node J3 unless a line integral is
*         involved in which case the line integral goes from node J1
*         to node J2 in triangle I or unless vertex I1 is node J1
*         and vertex I2 is node J2 - the basis functions involve
*         A(I,I1)+B(I,I1)*X+C(I,I1)**Y for vertex I1 in triangle I
*         and A(I,I2)+B(I,I2)*X+C(I,I2)*Y for vertex I2 in triangle I
*         delta is 1/2 the area of triangle I
*
*    To change problems:
*      1) change function subprograms P,Q,R,F,G,G1,G2
*      2) change data input for K,N,M,LN,LM,NL.
*      3) change data input for XX,YY,LLL,II,NV.
*      4) change data input for line.
*      5) change definition statements to read :
*         A(M,3),B(M,3),C(M,3),XX(LM),YY(LM)
*         definition LINE(NL,2),LL(LM),II(LM,MAX LL(LM)),
*              NV(LM,MAX LL(LM))
*         definition NTR(M,3),GAMMA(LM),ALPHA(LN,LN+1), use
*         the appropriate numbers for the variables M, LM,
*         NL.
*/

#include<stdio.h>
#include<math.h>
#define pi 4*atan(1)
#define true 1
#define false 0

double P(double, double);
double Q(double, double);
double R(double, double);
double F(double, double);
double G(double, double);
double G1(double, double);
double G2(double, double);
double RR(double, double, double [][3], double [][3], double [][3], int, int, int);
double FFF(double, double, double [][3], double [][3], double [][3],int, int);
double GG1(double, double, double [][3], double [][3], double [][3], int, int, int);
double GG2(double, double, double [][3], double [][3], double [][3], int, int);
double GG3(double, double, double [][3], double [][3], double [][3], int, int);
double GG4(double, double, double [][3], double [][3], double [][3], int, int);
double GG5(double, double, double [][3], double [][3], double [][3], int, int);
double QQ(int, double *, double *, double, int, int, int, int, int, double [][3], double [][3], double [][3]);
double SQ(int, double *, double *, int, int, int, int, int, double [][3], double [][3], double [][3]);
double absval(double);
void INPUT(int *, int *, int *, int *, int *, int *, int *, double *, double *, int *, int [][5], int [][5], int *, int *, int *, int [][3], int [][2]);
void OUTPUT(FILE **);

main()
{
   double A[10][3],B[10][3],C[10][3],XX[11],YY[11],GAMMA[11],ALPHA[5][6];
   double XJ,XJ1,CCC,XJ2,XI1,XI2,HH,ZZ,DELTA;
   int  II[11][5],NV[11][5],NTR[10][3],LL[11],LINE[5][2]; 
   int I,I1,I2,J1,J2,J3,K,N,M,LN1,LM,NL,KK,LLL,J,N1,N2,K1,L1,L,JJ1;
   int JI,JJ2,INN,OK;
   FILE *OUP[1];

   INPUT(&OK, &K, &N, &M, &LN1, &LM, &NL, XX, YY, &LLL, II, NV, LL, &N1, &N2, NTR, LINE);
   if (OK) {
      OUTPUT(OUP);
      K1 = K+1;
      N1 = LN1+1;
      fprintf(*OUP, "Vertices and Nodes of Triangles\n");
      fprintf(*OUP, "Trinagle-node number for vertex 1 to 3\n");
      for (I=1; I<=M; I++) {
	 fprintf(*OUP, " %5d", I);
	 for (J=1; J<=3; J++) fprintf(*OUP, " %4d", NTR[I-1][J-1]); 
	 fprintf(*OUP, "\n");
      }  
      fprintf(*OUP, "x and y coordinates of nodes\n");
      for (KK=1; KK<=LM; KK++) fprintf(*OUP, "%5d %11.8f %11.8f\n", KK, XX[KK-1], YY[KK-1]); 
      fprintf(*OUP, "Lines of the Domain\n");
      for (KK=1; KK<=NL; KK++) fprintf(*OUP, "%5d %4d %4d\n", KK, LINE[KK-1][0], LINE[KK-1][1]);
      /* STEP 1 */
      if (LM != LN1) 
	 for (L=N1; L<=LM; L++) GAMMA[L-1] = G(XX[L-1],YY[L-1]);
      /* STEP 2 - initialization of ALPHA - note that
	 ALPHA[I,LN1 + 1] = BETA[I] */
      for (I=1; I<=LN1; I++) 
	 for (J=1; J<=N1; J++) ALPHA[I-1][J-1] = 0.0;
      /* STEPS 3, 4, and 6 - 12 are within the next loop
	 for each triangle I let node J1 be vertex 1, node J2 be
	 vertex 2 and node J3 be vertex 3 */
      /* STEP 3 */
      for (I=1; I<=M; I++) {
	 J1 = NTR[I-1][0];
	 J2 = NTR[I-1][1];
	 J3 = NTR[I-1][2];
	 DELTA = XX[J2-1]*YY[J3-1]-XX[J3-1]*YY[J2-1]-XX[J1-1]*(YY[J3-1]-
		 YY[J2-1])+YY[J1-1]*(XX[J3-1]-XX[J2-1]);
	 A[I-1][0] = (XX[J2-1]*YY[J3-1]-YY[J2-1]*XX[J3-1])/DELTA;
	 B[I-1][0] = (YY[J2-1]-YY[J3-1])/DELTA;
	 C[I-1][0] = (XX[J3-1]-XX[J2-1])/DELTA;
	 A[I-1][1] = (XX[J3-1]*YY[J1-1]-YY[J3-1]*XX[J1-1])/DELTA;
	 B[I-1][1] = (YY[J3-1]-YY[J1-1])/DELTA;
	 C[I-1][1] = (XX[J1-1]-XX[J3-1])/DELTA;
	 A[I-1][2] = (XX[J1-1]*YY[J2-1]-YY[J1-1]*XX[J2-1])/DELTA;
	 B[I-1][2] = (YY[J1-1]-YY[J2-1])/DELTA;
	 C[I-1][2] = (XX[J2-1]-XX[J1-1])/DELTA;
	 /* STEP 4 */
	 /* I1 = J for STEP 4 and I1 = K for STEP 7 */
	 for (I1=1; I1<=3; I1++) {
	    /* STEP 8 */
	    JJ1 = NTR[I-1][I1-1];
	    /* I2 = K for STEP 4 and I2 = J for STEP 9 */
	    for (I2=1; I2<=I1; I2++) {
	       /* STEP 4 and STEP 10 */
	       JJ2 = NTR[I-1][I2-1];
	       ZZ = B[I-1][I1-1]*B[I-1][I2-1]*
		    QQ(1,XX,YY,DELTA,J1,J2,J3,I1,I2,A,B,C)+
		    C[I-1][I1-1]*C[I-1][I2-1]*
		    QQ(2,XX,YY,DELTA,J1,J2,J3,I1,I2,A,B,C)-
		    QQ(3,XX,YY,DELTA,J1,J2,J3,I1,I2,A,B,C);
	       /* STEPS 11 and 12 */
	       if (JJ1 <= LN1) {
		  if (JJ2 <= LN1) {
		     ALPHA[JJ1-1][JJ2-1] = ALPHA[JJ1-1][JJ2-1]+ZZ;
		     if (JJ1 != JJ2) 
			ALPHA[JJ2-1][JJ1-1] = ALPHA[JJ2-1][JJ1-1]+ZZ;
		  }     
		  else ALPHA[JJ1-1][N1-1] = ALPHA[JJ1-1][N1-1]-ZZ*GAMMA[JJ2-1];
	       }  
	       else
		  if (JJ2 <= LN1) ALPHA[JJ2-1][N1-1] = ALPHA[JJ2-1][N1-1]
						       -ZZ*GAMMA[JJ1-1];
	    }  
	    HH = -QQ(4,XX,YY,DELTA,J1,J2,J3,I1,I2,A,B,C);
	    if (JJ1 <= LN1) ALPHA[JJ1-1][N1-1] = ALPHA[JJ1-1][N1-1]+HH;
	 }  
      }  
      /* output the basis functions */
      fprintf(*OUP, "Basis Functions\n");
      fprintf(*OUP, "Triangle - Vertex - Node - Function\n");
      for (I=1; I<=M; I++) 
	 for (J=1; J<=3; J++)
	    fprintf(*OUP, "%4d %3d %3d %13.8f %13.8f %13.8f\n", I, J, NTR[I-1][J-1], A[I-1][J-1], B[I-1][J-1], C[I-1][J-1]);
      /* STEP 5 */
      /* for each line segment JI = 1,..., NL and for each
	 triangle I, I = K1,..., N which may contain line JI
	 search all 3 vertices for possible correspondences.
	 STEP 5 and STEPS 13 - 19 */
      if ((NL != 0) && (N != K)) 
	 for (JI=1; JI<=NL; JI++)
	    for (I=K1; I<=N; I++) 
	       for (I1=1; I1<=3; I1++) {
		  /* I1 = J in STEP 5 and I1 = K in STEP 14 */
		  /* STEP 15 */
		  J1 = NTR[I-1][I1-1];
		  if (LINE[JI-1][0] == J1) {
		     for (I2=1; I2<=3; I2++) {
			/* I2 = K in STEP 5 and I2 = J in STEP 16 */
			/* STEP 17 */
			J2 = NTR[I-1][I2-1];
			if (LINE[JI-1][1] == J2) {
			   /* There is a correspondence of
			      vertex I1 in triangle I with
			      node J1 as the start of line
			      JI and vertex I2 with node J2
			      as the end of line JI */
			   /* STEP 5 */
			   XJ = SQ(1,XX,YY,J1,J2,I,I1,I2,A,B,C);
			   XJ1 = SQ(4,XX,YY,J1,J2,I,I1,I2,A,B,C);
			   XJ2 = SQ(5,XX,YY,J1,J2,I,I1,I2,A,B,C);
			   XI1 = SQ(2,XX,YY,J1,J2,I,I1,I2,A,B,C);
			   XI2 = SQ(3,XX,YY,J1,J2,I,I1,I2,A,B,C);
			   /* STEPS 8 and 19 */
			   if (J1 <= LN1) 
			      if (J2 <= LN1) {
				 ALPHA[J1-1][J1-1] = ALPHA[J1-1][J1-1]+XJ1;
				 ALPHA[J1-1][J2-1] = ALPHA[J1-1][J2-1]+XJ;
				 ALPHA[J2-1][J2-1] = ALPHA[J2-1][J2-1]+XJ2;
				 ALPHA[J2-1][J1-1] = ALPHA[J2-1][J1-1]+XJ;
				 ALPHA[J1-1][N1-1] = ALPHA[J1-1][N1-1]+XI1;
				 ALPHA[J2-1][N1-1] = ALPHA[J2-1][N1-1]+XI2;
			      }  
			      else {
				 ALPHA[J1-1][N1-1] = ALPHA[J1-1][N1-1]-
						     XJ*GAMMA[J2-1]+XI1;
				 ALPHA[J1-1][J1-1] = ALPHA[J1-1][J1-1]+XJ1;
			      }  
			   else
			      if (J2 <= LN1) {
				 ALPHA[J2-1][N1-1] = ALPHA[J2-1][N1-1]-
						     XJ*GAMMA[J1-1]+XI2;
				 ALPHA[J2-1][J2-1] = ALPHA[J2-1][J2-1]+XJ2;
			      }  
			}
		     }
		  }
	       }
      /* output ALPHA */
      fprintf(*OUP, "Matrix ALPHA follows:\n");
      for (I=1; I<=LN1; I++) {
	 fprintf(*OUP, "Row %4d\n", I);
	 for (J=1; J<=N1; J++) 
	    fprintf(*OUP, " %13.10e\n ", ALPHA[I-1][J-1]);
      }  
      fprintf(*OUP, "\n");
      /* STEP 20 */
      if (LN1 > 1) {
	 INN = LN1-1;
	 for (I=1; I<=INN; I++) {
	    I1 = I+1;
	    for (J=I1; J<=LN1; J++) {
	       CCC = ALPHA[J-1][I-1]/ALPHA[I-1][I-1];
	       for (J1=I1; J1<=N1; J1++) 
		  ALPHA[J-1][J1-1] = ALPHA[J-1][J1-1]-CCC*ALPHA[I-1][J1-1];
	       ALPHA[J-1][I-1] = 0.0;
	    }  
	 }  
      }  
      GAMMA[LN1-1] = ALPHA[LN1-1][N1-1]/ALPHA[LN1-1][LN1-1];
      if (LN1 > 1) 
	 for (I=1; I<=INN; I++) {
	    J = LN1-I;
	    CCC = ALPHA[J-1][N1-1];
	    J1 = J+1;
	    for (KK=J1; KK<=LN1; KK++) 
	       CCC = CCC-ALPHA[J-1][KK-1]*GAMMA[KK-1];
	    GAMMA[J-1] = CCC/ALPHA[J-1][J-1];
	 }  
      /* STEP 21 */
      /* output gamma */
      fprintf(*OUP, "Coefficients of Basis Functions:\n");
      for (I=1; I<=LM; I++) {
	 LLL = LL[I-1];
	 fprintf(*OUP, "%3d %13.8f %d", I, GAMMA[I-1], I);
	 for (J=1; J<=LLL; J++) fprintf(*OUP, " %4d", II[I-1][J-1]);
	 fprintf(*OUP, "\n");
      }
      fclose(*OUP);
      /* STEP 23 */
   }
   return 0;
}

double P(double X, double Y)
{
   double p; 

   p =  1.0;
   return p;
}

double Q(double X, double Y)
{
   double q; 

   q =  1.0;
   return q;
}

double R(double X, double Y)
{
   double r; 

   r =  0.0;
   return r;
}

double F(double X, double Y)
{
   double f; 

   f =  0.0;
   return f;
}

double G(double X, double Y)
{
   double g; 

   g =  4.0;
   return g;
}

double G1(double X, double Y)
{
   double g1; 

   g1 =  0.0;
   return g1;
}

double G2(double X, double Y)
{
   double g2, T, Z1; 

   T = 1.0e-05;
   Z1 = 0.0;
   if ( ( (0.2-T) <= X) && (X <= (0.4+T)) && (absval(Y-0.2) <= T)) 
      Z1 = X;
   if ( ( (0.5-T) <= X) && (X <= (0.6+T)) && (absval(Y-0.1) <= T))
      Z1 = X;
   if ( ( -T <= Y) && (Y <= (0.1+T)) && (absval(X-0.6) <= T)) 
      Z1 = Y;
   if ( ( -T <= X) && (X <= (0.2+T)) && (absval(Y+X-0.4) <= T)) 
      Z1 = (X+Y)/sqrt(2.0);
   if ( (0.4 -T <= X) && (X <= (0.5+T)) && (absval(Y+X-0.6) <= T)) 
      Z1 = (X+Y)/sqrt(2.0);
   g2 = Z1;
   return g2;
}

double RR(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I1, int I2)
{
   double rr; 

   rr = R(X,Y)*(A[I-1][I1-1]+B[I-1][I1-1]*X+C[I-1][I1-1]*Y)*(A[I-1][I2-1]
	+B[I-1][I2-1]*X+C[I-1][I2-1]*Y);
   return rr;
}

double FFF(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I1)
{
   double fff; 

   fff = F(X,Y)*(A[I-1][I1-1]+B[I-1][I1-1]*X+C[I-1][I1-1]*Y);
   return fff;
}

double GG1(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I1, int I2)
{
   double gg1; 

   gg1 = G1(X,Y)*(A[I-1][I1-1]+B[I-1][I1-1]*X+C[I-1][I1-1]*Y)*(A[I-1][I2-1]
	 +B[I-1][I2-1]*X+C[I-1][I2-1]*Y);
   return gg1;
}

double GG2(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I1)
{
   double gg2; 

   gg2 = G2(X,Y)*(A[I-1][I1-1]+B[I-1][I1-1]*X+C[I-1][I1-1]*Y);  
   return gg2;
}

double GG3(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I2)
{
   double gg3; 

   gg3 = G2(X,Y)*(A[I-1][I2-1]+B[I-1][I2-1]*X+C[I-1][I2-1]*Y);
   return gg3;
}

double GG4(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I1)
{
   double gg4; 

   gg4 = G1(X,Y) * (A[I-1][I1-1]+B[I-1][I1-1]*X+C[I-1][I1-1]*Y) * (A[I-1][I1-1]
	 +B[I-1][I1-1]*X+C[I-1][I1-1]*Y);
   return gg4;
}

double GG5(double X, double Y, double A[][3], double B[][3], double C[][3], int I, int I2)
{
   double gg5; 

   gg5 = G1(X,Y) * (A[I-1][I2-1]+B[I-1][I2-1]*X+C[I-1][I2-1]*Y) * 
	 (A[I-1][I2-1]+B[I-1][I2-1]*X+C[I-1][I2-1]*Y);
   return gg5;
}

double QQ(int L, double *XX, double *YY, double DELTA, int J1, int J2, int J3, int I1, int I2, double A[][3], double B[][3], double C[][3])
{
   double X[7], Y[7], S[7];
   double qq,QQQ,T1,T2,T3; 
   int I;

   X[0] = XX[J1-1]; Y[0] = YY[J1-1];
   X[1] = XX[J2-1]; Y[1] = YY[J2-1];
   X[2] = XX[J3-1]; Y[2] = YY[J3-1];
   X[3] = 0.5*(X[0]+X[1]); Y[3] = 0.5*(Y[0]+Y[1]);
   X[4] = 0.5*(X[0]+X[2]); Y[4] = 0.5*(Y[0]+Y[2]);
   X[5] = 0.5*(X[1]+X[2]); Y[5] = 0.5*(Y[1]+Y[2]);
   X[6] = (X[0]+X[1]+X[2])/3.0; Y[6] = (Y[0]+Y[1]+Y[2])/3.0;
   switch (L) {
      case 1:
	 for (I=1; I<=7; I++) S[I-1] = P(X[I-1],Y[I-1]);
	 break;
      case 2:
	 for (I=1; I<=7; I++) S[I-1] = Q(X[I-1],Y[I-1]);
	 break;
      case 3:
	 for (I=1; I<=7; I++) S[I-1] = RR(X[I-1],Y[I-1],A,B,C,I,I1,I2);
	 break;
      case 4:
	 for (I=1; I<=7; I++) S[I-1] = FFF(X[I-1],Y[I-1],A,B,C,I,I1);
	 break;
   }
   T1 = 0.0;
   for (I=1; I<=3; I++)  T1 = T1 + S[I-1];
   T2 = 0.0;
   for (I=4; I<=6; I++) T2 = T2 + S[I-1];
   T3 = S[6];
   QQQ = 0.5*(T1/20.0 + 2.0*T2/15.0 + 9.0*T3/20.0)*absval(DELTA);
   qq = QQQ;
   return qq;
}

double SQ(int L, double *XX, double *YY, int J1, int J2, int I, int I1, int I2, double A[][3], double B[][3], double C[][3])
{
   double S[101];
   double sq,SSQ,X,T1,T2,X1,X2,Y1,Y2,H,Q1,Q2,Q3,T3; 
   int K;

   X1 = XX[J1-1];
   Y1 = YY[J1-1];
   X2 = XX[J2-1];
   Y2 = YY[J2-1];
   H = 0.01;
   T1 = X2-X1;
   T2 = Y2-Y1;
   T3 = sqrt(T1*T1+T2*T2);
   for (K=1; K<=101; K++) {
       X = (K-1.0)*H;
       switch (L) {
	  case 1:
	     S[K-1] = T3*GG1(T1*X+X1,T2*X+Y1,A,B,C,I,I1,I2);
	     break;
	  case 2:
	     S[K-1] = T3*GG2(T1*X+X1,T2*X+Y1,A,B,C,I,I1);
	     break;
	  case 3:
	     S[K-1] = T3*GG3(T1*X+X1,T2*X+Y1,A,B,C,I,I2);
	     break;
	  case 4:
	     S[K-1] = T3*GG4(T1*X+X1,T2*X+Y1,A,B,C,I,I1);
	     break;
	  case 5:
	     S[K-1] = T3*GG5(T1*X+X1,T2*X+Y1,A,B,C,I,I2);
	     break;
      }      
   }
   Q3 = S[0]+S[100];
   Q1 = 0.0;
   Q2 = S[99];
   for (K=1; K<=49; K++) {
      Q1 = Q1 + S[2*K];
      Q2 = Q2 + S[2*K-1];
   }
   SSQ = (Q3 + 2.0*Q1 + 4.0*Q2)*H/3.0;
   sq = SSQ;
   return sq;
}

void INPUT(int *OK, int *K, int *N, int *M, int *LN1, int *LM, int *NL, double *XX, double *YY, int *LLL, int II[][5], int NV[][5], int *LL, int *N1, int *N2, int NTR[][3], int LINE[][2])
{
   int KK, I, J;
   char AA;
   char NAME[30];
   FILE *INP;

   printf("This is the Finite Element Method.\n");
   *OK = false;
   printf("The input will be from a text file in the following form:\n");
   printf("K     N     M     n     m     nl\n\n");
   printf("Each of the above is an integer -");
   printf("separate with at least one blank.\n\n");
   printf("Follow with the input for each node in the form:\n");
   printf("x-coor., y-coord., number of triangles in which the");
   printf(" node is a vertex.\n\n");
   printf("Continue with the triangle number and vertex number for\n");
   printf("each triangle in which the node is a vertex.\n");
   printf("Separate each entry with at least one blank.\n\n");
   printf("After all nodes have been entered follow with information\n");
   printf("on the lines over which line integrals must be computed.\n");
   printf("The format of this data will be the node number of the\n");
   printf("starting node, followed by the node number of the ending\n");
   printf("node for each line, taken in the positive direction.\n");
   printf("There should be 2 * nl such entries, each an integer\n");
   printf("separated by a blank.\n\n");
   printf("Have the functions P,Q,R,F,G,G1,G2 been created and\n");
   printf("has the input file been created?  Answer Y or N.\n");
   scanf("\n%c", &AA);
   if ((AA == 'Y') || (AA == 'y')) {
      printf("Input the file name in the form - drive:name.ext\n");
      printf("for example:   A:DATA.DTA\n");
      scanf("%s", NAME);
      INP = fopen(NAME, "r");
      *OK = true;
      fscanf(INP, "%d %d %d %d %d %d", K, N, M, LN1, LM, NL);
      for (KK=1; KK<=*LM; KK++) {
	 fscanf(INP, "%lf %lf %d", &XX[KK-1], &YY[KK-1], LLL);
	 for (J=1; J<=*LLL; J++) fscanf(INP, "%d %d", &II[KK-1][J-1], &NV[KK-1][J-1]);
	 LL[KK-1] = *LLL;
	 for (J=1; J<=*LLL; J++) {
	    *N1 = II[KK-1][J-1];
	    *N2 = NV[KK-1][J-1];
	    NTR[*N1-1][*N2-1] = KK;
	 }  
      }  
      if (*NL > 0) {
	 for (I=1; I<=*NL; I++)
	    for (J=1; J<=2; J++) fscanf(INP, "%d", &LINE[I-1][J-1]);
      }  
      fclose(INP);
   }
   else printf("The program will end so that the input file can be created.\n");
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
      printf("for example:   A:OUTPUT.DTA\n");
      scanf("%s", NAME);
      *OUP = fopen(NAME, "w");
   }
   else *OUP = stdout;
   fprintf(*OUP, "FINITE ELEMENT METHOD\n\n\n");
}

/* Absolute Value Function */
double absval(double val)
{
   if (val >= 0) return val;
   else return -val;
}
