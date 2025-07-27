#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;
    multiset<int> col; //col: lưu đuôi của các dãy con hiện có
    for (int x : A) {
        auto it = col.lower_bound(x); //Tìm phần tử đầu tiên >= x
        if (it != col.begin()) { //it = col.begin(): Mọi đuôi đều < x --> Không ghép được
            --it;  //Lùi về phần tử bên trái đầu tiên < x        
            col.erase(it); //Xoá đuôi cũ
        }
        col.insert(x); //Cập nhật đuôi mới
    }
    cout << col.size() << endl;  
}
