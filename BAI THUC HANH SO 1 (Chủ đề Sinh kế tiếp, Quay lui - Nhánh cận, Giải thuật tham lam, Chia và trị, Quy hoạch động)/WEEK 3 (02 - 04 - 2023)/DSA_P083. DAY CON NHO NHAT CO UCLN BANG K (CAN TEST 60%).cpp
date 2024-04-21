#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		int res = 1e9, check = 0; //res: luu chieu dai day con
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==k){
				check = 1;
				res = 1;
			}
		}
		if(check==0){
			for(int i=0;i<n-1;i++){
				int tmp = a[i];
				for(int j=i+1;j<n;j++){
					tmp = __gcd(tmp, a[j]);
					if(tmp==k){
						check = 1;
						res = min(res,j-i+1);
						break;
					}
				}
			}
		}
		if(check==0) cout<<-1<<endl;
		else cout<<res<<endl;
	}
}
