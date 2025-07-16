#include<bits/stdc++.h>
using namespace std;

//Tim vi tri dau tien >=1 va lui
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		auto it = lower_bound(a,a+n,1);
		int p = it - a;
		if(p==n) cout<<n<<endl;
		else {//Ton tai vi tri dau tien = 1
			p--;
			if(p<0) cout<<0<<endl;
			else cout<<p + 1<<endl;
		}
	}
}

