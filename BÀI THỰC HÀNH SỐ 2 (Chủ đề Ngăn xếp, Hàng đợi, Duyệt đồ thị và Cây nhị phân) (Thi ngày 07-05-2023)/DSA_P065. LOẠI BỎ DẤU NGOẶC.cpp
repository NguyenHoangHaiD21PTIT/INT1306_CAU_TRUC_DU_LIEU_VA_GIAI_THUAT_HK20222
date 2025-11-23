#include <bits/stdc++.h>
using namespace std;

string dsp (string s){
    string res = "";
    for (char x: s){
        if (x != ' ') res += x;
    }
    return res;
}
 
string d1 (string x){  //Bên trong cặp ngoặc mà không có toán tử --> Thừa. VD: ((A))
    stack <pair<int, char>>st;
    int dele[300] = {0};//Đánh dấu vị trí bị dư thừa ngoặc
    for (int i = 0; i < x.length(); i++){
        if (x[i] == ')'){
            int flag = 0;//Đánh dấu xem có toán tử hay không
            //Pop cho đến khi gặp dấu mở ngoặc, trong quá trình pop xem có toán tử không
            while (st.top().second != '('){
                if (st.top().second == '+' || st.top().second == '-') flag = 1;
                st.pop();
            }
            if (!flag){ //Không có toán tử đồng cấp --> Thừa ngoặc
                dele[st.top().first] = 1; //Vị trí dấu mở ngoặc thừa
                dele[i] = 1; //Vị trí dấu đóng ngoặc thừa
            }
            st.pop();//Xóa nốt dấu mở ngoặc ---> Xử lý xong cặp ngoặc
        }
        else st.push({i, x[i]});
    }
    string rs = "";
    for (int i = 0; i < x.length(); i++){
        if (!dele[i]) rs += x[i];
    }
    return rs;
}

string d2 (string x){  //Phía trước dấu ngoặc khác dấu trừ thì cặp ngoặc ấy cũng thừa
    stack <pair<int, char>>st;
    int dele[300] = {0};
    for (int i = x.length() - 1; i >= 0; i--){
        if (x[i] == '('){
            int du = 0;
            //Xem phía trước dấu ngoặc có phải dấu trừ không
            if (!i || x[i - 1] != '-') du = 1;
            //Xóa sạch những gì cùng cấp cặp ngoặc
            while (st.top().second != ')') st.pop();
            if (du){
                dele[st.top().first] = 1; //Vị trí dấu mở ngoặc thừa
                dele[i] = 1; //Vị trí dấu đóng ngoặc thừa
            }
            st.pop(); //Xóa nốt dấu mở ngoặc ---> Xử lý xong cặp ngoặc
        }
        else st.push({i, x[i]});
    }
    string rs = "";
    for (int i = 0; i < x.length(); i++){
        if (!dele[i]) rs += x[i];
    }
    return rs;
}

int main (){
    int t; cin >> t;
    cin.ignore();
    while (t--){
    	string s; getline(cin, s);
        cout << d2(d1(dsp(s))) << endl;
    }
}
//Nguồn tham khảo: https://e16cn-ptit.blogspot.com/2018/04/ptit122a-loai-bo-dau-ngoac-thua.html
