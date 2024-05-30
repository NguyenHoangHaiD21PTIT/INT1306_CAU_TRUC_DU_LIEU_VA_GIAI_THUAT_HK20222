#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node *left;
    node *right;
    node(string x) {
        data = x;
        left = right = NULL;
    }
};

node *build_tree(vector<string> &arr, int n) {
    if (n == 0) return NULL;
    node *root = new node(arr[0]);
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n) {
        node *current = q.front();
        q.pop();
        if (arr[i] != "N") {
            current->left = new node(arr[i]);
            q.push(current->left);
        }
        i++;
        if (i < n && arr[i] != "N") {
            current->right = new node(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void RNL(node *root){
    if(root==NULL) return;
    RNL(root->right);
    cout<<root->data<<" ";
    RNL(root->left);
}

int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<string>v;
        string token;
        while(ss>>token) v.push_back(token);
        int n = v.size();
        node *root = build_tree(v, n);
        RNL(root);
        cout<<endl;
    }
}
