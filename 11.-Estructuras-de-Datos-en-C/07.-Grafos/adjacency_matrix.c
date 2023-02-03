#include<stdio.h>
int no_vertices;
void printGraph(int adj[][no_vertices])
{
	for(int i=0;i<no_vertices;i++)
	{
		for(int j =0;j<no_vertices;j++)
		{
			printf(" %d  ",adj[i][j]);
		}
		printf("\n");
	}

}
void dfs(int adj[][no_vertices],int visited[], int start)
{
	printf("%d\t",start);
	visited[start] =1;
	for(int i=0;i<no_vertices;i++)
	{
		if(visited[i]!=1 && adj[start][i]==1)
		{
			dfs(adj,visited,i);
		}
	}	
}
void bfs(int adj[][no_vertices], int start)
{
	int visited[no_vertices],queue[no_vertices],front=-1,rear=-1;

	for(int i=0;i<no_vertices;i++)
		visited[i] =0;

	front++;
	queue[++rear] = start;
	visited[start] = 1;

	while(front<=rear)
	{
		start = queue[front++];
		printf("%d\t",start);

		for(int i=0;i<no_vertices;i++)
		{
			if(adj[start][i]==1 && visited[i] != 1)
			{
				queue[++rear] = i;
				visited[i] =1;
			}
		}


	}

}
int main()
{	
	int s,d,ch,start;
	printf("\nEnter the number of vertices : ");
	scanf("%d",&no_vertices);
	int adj[no_vertices][no_vertices],visited[no_vertices];
	

	for(int i =0;i<no_vertices;i++)
		for(int j=0;j<no_vertices;j++)
			adj[i][j] =0;

	while(s!=-1 && d!=-1)
	{
	printf("Enter an Edge fromnode(0 to %d) to node(0 to %d) : ",no_vertices,no_vertices);
	scanf("%d%d",&s,&d);
	adj[s][d] = 1;
	adj[d][s] = 1;
	}

	do
	{
		printf("\nEnter 1 for BFS\nEnter 2 for DFS\nEnter 3 for printing adjacency matrix\nEnter 4 to Exit : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Vertex fron which do you wanted to start : ");
				scanf("%d",&start);
				bfs(adj,start);break;
			case 2:
				printf("Enter the Vertex fron which do you wanted to start : ");
				scanf("%d",&start);
				for(int i =0;i<no_vertices;i++)
					visited[i] = 0;
				dfs(adj,visited, start);break;

			break;
			case 3:printGraph(adj);break;
			case 4: break;
		}

	}while(ch != 4);

	return 0;
}
