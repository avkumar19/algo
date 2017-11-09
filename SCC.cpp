#include<bits/stdc++.h>
using namespace std;
//to store topological ordering
stack<int>st;

//to store component
vector<int>comp;
int s=1;
//depth first search
void dfs(vector<vector<int> >g,vector<bool>&isvisit,int v)
{
   isvisit[v]=true;
   for(int i=0;i<g[v].size();i++)
   {
      if(isvisit[g[v][i]]==false)
       dfs(g,isvisit,g[v][i]); 
          
   }
   if(s)
   st.push(v);
   else
   comp.push_back(v);
   
}
void print(vector<int>vx)
{
   for(int i=0;i<vx.size();i++)
         cout<<vx[i]<<" ";
         cout<<endl;
}
int main(){
    cout<<"enter no of vertices:";
    int n;
    cin>>n;
    vector<vector<int> >v(n),vt(n);
    cout<<"no of edges:";
    int e;
    cin>>e;
    cout<<"src dest:\n";
    //take input to graph v
    for(int i=0;i<e;i++)
     {
         int s,d;
           cin>>s>>d;
           v[s].push_back(d);
           vt[d].push_back(s);
     }

     vector<bool>isvisit(n,false),isvisit2(n,false);
     
     //calling dfs for graph v
     for(int i=0;i<n;i++)
         if(isvisit[i]==false)
             dfs(v,isvisit,i);
             s=0;
       //printing strongly connected component
       int p=1;
       while(!st.empty())
       {
       	   int r=st.top();
       	   if(isvisit2[r]==false)
       	   {
       	      comp.clear();
       	      dfs(vt,isvisit2,r);
       	      cout<<"component"<<p<<":";
       	      print(comp);
       	   }
       	   st.pop();
       }       
             
 
}
