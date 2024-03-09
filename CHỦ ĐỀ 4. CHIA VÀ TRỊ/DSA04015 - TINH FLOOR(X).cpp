#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		auto it = lower_bound(a,a+n,x);//vi tri dau tien >= x
		int p = it - a;//vi tri 
		if(p==n){
			cout<<n<<endl;
		} else {
			if(a[p]!=x){
				p--;//Vi tri can tim
			}
			if(p<0){
				cout<<-1<<endl;
			} else {
				cout<<p+1<<endl;
			}
		}
	}
}