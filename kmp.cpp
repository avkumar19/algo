#include<bits/stdc++.h>
using namespace std;
vector<int> compute_lps(string pat)
{
	int l=pat.length();
	vector<int>v(l,0);
	int i=1,j=0;
	v[0]=0;
	while(i<l)
	{
		if(pat[i]==pat[j])
		{
			v[i]=j+1;
			i++;j++;
		}
		else 
		{
			if(j!=0)
			  j=v[j-1];
			  else
			  {
			  	v[i]=0;i++;
			  }
		}
	}
	return v;
}
void kmp_matching(string pat,string text,vector<int>lps)
{  
	int l=text.length();
	int m=pat.length();
	int i=0,j=0;
	while(i<l)
	{  
		if(pat[j]==text[i])
		{
			i++;j++;
		}
		if(j==m)
		   {  
		   	cout<<"match found at index:"<<i-j<<endl;
		   	j=lps[j-1];
		   }
		else if(i<l&&pat[j]!=text[i])
		{
			if(j!=0)
			j=lps[j-1];
			else
			i++;
		   }   
	}
}
int main()
{
	string pat,text;
	cout<<"text:";
	cin>>text;
	cout<<"pat:";
	cin>>pat;
	vector<int>lps;
	lps=compute_lps(pat);
	kmp_matching(pat,text,lps);
}
