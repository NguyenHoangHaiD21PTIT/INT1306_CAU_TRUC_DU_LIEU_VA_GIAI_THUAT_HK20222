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

void inorder(node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node *root){
	if(root == NULL) return;
	postorder(root -> left);
	postorder(root -> right);
	cout<<root->data <<" ";	
}

void insert(node* &root, int x) {
	if(root==NULL){
		root = new node(x);
		return;
	}
	if(x<root->data) insert(root->left, x);
	else insert(root->right, x);
}

node* min_value_node(node* root) {
    node* current = root;
    while (current->left != NULL) current = current->left;
    return current;
}

node* _delete(node* root, int x) {
    if (root == NULL) return root;
    if (x < root->data) root->left = _delete(root->left, x);
    else if (x > root->data) root->right = _delete(root->right, x);
    else {
        if (root->left == NULL) return root->right;
        else if (root->right == NULL) return root->left;
        // Lấy nút có giá trị bé nhất cây con phải có gốc là nút cần xóa
        node* temp = min_value_node(root->right);
        // Sao chép giá trị từ nút bé nhất này vào nút cần xóa
        root->data = temp->data;
        // Xóa nút lớn nhất từ cây con bên phải và cập nhật con trỏ của nút cha
        root->right = _delete(root->right, temp->data);
    }
    return root;
}


int main(){
	string s;
	node *root = NULL;
	while(getline(cin, s)){
		vector<int>v;
		stringstream ss(s);
		string token;
		while(ss>>token) v.push_back(stoi(token));
		if(v[0]==1) insert(root, v[1]);
		else if (v[0]==2) root = _delete(root, v[1]);
		else {
			if (v[0]==3) preorder(root);
			else if (v[0]==4) inorder(root);
			else postorder(root);
			cout<<endl;
		}
	}
}
/*
1 30
1 15
1 50
1 10
1 17
1 40
1 57
1 68
1 4
1 16
2 15
2 50
2 68
3
4
5 */