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

void postT(node *root){
	if(root == NULL) return;
	postT(root -> l);
	postT(root -> r);
	cout << root -> d << " ";	
}

node* build(const vector<int>& pre, int s, int e) { //start, end
    if (s > e) return NULL;
    node* root = new node(pre[s]);
    if (s == e) return root;
    int i = s + 1;
    while (i <= e && pre[i] < pre[s]) i++;
    root -> l = build(pre, s + 1, i - 1); 
    root -> r = build(pre, i, e);
    return root;
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> pre; 
		for(int i = 0;i<n;i++){
			int x; cin >> x;
			pre.push_back(x);
		}
		node *root = build(pre, 0, pre.size() - 1);
		postT(root); 
		cout << endl;
	}
}
