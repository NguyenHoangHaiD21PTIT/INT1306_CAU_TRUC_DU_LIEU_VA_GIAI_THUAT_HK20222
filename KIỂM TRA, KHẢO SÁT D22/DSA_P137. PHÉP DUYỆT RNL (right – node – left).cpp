#include <bits/stdc++.h>
using namespace std;

struct node {
    string d; 
    node *l, *r;
    node (string x){
        d = x;
        l = r = NULL;
    }
};

node *lv (vector <string> &a){
    if (a.empty() || a[0] == "N") return NULL;
    node *root = new node (a[0]);
    queue <node *> q;
    q.push (root);
    int i = 1, n = a.size();
    while (!q.empty() && i < n){
        node *p = q.front();
        q.pop();
        if (a[i] != "N") q.push (p -> l = new node (a[i]));
        i++;
        if (i < n && a[i] != "N") q.push (p -> r = new node (a[i]));
        i++;
    }
    return root;
}

void rnl (node *root){
    if (!root) return;
    rnl (root -> r);
    cout << root -> d << " ";
    rnl (root -> l);
}

int main(){
    int t; cin >> t;
    while (t--){
        string s, tok;
        getline (cin >> ws, s);
        stringstream ss (s);
        vector <string> v;
        while (ss >> tok) v.push_back (tok);
        node *root = lv (v);
        rnl (root);
        cout << endl;
    }
}
