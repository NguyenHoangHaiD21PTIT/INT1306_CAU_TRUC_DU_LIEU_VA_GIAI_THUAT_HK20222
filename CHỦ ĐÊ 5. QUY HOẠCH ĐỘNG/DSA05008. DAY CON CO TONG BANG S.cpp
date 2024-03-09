#include<bits/stdc++.h>
using namespace std;

bool f[40010];

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(f,false,sizeof(f));
		int n, s;
		cin>>n>>s;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		f[0] = true;
		for(int i=0;i<n;i++){
			for(int j=s;j>=a[i];j--){
				if(f[j-a[i]]==true) f[j] = true;
			}
		}
		if(f[s]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}