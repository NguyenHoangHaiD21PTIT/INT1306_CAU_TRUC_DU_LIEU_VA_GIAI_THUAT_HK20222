#include <bits/stdc++.h>
using namespace std;

struct N {
    int d;
    N *l, *r;
    N(int x) { d = x; l = r = NULL; }
};

N* add(N* rt, int u) {
    if (!rt) return new N(u);
    if (u < rt->d) rt->l = add(rt->l, u);
    else rt->r = add(rt->r, u);
    return rt;
}

void sp(N* rt) {
    if (!rt) return;
    queue<N*> q;
    vector<vector<int>> res;
    q.push(rt);
    while (!q.empty()) {
        // Ý tưởng: Xét hàng đợi theo từng tầng. Mỗi tầng lấy lần lượt ra rồi cho các con vào hàng đợi. 
        int c = q.size(); //Số node tầng đang xét
        vector<int> v; //Mảng lưu các node tầng đang xét
        while (c--) {
            N* t = q.front(); q.pop();
            v.push_back(t->d);
            if (t->l) q.push(t->l);
            if (t->r) q.push(t->r);
        }
        res.push_back(v);
    }
    // Nếu BFS thông thường thì không cần q.size(). Cứ lấy phần tử đằng trước, pop rồi cho 2 con vào qe
    for (int i = 0; i < res.size(); i++) {
        for (int j = res[i].size() - 1; j >= 0; j--) cout << res[i][j] << " ";
    }
}

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        N* rt = NULL;
        cin >> n;
        while (n--) {
            cin >> x;
            rt = add(rt, x);
        }
        sp(rt);
        cout << "\n";
    }
}
