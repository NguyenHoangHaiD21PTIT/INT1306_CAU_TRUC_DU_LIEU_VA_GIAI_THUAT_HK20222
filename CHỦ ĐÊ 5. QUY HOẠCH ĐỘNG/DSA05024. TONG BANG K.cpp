#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin>>n>>s;
		int a[n];
		for(int i = 0;i<n;i++) cin>>a[i];
		long long f[s+1] = {0}; f[0] = 1;
		for(int i=1;i<=s;i++){
			for(int j=0;j<n;j++){
				if(i>=a[j]){
					f[i]+=f[i-a[j]];
					f[i]%=(int)1e9+7;
				}
			}
		}
		cout<<f[s]<<endl;
	}
}