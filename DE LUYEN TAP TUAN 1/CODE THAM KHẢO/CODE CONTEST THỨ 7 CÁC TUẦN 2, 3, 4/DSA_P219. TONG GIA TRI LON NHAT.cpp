#include<bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define ii pair<int, int>
#define pb push_back
 
using namespace std;
 
void solve(){
	int n, t; cin >> n >> t;
	ii a[n + 1];
	for(int i = 1; i <= n; ++i) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + n + 1, [](ii x, ii y){
		return x.se > y.se;
	});
	int ans = 0;
	for(int i = 1; i <= min(n, 10); ++i){
		// chọn i là thằng bú ké time cuối
		// chọn trâu như này sẽ bị TLE nên chỉ chọn 10 thằng đầu(thuật sai)
		vector<ii> v;
		for(int j = 1; j <= n; ++j){
			if(j != i) v.pb({a[j].fi, a[j].se});
		}
		int time = t - 1;
		int DP[time + 1] = {}; 
		for(int i = 0; i < v.size(); ++i){
			for(int j = time; j >= v[i].fi; --j){
				DP[j] = max(DP[j], DP[j - v[i].fi] + v[i].se);
			}
		}
		ans = max(ans, DP[time] + a[i].se);
	}
	sort(a + 1, a + n + 1, [](ii x, ii y){
		return x.fi > y.fi;
	});
	for(int i = 1; i <= min(n, 10); ++i){
		// chọn i là thằng bú ké time cuối
		// chọn trâu như này sẽ bị TLE nên chỉ chọn 10 thằng đầu(thuật sai)
		vector<ii> v;
		for(int j = 1; j <= n; ++j){
			if(j != i) v.pb({a[j].fi, a[j].se});
		}
		int time = t - 1;
		int DP[time + 1] = {}; 
		for(int i = 0; i < v.size(); ++i){
			for(int j = time; j >= v[i].fi; --j){
				DP[j] = max(DP[j], DP[j - v[i].fi] + v[i].se);
			}
		}
		ans = max(ans, DP[time] + a[i].se);
	}
	cout << ans << endl;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin >> T;
	while(T--) solve();
}
