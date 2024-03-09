#include<bits/stdc++.h>
using namespace std;

struct node{
	char data;
	node *left;
	node *right;
	node(int x){
		data = x;
		left = right = NULL;
	}
};

void inorder(node *root){
	if(root == NULL) return;
	inorder(root -> left);
	cout<<root->data <<" ";
	inorder(root -> right);	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<node*>st;
		node *root = NULL;
		for(int i = 0;i<s.size();i++){
			if(!isalpha(s[i])){//Gap toan tu --> day se la root
				root = new node (s[i]);
				root -> right = st.top(); st.pop();
				root -> left = st.top(); st.pop();
				st.push(root);
			} else {
				st.push(new node (s[i]));
			}
		}
		inorder(root);
		cout<<endl;
	}
}