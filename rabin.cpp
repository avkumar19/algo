#include<bits/stdc++.h>
using namespace std;
#define d 10
void rabin_karp_match(string pat, string txt, int q)
{
    int M = pat.length();
    int N =txt.length();
    int i, j;
    int p = 0,t=0,h=1; 
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }
    for (i = 0; i <= N - M; i++)
    {
        if ( p == t )
        {
 			if(txt.substr(i+j,M)==pat)
                cout<<"Pattern found at index:"<< i<<endl;
        }

        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            if (t < 0)
            t = (t + q);
        }
    }
}
int main()
{   cout<<"text:";
	string t,p;
	cin>>t;
	cout<<"pattern:";
	cin>>p;
	int q=113;
	rabin_karp_match(p,t,q);
}
