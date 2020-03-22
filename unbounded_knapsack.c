#include<stdio.h>
#include<stdlib.h>


int bag[100][100];
int KS(int,int,int*,int*,int*);
int max(int a,int b)
{
	return a>b?a:b;
}



int main()
{
	int n,w,*val,*wt,*K;
	printf("Enter capacity of knapsack:\n");
	scanf("%d", &w);
	printf("enter the number of elements:\n");
	scanf("%d", &n);
	val = (int*)malloc(n*sizeof(int));
	wt = (int*)malloc(n*sizeof(int));
	K = (int*)malloc(w*sizeof(int));
	printf("Enter the weights of elements:\n");
	for(int i = 0 ;i < n ;i++)
		scanf("%d", wt+i);
	printf("Enter the values of elements:\n");
	for(int i = 0 ;i < n ;i++)
		scanf("%d", val+i);
	
	printf("\n\nMaximum value of the Knapsack: %d\n",KS(w,n,wt,val,K));
	printf("Knapsack contains:\n");
	for(int i=1;i<=bag[w][0];i++)
		printf("%d ",bag[w][i]);
	printf("\n");
	
}
int KS(int w,int n,int* wt,int* val,int* K)
{
	int p;
	K[0]=0;
	for(int i = 1 ;i <= w ;i++)
	{
		int t=1;
		K[i]=0;
		for( int j = 0;j < n; j++)
		{
			if(wt[j] <= i)
			{
				int new = K[i-wt[j]]+val[j];
				if(K[i] < new )
				{
					K[i] = new;
					for(p=1; p<=bag[i-wt[j]][0]; p++)
					{
						bag[i][p] = bag[i-wt[j]][p];
						
					}
					bag[i][p]=j+1;
					bag[i][0]=bag[i-wt[j]][0]+1;
				}
			}
		}
	}
	return K[w];
}









