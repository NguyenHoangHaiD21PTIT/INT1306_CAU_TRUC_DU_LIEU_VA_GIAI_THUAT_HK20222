#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

struct edge {
    int a, b;
    long long w;
};

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

const int MAXN = 100005;
int par[MAXN], sz[MAXN];

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

long long dist(point A, point B) {
    long long dx = A.x - B.x;
    long long dy = A.y - B.y;
    return dx * dx + dy * dy;
}

int main() {
    int n; cin >> n;
    vector<point> pts(n + 1);
    vector<vector<pair<int,int>>> cor(11); // cor[y] lưu các điểm chung tung độ y kèm theo STT điểm đó
    for (int i = 1; i <= n; i++) {
        cin >> pts[i].x >> pts[i].y;
        cor[pts[i].y].push_back({pts[i].x, i});
    }
    for (int y = 0; y <= 10; y++)  sort(cor[y].begin(), cor[y].end());
    vector<edge> edges;
    for (int i = 1; i <= n; i++) {//Duyệt từng điểm i
        for (int y = 0; y <= 10; y++) { //Duyệt từng tung độ
            auto vec = cor[y]; //Lấy các điểm chung tung độ, được SX tăng dần theo hoành độ
            int l = -1, r = vec.size();
            // Với mỗi tung độ, ta tìm 2 điểm gần nhất theo x so với điểm đang xét về bên trái và bên phải
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (vec[mid].first > pts[i].x) r = mid;
                else l = mid;
            }
            if (r < vec.size()) {
                int j = vec[r].second;
                edges.push_back({i, j, dist(pts[i], pts[j])});
            }
            if (pts[i].y == y) l--; // tránh trùng chính nó
            if (l >= 0) {
                int j = vec[l].second;
                edges.push_back({i, j, dist(pts[i], pts[j])});
            }
        }
    }
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    long long res = 0;
    int cnt = 0;
    for (auto &e : edges) {
        if (Union(e.a, e.b)) {
            res += e.w;
            if (++cnt == n - 1) break;
        }
    }
    cout << res;
}
