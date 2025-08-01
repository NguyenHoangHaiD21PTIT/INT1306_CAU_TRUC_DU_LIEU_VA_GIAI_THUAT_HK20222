#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll C[61][61]; 

void pre() {
    for (int n = 0; n <= 60; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k) C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
}

string build(int a, int b, ll k) {
    //Tức là còn lại a chữ A, b chữ B
    string res;
    while (a > 0 && b > 0) {
        //Ta cần xây dựng chuỗi bắt đầu tại vị trí i chẳng hạn (chưa biết chọn chữ gì) khi có a chữ A và b chữ b
        //Giả sử ở vị trí i ta chọn chữ A, thế thì còn a - 1 chữ A, b chữ B. 
        //Với a - 1 chữ A, b chữ B có C[a + b - 1][a - 1] cách sắp xếp
        //Như vậy, ta có C[a + b - 1][a - 1] chuỗi mà chữ cái tại i là A 
        //Vậy ta so sánh k với số chuỗi này, nếu mà nằm trong số chuỗi ấy chứng tỏ chữ cái tại i là A, ngược lại chữ cái tại i phải là B
        ll cnt = C[a + b - 1][a - 1];
        if (k <= cnt) {
            res += 'a';
            --a;
        } else {
            res += 'b';
            --b;
            //Khi chữ cái tại i là B rồi, ta phải skip mọi chuỗi mà chữ cái tại i là A
            k -= cnt;
        }
    }
    res += string(a, 'a') + string(b, 'b');
    return res;
}

int main() {
    int A, B; ll K;
    cin >> A >> B >> K;
    pre();
    cout << build(A, B, K) << '\n';
}
