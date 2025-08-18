#include <bits/stdc++.h>
using namespace std;

//pref[i] = j: Độ dài dài nhất của xâu tiền tố trùng hậu tố mà dài j khi xét đến i. Định nghĩa tiền tố và hậu tố xem phía dưới
vector<int> pref(const string &s) {
    int n = (int)s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        //pi[i - 1] = j: Đã tồn tại một tiền tố độ dài j trùng tiền tố độ dài j khi xét đến i - 1
        //Tức là: [s[0], s[1], ..., s[j - 1]] =  [s[i - j] ... s[i - 2] s[i - 1]] 
        //Thử mở rộng ra xâu tiền tố lẫn hậu tố mỗi bên thêm 1 ký tự về phải --> Xác định được s[i] ? s[j]
        while (j > 0 && s[i] != s[j]) j = pi[j - 1]; //Tức là mở rộng tiền hậu ra i j rồi. Nhưng thấy không khớp, vậy thì xem, nếu end ở j - 1 thì match lớn nhất là mấy. Lại thử widen từ đó
        // 2 thằng bằng nhau --> widen độ dài xâu tiền tố
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

/*Hiểu 1: Giả sử ta có xâu 12345.
Các tiền tố: 1, 12, 123, 1234.
Các hậu tố: 5, 45 345, 2345. Cả tiền tố và hậu tố không được lấy chính nó
Ví dụ: ababab. Tiền tố: a, ab, aba, abab, ababa. Hậu tố: b, ab, bab, abab, babab. Như vậy thì pi[5] = 4 thì prefix = posfix (max) = abab
*/

// Kiểm tra nếu a là xâu con của b
bool is_substr(const string &a, const string &b) {
    if (a.size() > b.size()) return false;
    string t = a + "#" + b; // '#' trong đề không có
    vector<int> pi = pref(t);
    int m = (int)a.size();
    for (int i = 0; i < (int)pi.size(); ++i)
        if (pi[i] == m) return true;
    return false;
}

// Độ chồng lấn lớn nhất giữa suffix(A) và prefix(B)
int overlap_suffix_prefix(const string &A, const string &B) {
    string t = B + "#" + A;
    vector<int> pi = pref(t);
    return pi.back(); // luôn <= B.size()
}

// Gộp A và B thành xâu ngắn nhất chứa cả A và B
string merge_AB(const string &A, const string &B) {
    if (is_substr(A, B)) return B;
    if (is_substr(B, A)) return A;
    int ov = overlap_suffix_prefix(A, B);
    string res = A + B.substr(ov);
    return res;
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    vector<string> v = {s1, s2, s3};
    vector<bool> keep(3, true);
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            if (i != j && keep[i] && keep[j] && is_substr(v[i], v[j])) keep[i] = false;
        }
    }
    vector<string> a;
    for (int i = 0; i < 3; ++i) if (keep[i]) a.push_back(v[i]);
    if (a.empty()) { cout << 0 << "\n"; return 0; }
    if (a.size() == 1u) { cout << a[0].size() << "\n"; return 0; }
    if (a.size() == 2u) {
        string x = merge_AB(a[0], a[1]);
        string y = merge_AB(a[1], a[0]);
        cout << min(x.size(), y.size()) << "\n";
        return 0;
    }
    // a.size() == 3
    vector<int> idx = {0, 1, 2};
    size_t best = (size_t)4e18;
    sort(idx.begin(), idx.end());
    do {
        string ab = merge_AB(a[idx[0]], a[idx[1]]);
        string abc = merge_AB(ab, a[idx[2]]);
        if (abc.size() < best) best = abc.size();
    } while (next_permutation(idx.begin(), idx.end()));
    cout << best << "\n";
}
