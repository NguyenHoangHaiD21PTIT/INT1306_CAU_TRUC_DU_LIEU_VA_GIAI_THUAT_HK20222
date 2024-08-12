#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Data {
	// lưu 3 biến
	// x, y là đỉnh
	// w là trọng số của cạnh
	int x, y, w;
};

const int maxn = 500001;
const int inf = INT_MAX;
int n, m;
int h1, s1, h2, s2;
// biến parent để check đường đi
int parent[maxn];
// biến này là danh sách kề
vector<pair<int, int>> adj[maxn];
// biến này lưu vết đường đi ngắn nhất của Tý và Tèo
vector<Data> pathTy, pathTeo;
// dùng để truy cập vào trọng số của cạnh cho nhanh (VD: mp[1][2] = trọng số cạnh từ đỉnh 1 nối tới đỉnh 2)
map<int, int> mp[maxn];
// đếm số lần đỉnh được đến thăm (VD: cả Tý và Tèo đều đi qua điểm 3 => cnt[3] = 2)
int cnt[maxn];
// đếm số lần cạnh được đến thăm (VD: Tý đi qua cạnh 5-6 với tổng thời gian đến cạnh đó là 100, nghĩa là cạnh 5-6 được đi qua 1 lần => mp[{{5, 6}, 100}] = 1)
// Vậy ta kết luận rằng, nếu 1 cạnh nào đó được cả Tý và Tèo đều đi qua và cùng chung thời gian, ta kết luận infinity, nghĩa là có vô số điểm chung trong cạnh đó
map<pair<pair<int, int>, int>, int> cntPath;
// tính tổng độ dài của từng Node, hay là tổng thời gian sau khi đi qua mỗi Node
// sum1 là tổng thời gian sau khi đi qua mỗi Node của Tý
// sum2 là tổng thời gian sau khi đi qua mỗi Node của Tèo
int sum1[maxn], sum2[maxn];

void nhap() {
	for (int i = 0; i < maxn; i++) {
		adj[i].clear();
		mp[i].clear();
		cnt[i] = 0;
	}
	pathTy.clear();
	pathTeo.clear();
	cntPath.clear();
	cin >> n >> m;
	cin >> h1 >> s1 >> h2 >> s2;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
		mp[x][y] = w;
		mp[y][x] = w;
	}
}

void dijkstra(int s, int t, string name) {
	vector<ll> d(n + 1, inf);
	d[s] = 0;
	parent[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, s});
	while(!q.empty()) {
		// chon ra dinh co khoang cach tu s nho nhat
		pair<int, int> top = q.top();
		q.pop();
		int u = top.second;
		int kc = top.first;
		if (kc > d[u]) continue;
		// relaxation: cap nhat kcach tu s cho moi dinh ke voi u
		for (auto it : adj[u]) {
			int v = it.first;
			int w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push({d[v], v});
				parent[v] = u;
			}
		}
	}
	if (name == "Ty") {
		while(t != parent[t]) {
			int v = t;
			t = parent[t];
			int w = mp[t][v];
			pathTy.push_back({t, v, w});
		}
		reverse(pathTy.begin(), pathTy.end());
	}
	else {
		while(t != parent[t]) {
			int v = t;
			t = parent[t];
			int w = mp[t][v];
			pathTeo.push_back({t, v, w});
		}
		reverse(pathTeo.begin(), pathTeo.end());
	}
}

// hàm này là để tính tổng độ dài của từng Node nó đi qua
void tinhTongDoDai(int sum[], vector<Data> path) {
	sum[path[0].x] = 0;
	for (int i = 1; i < path.size(); i++) {
		sum[path[i].x] = sum[path[i - 1].x] + path[i - 1].w;
	}
	sum[path[path.size() - 1].y] = sum[path[path.size() - 1].x] + path[path.size() - 1].w;
}

void solve(int ans) {
	memset(sum1, 0, sizeof(sum1));
	memset(sum2, 0, sizeof(sum2));
	tinhTongDoDai(sum1, pathTy);
	tinhTongDoDai(sum2, pathTeo);
	if (pathTy.size() <= pathTeo.size()) {
		for (int i = 0; i < pathTy.size(); i++) {
			// nếu cả Tý và Tèo đều đi qua 1 điểm trung gian nào đó (nghĩa là cnt[pathTy[i].x] = 2) và tổng độ dài của từng Node bằng nhau 
			// ta suy ra Tý và Tèo sẽ gặp nhau tại Node đó (vì tốc độ của 2 người là giống nhau)
			if (cnt[pathTy[i].x] == 2 && sum1[pathTy[i].x] == sum2[pathTy[i].x]) ans++;
		}
	}
	cout << ans << endl;
}

// đếm số lần xuất hiện đường đi
void demSoLanXuatHienDuongDi(vector<Data> path) {
	int sum = 0;
	for (Data tmp : path) {
		// tính tổng thời gian sau khi đi qua các cạnh
		sum += tmp.w;
		// đếm số Node mà họ đi qua
		cnt[tmp.x]++;
		// đếm số cạnh mà họ đi qua và có cùng thời gian hay không (mục đích để check xem nó infinity không)
		cntPath[{{tmp.x, tmp.y}, sum}]++;
	}
	cnt[path[path.size() - 1].y]++;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		nhap();
		dijkstra(h1, s1, "Ty");
		dijkstra(h2, s2, "Teo");

		demSoLanXuatHienDuongDi(pathTy);
		demSoLanXuatHienDuongDi(pathTeo);
		
		bool checkInf = false;
		for (auto it : cntPath) {
			if (it.second == 2) {
				cout << "infinity" << endl;
				checkInf = true;
				break;
			}
		}
		if (checkInf) continue;
		
		int ans = 0;
		if (s1 == s2) {
			ans++;
			solve(ans);
		}
		else {
			solve(ans);
		}
	}
	return 0;
}