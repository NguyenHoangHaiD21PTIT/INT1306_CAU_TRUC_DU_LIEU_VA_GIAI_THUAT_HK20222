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

void postorder(node *root){
	if(root == NULL) return;
	postorder(root -> left);
	postorder(root -> right);
	cout<<root->data <<" ";	
}

node* buildTree(vector<int>& preorder) {
    if (preorder.empty()) return NULL;
    node* root = new node(preorder[0]);
    int i = 1;
    //Tìm vị trí đầu tiên i kể từ sau gốc hiện tại mà lớn hơn gốc hiện tại -> Gốc của cây con bên phải
    //[1; i -1]: Các số cây con trái, [i; hết): Các số cây con phải
    while (i < preorder.size() && preorder[i] < preorder[0]) i++;
    vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + i);
    vector<int> right_preorder(preorder.begin() + i, preorder.end());
    root->left = buildTree(left_preorder);
    root->right = buildTree(right_preorder);
    return root;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>preorder;
		node *root;
		for(int i = 0;i<n;i++){
			int x; cin>>x;
			preorder.push_back(x);
		}
		root = buildTree(preorder);
		postorder(root);
		cout<<endl;
	}
}