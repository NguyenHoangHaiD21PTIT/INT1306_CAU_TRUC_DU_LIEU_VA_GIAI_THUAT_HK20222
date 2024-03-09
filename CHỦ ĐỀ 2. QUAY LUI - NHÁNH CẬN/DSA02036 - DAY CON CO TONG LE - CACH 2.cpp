#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n,greater<int>());
		for(int i=0;i<(1<<n);i++){ //Xet tap tat ca cac cau hinh np
			int tong = 0 ;
			for(int j = n-1;j>=0;j--){
				if(i&(1<<j)) tong +=a[n-j-1];
			}
			if(tong%2==1){
				for(int j = n-1;j>=0;j--){
					if(i&(1<<j)) cout<<a[n-j-1]<<" ";
				}
				cout<<endl;
			}
		}
	}
}