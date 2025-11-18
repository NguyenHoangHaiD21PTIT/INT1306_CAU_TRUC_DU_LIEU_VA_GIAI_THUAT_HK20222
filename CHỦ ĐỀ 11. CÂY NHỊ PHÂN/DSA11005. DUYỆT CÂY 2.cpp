#include<bits/stdc++.h>
using namespace std;

// Cấu trúc Nút (Node Struct)
struct node{
	int d; 
	node *l, *r; 
	node(int x){
		d = x;
		l = r = NULL;
	}
};

int findI(const vector<int>& in, int val, int s, int e){ 
	for(int i = s; i <= e; i++){
		if(in[i] == val) return i;
	}
	return -1;
}

node* build(const vector<int>& in, const vector<int>& level, int inS, int inE) {
    if (inS > inE || level.empty()) return NULL;
    node* root = new node(level[0]);
    int rootI = findI(in, level[0], inS, inE);
    vector<int> lL, rL;
    for (int i = 1; i < level.size(); i++) {
        int val = level[i];
        if (findI(in, val, inS, rootI - 1) != -1) lL.push_back(val);
        else if (findI(in, val, rootI + 1, inE) != -1) rL.push_back(val);
    }
    root->l = build(in, lL, inS, rootI - 1);
    root->r = build(in, rL, rootI + 1, inE);
    return root;
}

void postT(node *root){
	if(root == NULL) return;
	postT(root -> l);
	postT(root -> r);
	cout << root->d << " ";	
}

int main(){
	int T; cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> in(N), level(N); 
		for(int i = 0; i < N; i++) cin >> in[i];
		for(int i = 0; i < N; i++) cin >> level[i];
        node *root = build(in, level, 0, N - 1);
		postT(root);
		cout << endl;
	}
}