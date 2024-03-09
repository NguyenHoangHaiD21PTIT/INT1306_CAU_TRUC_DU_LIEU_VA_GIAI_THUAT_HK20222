#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++) cin>>a[i];
		sort(a, a+n);
		if(n%2==1) cout<<a[n/2]<<endl;
		else cout<<a[n/2 - 1]<<endl;
	}
}