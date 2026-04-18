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

void pre(node *root) {
	if (root == NULL) return;
	cout << root->d << " ";
	pre(root->l);
	pre(root->r);
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
		pre(root);
		cout << endl;
	}
}
