#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int ans = 1e9;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n-1;i++){
			ans = min(ans, abs(a[i]-a[i+1]));
		}
		cout<<ans<<endl;
	}
}