#include<bits/stdc++.h>
using namespace std;
void swap1(float *a,float *b)
{
	float temp=*a;
	*a=*b;
	*b=temp;
}
void swap2(int*a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(vector<vector<float> >v)
{
  int n=v.size();
  for(int i=0;i<n;i++)
  {
  	 for(int j=0;j<n;j++)
 	 	printf("%.3f\t",v[i][j]);
 	 	
 	 cout<<endl;
  }
}
void LUP_DCMP(vector<vector<float> >&v,vector<int>&pi)
{    //cout<<"a";
    int n=v.size(),i,j,k,k1;
    float p;
    for(i=0;i<n;i++)
     pi[i]=i;
    for( k=0;k<n;k++)
    {  
    	 p=0;
    	for(i=k;i<n;i++)
    	  {
    	  		if(abs(v[i][k])>p)
    	  		{
    	  			p=abs(v[i][k]);
    	  			k1=i;
    	  		}
    	  }
    	 // cout<<p<<endl;
    	  if(p==0)
    	    return;
    	  swap2(&pi[k],&pi[k1]);
    	   for(i=0;i<n;i++)
    	   {
    	   		swap1(&v[k][i],&v[k1][i]);
    	   } 
    	   for(i=k+1;i<n;i++)
    	   {    if(v[k][k]!=0)
    	   		v[i][k]=v[i][k]/v[k][k];
    	   		for(j=k+1;j<n;j++)
    	   		 v[i][j]=v[i][j]-v[i][k]*v[k][j];
    	   }
    	  
    }
    
}
void decompose(vector<vector<float> >v)
{
	cout<<"lower triangular matrix:\n";
	int n=v.size();
	for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	  {
		if(i==j)
			printf("1.00\t ");
		else if(i>j)
		printf("%.3f\t",v[i][j]);
		else
		printf("0.00\t");
	  }
	   cout<<endl;
	}
	cout<<"upper triangular matrix:\n";
	for(int i=0;i<n;i++)
	{
    	for(int j=0;j<n;j++)
	  {
	   if(i<=j)
		printf("%.3f\t",v[i][j]);
		else
		printf("0.00\t");
	  }
	  cout<<endl;
	}
}

int main ()
{
  int n;
  cin>>n;
  vector<vector<float> >v(n,vector<float>(n,0));
  vector<int>pi(n);
  for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  cin>>v[i][j];
  cout<<"INPUT MATRIX:\n";
  print(v); 
  //cout<<"a\n";
  LUP_DCMP(v,pi);
  cout<<"OUTPUT LU MATRIX:\n";
   print(v);
   decompose(v); 
   
}
