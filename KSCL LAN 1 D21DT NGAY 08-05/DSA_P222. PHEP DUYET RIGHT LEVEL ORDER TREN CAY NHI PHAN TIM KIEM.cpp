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

void spiralorder(node *root){
	if (root == NULL) return;
    queue<node *> q;
    vector<vector<int>> levels;
    q.push(root);
    while (!q.empty()) {
        int nodeCount = q.size();
        vector<int> levelValues;
        while (nodeCount > 0) {
            node *tmp = q.front();
            q.pop();
            levelValues.push_back(tmp->data);
            if (tmp->left != NULL) q.push(tmp->left);
            if (tmp->right != NULL) q.push(tmp->right);
            nodeCount--;
        }
        levels.push_back(levelValues);
    }
    for(int i = 0;i<levels.size();i++){
		for(int j = levels[i].size()-1;j>=0;j--) cout<<levels[i][j]<<" ";
	}
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
		spiralorder(root);
		cout << endl;
	}
	return 0;
}
