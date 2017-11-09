#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int m[105][105];
void dfs(vector<bool>& visited, int s)  {
visited[s]=1;
int n=visited.size();
char c= 'A'+s;
cout<<c<<" ";
for(int i=0;i<n;i++)  {
if(m[s][i]&& !visited[i])
dfs(visited,i);
}
}
int main()  {
int v,e,i;
char x,y;
cin>>v>>e;
for(i=0;i<e;i++)  {
cin>>x>>y;m[x-'A'][y-'A']=1;
}
vector<bool> visited(v,0);
char src;
cin>>src;
dfs(visited,src-'A');
for(i=0;i<v;i++)  {
       if(!visited[i]){dfs(visited,i);
        }
}
return 0;
}

