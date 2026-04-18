#include<bits/stdc++.h>
using namespace std;

struct node{
	int d;
	node *l, *r;
	node(int x){
		d = x;
		l = r = NULL;
	}
};

void mr(node *root, int u, int v, char c){ //make root
	if(c == 'L') root -> l = new node (v);
	else root -> r = new node (v);
}

void ins(node *root, int u, int v, char c){
	if(root == NULL) return;
	if(root -> d == u) mr(root, u, v, c);
	else {
		ins(root -> l, u, v, c);
		ins(root -> r, u, v, c);
	}
}

int check(node *root){
    if(root -> l == NULL && root -> r == NULL) return 1;
    if(root -> l != NULL && root -> r != NULL) return check(root -> l) && check(root -> r);
    else return 0;
}


int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >>n ;
		node *root = NULL;
		for(int i = 0;i<n;i++){
			int u, v; char c;
			cin >> u >> v >> c;
			if(root == NULL){
				root = new node(u);
				mr(root, u, v, c);
			} else ins(root, u, v, c);
		}
		if (check(root)) cout << "YES" << endl;
        else cout << "NO" << endl;
	}
}