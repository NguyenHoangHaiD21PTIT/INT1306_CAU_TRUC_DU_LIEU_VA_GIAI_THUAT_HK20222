#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int ans = 0;
		for(int i = 0;i<n-2;i++){
			if(a[i]==a[i+1]){
				continue;
			}
			int j = i+1;
			int k = n-1;
			while (j<k){
				int x = a[i] + a[j] + a[k];
				if(x==0){
					ans++;
					while(j<k&&a[j]==a[j+1]){
						j++;
					}
					while(j<k&&a[k]==a[k-1]){
						k--;
					}
					j++;
					k--;
				} else if(x<0){
					j++;
				} else {
					k--;
				}
			}
		}
		cout<<ans<<endl;
	}
}