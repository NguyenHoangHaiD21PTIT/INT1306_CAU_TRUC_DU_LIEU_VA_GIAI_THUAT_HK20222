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
        current->left = new node(arr[i++]); // Gán con trái của nút hiện tại
        q.push(current->left); // Thêm con trái vào hàng đợi
        if(i < n) {
            current->right = new node(arr[i++]); // Gán con phải của nút hiện tại
            q.push(current->right); // Thêm con phải vào hàng đợi
        }
    }
    return root;
}

void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++){
	        cin >> arr[i]; // Nhập mảng
	    }
	    node *root = build_tree(arr, n); // Xây dựng cây
	    inorder(root); // Duyệt giữa
	    cout<<endl;
	}
    return 0;
}
