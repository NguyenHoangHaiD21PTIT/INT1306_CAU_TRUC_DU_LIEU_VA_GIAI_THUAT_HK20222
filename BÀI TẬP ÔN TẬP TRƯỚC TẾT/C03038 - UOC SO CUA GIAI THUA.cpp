#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		int ans = 0;
		for(int i=1;i<=n;i++){
			int cnt = 0;
			int tmp = i;
			while(tmp%p==0){
				cnt++;
				tmp/=p;
			}
			ans+=cnt;
		}
		cout<<ans<<endl;
	}
}