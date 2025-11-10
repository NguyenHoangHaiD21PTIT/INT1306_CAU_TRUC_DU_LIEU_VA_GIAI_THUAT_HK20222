#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        stack<int> st;     //Stack lưu vị trí các dấu mở ngoặc
        int a[1005] = {0}; 
        for (int i = 0; i < s.size(); i++) a[i] = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (!st.empty()){ //Đóng có mở tương ứng
                    a[i] = 1; //Dấu đóng ngoặc đúng
                    a[st.top()] = 0; //Dấu mở ngoặc đúng
                    st.pop(); //Loại bỏ cặp ngoặc đã được ghép đôi
                } else a[i] = -1; //Đóng không có mở tương ứng là ngoặc sai
            }
        }
        //Lúc này đã xử lý xong ngoặc đóng sai, giờ chỉ còn lại ngoặc mở sai trong stack
        while (!st.empty()){
            a[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == ')') cout << a[i];
            else cout << s[i];
        }
        cout << endl;
    }
}
