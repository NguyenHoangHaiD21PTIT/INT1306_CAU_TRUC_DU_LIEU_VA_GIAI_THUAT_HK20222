#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node *build_tree(vector<int> &arr, int n) {
    if (n == 0) return NULL;
    node *root = new node(arr[0]);
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        node *current = q.front();
        q.pop();
        if (arr[i] != -1) {
            current->left = new node(arr[i]);
            q.push(current->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = new node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void levelorderReverse(node *root) {
    if (root == NULL) return;

    queue<node *> q;
    stack<vector<int>> levels;

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
        levels.push(levelValues);
    }

    while (!levels.empty()) {
        vector<int> levelValues = levels.top();
        levels.pop();

        for (int i = 0; i < levelValues.size(); i++) {
            cout << levelValues[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
	cin>>t;
	cin.ignore();
	while(t--){
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i = 0;i<n;i++) cin>>v[i];
	    node *root = build_tree(v, n); // Xây dựng cây
        levelorderReverse(root);
    }
    return 0;
}
/*
1
7
3 9 20 -1 -1 15 7 */