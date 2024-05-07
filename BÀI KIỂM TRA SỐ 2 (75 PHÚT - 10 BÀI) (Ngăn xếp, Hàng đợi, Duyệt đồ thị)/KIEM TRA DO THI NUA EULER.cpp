#include<bits/stdc++.h>
using namespace std;

int deg[1005];

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(deg,0,sizeof(deg));
		int dinh, canh;
		cin>>dinh>>canh;
		while(canh--){
			int dau, cuoi;
			cin>>dau>>cuoi;
			deg[dau]++;
			deg[cuoi]++;
		}
		int cnt = 0;
		for(int i=1;i<=dinh;i++){
			if(deg[i]%2==1) cnt++;
		}
		if(cnt==0||cnt==2) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}