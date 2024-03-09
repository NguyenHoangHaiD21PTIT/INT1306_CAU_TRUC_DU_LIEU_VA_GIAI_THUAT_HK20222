#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		int ans = 0;
		for(int i=(1<<n)-1;i>=0;i--){
			int tong = 0;
			for(int j=n-1;j>=0;j--){
				if(i&(1<<j)) tong+=a[n-j-1];
			}
			if(tong==k){
				ans++;
				string s="[";
				for(int j=n-1;j>=0;j--){
					if(i&(1<<j)) s = s + to_string(a[n-j-1]) + " ";
				}
				s.pop_back();
				s = s + "]";
				cout<<s<<" ";
			}
		}
		if(ans==0) cout<<-1;
		cout<<endl;
	}
}