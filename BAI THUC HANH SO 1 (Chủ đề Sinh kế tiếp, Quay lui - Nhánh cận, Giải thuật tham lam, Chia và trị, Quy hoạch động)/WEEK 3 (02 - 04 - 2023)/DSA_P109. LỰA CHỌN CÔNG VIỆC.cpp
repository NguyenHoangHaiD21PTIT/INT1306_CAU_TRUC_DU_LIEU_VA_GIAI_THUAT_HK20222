#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct task{
    ll dl, prf;//deadline, profit
};

bool cmp (task a, task b){
    if (a.prf != b.prf) return a.prf > b.prf;
    return a.dl > b.dl;
}

task a[100007];

int main(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].dl >> a[i].prf;
    sort(a, a + n, cmp);
    ll ans = 0;
    set <int> t; //set này chứa các đơn vị thời gian chưa sử dụng
    for (int i = 1; i <= n; i++) t.insert(i);
    for (int i = 0; i < n; i++){
        auto x = t.upper_bound (a[i].dl);
        if (x == t.begin()) continue;
        /* Tư tưởng: Trong các mốc thời gian chưa dùng, ta cần tìm mốc thời gian TRỐNG lớn nhất nhưng vẫn nằm trong phạm vi cho phép (tức là <= deadline) để dành chỗ xếp cho những việc có dl sớm hơn
        Cách làm: Tìm mốc thời gian trống đầu tiên > deadline, sau đó lùi lại một bước để lấy mốc thời gian ngay sát trước nó.
        - Nếu mốc thời gian trống nhỏ nhất hiện tại cũng đã > deadline, nghĩa là toàn bộ các ngày trống đều đã trễ hạn -> Không thể xếp việc -> Bỏ qua.
        
        Ví dụ 1: deadline = 3. Các mốc chưa dùng là 5 7 8 15. 
        -> Mốc trống nhỏ nhất (5) đã lớn hơn 3. Không có ngày nào hợp lệ để làm việc này -> Bỏ qua.
        
        Ví dụ 2: deadline = 5. Các mốc chưa dùng là 1 2 4 7 8. 
        -> Mốc thời gian trống đầu tiên vượt quá 5 là ngày 7. 
        -> Lùi lại liền trước mốc 7, ta được mốc 4. 
        -> Ngày 4 chính là thời điểm lý tưởng nhất (vừa sát deadline 5, vừa thỏa mãn điều kiện <= 5). Ta chốt xếp việc vào ngày 4!
        */
        x--;
        ans += a[i].prf;
        t.erase(x);
    }
    cout << ans;
}
/*Nguyên tắc sắp xếp: 
- Ưu tiên công việc nhiêu tiền hơn
- Trì hoãn công việc đến phút chót, vì cần không gian cho những việc có dl sớm hơn
*/
