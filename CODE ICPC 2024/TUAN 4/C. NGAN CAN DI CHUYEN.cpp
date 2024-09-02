#include<bits/stdc++.h>
#define endl '\n'
#define T tuple<int, int, int>

using namespace std;

int n, m;
char a[1005][1005];
int d[1005][1005];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};


bool ok(int i, int j){
	return (i >= 1 && j >= 1 && i <= n && j <= m);
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j) cin >> a[i][j];
	}
	memset(d, 0x3f, sizeof d);
	priority_queue<T, vector<T>, greater<T>> q;
	for(int i = 1; i <= n; ++i){
		if(a[i][1] == '#'){
			q.push({0, i, 1});
			d[i][1] = 0;
		}
		else{
			q.push({1, i, 1});
			d[i][1] = 1;
		}
	}
	int ans = 1e9;
	while(q.size()){
		auto [w, i, j] = q.top(); 
		q.pop();
		if(w > d[i][j]) continue;
		if(j == m){
			ans = min(ans, w);
			break;
		}
		for(int k = 0; k < 8; ++k){
			int i1 = i + dx[k];
			int j1 = j + dy[k];
			if(ok(i1, j1)){
				if(a[i1][j1] == '#'){
					if(d[i1][j1] > w ){
						q.push({w, i1, j1});
						d[i1][j1] = w;
					}
				}
				else{
					if(d[i1][j1] > w + 1){
						q.push({w + 1, i1, j1});
						d[i1][j1] = w + 1;
					}
				}
			}
		}
	}
	cout << ans << endl;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int tt = 1;
	while(tt--) solve();
}
