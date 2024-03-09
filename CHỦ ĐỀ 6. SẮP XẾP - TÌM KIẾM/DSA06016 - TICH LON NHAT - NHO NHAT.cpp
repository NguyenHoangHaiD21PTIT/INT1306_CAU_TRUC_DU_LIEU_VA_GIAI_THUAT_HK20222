#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin>>x>>y;
		int a[x], b[y];
		for(int i=0;i<x;i++){
			cin>>a[i];
		}
		for(int i=0;i<y;i++){
			cin>>b[i];
		}
		int p = *max_element(a,a+x);
		int q = *min_element(b,b+y);
		long long ans = 1ll*p*q;
		cout<<ans<<endl;
	}
}