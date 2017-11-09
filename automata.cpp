#include<bits/stdc++.h>
using namespace std;
#define n 250
void computeTransFun(string pat, int M, vector<vector<int> >&TF)
{
    int i, lps = 0, x;
    for (x =0; x < n; x++)
       TF[0][x] = 0;
    TF[0][pat[0]-'a'] = 1;
    for (i = 1; i<= M; i++)
    {
        for (x = 0; x < n; x++)
            TF[i][x] = TF[lps][x];
        TF[i][pat[i]-'a'] = i + 1;
        if (i < M)
          lps = TF[lps][pat[i]-'a'];
    }
}
void print_transition(string pat, int M, vector<vector<int> >&TF)
{    set<int>s;
     for(int i=0;i<M;i++)
       s.insert(pat[i]);
       set<int>::iterator it;
	for(int i=0;i<M;i++)
	{
		cout<<"q"<<i<<":";
		it=s.begin();
		while(it!=s.end())
		{
			char p=*it;
			cout<<TF[i][p-'a']<<" ";
			it++;
		}
		cout<<endl;
	}
	  
}
void automata_match(string pat, string txt)
{
    int M = pat.length();
    int N =txt.length();
 	 vector<vector<int> >TF(M+1,vector<int>(n));
    computeTransFun(pat, M, TF);
    	print_transition(pat,M,TF);
    int i, j=0;
    for (i = 0; i < N; i++)
    {
       j = TF[j][txt[i]-'a'];
       if (j == M)
       {
         cout<<"pattern found with shift:"<< i-M+1<<endl;
       }
    }
}
int main()
{
	cout<<"text:";
	string t,p;
	cin>>t;
	cout<<"pattern:";
	cin>>p;
	automata_match(p,t);
}
