#include<bits/stdc++.h>
using namespace std;
#define M 99999

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

void print_path(vector<int>path)
{ cout<<"path:"<<endl;
 int s=path.size();
 for(int i=0;i<s;i++)
 cout<<path[i]<<" ";
 cout<<endl;
}
int main()
{
	int n,e;
	cout<<"enter no of vertices:";
	cin>>n;
	cout<<"enter no of edges:";
	cin>>e;
	vector<vector<int> >w(n,vector<int>(n,0));
	cout<<"enter src dest weight:"<<endl;
	for(int i=0;i<e;i++)
	{
		int s,d;
		cin>>s>>d;
		w[s][d]=1;
	}
	    //cout<<" cost matrix:"<<endl;
    		//print(w);
   vector<vector<int> >path(n,vector<int>(n));
   for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
       if(i==j||w[i][j])
          path[i][j]=1;
        else
          path[i][j]=0;
   for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
   {
   		path[i][j]=(path[i][j])||(path[i][k]&&path[k][j]);
   }       
      print(path);
}
