#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<string> s(n + 1);
    for (ll i = 1; i <= n; i++) cin >> s[i];
    vector<ll> cntLen(31, 0);  //cntLen[len]: Số chuỗi trước chuỗi hiện tại có độ dài len và nằm trong phạm vi k chỉ số gần nhất
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        int length = s[i].size();
        ans += cntLen[length];  //Mỗi xâu s[i] chỉ xét các xâu có cùng độ dài nhưng đứng trước nó để cặp --> Không bị xét lặp
        cntLen[length]++;
        //Ví dụ, cửa sổ trượt dài 3, xét đến i = 4 --> Cửa sổ sẽ là 4 3 2
        //Loại s1 đi --> cnt[độ xài xâu s1]--;. Rồi i = 5 --> Cửa sổ là 5 4 3 --> Loại s2 đi --> cnt[độ dài xâu s2]--;
        if (i - k >= 1) cntLen[s[i - k].size()]--; //Loại chuỗi nằm ngoài phạm vi cần xét
    }
    cout << ans;
}
