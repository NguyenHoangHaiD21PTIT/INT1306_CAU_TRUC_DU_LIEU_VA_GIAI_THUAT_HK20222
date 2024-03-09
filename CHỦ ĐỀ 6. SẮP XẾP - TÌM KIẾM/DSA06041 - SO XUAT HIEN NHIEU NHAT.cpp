#include<bits/stdc++.h>
using namespace std;

int cnt[10000005]={};

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(cnt,0,sizeof(cnt));
		int n;
		cin>>n;
		int p = n/2;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			cnt[a[i]]++;
		}
		int ans = -1e9;
		for(int i=0;i<n;i++){
			if(cnt[a[i]]>p){
				ans = a[i];
				break;
			}
		}
		if(ans==-1e9){
			cout<<"NO"<<endl;
		} else {
			cout<<ans<<endl;
		}
	}
}