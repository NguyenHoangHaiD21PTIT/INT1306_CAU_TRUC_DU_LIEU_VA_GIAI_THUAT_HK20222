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
		int kq=0;
		for(int i=0;i<n-1;i++){
			auto x1=lower_bound(a+i+1,a+n, k-a[i]);//vi tri phan tu dau tien >= k-a[i] (ưu tiên trả = trước). 
			auto x2=upper_bound(a+i+1,a+n,k-a[i]);//vi tri ptu dau tien >k-a[i] -> lùi đi 1 vị trí -> vị trí cuối =
			int x =x1 - a;
			int y = x2 - a;
			cout<<x<<" "<<y<<" ";
			kq+=(x2-1)-x1+1;
		}
		cout<<kq<<endl;
	}
}

