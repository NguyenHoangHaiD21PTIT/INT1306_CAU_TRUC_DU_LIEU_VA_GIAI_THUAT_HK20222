#include <bits/stdc++.h>
using namespace std;

struct node {
    int d;
    node* l, *r;
    node(int x) {
        d = x;
        l = r = nullptr;
    }
};

node *ins(node *root, int u) {
	if (root == NULL) root = new node(u);
	else {
		if (u < root->d) root->l = ins(root->l, u);
		else root->r = ins(root->r, u);
	}
	return root;
}

void nrl(node *root) {
    if (!root) return;
    cout << root -> d << " ";
	nrl(root -> r);
    nrl(root -> l);
}

int main(){
	int t; cin >> t;
	while (t--) {
		node *root = NULL;
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			root = ins(root, x);
		}
		nrl(root);
		cout << endl;
	}
}
