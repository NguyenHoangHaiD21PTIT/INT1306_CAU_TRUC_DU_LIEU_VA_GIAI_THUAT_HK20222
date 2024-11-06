#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> st[4 * MAXN];
int a[MAXN];

// Hàm xây dựng cây phân đoạn
void build(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(), back_inserter(st[id]));
}

// Hàm đếm số phần tử <= x trong đoạn [u, v]
int cnt(int id, int l, int r, int u, int v, int x) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return upper_bound(st[id].begin(), st[id].end(), x) - st[id].begin();
    int mid = (l + r) / 2;
    return cnt(id * 2, l, mid, u, v, x) + cnt(id * 2 + 1, mid + 1, r, u, v, x);
}

int kthSmallest(int N, int u, int v, int k) {
    int left = -1e9, right = 1e9; 
    while (left < right) {
        int mid = left + (right - left) / 2;
        int cnt1 = cnt(1, 0, N - 1, u, v, mid);
        if (cnt1 >= k) right = mid; 
        else left = mid + 1;
    }
    return left;
}

int main() {
    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> a[i];
    build(1, 0, N - 1); 
    while (Q--) {
        int u, v, k;
        cin >> u >> v >> k;
        u--; v--; // Chuyển sang chỉ số 0-based
        cout << kthSmallest(N, u, v, k) << endl;
    }
}
