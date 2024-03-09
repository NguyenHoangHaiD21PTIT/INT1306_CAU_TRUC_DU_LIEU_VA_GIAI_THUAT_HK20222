#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans = 0;
		for(int i=1;i<=sqrt(n);i++){
			if(n%i==0){
				if((n/i)%2==0) ans++;
				if(i%2==0) ans++;
				if(i%2==0&&i==n/i) ans--;
			}
		}
		cout<<ans<<endl;
	}
}