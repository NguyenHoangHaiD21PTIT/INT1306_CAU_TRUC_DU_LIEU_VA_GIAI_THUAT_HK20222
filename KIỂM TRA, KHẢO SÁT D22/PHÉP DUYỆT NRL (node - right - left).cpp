#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node *left, *right;
    node(string x) {
        data = x;
        left = right = NULL;
    }
};

node* build(vector<string>& a) {
    if (a.empty() || a[0] == "N") return NULL;
    node *root = new node(a[0]);
    queue<node*> q;
    q.push(root);
    int i = 1, n = a.size();
    while (!q.empty() && i < n) {
        node *p = q.front();
        q.pop();
        if (a[i] != "N") q.push(p->left = new node(a[i]));
        i++;
        if (i < n && a[i] != "N") q.push(p->right = new node(a[i]));
        i++;
    }
    return root;
}

void NRL(node *root) {
    if (!root) return;
    cout << root->data << " ";
    NRL(root->right);
    NRL(root->left);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, token;
        getline(cin >> ws, s);
        stringstream ss(s);
        vector<string> v;
        while (ss >> token) v.push_back(token);
        node *root = build(v);
        NRL(root);
        cout << endl;
    }
}
