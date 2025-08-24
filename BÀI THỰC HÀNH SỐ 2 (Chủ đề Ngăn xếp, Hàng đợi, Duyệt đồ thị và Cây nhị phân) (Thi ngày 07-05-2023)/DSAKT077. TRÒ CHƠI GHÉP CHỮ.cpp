#include <bits/stdc++.h>
using namespace std;

const int MXN = 5007;

int child[MXN][26];   // Trie: con của node u theo ký tự k
int e[MXN];           // số từ kết thúc tại node u
int sz[MXN];          // tổng số từ trong subtree của u
int dp[MXN];          // số từ đã duyệt ở u
int cnt;              // số node trong Trie

char a[10][10];       // bảng chữ cái Boggle
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[10][10];     // đánh dấu ô đã đi
set<string> res;      // kết quả các từ tìm được

// Thêm từ vào Trie
void addWord(const string &s) {
    int u = 0;
    for (char c : s)  {
        int k = c - 'a';
        if (!child[u][k]) child[u][k] = ++cnt;
        u = child[u][k];
    }
    e[u]++;
}

// Tính số từ trong mỗi subtree
void dfs(int u) {
    sz[u] = e[u];
    for (int k = 0; k < 26; k++) {
        if (child[u][k]){
            dfs(child[u][k]);
            sz[u] += sz[child[u][k]];
        }
    }
}

// DFS từ ô (i,j) theo Trie node u
void run(int i, int j, int u, string &w, int n) {
    vis[i][j] = true;
    w.push_back(a[i][j]);
    if (a[i][j] == 'q')  w.push_back('u');
    if (e[u] > 0) {
        res.insert(w);
        dp[u] += e[u];
    }
    if (w.size() > 25) {
        vis[i][j] = false;
        if (a[i][j] == 'q') w.pop_back();
        w.pop_back();
        return;
    }
    for (int id = 0; id < 8; id++) {
        int ni = i + dx[id];
        int nj = j + dy[id];
        if (1 <= ni && ni <= n && 1 <= nj && nj <= n && !vis[ni][nj]){
            int k = a[ni][nj] - 'a';
            if (child[u][k]) {
                if (a[ni][nj] == 'q') {
                    int uu = child[u][k];
                    if (child[uu]['u' - 'a'] && dp[uu] < sz[uu]) {
                        run(ni, nj, child[uu]['u' - 'a'], w, n);
                        dp[uu] += dp[child[uu]['u' - 'a']];
                        dp[u] += dp[uu];
                    }
                } 
                else if (dp[u] < sz[u]) {
                    run(ni, nj, child[u][k], w, n);
                    dp[u] += dp[child[u][k]];
                }
            }
        }
    }
    vis[i][j] = false;
    if (a[i][j] == 'q') w.pop_back();
    w.pop_back();
}

int main() {
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        addWord(s);
    }
    dfs(0);
    int n;
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) cin >> a[i][j];
        }
        res.clear();
        fill(dp, dp + cnt + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++){
                int k = a[i][j] - 'a';
                if (child[0][k] && dp[0] < sz[0]) {
                    string w;
                    if (a[i][j] == 'q') {
                        int u = child[0][k];
                        if (child[u]['u' - 'a'] && dp[u] < sz[u]) {
                            run(i, j, child[u]['u' - 'a'], w, n);
                            dp[u] += dp[child[u]['u' - 'a']];
                            dp[0] += dp[u];
                        }
                    } 
                    else if (dp[child[0][k]] < sz[child[0][k]]){
                        run(i, j, child[0][k], w, n);
                        dp[0] += dp[child[0][k]];
                    }
                }
            }
        }
        for (auto &s : res) cout << s << '\n';
        cout << "-\n";
    }
}
/* Lưu ý:
1. Đây là bài cực khó, chỉ dành cho các bạn giỏi. 
2. Sử dụng: DFS + Trie + Quy hoạch động trên cây
3. Bài chỉ có 1 test duy nhất. Chưa học vững các mảng nâng cao nên bỏ qua cho đỡ mất thời gian, không có test mà cắn đâu.
4. Tác giả: Bạn Vũ Đình Long - B23DCAT175
*/
