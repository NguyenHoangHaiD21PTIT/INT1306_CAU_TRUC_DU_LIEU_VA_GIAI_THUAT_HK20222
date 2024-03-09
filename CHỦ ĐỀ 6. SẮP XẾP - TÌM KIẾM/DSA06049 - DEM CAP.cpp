#include<bits/stdc++.h>
using namespace std;

//DEM CAP PHAN TU CO DO CHENH LECH < K
/*Sort. Xet cac ptu ben phai a[i] goi la x. x - a[i]<k --. x <= k + a[i] - 1
--> Tim vi tri dau tien > k + a[i] - 1 trong doan [i+1;n-1] va lui di 1 -->vi tri cua x */

int main(){
	int t;
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
		for(long long i = 0;i<n-1;i++){
			auto it = upper_bound(a+i+1,a+n,k+a[i]-1);
			long long pos = it - a;
			//--> Cac so tu [i+1;pos-1] thoa man
			long long socap = (pos-1) - (i+1) + 1;
			ans+=socap;
		}
		cout<<ans<<endl;
	}
}