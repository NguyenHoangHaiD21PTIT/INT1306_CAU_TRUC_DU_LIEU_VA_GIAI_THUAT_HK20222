#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll s1 = 0, s2 = 0;
    int l = 0, r = n - 1;
    bool Ti = true;
    while (l <= r){
        int val;
        if (a[l] > a[r]) val = a[l++];
        else val = a[r--];
        if (Ti) s1 += val;
        else s2 += val;
        Ti = !Ti;
    }
    cout << s1 << " " << s2;
}
/* Code này vẫn AC 8/8. Tuy nhiên, có thể chỉ ra 1 test hiểm. Với mảng [20, 30, 2, 10]. Nếu tham lam:
Tí chọn 20. Tèo chọn 30. Tí chọn 10 và Tèo chọn 2. Kết quả: Tí 30 điểm, Tèo 32 điểm.
Chiến lược đúng phải là: Tí chọn 10. Lúc này dãy còn lại: 20, 30, 2.
Tèo chọn số gì thì cũng lòi ra 30 nên buộc phải chọn 20. Lúc này, Tí chọn 30 và chỉ còn số 2 cho Tèo. Do đó, Tí 40 điểm, Tèo 22 */
