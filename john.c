#include<stdio.h>
int n;

int NextMinimum(int u,int D[n][n],int C[n])
{
	int min,min_val,i;
	min = -1;
	min_val = 9999;
	for(i=0;i<n;i++)
		if(C[i] == 0 && D[u][i] < min_val)
		{
			min = i;
			min_val = D[u][i];
		}
	return min;
}

void Dijkstra(int G[n+1][n+1],int u,int D[n][n],int P[n][n])
{
	int C[n], i,j,v,w;
	for(i=0;i<n;i++)
	{
		C[i] = 0;
		P[u][i] = -1;
		D[u][i] = 9999;
	}
	D[u][u] = 0;
	v = u;
	while(v != -1)
	{
		for(i=0;i<n;i++)
		{
			if(C[i] == 0)
			{
				w = G[v][i]+D[u][v];
				if(w < D[u][i])
				{
					D[u][i] = w;
					P[u][i] = v;
				}
			}
		}
		C[v] = 1;
		v = NextMinimum(u,D,C);
	}
}


int BellmanFord(int G[n+1][n+1],int u,int h[n])
{
	int D[n+1], i,j,k,w;
	for(i=0;i<=n;i++)
		D[i] = 9999;
	D[u] = 0;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			for(k=0;k<=n;k++)
				if(D[j]+G[j][k] < D[k])
					D[k] = D[j] + G[j][k];
	for(j=0;j<=n;j++)
		for(k=0;k<=n;k++)
			w = D[j] + G[j][k];
			if(D[j]+G[j][k] < D[k])
				return 0;
	for(i=0;i<n;i++)
		h[i] = D[i];
	return 1;
}

void Johnson(int G[n+1][n+1])
{
	int i,j,k,h[n],d[n][n],p[n][n];
	k = BellmanFord(G,n,h);
	if(k==0)
		printf("\nNegative egde present.");
	else
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(G[i][j]!=9999 && i!=j)
					G[i][j] += h[i] - h[j];
		for(i=0;i<n;i++)
			Dijkstra(G,i,d,p);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i!=j && d[i][j]!=9999)
					d[i][j] += h[j] - h[i];
	}
	printf("\nResultant Shortest Path Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(d[i][j] == 9999)
				printf("-\t");
			else
				printf("%2d\t",d[i][j]);
		}
		printf("\n");
	}
	
	printf("\nResultant Path:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(i==j || p[i][j]==-1)
				printf("-\t");
			else
				printf("%2d\t",p[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	int e,i,j,u,v,w,k;
	printf("\nNo. of vertices >> ");
	scanf("%d",&n);
	int G[n+1][n+1];
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			G[i][j] = 9999;
	for(i=0;i<=n;i++)
		G[i][i] = 0;
	for(i=0;i<=n;i++)
		G[n][i] = 0;
	printf("\nNo. of edges >> ");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("\nEdge %d: ",i+1);
		scanf("%d %d %d",&u,&v,&w);
		G[u][v] = w;
	}
	Johnson(G);
	printf("\n");
	return 0;
}
