#include <bits/stdc++.h>
using namespace std;

struct node {
    int d;
    node *l, *r;
    node (int x){
        d = x; l = r = nullptr;
    }
};

node *ins (node *root, int u){
    if (!root) root = new node(u);
    else {
        if (u < root -> d) root -> l = ins (root -> l, u);
        else root -> r = ins (root -> r, u);
    }
    return root;
}

void lv(node *rt){
    if (!rt) return;
    queue <node *>q;
    vector <vector <int>>res;
    q.push(rt);
    while (!q.empty()){
        int c = q.size();
        vector <int> v;
        while (c--){
            node *t = q.front(); q.pop();
            v.push_back (t -> d);
            if (t -> l) q.push (t -> l);
            if (t -> r) q.push (t -> r);
        }
        res.push_back(v);
    }
    for (int i = 0; i < res.size(); i++){
        cout << "Level " << i + 1 << ": ";
        for(int x: res[i]) cout << x << " ";
        cout << endl;
    }
}

int main(){
    int t, n, x;
    cin >> t;
    while (t--){
        node *rt = NULL;
        cin >> n;
        while (n--){
            cin >> x;
            rt = ins (rt, x);
        }
        lv (rt);
        cout << endl;
    }
}
