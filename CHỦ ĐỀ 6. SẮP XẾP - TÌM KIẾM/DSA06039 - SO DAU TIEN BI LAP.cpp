#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		map<int,int>mp;
		int n;
		cin>>n;
		int a[n];
		int ans = -1e9+7;
		for(int i=0;i<n;i++){//i: STT cua so dang xet
			cin>>a[i];
			mp[a[i]]++;	
		}
		for(int i = 0;i<n;i++){
			if(mp[a[i]]>=2){
				ans = a[i];
				mp[a[i]]=0;
				break;
			}	
		}
		if(ans ==-1e9+7){
			cout<<"NO"<<endl;
		} else {
			cout<<ans<<endl;
		}
	}
}