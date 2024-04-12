#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    
    int n = arr.size();
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    for (int i = 1; i < n; i += 2) {
        TreeNode* current = q.front();
        q.pop();
        
        if (arr[i] != -1) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        
        if (i + 1 < n && arr[i + 1] != -1) {
            current->right = new TreeNode(arr[i + 1]);
            q.push(current->right);
        }
    }
    
    return root;
}

void rightSideView(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int nodeCount = q.size();
        TreeNode* lastNode = nullptr;

        while (nodeCount--) {
            TreeNode* current = q.front();
            q.pop();
            lastNode = current;

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        cout << lastNode->val << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        TreeNode* root = buildTree(arr);
        rightSideView(root);
        cout << endl;
    }
    return 0;
}