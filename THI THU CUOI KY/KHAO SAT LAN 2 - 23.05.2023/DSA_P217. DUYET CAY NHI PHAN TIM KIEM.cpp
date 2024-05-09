#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int x) {
        data = x;
        left = right = nullptr;
    }
};

node *insert_node(node *root, int u) {
	if (root == NULL) root = new node(u);
	else {
		if (u < root->data) root->left = insert_node(root->left, u);
		else root->right = insert_node(root->right, u);
	}
	return root;
}

void postOrder(node *root) {
	if (root == NULL) return;
	cout << root->data << " ";
	postOrder(root->left);
	postOrder(root->right);
}

int main(){
	int t;
	cin >> t;
	while (t--) {
		node *root = NULL;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			root = insert_node(root, x);
		}
		postOrder(root);
		cout << endl;
	}
	return 0;
}
