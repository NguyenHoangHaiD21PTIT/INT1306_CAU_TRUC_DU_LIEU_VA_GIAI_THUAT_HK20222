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

bool check(node *root1, node *root2){
	if(root1==NULL&root2==NULL) return true;
	if(root1!=NULL&&root2!=NULL){
		return root1 -> data == root2 -> data && check(root1 -> left, root2 -> left) && check(root1 -> right, root2 -> right);
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n1; cin>>n1;
		node *root1 = NULL; node *root2 = NULL;
		while(n1--){
			int u, v; char c;
			cin>>u>>v>>c;
			if(root1 == NULL){
				root1 = new node (u);
				makeroot(root1, u, v, c);
			} else {
				insertnode(root1, u, v, c);
			}
		}
		int n2; cin>>n2;
		while(n2--){
			int u, v; char c;
			cin>>u>>v>>c;
			if(root2 == NULL){
				root2 = new node (u);
				makeroot(root2, u, v, c);
			} else {
				insertnode(root2, u, v, c);
			}
		}
		if(check(root1, root2)) cout<<1<<endl;
		else cout<<0<<endl;
	}
}