#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    const int INF = 1e9;
    int n = s.size();
    vector<int> dp(n, INF);           // dp[i] = số đoạn tối thiểu để chia s[0..i]
    unordered_map<int, int> best;     // best[mask] = số đoạn tối thiểu để đạt mask này
    best.reserve(n * 2);
    int mask = 0;
    best[0] = 0;                     // prefix rỗng → mask = 0, cần 0 đoạn
    for (int i = 0; i < n; i++) {
        mask ^= 1 << (s[i] - 'a');   
        // TH1: mask trùng
        auto it = best.find(mask);
        if (it != best.end()) dp[i] = min(dp[i], it->second + 1);
        // TH2: mask khác đúng 1 bit
        for (int b = 0; b < 26; b++) {
            auto it2 = best.find(mask ^ (1 << b));
            if (it2 != best.end()) dp[i] = min(dp[i], it2->second + 1);
        }
        // lưu best cho mask hiện tại
        auto itb = best.find(mask);
        if (itb == best.end()) best[mask] = dp[i];
        else itb->second = min(itb->second, dp[i]);
    }
    cout << dp[n-1];
}
/*Một xâu có thể hoán vị thành xâu đối xứng nếu xâu đó chỉ có đúng 1 ký tự xuất hiện lẻ lần
best[X] = Y. X: Mask 26 bit biểu thị số lần xuất hiện mod 2 của 26 ký tự từ Z về A của xâu con đó Z Y X ... D C B A
Ví dụ: Xâu con này: D xuất hiện 5 lần, mod 2 = 1; C 8 lần, mod 2 = 0, A 5 lần, mod 2 = 1 --> 0 0 0 0 ... 1 0 0 1
Phép XOR: Cùng thì ra 1, khác ra 0. s[i] - 'a': Độ lệch với a, chính là index từ bên phải qua của mask
1 << (s[i] - 'a'): 2 ^ index: Bật bit thứ index trong mask lên. Ví dụ chữ D, độ lệch 3, 2^3 lầ bật bit thứ 3 từ phải qua
0^1 = 1, 1^1 = 0. Hiểu là ký tự đó đang chẵn lần, thêm thì ra lẻ, mà đang lẻ lần thêm thì ra chẵn
Tóm lại mask lấy XOR là để ra state hiện tại

Ta đã biết mask của xâu con từ 1 2 ... i là X: Giả dụ a chẵn lần, c lẻ lần, f lẻ lần, g chẵn lần
TH1: Tồn tại xâu con 1 2 ... j cùng mask: 
Giả sử tồn tại j sao cho từ 1 đến j: a chẵn lần, c lẻ lần, f lẻ lần, g chẵn lần 
Như vậy thì xâu con j+1 j+2 ... i: a, c, f, g đều chẵn lần --> Hoán vị thành đối xứng được
Có 2 option:
1. Để nguyên số phân hoạch đang có từ đầu đến i
2. Lấy số phân hoạch đến j, sau đó thêm 1 (Là xâu j+1 đến i, xâu này hoán vị ra ĐX được)

TH2: Tồn tại xâu con 1 2 ... j khác mask đúng 1 bit:
Giả sử tồn tại j sao cho từ 1 đến j: a chẵn lần, c CHẴN lần, f lẻ lần, g chẵn lần 
Như vậy thì xâu con j+1 j+2 ... i: a chẵn lần, c lẻ lần, f và g chẵn lần. 2 option kia cũng như vậy
*/
