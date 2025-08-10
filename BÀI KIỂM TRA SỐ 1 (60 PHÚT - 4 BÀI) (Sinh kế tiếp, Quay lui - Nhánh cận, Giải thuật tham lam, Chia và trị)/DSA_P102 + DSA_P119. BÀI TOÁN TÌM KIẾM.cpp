#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	while(t--){
		int n, s, k;
		cin >> n >> s >> k;
		s--;
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		long long pre[n];
		for(int i = 0; i < n; i++){
			if(i == 0) pre[0] = a[0];
			else pre[i] = pre[i - 1] + a[i];
		}
		int ans = -1e9;
		if(pre[s] <= k) ans = 1;
		else {
			for(int i = 1; i <= s; i++){
				if(pre[s] - pre[i - 1] <= k){
					ans = i + 1;
					break;
				}	
			}
		}
		if(ans == -1e9) cout << -1 << endl;
		else cout << ans << endl;
	}
}

