#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll tongCS(ll x){
    ll s = 0;
    while (x){ 
        s += x % 10; 
        x /= 10; 
    }
    return s;
}

int main(){
    int T; cin >> T;
    while(T--){
        ll N, S; cin >> N >> S;
        if (tongCS(N) <= S){ 
            cout << 0 << endl; 
            continue; 
        }
        //Ý tưởng của ta là cố gắng làm tròn lên nhiều nhất có thể, luôn làm tròn lên, không theo luật trên 5 thì lên, dưới thì xuống
        ll ans = 0, pw = 1; // pw là luỹ thừa của 10 = 10 ^ k
        while (tongCS(N) > S){
            // Ví dụ: N là 1234, cần lấy số 2, 2 ở hàng trăm --> Chia cho 100 để loại bỏ các chữ số sau, mod 10 để loại hết các chữ số trước nó
            ll d = (N / pw) % 10;  // Lấy chữ số tại hàng thứ k (Hàng nghìn, hàng chục, ...) giảm trọng số từ bên trái qua
            // Tại vị trí đang xét bằng 0 rồi, thì xét ở vị trí có trọng số cao hơn
            if (d == 0){ 
                pw *= 10; 
                continue; 
            }    
            // Ví dụ: 1237000 đi, ta xét đến chữ số 7. 7 = (1237000 / 1000) % 10     
            // Để chữ số tại vị trí hàng nghìn thành 0, 7 + 3 = 10 --> Như vậy, ta lấy 1237000 + 3000 --> 1240000
            ll inc = (10 - d) * pw;    
            N += inc; //Tăng trực tiếp vào số ban đầu
            ans += inc; //Tăng trực tiếp vào lượng cần tăng
            pw *= 10; // Dịch lên hàng có trong số cao hơn                                   
        }
        cout << ans << endl;
    }
}
/* Ví dụ: 1237000
3 chữ số đầu là 0 thì thôi
+) Đến con 7, 7 + 3 = 10, 7 ở hàng nghìn. Nên:
 1237000
+   3000
 1240000
+) Dịch lên hàng vạn (1e4): 4 + 6 = 10. Nên
 1240000
+  60000
 1300000
+) Cứ thế ...
*/
