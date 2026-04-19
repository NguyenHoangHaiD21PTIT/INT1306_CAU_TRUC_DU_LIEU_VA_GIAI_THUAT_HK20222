#include <bits/stdc++.h>
using namespace std;

/*
================================================================
  TƯ TƯỞNG CỐT LÕI (Thuật toán "Nhét - Nôn" với Stack):
  1. Mặc định nguồn số của ta là TĂNG DẦN (1, 2, 3...). 
  2. "Nhét": Cứ nhét lần lượt các số tăng dần này vào một cái bao (Stack).
  3. "Nôn": Vì Stack có tính chất "Vào sau - Ra trước", nên khi ta 
     nhét số TĂNG DẦN, lúc nôn ra nó sẽ tự động biến thành GIẢM DẦN.
  4. Quy luật hành động: 
     - Còn 'D' (còn cần giảm) -> CÒN NHÉT để gom hàng.
     - Khi gặp 'I' (gãy chuỗi giảm) hoặc HẾT CHUỖI -> NÔN HẾT RA!
================================================================
*/

void sol() {
    string s; 
    cin >> s;
    stack<int> st; // Đây chính là "cái bao" để gom số
    int cur = 1;   // Nguồn số của ta, mặc định luôn chạy tiến lên (1, 2, 3...)
    for (int i = 0; i <= s.size(); i++) {
        // Bất kể đang là 'I' hay 'D', cứ nhét số hiện tại vào bao trước, rồi tự động nâng số nguồn lên 1 đơn vị (cur++)
        st.push(cur++); 
        // BƯỚC 2: KIỂM TRA XEM CÓ BỊ "GÃY CHUỖI" ĐỂ NÔN RA KHÔNG?
        // Gãy chuỗi xảy ra khi:
        // 1. i == s.size() -> Đã chạy đến cuối cùng (hết chuỗi, chốt sổ)
        // 2. s[i] == 'I'   -> Muốn tăng lên (cắt đứt chuỗi đang giảm)
        if (i == s.size() || s[i] == 'I') {
            while (!st.empty()) {
                cout << st.top(); 
                st.pop();         
            }
        }
    }
    cout << endl; // Xong một test case thì xuống dòng
}

int main() {
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Test " << i << ": ";
        sol();
    }
}
