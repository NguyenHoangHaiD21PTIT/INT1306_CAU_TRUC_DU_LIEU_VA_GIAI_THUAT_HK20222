#include<bits/stdc++.h>
using namespace std;

/* TIM CAP SO CO DO CHENH LECH <K .
SX. Xet cac so sau a[i]: x sao cho x - a[i] <k --> x <= k + a[i]- 1 
--> Tim vi tri dau tien > k + a[i] - 1 --> upperbound --> Lui pos di 1
--> Cac so thoa man [i+1;pos-1] */

int main(){
	long long t;
	cin>>t;
	while(t--){
		long long n, k;
		cin>>n>>k;
		long long a[n];
		for(long long i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		long long ans = 0;
		for(long long i=0;i<n-1;i++){
			auto it = upper_bound(a+i+1,a+n,k+a[i] - 1);
			long long pos = it - a;
			long long socap = (pos-1)-(i+1)+1;
			ans+=socap;
		}
		cout<<ans<<endl;
	}
}