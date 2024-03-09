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

bool check(node *root){
	if(root -> left == NULL && root -> right == NULL) return true;
	return false;
}

int sum = 0;

void count(node *root){
	if(root == NULL) return;
	if(root -> right != NULL && check(root -> right)) sum+=root -> right -> data;
	if(root -> right != NULL && !check(root -> right)) count(root->right);
	if(root -> left != NULL && !check(root -> left)) count(root->left);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		sum = 0;
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
		count(root);
		cout<<sum<<endl;
	}
}