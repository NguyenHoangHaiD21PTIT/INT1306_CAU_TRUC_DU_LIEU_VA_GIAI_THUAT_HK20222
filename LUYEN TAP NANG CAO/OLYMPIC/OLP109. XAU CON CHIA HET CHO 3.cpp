#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

struct Node {
    int sum = 0;
    int dp[3] = {0}; 
} tree[4 * MAXN];

int n, m;
int a[MAXN];

void build(int node, int l, int r) {
    if (l == r) {
        tree[node].sum = a[l];
        tree[node].dp[a[l] % 3]++;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    for (int i = 0; i < 3; i++) {
        int x = (i + tree[2 * node].sum) % 3;
        tree[node].dp[x] = tree[2 * node].dp[x] + tree[2 * node + 1].dp[i];
    }
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        tree[node].dp[tree[node].sum % 3]--;
        tree[node].sum = val;
        tree[node].dp[val % 3]++;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else update(2 * node + 1, mid + 1, r, idx, val);
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    for (int i = 0; i < 3; i++) {
        int x = (i + tree[2 * node].sum) % 3;
        tree[node].dp[x] = tree[2 * node].dp[x] + tree[2 * node + 1].dp[i];
    }
}

Node get(int node, int l, int r, int left, int right) {
    if (r < left || l > right) return Node();
    if (l >= left && r <= right) return tree[node];
    int mid = (l + r) / 2;
    Node leftNode = get(2 * node, l, mid, left, right);
    Node rightNode = get(2 * node + 1, mid + 1, r, left, right);
    Node res;
    res.sum = leftNode.sum + rightNode.sum;
    for (int i = 0; i < 3; i++) {
        int x = (i + leftNode.sum) % 3;
        res.dp[x] = leftNode.dp[x] + rightNode.dp[i];
    }
    return res;
}

void solve(int l, int r) {
    Node result = get(1, 1, n, l, r);
    int F[3] = {0};
    for (int i = 0; i < 3; i++) {
        F[i] = result.dp[i];
        if (i == 0) F[i]++;
        F[i] = F[i] * (F[i] - 1) / 2;
    }
    cout << F[0] + F[1] + F[2] << endl;
}

int32_t main() {
    string s;
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    build(1, 1, n);
    while (m--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) update(1, 1, n, x, y);
        else solve(x, y);
    }
}
 
