#include<bits/stdc++.h>
using namespace std;

int a[10]={1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans =0;
		for(int i=9;i>=0;i--){
			int p = n/a[i];//so to tien toi da doi duoc loai i
			ans+=p;
			n = n - p*a[i];
		}
		cout<<ans<<endl;
	}
}