#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n; cin >> n;
    ll res = 0;
    // Stack lưu pair: {giá trị phần tử, số lần xuất hiện liên tiếp (chưa bị che khuất)}
    stack<pair<int, int>> st; //st lưu những phần tử chưa bị bên phải che khuất
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int cnt = 1; 
        while (!st.empty() && st.top().first < x) {
            res += st.top().second;
            st.pop();
        }
        if (!st.empty() && st.top().first == x) {
            res += st.top().second;   
            cnt += st.top().second; 
            st.pop();
        }
        if (!st.empty()) res += 1;
        //Vẫn còn --> Đỉnh stack phải là thằng cao hơn (Thấp hơn đã bị lấy ở lần 1, bằng nhau bị láy ở lần 2)
        st.push({x, cnt});
    }
    cout << res;
}
/*Tư duy chủ đạo: Khi xét đến phần tử X, cho X nhìn về bên trái
1. Nếu X nhìn thấy những thằng thấp hơn nó: Cái đám thấp hơn này ghép cặp với X.
Nhưng X làm bức tường chắn những người đến sau sẽ không thấy nữa --> Tống khỏi stack
2. X thấy thằng bằng nó: X không che khuất, nhưng sẽ gộp lại thành 1 cục lớn
3. X tìm thấy người cao hơn mình: X và người đó thành 1 cặp, nhưng không đi xa hơn được nữa
*/
/*Giả sử trong hàng có 3 người cùng cao 170 -->St lưu {170, 3}
Số 180 bước vào, số cặp cộng thêm chính là số cặp 170 đang có trong stack
*/
