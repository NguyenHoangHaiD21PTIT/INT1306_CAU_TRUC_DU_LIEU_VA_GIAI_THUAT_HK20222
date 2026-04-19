#include <bits/stdc++.h>
using namespace std;

bool check (char a, char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

int main(){
    string s; cin >> s;
    int cnt = 0, res = 0;
    stack <pair <char, int>>st; //{Loại ngoặc, Số dấu ngoặc vuông từ đầu chuỗi đến khi ký tự này được đưa vào stack}
    st.push ({'*', 0});
    for (char i: s){
        if (!st.empty() && check (st.top().first, i)){
            st.pop();
            // Dấu đóng hiện tại khớp với dấu mở ở đỉnh stack -> Cặp ngoặc hợp lệ -> Lấy dấu mở đó ra khỏi stack.
            if (!st.empty()) res = max (res, cnt - st.top().second);
            // Sau khi pop, phần tử ở đỉnh stack chính là dấu ngoặc chưa được ghép cặp gần nhất nằm ngay trước dãy ngoặc hợp lệ mà ta vừa tìm được.
            // - Số lượng dấu '[' NẰM BÊN TRONG dãy ngoặc hợp lệ vừa rồi sẽ bằng:
            //   (Tổng số '[' từ đầu đến hiện tại) TRỪ ĐI (Tổng số '[' từ đầu tính đến cái Cột mốc biên kia).
        } else {
            if (i == '[') cnt++;
            st.push ({i, cnt});
        }
    }
    cout << res;
}
