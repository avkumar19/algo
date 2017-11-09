#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cout<<"no of stages\n";
scanf("%d",&n);
int time[2][n+4];//0 1st line 1 2nd line
int e1,e2,x1,x2;
int shift[2][n+4];
int dp[2][n+4];
int path[n+3];
cout<<"entry time e1 and e2\n";cin>>e1>>e2;cout<<"time for line 1\n";
for(int i=0;i<n;i++)
cin>>time[0][i];cout<<"time for line 2\n";
for(int i=0;i<n;i++)
cin>>time[1][i];cout<<"time for shift line 1to 2\n";
for(int i=0;i<n-1;i++)
cin>>shift[0][i];cout<<"time for shift line 2to 1\n";
for(int i=0;i<n-1;i++)
cin>>shift[1][i];cout<<"exit time x1,x2\n";
cin>>x1>>x2;
dp[0][0]=e1+time[0][0];
dp[1][0]=e2+time[1][0];
// optimal sub problem
for(int i=1;i<n;i++)
{if(dp[0][i-1]<=dp[1][i-1]+shift[1][i-1]){
dp[0][i]= dp[0][i-1]+time[0][i];
}else
{dp[0][i]= dp[1][i-1]+time[0][i]+shift[1][i-1];
}
if(dp[1][i-1]<=dp[0][i-1]+shift[0][i-1]){
dp[1][i]= dp[1][i-1]+time[1][i];
}
else {
dp[1][i]= dp[0][i-1]+time[1][i]+shift[0][i-1];
}
}
dp[0][n-1]+=x1;
dp[1][n-1]+=x2;
// for path
int m=min(dp[0][n-1],dp[1][n-1]);
if(dp[0][n-1]>dp[1][n-1])
path[n-1]=2;
else
path[n-1]=1;
dp[0][n-1]-=x1;
dp[1][n-1]-=x2;
for(int i=n-2;i>=0;i--){
if(path[i+1]==1){
if(dp[0][i]==dp[0][i+1]-time[0][i+1])
path[i]=1;
else
path[i]=2;
}
else if (dp[1][i]==dp[1][i+1]-time[1][i+1])
path[i]=2;	                    
else
path[i]=1;
}
cout<<"minimum time ="<<m<<endl;
cout<<"optimal path"<<"::";
for(int i=0;i<n;i++)
cout<<path[i];
cout<<endl;
}

