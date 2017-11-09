#include<bits/stdc++.h>
using namespace std;
#define MAX 99999
void print_path(vector<vector<int> >path,int src,int dest)
{  if(path[src][dest]==0)
   {
    	 cout<<"no path exist"<<endl;
    	 return;
	}
	stack<int>s;
	while(path[src][dest]!=src)
	{
		 s.push(dest);
		 dest=path[src][dest];
	}
	s.push(dest);
	s.push(src);
	while(!s.empty())
	{
		 cout<<s.top()<<"->";
		 s.pop();
	}
	cout<<endl;
}
void print(vector<vector<int> >cost)
{
   int n=cost.size();
   for(int i=1;i<n;i++)
   {
  	    for(int j=1;j<n;j++)
  	    {
  		    if(cost[i][j]<MAX)
  		        cout<<cost[i][j]<<"\t";
  		    else
  		        cout<<"INF\t";  
  	    }
  	    cout<<endl;
  }
}
void floyd(vector<vector<int> >&cost,vector<vector<int> >&path)
{
    int n=cost.size();
    for(int k=1;k<n;k++)
    {
    	for(int i=1;i<n;i++)
    	{
    	    for(int j=1;j<n;j++)
    	    { 
			    if(cost[i][j]>cost[i][k]+cost[k][j])
    	            path[i][j]=path[k][j];
    	        cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
    	    }
    	}
    }
}

int main(){
  int no_ver;
  cout<<"enter no of vertices:";
  cin>>no_ver;
  cout<<"enter no of edges:";
  int no_edge;
  cin>>no_edge;
  vector<vector<int> >cost(no_ver+1,vector<int>(no_ver+1,MAX)),path(no_ver+1,vector<int>(no_ver+1,0));
   for(int i=0;i<no_edge;i++)
   {
        int s,d,w;
        cin>>s>>d>>w;
        cost[s][d]=w;
        path[s][d]=s;
        cost[s][s]=cost[d][d]=0;
   }
  cout<<"cost_matrix"<<endl;
  print(cost);
  floyd(cost,path);
  cout<<endl<<"shortest distance"<<endl;
  print(cost);
  cout<<endl<<"path matrix"<<endl;
  print(path);
  cout<<"enter src and dest to find path:";
  int src,dest;
  cin>>src>>dest;
  print_path(path,src,dest);
  
}

