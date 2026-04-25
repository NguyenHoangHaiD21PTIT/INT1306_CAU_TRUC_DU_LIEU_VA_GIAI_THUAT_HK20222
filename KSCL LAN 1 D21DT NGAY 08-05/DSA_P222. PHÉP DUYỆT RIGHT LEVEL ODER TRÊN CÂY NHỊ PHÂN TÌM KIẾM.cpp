#include <bits/stdc++.h>
using namespace std;

struct node {
    int d; 
    node *l, *r;
    node (int u){
        d = u; 
		l = r = nullptr;
    }
};

node *ins (node *root, int u){
    if (!root) root = new node (u);
    else {
        if (u < root -> d) root -> l = ins (root -> l, u);
        else root -> r = ins (root -> r, u);
    }
    return root;
}

void lv (node *root){
    if (!root) return;
    queue <node *> q;
    q.push(root);
    vector <vector <int>> res;
    while (!q.empty()){
        // Ý tưởng: Xét hàng đợi theo từng tầng. Mỗi tầng lấy lần lượt ra rồi cho các con vào hàng đợi. 
        int c = q.size();//Số node tầng đang xét
        vector <int> v;//Mảng lưu các node tầng đang xét
        while (c--){
            node *t = q.front(); q.pop();
            v.push_back(t -> d);
            if (t -> l) q.push (t -> l);
            if (t -> r) q.push (t -> r);
        }
        res.push_back(v);
    }
    for (auto x: res){
        reverse(x.begin(), x.end());
        for (int y: x) cout << y << " ";
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        node *root = NULL;
        int n; cin >> n;
        while (n--){
            int x; cin >> x;
            root = ins (root, x);
        }
        lv (root);
        cout << endl;
    }
}
