#include<stdio.h>
#include<stdlib.h>

int bag[100][100][100];
int KS(int,int,int*,int*,int**);

int main()
{
	int n,w,*val,*wt,**K;
	printf("Enter capacity of knapsack:\n");
	scanf("%d", &w);
	printf("enter the number of element:\n");
	scanf("%d", &n);
	val = (int*)malloc(n*sizeof(int));
	wt = (int*)malloc(n*sizeof(int));

	K = (int**)malloc((w+1)*sizeof(int*));
	for(int i=0 ;i<=w ; i++)
		K[i] = (int*)malloc((n+1)*sizeof(int));
	printf("Enter the weights of elements:\n");
	for(int i = 0 ;i < n ;i++)
		scanf("%d", wt+i);
	printf("Enter the values of elements:\n");
	for(int i = 0 ;i < n ;i++)
		scanf("%d", val+i);
	
	printf("Max value of the Knapsack: %d\n",KS(w,n,wt,val,K));
	printf("\nKnapsack contains:\n");
	for(int i=1;i<=bag[w][n][0];i++)
		printf("%d ",bag[w][n][i]);
	printf("\n");
}


int KS(int w,int n,int* wt,int* val,int** K)
{
	int p;
	for(int i=0;i<=w;i++)
		K[i][0] = 0;
	for(int i=0;i<=n;i++)
		K[0][i] = 0;
	for(int i=1;i<=w;i++)
		for(int j=1;j<=n;j++)
		{
			K[i][j] = K[i][j-1];
			for(p=0; p<= bag[i][j-1][0]; p++)
				bag[i][j][p] = bag[i][j-1][p];
			if(wt[j-1] <= i)
			{
				int new = K[i-wt[j-1]][j-1] + val[j-1];
				if(K[i][j] < new)
				{
					K[i][j] = new;
					for(p=1; p<= bag[i-wt[j-1]][j-1][0]; p++)
						bag[i][j][p] = bag[i-wt[j-1]][j-1][p];
					bag[i][j][p] = j;
					bag[i][j][0] = bag[i-wt[j-1]][j-1][0] + 1;
				}
			}
		}
	return K[w][n];
}






















