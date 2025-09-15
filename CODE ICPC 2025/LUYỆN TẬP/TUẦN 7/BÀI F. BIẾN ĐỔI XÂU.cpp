#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string s; cin >> s;
    string t;
    long long a = 0, b = 0;
    for (char c : s) {
        if (c == 'C') {
            long long v = a + (b / 2);
            t += string(v, 'A');
            int r = b % 2;
            if (r) t.push_back('B');
            t.push_back('C');
            a = b = 0;
        } else if (c == 'A') ++a;
        else ++b;
    }
    long long v = a + (b / 2);
    t += string(v, 'A');
    int r = b % 2;
    if (r) t.push_back('B');
    cout << t;
}
/* Chú ý rằng: BA -> AAA -> AB. Như vậy, với mỗi cặp BA, ta có thể hoán đổi thành AB
- Do đó, trong bất kỳ đoạn chỉ gồm A và B nào, ta luôn có thể "dồn" tất cả A về đầu, B về cuối mà không thay đổi số lượng A hay B.
2. Ví dụ minh họa cho BBAAB:
   - Chọn cặp (2, 3): B B A A B → B A B A B
   - Chọn cặp (1, 2): B A B A B → A B B A B
   - Chọn cặp (3, 4): A B B A B → A B A B B
   - Chọn cặp (2, 3): A B A B B → A A B B B
   → Kết quả cuối: tất cả A lên đầu, B xuống cuối
3. Sau khi dồn A và B:
   - Mỗi cặp BB có thể biến thành 1 A.
   - Nếu còn dư 1 B đơn lẻ, giữ nguyên.
4. Các ký tự 'C' không bị ảnh hưởng, coi như vách ngăn tách các cụm AB.
*/
