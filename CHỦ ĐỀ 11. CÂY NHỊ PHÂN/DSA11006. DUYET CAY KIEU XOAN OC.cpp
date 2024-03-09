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
    stack<node*> st1, st2;
    st1.push(root);
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            node* tmp = st1.top(); st1.pop();
            cout << tmp->data << ' ';
            if(tmp->right != NULL) st2.push(tmp->right);
            if(tmp->left != NULL) st2.push(tmp->left);
        }
        while(!st2.empty()){
            node* tmp = st2.top(); st2.pop();
            cout << tmp->data << ' ';
            if(tmp->left != NULL) st1.push(tmp->left);
            if(tmp->right != NULL) st1.push(tmp->right);
        }
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