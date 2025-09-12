#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> vec;
int m;

//Giống như so sánh 2 số có cùng chữ số
bool cmp(int i, int j) {
    for (int k = 0; k < m; k++) {
        if (vec[i][k] != vec[j][k]) return vec[i][k] < vec[j][k];
    }
    return i < j; 
}

bool leq(int i, int j) { //Check xem vec[i] <= vec[j] không
    for (int k = 0; k < m; k++) {
        if (vec[i][k] > vec[j][k]) return false;
    }
    return true;
}

int main() {
    int n; cin >> n >> m;
    vec.assign(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> vec[i][j];
        sort(vec[i].begin(), vec[i].end());
    }
    vector<int> id(n);
    for(int i = 0; i < n; i++) id[i] = i;
    sort(id.begin(), id.end(), cmp);
    // DP: dp[i] = độ dài chuỗi dài nhất kết thúc tại vector i
    vector<int> dp(n, 1); // gán =1 luôn
    int K = 1;             // số nhóm lớn nhất
    for (int t = 0; t < n; t++) {
        int i = id[t];
        for (int u = 0; u < t; u++) {
            int j = id[u];
            if (leq(j, i)) dp[i] = max(dp[i], dp[j] + 1);
        }
        K = max(K, dp[i]);
    }
    vector<vector<int>> gr(K + 1); 
    for (int i = 0; i < n; i++) gr[dp[i]].push_back(i + 1);
    cout << K << "\n";
    for (int lvl = 1; lvl <= K; lvl++) {
        auto &g = gr[lvl];
        sort(g.begin(), g.end()); 
        cout << g.size();
        for (int x : g) cout << ' ' << x;
        cout << "\n";
    }
}
