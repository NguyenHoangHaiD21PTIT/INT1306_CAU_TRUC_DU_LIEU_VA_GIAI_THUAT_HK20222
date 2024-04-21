#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if((int)log2(i)+1- __builtin_popcount(i)==k) cnt++;
		}
		if(k==1) cnt++;
		cout<<cnt<<endl;
	}
}
