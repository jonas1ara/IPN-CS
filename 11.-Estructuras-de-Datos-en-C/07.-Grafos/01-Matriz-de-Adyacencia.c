#include <stdio.h>
#include <stdlib.h>
    
int main(int argc, char **argv)
{
    // n is the number of vertices
    // m is the number of edges
    int n, m;
    
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &n, &m);
    int adjMat[n + 1][n + 1];
    for (int i = 0; i < m; i++) {
        int u, v;
        printf("Enter the edge: ");
        scanf ("%d %d", &u, &v);
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
        // for a directed graph with an edge pointing from u to v,we just assign
        // adjMat[u][v] as 1
    }

    // print the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
   }

 
        
    return 0;
}