#include<iostream>
using namespace std;
int rep_sqr(int a,int b,int m)
{
	int n=b;
	int cnt=0;
	while(n)
	{
		n=n>>1;
		cnt++;
	}
	//cout<<cnt<<endl;
	int z=1;
	for(int i=cnt-1;i>=0;i--)
	  {
	  	z=(z*z)%m;
	  	if(b&(1<<i))
	  	   z=(z*a)%m;
	  }
	  return z;
}
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	cout<<rep_sqr(a,b,c);
}
