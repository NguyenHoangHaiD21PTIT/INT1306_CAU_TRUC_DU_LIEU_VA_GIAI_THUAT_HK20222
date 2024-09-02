#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;

vector <pair<int, bool>> neighb[maxN];  // Danh sách kề cho mỗi đỉnh, lưu cặp (đỉnh kề, có phải là cạnh may mắn không)
int CompSize[maxN];  //CompSize[i]: Kích thước cuả TPLT có đỉnh đại diện là i
int par[maxN];  //par[x] = y: x nằm trong TPLT có đỉnh đại diện là i
int CurPar;  //Đỉnh đại diện

bool mark[maxN];  // Đánh dấu đỉnh đã được thăm

bool checkLucky(string x) {
    // Kiểm tra xem một số có phải là số may mắn không
	for(int i = 0; i < x.size(); i++) {
		if(x[i] != '4' and x[i] != '7') return false;
	}
	return true;
}

void dfs(int u) {
	mark[u] = true;
	CompSize[CurPar]++;
	par[u] = CurPar;
	for(int i = 0; i < neighb[u].size(); i++) {
		int v = neighb[u][i].first;
		int l = neighb[u][i].second;
		if(!mark[v] and !l) dfs(v);
	}
}

int main() {	
	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int a, b;
		string w;
		cin >> a >> b >> w;
		bool c = checkLucky(w);
		neighb[a].push_back({b, c});
		neighb[b].push_back({a, c});
	}
	
	//Ta sẽ xem đồ thị gồm những thành phần liên thông nào, chỉ chứa các cạnh không may 
	for(int i = 1; i <= n; i++) {
		if(!mark[i]) {
			CurPar = i;
			dfs(i);
		}
	}
	//Mỗi đỉnh, ta cần chọn 2 đỉnh không thuộc cùng TPLT xấu với nó
	long long int ans = 0;
	for(int i = 1; i <= n; i++) {
		long long int p = par[i];
		long long int f = n - CompSize[p];
		ans += (f * (f-1));
	}
	cout << ans << "\n";
}