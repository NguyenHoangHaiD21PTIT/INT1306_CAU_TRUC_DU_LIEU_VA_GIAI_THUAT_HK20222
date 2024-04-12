#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node *left;
    node *right;
    node(char x){
        data = x;
        left = right = NULL;
    }
};

node* build_tree(vector<char> &arr, int n) {
    if(n == 0) return NULL; // Trường hợp cơ sở: nếu mảng rỗng, trả về NULL
    node* root = new node(arr[0]); // Gán phần tử đầu tiên làm nút gốc
    queue<node*> q;
    q.push(root); // Thêm nút gốc vào hàng đợi
    int i = 1; // Bắt đầu từ vị trí thứ 1 trong mảng
    while(!q.empty() && i < n) {
        node* current = q.front(); // Lấy nút đầu tiên trong hàng đợi
        q.pop(); // Loại bỏ nút đã lấy ra khỏi hàng đợi
        if(current->data!='l'){
        	// Xử lý con trái
            current->left = new node(arr[i]); // Gán con trái của nút hiện tại
            q.push(current->left); // Thêm con trái vào hàng đợi
        	i++;
        	if(i < n) {
	            current->right = new node(arr[i]); // Gán con phải của nút hiện tại
	            q.push(current->right); // Thêm con phải vào hàng đợi
        	}
        	i++;
        }
    }
    return root;
}

// Hàm đệ quy để tính toán độ sâu của cây nhị phân
int depth(node* root, int current_depth) {
    if (root == NULL) return current_depth; // Nếu gặp nút lá, trả về độ sâu hiện tại

    // Gọi đệ quy để tính toán độ sâu của cây con bên trái và bên phải
    int left_depth = depth(root->left, current_depth + 1);
    int right_depth = depth(root->right, current_depth + 1);

    // Trả về độ sâu lớn nhất giữa cây con bên trái và bên phải
    return max(left_depth, right_depth);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        string s;
        cin >> s;
        
        // Chuyển chuỗi s thành mảng vector<char>
        vector<char> arr(s.begin(), s.end());

        // Xây dựng cây nhị phân từ chuỗi đầu vào
        node* root = build_tree(arr, n);

        // Tính toán và in ra độ sâu của cây nhị phân
        cout << depth(root, 0) - 1 << endl;
    }
    return 0;
}