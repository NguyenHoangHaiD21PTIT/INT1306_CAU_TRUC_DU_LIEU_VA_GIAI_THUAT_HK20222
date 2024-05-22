class Solution {
public:
    vector<int> par;
    vector<int> sze;

    Solution() {}

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        initialize(n);
        for (const auto& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            Union(x, y);
        }

        return find(source) == find(destination);
    }

private:
    void initialize(int n) {
        par.resize(n);
        sze.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
        }
    }

    int find(int x) {
        if (x == par[x]) return x;
        par[x] = find(par[x]);
        return par[x];
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (sze[x] < sze[y]) swap(x, y);
        par[y] = x;
        sze[x] += sze[y];
    }
};