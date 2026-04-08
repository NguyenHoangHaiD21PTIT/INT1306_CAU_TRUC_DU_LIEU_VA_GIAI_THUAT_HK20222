#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

void add(node *root, int u, int v, char c) {
    if (c == 'L') root->left = new node(v);
    else root->right = new node(v);
}

void ins(node *root, int u, int v, char c) {
    if (!root) return;
    if (root->data == u) {
        add(root, u, v, c);
    } else {
        ins(root->left, u, v, c);
        ins(root->right, u, v, c);
    }
}

void sol(node *root) {
    if (!root) return;
    queue<node*> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> cur;
        while (sz--) {
            node *p = q.front();
            q.pop();
            cur.push_back(p->data);
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
        ans.push_back(cur);
    }
    for (int i = ans.size() - 1; i >= 0; i--) { 
        for (int x: ans[i]) cout << x << " ";
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        node *root = NULL;
        for (int i = 0; i < n; i++) {
            int u, v; char c;
            cin >> u >> v >> c;
            if (!root) {
                root = new node(u);
                add(root, u, v, c);
            } else ins(root, u, v, c);
            
        }
        sol(root);
        cout << endl;
    }
}
