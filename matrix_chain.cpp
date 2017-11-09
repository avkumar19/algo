#include<bits/stdc++.h>
using namespace std;

void print(int arr[100][100], int i, int j){
	if(i == j)
		cout<< "A" << i;
	else{
		cout << "(";
		print(arr,i,arr[i][j]);
		print(arr,arr[i][j] + 1,j);
		cout << ")";
	}	
}
int main(){
	int arr[100];   //to store size of matrix
	int m[100][100];// dp
	int s[100][100]; 
int i,j,n,p;
	while(1){
cout << "Enter the num of matrix + 1" << endl;
cin>>n;//no of matries -1
if(n==0)// breaking condition 
return 0;
	for(i=0;i<n;i++)
	cin>>arr[i];
	for(i=0;i<n;i++)
	m[i][i]=0;//product of matrix it self is zero 
	for(int len=2;len<n;len++){
	    for(i=1;i<n-len+1;i++){j=i+len-1;m[i][j]=INT_MAX;
	       for(int k=i;k<j;k++){		
		p=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
		    if(p<m[i][j]){
				m[i][j]=p;
				s[i][j] = k;
		}    }	}
}
cout<<m[1][n-1] << endl;
print(s,1,n - 1);	
}
}


