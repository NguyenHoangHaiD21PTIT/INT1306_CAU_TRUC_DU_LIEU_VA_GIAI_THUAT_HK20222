#include<bits/stdc++.h>
using namespace std;    
using ll = long long;
int main(){
    int m, q; cin >> m >> q;
    vector<int> t(m);
    for(int i = 0; i < m; i++) cin >> t[i];
    sort(t.begin(), t.end());
    vector<ll>p(m + 1, 0);
    for(int i = 0; i < m; i++) p[i + 1] = p[i] + t[i];
    while(q--){
        ll N; cin >> N;
        int l = 0, r = m, s = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(p[mid] <= N) s = mid, l = mid + 1;
            else r = mid - 1;
        }
        l = 0, r = m - s;
        int pos = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(p[s + mid] - p[mid] <= N) pos = mid, l = mid + 1;
            else r = mid - 1;
        }
        cout << s << " " << t[pos] << endl;
    }
}
/* 
1. MỤC TIÊU 1: CHỌN ĐƯỢC NHIỀU BẠN NHẤT (TƯ DUY THAM LAM)
- Để mua được nhiều đồ nhất với số tiền N, ta phải ưu tiên những món rẻ nhất. -> Bắt buộc phải SẮP XẾP mảng tăng dần.
- Cách ngây thơ: Cứ nhặt lần lượt từ đầu, cộng dồn đến khi nào quá N thì dừng.
- Tối ưu 1: Mảng cộng dồn để truy xuất liên tục nhiều đoạn con liên tiếp trong O(1).
- Tối ưu 2: Mảng tổng tiền tố bây giờ đã là mảng tăng dần.
pre[i] là tổng đến chỉ số i -->Ta cần tìm chỉ số i xa nhất sao cho pre[i] <= N --> Tìm kiếm nhị phân (BS 1) để tìm được số lượng s bạn có thể mua.
- Đã sắp xếp rồi sẽ không ai đi rút người ở giữa ra, lấy người đằng sau nhét vào.
Làm thêo sẽ làm phình to tổng tiền mà cái "đáy" (người đứng đầu) vẫn dậm chân tại chỗ. -> Nhảy cóc là dở hơi!
2. MỤC TIÊU 2: NÂNG "ĐÁY" LÊN CAO NHẤT (CỬA SỔ TRƯỢT ĐƠN ĐIỆU)
- Vấn đề: Đã chốt được số lượng là 's' bạn. Trong 's' bạn này, người vay ít tiền nhất (cái "đáy") phải lớn nhất có thể.
- Giải pháp: Ta coi 's' bạn này là 1 cái "cửa sổ" kích thước cố định. Ta giữ guyên đội hình, bê nguyên cái cửa sổ này TRƯỢT DẦN SANG PHẢI (về phía 
  các bạn đắt tiền hơn). Trượt được càng sâu, cái "đáy" càng được nâng cao.
- Có m phần tử, cửa sổ có kích thước s, nên có m - s + 1 vị trí đặt cửa sổ. 
Do chỉ số từ 0 --> Vị trí xa nhất của cửa sổ là m - s. --> Tìm kiếm nhị phân cho vị trí đặt cửa sổ
=> CHỐT LẠI: 
- BS 1: Tìm ĐỘ DÀI cửa sổ (s).
- BS 2: Tìm VỊ TRÍ đặt cửa sổ (pos).
*/
