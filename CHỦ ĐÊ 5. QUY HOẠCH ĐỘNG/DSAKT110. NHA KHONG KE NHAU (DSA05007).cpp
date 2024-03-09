#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+2] = {0};
		for(int i=1;i<=n;i++) cin>>a[i];
		int f[n+2] = {0};
		f[0] = 0; f[1] = a[1];
		for(int i=2;i<=n;i++) f[i] = max(f[i-1], f[i-2] + a[i]);
		cout<<f[n]<<endl;
	}
}