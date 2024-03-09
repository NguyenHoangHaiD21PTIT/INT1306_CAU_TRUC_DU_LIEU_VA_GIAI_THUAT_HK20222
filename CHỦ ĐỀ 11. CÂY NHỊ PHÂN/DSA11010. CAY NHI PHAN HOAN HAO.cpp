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

bool perfect(node *root){
	queue<node*> q;
	q.push(root);
	int level = 0; 
	while(!q.empty()){
		int s = q.size();//so phan tu cua muc do
		if(s!=pow(2, level)) return false;
		for(int i = 0;i<s;i++){
			node *tmp = q.front(); q.pop();
			if(tmp -> left !=NULL) q.push (tmp->left);
			if(tmp -> right != NULL) q.push(tmp->right);
		}
		level+=1;
	}
	return true;
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
		if(perfect(root)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}