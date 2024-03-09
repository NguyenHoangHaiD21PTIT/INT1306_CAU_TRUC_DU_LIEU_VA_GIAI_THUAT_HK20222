#include<bits/stdc++.h>
using namespace std;

struct node{
    string data;
    node *left;
    node *right;
    node(string x){
        data = x;
        left = right = NULL;
    }
};

node* build_tree(vector<string> &arr, int n) {
    if(n==0) return NULL; // Trường hợp cơ sở: nếu mảng rỗng, trả về NULL
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

void preorder(node* root, vector<string>& result) {
    if (root == NULL) return;
    result.push_back(root->data);
    preorder(root->left, result);
    preorder(root->right, result);
}

long long calc(long long x, long long y, string s){
	if(s=="+") return x + y;
	else if (s=="-") return x - y;
	else if (s=="*") return x * y;
	else return x/y;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<string>v;
	    while(n--){
	    	string s; cin>>s;
	    	v.push_back(s);
		}
		//Bước 1: Xây cây và chuyển sang preorder -->Tiền tố
		node *root = build_tree(v, v.size());
		vector<string> pr;//preorder_result
	        preorder(root, pr); //Bước 2: Tính giá trị biểu thức tiền tố
	        stack<long long>st;
		for(int i = pr.size()-1;i>=0;i--){
			if(pr[i]!="+"&&pr[i]!="-"&&pr[i]!="*"&&pr[i]!="/") st.push(stoll(pr[i]));
			else {
				long long x1 = st.top(); st.pop();
				long long x2 = st.top(); st.pop();
				st.push(calc(x1, x2, pr[i]));
			}
		}
		cout<<st.top()<<endl;
	}
}
