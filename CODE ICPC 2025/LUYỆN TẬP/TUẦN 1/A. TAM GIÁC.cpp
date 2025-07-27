#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n; cin >> n;
    vector <pair <ll, ll>>a;
    for(int i = 0; i < n;i++){
        int x, y; 
        cin >> x >> y;
        a.push_back({x, y});
    }
    //Số tam giác = Số bộ ba bất kỳ - Số bộ ba thẳng hàng
    ll res = n * (n - 1) * (n - 2)/6;// Số bộ ba bất kỳ = C(N, 3) = N!/[3! x (N - 3)!]
    //Đếm số bộ ba thẳng hàng
    /* *A(x1, y1), B(x2, y2), C(x3, y3) -->vtAB = (x2 - x1, y2 - y1), vtAC = (x3 - x1, y3 - y1)
    -->vtAB cùng phương vtAC khi (x2 - x1)/(x3 - x1) = (y2 - y1)/(y3 - y1) --> Nhân chéo 
    */
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                ll x1 = a[i].first, y1 = a[i].second, x2 = a[j].first, y2 = a[j].second, x3 = a[k].first, y3 = a[k].second;
                if((x2 - x1) * (y3 - y1) == (y2 - y1) * (x3 - x1)) res--;
            }
        }
    }
    cout << res;
}