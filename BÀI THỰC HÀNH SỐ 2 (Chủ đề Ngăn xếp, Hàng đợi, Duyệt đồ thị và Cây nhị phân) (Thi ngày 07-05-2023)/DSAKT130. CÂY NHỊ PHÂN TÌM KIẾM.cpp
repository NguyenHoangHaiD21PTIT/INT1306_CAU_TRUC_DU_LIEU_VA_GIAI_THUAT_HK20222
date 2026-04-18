#include <bits/stdc++.h>
using namespace std;

struct node {
    int v; node *l, *r;
    node(int x) { 
        v = x; 
        l = r = NULL; 
    }
};

void pre(node* t) { 
    if (t == NULL) return;
	cout << t -> v << " ";
	pre(t -> l);
	pre(t -> r);
}

void in(node* t) { 
    if (t == NULL) return;
    in (t -> l);
    cout << t -> v << " "; 
    in (t -> r);
}

void post(node* t) { 
    if (t == NULL) return;
    post(t -> l); 
    post(t -> r); 
    cout << t -> v << " "; 
}

node *add (node *root, int u){
    if (root == NULL) root = new node(u);
	else {
		if (u < root -> v) root->l = add(root->l, u);
		else root -> r = add(root->r, u);
	}
	return root;
}

//Tìm node trái nhất có thể (Trả về con trỏ đến node đó)
node* minNode(node* t) {
    while(t->l) t = t->l;
    return t;
}

node* del(node* t, int x) {
    //Bước 1: Tìm node cần xóa
    if(!t) return t; 
    if(x < t->v) t -> l = del(t -> l, x); //Nhỏ hơn node hiện tại -> đi sang trái
    else if(x > t -> v) t -> r = del(t -> r, x); //Lớn hơn node hiện tại -> đi sang phải
    //Bước 2: Tìm node thế mạng 
    else {
        if(!t -> l) return t -> r; //Không có con trái -> trả về con phải
        if(!t -> r) return t -> l; 
        //minNode(t -> r): Trả con trỏ của node trái nhất cây con phải, thêm -> v để lấy giá tri số
        t -> v = minNode(t -> r) -> v; 
        t -> r = del(t -> r, t->v); 
    }
    return t;
}

int main() {
    node* root = NULL;
    int t, x;
    while (cin >> t) {
        if (t == 1) { 
            cin >> x; 
            root = add(root, x);
        } else if (t == 2) { 
            cin >> x; 
            root = del(root, x); 
        } else {
            if (t == 3) pre(root);
            else if (t == 4) in(root);
            else post(root);
            cout << "\n";
        }
    }
}
