#include <bits/stdc++.h>
using namespace std;
//Hướng giải: Mảng hiệu
int main(){
    int n, q;
    cin>>n>>q;
    int a[100005] = {};
    while(q--){
        int x, y;
        cin>>x>>y;
        a[x]++; a[y + 1]--;
    }
    for(int i = 1;i<=n;i++) a[i]+=a[i - 1];
    for(int i = 1;i<=n;i++) cout<<a[i]%2<<" ";
}
/*
KIẾN THỨC CẦN NẮM: MẢNG HIỆU.
Bài toán: Cho mảng a có n <= 10^5 phần tử. Có q<=10^5 truy vấn, mỗi truy vấn là một đoạn [x; y] và yêu cầu tăng mỗi phần tử trong đoạn này thêm 1 đơn vị.
Hỏi sau q truy vấn thì mảng a có các phần tử thế nào
1. Cho dãy số a0, a1, ..., an. Ta gọi dãy d là mảng hiệu của dãy a, với: d[0] = a[0], d[i] = a[i] - a[i - 1] với i > 0. 
2. Về tư tưởng: Giả sử ta có dãy số: a0 a1 a2 a3 a4 a5 a6 a7 a8 a9. Xét truy vấn: Tăng từ a3 đến a6 [3;6] mỗi số thêm 2 đơn vị
thì ta có dãy số a0 a1 a2 a3+2 a4+2 a5+2 a6+2 a7 a8 a9.
Rõ ràng ta thấy sự thay đổi với mảng hiệu như sau: d0 = a0, d1 = a1 - a0, d2 = a2 - a1
d3_moi = a3_moi - a2_moi = (a3 + 2) - a2 = (a3 - a2) + 2 = d3_cu + 2
d4_moi = a4_moi - a3_moi = (a4 + 2) - (a3 + 2) = a4 - a3 = d4_cu
...
d6_moi = a6_moi - a5_moi = (a6 + 2) - (a5 + 2) = a6 - a5 = d6_cu
d7_moi = a7_moi - a6_moi =  a7 - (a6 + 2) = (a7 - a6) - 2 = d7_cu - 2 
d8_moi = a8_moi - a7_moi =  a8 - a7 = d8_cu ...
Như vậy ta thấy rằng: Khi truy vấn tăng từ a3 đến a6 mỗi số thêm 2 đơn vị thì ta chỉ cần thay đổi ở d3 thành d3 + 2, d7 thành d7 - 2 
Tổng quát, với mỗi truy vấn tăng từ x đến y mỗi số thêm v đơn vị thì ta chỉ cần thay đổi ở d[x] thành dx + v, d[y+1] thành d[y + 1] - v.
Chứ không cần phải thay đổi toàn bộ các phần tử từ a[x] đến a[y] --> Giảm độ phức tạp từ O(n * q) xuống O(n + q).
3. Ta thấy: 
a0 = d0
a1 = d0 + d1 = a0 + (a1 - a0) = a0 + d1
a2 = d0 + d1 + d2 = a0 + (a1 - a0) + (a2 - a1) = a1 + d2
a3 = d0 + d1 + d2 + d3 = a0 + (a1 - a0) + (a2 - a1) + (a3 - a2) = a3
...
Nôm na hiểu là: Từ mảng hiệu, muốn khôi phục mảng gốc thì ta lấy tổng cộng dồn mảng hiệu đến vị trí đó

VẬN DỤNG: Cho mảng a có n<=10^5 phần tử tất cả đều là 0. Có q<=10^5 truy vấn, mỗi truy vấn là một đoạn [x; y] và yêu cầu đảo mỗi phần tử từ 0 sang 1 và ngược lại trong đoạn này.
Hỏi sau q truy vấn thì mảng a có các phần tử thế nào
Giải:
Ta gọi b[i] là số lần đảo chiều của phần tử thứ i. Như vậy đổi chiều chẵn lần thì là 0, lẻ lần thì là 1. 
Gọi a là mảng hiệu của b, với a[0] = b[0], a[i] = b[i] - b[i - 1] với i > 0.
Nhiệm vụ của ta là từ mảng a là mảng hiệu, khôi phục lại mảng b cần tìm là số lần đảo chiều của mỗi phần tử.
--> Ta tính tổng cộng dồn là xong
*/
