#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};

void makeroot(node *root, int u, int v, char c){
	if(c=='L') root -> left = new node (v);
	else root -> right = new node (v);
}

void insertnode(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root -> data == u){
		makeroot(root, u, v, c);
	} else {
		insertnode(root -> left, u, v, c);
		insertnode(root -> right, u, v, c);
	}
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
    for (int i = levels.size() - 1; i >= 0; i--) { // Traverse levels in reverse order
        for (int j = 0; j < levels[i].size(); j++) cout << levels[i][j] << " ";
        if(i)reverse(levels[i - 1].begin(), levels[i - 1].end());
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node *root = NULL;
		for(int i = 0;i<n;i++){
			int u, v; char c;
			cin>>u>>v>>c;
			if(root == NULL){
				root = new node(u);
				makeroot(root, u, v, c);
			} else {
				insertnode(root, u, v, c);
			}
		}
		spiralorder(root);
		cout<<endl;
	}
}
/*
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R */