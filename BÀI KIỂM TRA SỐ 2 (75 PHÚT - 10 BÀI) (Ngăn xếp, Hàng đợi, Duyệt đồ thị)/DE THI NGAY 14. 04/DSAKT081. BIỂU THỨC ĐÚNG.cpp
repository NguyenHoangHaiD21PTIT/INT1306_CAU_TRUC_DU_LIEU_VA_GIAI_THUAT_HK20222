#include<bits/stdc++.h>
using namespace std;
int sol(string s){
    int d = 0, res = 0; //d: độ sâu hiện tại, res: dãy ngoặc đúng cấp cao nhất
    for(char c : s){
        if(c == '('){
            d++; 
            res = max(res, d); 
        } else if (c == ')'){
            d--; 
            if(d < 0) return -1; //Đóng không có mở tương ứng
        }
    }
    if(d != 0) return -1; //Còn mở không đóng tương ứng
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << sol(s) << endl;
    }
}
