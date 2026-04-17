#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string res(ll p){
    if (p == 1) return "1";
    vector <int> v;
    for(int i = 9; i >= 2; i--){
        while (p % i == 0){
            v.push_back(i);
            p /= i;
        }
    }
    if (p != 1) return "-1";
    string ans;
    for (int i = v.size() - 1; i >= 0; i--) ans += to_string(v[i]);
    return ans;
}

int main(){
    int t; cin >> t;
    while (t--){
        ll p; cin >> p;
        cout << res(p) << "\n";
    }
}
/*Tư duy tham lam: Cố gắng viết thành tích ít số nhất có thể. Do đó chia từ số to xuống, sau đó đảo lại
Việc thêm 1 vào không làm thay đổi tích, mà chỉ khiến số cần tìm dài hơn
*/
