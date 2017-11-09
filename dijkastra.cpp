#include<bits/stdc++.h>
using namespace std;
int min(int dist[],bool set[],int v)
{   int min_value=INT_MAX,min_index;
	for(int i=0;i<v;i++)
	{
		if(set[i]==false&&dist[i]<min_value)
		{
			min_value=dist[i];
			min_index=i;
		}
	}
	return min_index;
}
int main()
{  cout<<"Enter no of vertices and edge:";
   int v;
   cin>>v;
   int a[v][v]={0};
   for(int i=0;i<v;i++)
   for(int j=0;j<v;j++)
        a[i][j]=0;
   int e,src,dest,weight;
   cin>>e;
   cout<<"enter src dest weight of "<<e<<" edge:\n";
   for(int i=0;i<e;i++)
   {
       cin>>src>>dest>>weight;
	   a[src][dest]=weight;
	   a[dest][src]=weight; 	
   }
   int dist[v];
   bool set[v];
   for(int i=0;i<v;i++)
   {
       dist[i]=INT_MAX;
	   set[i]=false;   	
   }
   cout<<"Enter source vertices:";
   cin>>src;
   dist[src]=0;
   vector<int>path;
   for(int i=0;i<v-1;i++)
   {
   	    int u=min(dist,set,v);
		set[u]=true;
		path.push_back(u);
	    for(int j=0;j<v;j++)
		{
			if(set[j]==false&&a[u][j]&&dist[u]<INT_MAX&&dist[u]+a[u][j]<dist[j])
			    dist[j]=dist[u]+a[u][j];
	    }	 
   }
   path.push_back(min(dist,set,v));
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < v; i++)
        if(dist[i]!=INT_MAX)
            printf("%d \t\t %d\n", +i, dist[i]);
        else
            printf("%d \t\tNot rechable\n",i);
    cout<<"path vector with source:"<<src<<endl;
    for(int i=0;i<v;i++)
	cout<<path[i]<<" ";
	return 0;		          
}

