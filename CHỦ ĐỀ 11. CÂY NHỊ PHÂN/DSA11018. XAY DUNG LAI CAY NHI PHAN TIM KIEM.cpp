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

void preorder(node *root){
	if(root == NULL) return;
	cout<<root->data <<" ";	
	preorder(root -> left);
	preorder(root -> right);
	
}

void insert(node* &root, int x) {
	if(root==NULL){
		root = new node(x);
		return;
	}
	if(x<root->data) insert(root->left, x);
	else insert(root->right, x);
}
    
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node *root = NULL;
		for(int i = 0;i<n;i++){
			int x; cin>>x;
			insert(root, x);
		}
		preorder(root);
		cout<<endl;
	}
}