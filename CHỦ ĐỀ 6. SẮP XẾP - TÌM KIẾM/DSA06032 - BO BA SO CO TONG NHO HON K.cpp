#include<bits/stdc++.h>
using namespace std;
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
		for(long long i=0;i<n-2;i++){
			//x + y + a[i]<k--> Tim cap so (x,y) co tong x + y < k - a[i]
			if(a[i]>k) break;
			long long kq = 0;
			for(int j = i+1;j<n-1;j++){
				//x + a[i] + a[j] < k --> x <= k - a[i] - a[j] - 1
				//--> Tim vi tri dau tien > k - a[i] - a[j] - 1 roi lui di 1 
				//--> Vi tri so max <= k - a[i] - a[j] - 1
				auto it = upper_bound(a+j+1,a+n, k-a[i]-a[j] - 1);
				long long pos = it - a;
				kq += 1ll*((pos-1)-(j+1) + 1);
			}
			ans +=kq;
		}
		cout<<ans<<endl;
	}
}