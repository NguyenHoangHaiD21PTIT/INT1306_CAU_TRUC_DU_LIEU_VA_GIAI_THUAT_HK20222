#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		long long kq=0;
		for(int i=0;i<n-1;i++){
			auto x1=lower_bound(a+i+1,a+n, k-a[i]);//vi tri phan tu dau tien >= k-a[i]. 
			auto x2=upper_bound(a+i+1,a+n,k-a[i]);//vi tri ptu dau tien >k-a[i]
			kq+=(x2-1)-x1+1;
		}
		cout<<kq<<endl;
	}
}