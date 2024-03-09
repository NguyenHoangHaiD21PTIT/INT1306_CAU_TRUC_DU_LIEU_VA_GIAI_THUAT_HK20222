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
		int check = 0;//kiem tra dk ton tai bo ba
		for(int i=0;i<n-2;i++){
			int check1 = 0;//ton tai cap so co tong = (k - a[i])
			for(int j = i+1;j<n-1;j++){
				auto x1 = lower_bound(a+j+1,a+n,k-a[i]-a[j]);//Tim vi tri dau tien >= k - a[i] - a[j]
				auto x2 = upper_bound(a+j+1,a+n,k-a[i]-a[j]);//Tim vi tri dau tien > k - a[i] - a[j]
				if(x1!=x2){
					check1=1;
					break;
				}
			}
			if(check1==1){
				check=1;
				break;
			}
		}
		if(check==1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}