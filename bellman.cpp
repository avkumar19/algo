#include<bits/stdc++.h>
using namespace std;
#define M 99999
void relax(int u,int v, vector<int>&path,vector<int>&dist,vector<vector<int> >w)
{
     if(dist[v]>dist[u]+w[u][v])
     {
          dist[v]=dist[u]+w[u][v];
          path[v]=u;
     }
     return;
}
void print(vector<vector<int> >w)
{
  int s=w.size();
  for(int i=0;i<s;i++)
  {
   		for(int j=0;j<s;j++)
   			cout<<w[i][j]<<"\t";
   	    cout<<endl;
   }		
}
bool bellford(vector<vector<int> >w,vector<int>&path,vector<int>&dist)
{   int n=dist.size();
    for(int i=0;i<n-1;i++)
    {
    	for(int u=0;u<n;u++)
    	{
    		for(int v=0;v<n;v++)
    		{  if(w[u][v]!=M)
    		   relax(u,v,path,dist,w);
    		}
    	}
    
    }
    	for(int u=0;u<n;u++)
    	{
    		for(int v=0;v<n;v++)
    		{
    		    if(dist[v]>dist[u]+w[u][v])
     			{
         			return false;
                }
    		}
    	}
    return true;
}
void print_path(vector<int>path)
{ cout<<"path:"<<endl;
 int s=path.size();
 for(int i=0;i<s;i++)
 cout<<path[i]<<" ";
 cout<<endl;
}
void print_dist(vector<int>dist)
{ cout<<"distance:"<<endl;
  int s=dist.size();
  for(int i=0;i<s;i++)
    cout<<dist[i]<<" ";
   cout<<endl; 
}
int main()
{
	int n,e;
	cout<<"enter no of vertices:";
	cin>>n;
	cout<<"enter no of edges:";
	cin>>e;
	vector<vector<int> >w(n,vector<int>(n,M));
	cout<<"enter src dest weight:"<<endl;
	for(int i=0;i<e;i++)
	{
		int s,d,wt;
		cin>>s>>d>>wt;
		w[s][d]=wt;
	}
    vector<int>path(n,-1);
    vector<int>dist(n,M);
    cout<<"enter source:";
    int src;
    cin>>src;
    dist[src]=0;
    path[src]=src;
    cout<<" cost matrix:"<<endl;
    print(w);
    if(bellford(w,path,dist))
    {
    	print_dist(dist);
    	print_path(path);
    }
    else
    {
        cout<<"negetive edge cycle found!"<<endl;
    }
    
}
