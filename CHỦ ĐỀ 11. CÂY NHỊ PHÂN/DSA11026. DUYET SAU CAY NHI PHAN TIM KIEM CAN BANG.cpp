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

node *createBST(int a[], int start, int end){
	if(start > end) return NULL;
	int mid = (start + end)/2;
	node *root = new node(a[mid]);
	root -> left = createBST(a, start, mid - 1);
	root -> right = createBST(a, mid+1, end);
	return root;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		node *root;
		for(int i = 0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		root = createBST(a, 0, n - 1);
		postorder(root);
		cout<<endl;
	}
}
