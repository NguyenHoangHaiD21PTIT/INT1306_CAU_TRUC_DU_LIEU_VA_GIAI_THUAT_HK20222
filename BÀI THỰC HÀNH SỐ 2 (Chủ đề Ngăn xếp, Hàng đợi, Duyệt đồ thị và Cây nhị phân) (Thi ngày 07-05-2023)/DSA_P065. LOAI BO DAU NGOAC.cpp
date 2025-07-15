#include <bits/stdc++.h>
using namespace std;
string xoaDauCach (string x){   //a+ b -> a+b
    string res = "";
    for (int i=0; i<x.length(); i++){
        if (x[i]!=' ') res+=x[i];
    }
    return res;
}
string delete_1 (string x){  //Bên trong cặp ngoặc mà không có toán tử đồng cấp cặp ngoặc --> Thừa
    stack <pair<int, char>>st;
    int dele[300] = {0};//Đánh dấu vị trí bị dư thừa ngoặc
    for (int i=0; i<x.length(); i++){
        if (x[i]==')'){
            int flag = 0;//Đánh dấu xem có toán tử hay không
            while (st.top().second!='('){
                if (st.top().second=='+' || st.top().second=='-') flag = 1;
                st.pop();
            }
            //Hết vòng while thì stack sẽ trở lại vị trí dấu mở ngoặc tương ứng --> y là vị trí dấu mở ngoặc
            if (flag == 0){ //Không có toán tử đồng cấp --> Thừa ngoặc
                dele[st.top().first] = 1; //Vị trí dấu mở ngoặc thừa
                dele[i] = 1; //Vị trí dấu đóng ngoặc thừa
            }
            st.pop();//Xóa nốt dấu mở ngoặc ---> Xử lý xong cặp ngoặc
        }
        else st.push({i, x[i]});
    }
    string rs = "";
    for (int i=0; i<x.length(); i++){
        if (dele[i]==0) rs+=x[i];
    }
    return rs;
}
string delete_2 (string x){  //Phía trước dấu ngoặc khác dấu trừ thì cặp ngoặc ấy cũng thừa
    stack <pair<int, char>>st;
    int dele[300] = {0};
    for (int i=x.length()-1; i>=0; i--){
        if (x[i]=='('){
            int reduntdant = 0;
            //Xem phía trước dấu ngoặc có phải dấu trừ không
            if (i==0 || x[i-1]!='-') reduntdant = 1;
            //Xóa sạch những gì cùng cấp cặp ngoặc
            while (st.top().second!=')') st.pop();
            if (reduntdant){
                dele[st.top().first] = 1; //Vị trí dấu mở ngoặc thừa
                dele[i] = 1; //Vị trí dấu đóng ngoặc thừa
            }
            st.pop(); //Xóa nốt dấu mở ngoặc ---> Xử lý xong cặp ngoặc
        }
        else st.push({i, x[i]});
    }
    string rs="";
    for (int i=0; i<x.length(); i++){
        if (dele[i]==0) rs+=x[i];
    }
    return rs;
}
int main (){
    int t;
    cin>>t;
    cin.ignore();
    while (t--){
    	string str;
        getline(cin, str);
        string str_no_space = xoaDauCach(str);
        string str_1 = delete_1(str_no_space);
        string str_2 = delete_2(str_1);
        cout<<str_2<<endl;
    }
    return 0;
}
/*
3
(A-B + C) - (A+(B – C)) - (C-(D- E) )
((A)-( (B)))
A-(B+C) */
