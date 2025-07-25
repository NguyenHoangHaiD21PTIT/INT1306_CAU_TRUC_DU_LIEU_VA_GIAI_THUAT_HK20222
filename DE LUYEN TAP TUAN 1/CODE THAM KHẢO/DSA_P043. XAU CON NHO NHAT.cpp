#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        set<char>sc;
        // Xác định tập các ký tự trong xâu s
        for(char x: s) sc.insert(x);
        int st = 0, ans = 1e9, x = 0, a[256] = {};//st: Chỉ số bắt đầu đoạn con đang xét, x: Số ký tự khác nhau trong xâu con đang xét
        for(int i = 0;i<s.size();i++){
            a[s[i]]++;
            if(a[s[i]] == 1) x++;//đếm = 1 --> Lần đầu xuất hiện --> Ghi nhận là có thêm 1 ký tự phân biệt
            if(x == sc.size()){ //Có đủ mọi ký tự trong xâu s rồi
                //Cố gắng thu gọn về bên phải nhất có thể
                while(a[s[st]] > 1){
                    a[s[st]]--;
                    st++;
                }
                ans = min(ans, i - st + 1);
            }
        }
        cout << ans << endl;
    }
}
