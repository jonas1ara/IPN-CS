//C Program to Simulate KnapSack Problem
// Code by Nived Kannada 
#include<stdio.h>

void main ()
{
  int n, m, w[100], p[100], ratio[100] , i, j, u, temp;
  float xr, x[100], total_profit=0, total_weight=0;

  //Reading number of items
  printf ("Enter the number of items(n): ");
  scanf ("%d", &n);

  //Reading the capacity of the knapsack 
  printf ("Enter the capacity of the Knapsack(m): ");
  scanf ("%d", &m);

  //Initializing remaining capacity of Knapsack (u)
  u = m;
  
  //Initializing Solution Array x[]
  for(i=0;i<n;i++)
  {
      x[i]=0;
  }

  //Reading the Weights
  printf ("Enter the Weights of items: ");
  for (i = 0; i < n; i++)
    {
      printf ("\n\tWeight of item %d = ", i + 1);
      scanf ("%d", &w[i]);
    }

  //Reading the Profit values
  printf ("\nEnter the Profit Values of items: ");
  for (i = 0; i < n; i++)
    {
      printf ("\n\tProfit of item %d = ", i + 1);
      scanf ("%d", &p[i]);
    }

  //Calculating Pi/Wi ratio of each item and storing in array ratio[]
  for (i = 0; i < n; i++)
    {
      ratio[i] = p[i] / w[i];
    }

  //Sorting all the arrays based on the ratio in descending order
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n - 1; j++)
	{
	  if (ratio[j] < ratio[i])
	    {
	      temp = ratio[i];
	      ratio[i] = ratio[j];
	      ratio[j] = temp;
	      
	      temp = w[i];
	      w[i] = w[j];
	      w[j] = temp;
	      
	      temp = p[i];
	      p[i] = p[j];
	      p[j] = temp;
	    }
	}
    }
    
    //PRINTING THE SORTED TABLE 
    printf("\n The Table After Sorting based on the Ratio: \n");
    
    //Printing Item numbers 
    printf("\nItem:\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",i+1);
    }
    
    //Printing Profit Array 
    printf("\nProfit:\t\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",p[i]);
    }
    
    //Printing Weight Array 
    printf("\nWeights:\t");
    for(i=0;i<n;i++)
    {
        printf("%d\t",w[i]);
    }


    //Printing RATIO Array 
    printf ("\nRATIO:\t\t"); 
    for (i = 0; i < n; i++)
    {
      printf ("%d\t", ratio[i]);
    }
    
    //Calculating Solution Array x
    for(i=0;i<n;i++)
    {
        if(w[i]<=u)
        {
            x[i]=1;     //Setting solution index as 1 
            u=u-w[i];   //updating remaining knapsack capacity 
        }
        else if(w[i]>u)
        {
            break;
        }
    }
    
    if(i<=n)
    {
        xr = (float)u/w[i];    //Calculating what fraction of that item will fit into the knapsack
        x[i] = xr;      //Setting this fraction to solution array 
    }
    
    //Printing Solution Array x 
    printf("\n X = [");
    for(i=0;i<n;i++)
    {
        printf("%.3f , ",x[i]);
    }
    printf("]");
    
    //Calculating Total Profit & Total Weight 
    for(i=0;i<n;i++)
    {
        total_profit += x[i]*p[i];
        total_weight += x[i]*w[i];
    }
    
    //Displaying Total Profit and Total Weight 
    printf("\nTotal Profit = %.2f \n Total Weight = %.2f ",total_profit,total_weight);


}

//End of Code 
//Code by Nived Kannada 