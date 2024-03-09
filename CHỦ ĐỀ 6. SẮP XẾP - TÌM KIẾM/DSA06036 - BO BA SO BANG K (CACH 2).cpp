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
			int l = i + 1, r = n-1;
			while(l<r){
				if(a[i]+a[l]+a[r]==k){
					check1=1;
					break;
				}
				if(a[i]+a[l]+a[r]<k) l++;
				if(a[i]+a[l]+a[r]>k) r--;
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