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

node* build_tree(vector<int> &arr, int n) {
    if(n == 0) return NULL; // Trường hợp cơ sở: nếu mảng rỗng, trả về NULL
    node* root = new node(arr[0]); // Gán phần tử đầu tiên làm nút gốc
    queue<node*> q;
    q.push(root); // Thêm nút gốc vào hàng đợi
    int i = 1; // Bắt đầu từ vị trí thứ 1 trong mảng
    while(!q.empty() && i < n) {
        node* current = q.front(); // Lấy nút đầu tiên trong hàng đợi
        q.pop(); // Loại bỏ nút đã lấy ra khỏi hàng đợi
        // Xử lý con trái
        if(arr[i] != -1) {
            current->left = new node(arr[i]); // Gán con trái của nút hiện tại
            q.push(current->left); // Thêm con trái vào hàng đợi
        }
        i++;
        if(i < n && arr[i] != -1) {
            current->right = new node(arr[i]); // Gán con phải của nút hiện tại
            q.push(current->right); // Thêm con phải vào hàng đợi
        }
        i++;
    }
    return root;
}

void levelorder(node *root){
    if(root == NULL) return;

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int nodeCount = q.size();
        vector<int> levelValues;

        while(nodeCount > 0){
            node *tmp = q.front();
            q.pop();
            cout<<tmp->data<<" ";

            if(tmp->left != NULL) q.push(tmp->left);
            if(tmp->right != NULL) q.push(tmp->right);

            nodeCount--;
        }
        cout<<endl;
    }
}

int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		int n;
		cin>>n;
		vector<int>v(n);
		for(int i = 0;i<n;i++) cin>>v[i];
	    node *root = build_tree(v, n); // Xây dựng cây
	    levelorder(root); 
	}
    return 0;
}
/*
1
7
3 9 20 -1 -1 15 7 */