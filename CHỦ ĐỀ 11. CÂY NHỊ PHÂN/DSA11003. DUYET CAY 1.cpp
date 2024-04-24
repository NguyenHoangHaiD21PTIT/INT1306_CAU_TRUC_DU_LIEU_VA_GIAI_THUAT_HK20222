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

// Tìm vị trí của giá trị root trong mảng inorder
int findIndex(vector<int>& inorder, int val, int start, int end){
    for(int i = start; i <= end; i++){
        if(inorder[i] == val) return i;
    }
    return -1;
}

// Duyệt cây và in ra kết quả Postorder
void printPostOrder(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd, int& preIndex){
    if(inStart > inEnd)
        return;
    // Tìm root của cây con hiện tại
    int rootIndex = findIndex(inorder, preorder[preIndex], inStart, inEnd);
    // Tăng preIndex để di chuyển sang root tiếp theo trong preorder
    preIndex++;
    // Duyệt cây con bên trái
    printPostOrder(inorder, preorder, inStart, rootIndex - 1, preIndex);
    // Duyệt cây con bên phải
    printPostOrder(inorder, preorder, rootIndex + 1, inEnd, preIndex);
    // In ra giá trị của root
    cout << inorder[rootIndex] << " ";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> inorder(N), preorder(N);
        for(int i = 0; i < N; i++)
            cin >> inorder[i];
        for(int i = 0; i < N; i++)
            cin >> preorder[i];
        
        int preIndex = 0; // chỉ số của phần tử trong preorder
        printPostOrder(inorder, preorder, 0, N - 1, preIndex);
        cout << endl;
    }
    return 0;
}
/*
4 2 5 1 3 6
1 2 4 3 5 6
     1
    /
    2
*/