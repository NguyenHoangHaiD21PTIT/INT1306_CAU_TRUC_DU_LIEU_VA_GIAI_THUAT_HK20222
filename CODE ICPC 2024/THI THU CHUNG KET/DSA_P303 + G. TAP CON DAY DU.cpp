#include <bits/stdc++.h>
using namespace std;
int N, res = 0;  
vector<int> bitmask;  // Lưu bitmask của từng từ
int get(string word) {
    int mask = 0;
    for (char c : word) mask |= (1 << (c - 'a'));  // Bật bit tương ứng với ký tự c
    return mask;
/*
    Toán tử dịch trái: Ví dụ: 1 << 2 = 4, tương đương nhị phân: 1 → 100, bản chất là 2 ^ i
    (Mỗi lần dịch trái, thêm một chữ số 0 vào bên phải trong biểu diễn nhị phân)
    Giả sử ta có từ "abc". Với mỗi ký tự, ta sẽ bật 1 bit tương ứng trong chuỗi 26 bit.
    Ví dụ:
    x = 'a' thì x - 'a' = 0 → 1 << 0 → 000...0001
    x = 'b' thì x - 'a' = 1 → 1 << 1 → 000...0010
    x = 'c' thì x - 'a' = 2 → 1 << 2 → 000...0100
    Thực hiện phép OR để gộp lại:
        000...0001   // a
      | 000...0010   // b
      | 000...0100   // c
      = 000...0111   → biểu diễn tập {a, b, c}
    Hình dung:
    - Ta có 26 cái "hộp" đặt liền nhau, từ trái qua phải tượng trưng cho các chữ cái từ 'z' đến 'a' 
    - Mỗi chữ cái sẽ bật một "hộp" tương ứng: nếu chữ đó có mặt thì hộp chứa số 1, nếu không có thì chứa 0.
    Ví dụ:
    - "abc" → bitmask = 000...000111  (3 bit cuối cùng là 1 vì có 'a', 'b', 'c')
    - "z"   → bitmask = 100...000000  (bit đầu tiên là 1, còn lại là 0)
*/
}
void Try(int idx, int curMask) {
    if (idx == N) {
        if (curMask == (1 << 26) - 1) res++;
        /*
        111 = 2^3 - 1 = (1 << 3) - 1
        Như vậy, (1 << 26) - 1 là dãy có 26 số 1 tức là đủ cả 26 ký tự
        */
        return;
    }
    Try(idx + 1, curMask);
    Try(idx + 1, curMask | bitmask[idx]);
}
int main() {
    cin >> N;
    bitmask.resize(N);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        bitmask[i] = get(word);  
    }
    Try(0, 0);
    cout << res << endl;
}
//Link: https://oj.vnoi.info/problem/backtrack_d
