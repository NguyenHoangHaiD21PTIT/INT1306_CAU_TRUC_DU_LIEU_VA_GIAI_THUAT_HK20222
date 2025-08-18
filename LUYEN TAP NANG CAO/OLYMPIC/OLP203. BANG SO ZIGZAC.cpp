#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll val(ll h, ll c){
	return h * (h - 1) / 2 + (c - 1) * (c + h * 2) / 2 + 1;
}
//Trong bài này ta dùng 1 - index. Dịch như sau: Để đi từ (1, 1) xuống (i, j)
/*Đầu tiên, từ (1, 1) = 1 = F: đi xuống ô hàng i.
Ta thấy: (2, 1) = 2 = F + 1; (3, 1) = 4 = F + 1 + 2; (4, 1) = 7 = F + 1 + 2 + 3
Như vậy, từ (1, 1) xuống hàng thứ i, ta cần cộng thêm: F + (1 + 2 + ... + (i - 1))
Số số hạng = i - 1. Tổng = (Cuối - Đầu) * Số số hạng / 2 = h * (h - 1) / 2

Bước 2: Từ điểm đầu mỗi hàng, ta dịch sang cột j tương ứng
Ví dụ: Hàng số 2: Các ô giá trị 2, 5, 9 và 14. 
Ta thấy, số cộng thêm chính là +3, +4 và +5. Bắt đầu từ hàng 2 là +3
Như vậy, đi từ đầu hàng, để sang cột 2, ta lấy đầu hàng + (h - 1)
Để sang cột 3, ta cộng tiếp h - 2
...
Như vậy, cộng dồn (h + 1) + (h + 2) + ... + (h + c - 1)
*/
int main(){
    ll x, y, z; cin >> x >> y >> z;
    cout << val(x, y) << endl;
    ll l = 1, r = 1e9;
	// Chặt nhị phân theo chỉ số đường chéo
    while(l <= r){
        ll mid = (l + r) / 2; //Giả định số đường chéo đang xét, đường chéo thứ i thì có i phần tử
		ll start = val(mid, 1), end = start + mid - 1; //Điểm bắt đầu, kết thúc đường chéo
		if(start <= z and z <= end){
			ll j = 1 + (z - start);
			ll i = mid - j + 1; //dài mid
			cout << i << ' ' << j;
			return 0;
		}
		if(start > z) r = mid - 1;
		else l = mid + 1;
    }
}
/* Ví dụ trong hình: Ta cần tìm số 14 
Ta đã xác định được 14 thuộc đường chéo số 3, 11 thì ở (4, 1), 15 thì ở (1, 5)
Quan sát đường chéo số 3, ta thấy, đi theo đường chéo, 14 dịch xuống 1 hàng ra số 13, 13 dịch 1 hàng ra số 12
Đi trên đường chéo mà lại còn dịch xuống 1 hàng, nghĩa là dịch xuống 1 hàng ĐỒNG THỜI lùi về trái 1 cột
Như vậy, phải tính độ dịch của số z với bắt đầu đường chéo để ra số CỘT
*/
