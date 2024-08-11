#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int cong = 0, tru = 0;//tổng số dấu cộng, tổng số dấu trừ
    //Đếm số dấu cộng, số dấu - trong toàn xâu
    for (char c : s) {
        if (c == '+') cong++;
        else tru++;
    }
    int Q;
    cin >> Q;
    while (Q--) {
        long long a, b;
        cin >> a >> b;
        //Nếu 2 số bằng nhau, chỉ có 1 loại số để chọn: Số dấu cộng phải bằng số dấu trừ mới triệt tiêu nhau
        if(a == b) {
            if(cong==tru) cout << "YES" << endl;
            else cout << "NO" << endl;
        /*Gọi x1 là số dấu cộng đặt vào a, y1 là số dấu trừ đặt vào a 
        Vậy, B còn lại: cong - x1 dấu cộng, tru - y1 dấu trừ
        Theo đề ra ta có: (x1 - y1)a + (cong - x1 - tru + y1)b = 0
        (x1 - y1)a + (-x1 + y1)b + (cong - tru)b = 0 -->(x1 - y1)(a - b)= (tru - cong)b
        -->x1 - y1 = (tru - cong)b/(a - b)
        */
        } else {
            long long diff = tru - cong; 
            long long tmp = a - b;
            if ((diff * b) % tmp == 0) {
                long long K = (diff * b) / tmp;
                /*x1 - y1 = K, 0<=x1<=cong, 0<=y1<=tru -->x1 = y1 +K 
                -->0<=y1+K<=cong -->-K<=y1<=cong - K 
                */
                //Mà theo bài ra: y1 thuộc [0; tru]. Ta tìm giao khoảng này với [-K; cong - K]. Vẽ trên trục số sẽ thấy
                long long min_y1 = max(0LL, -K);
                long long max_y1 = min((long long)tru, (long long)cong - K);
                if (min_y1 <= max_y1) cout << "YES" << endl;
                else cout << "NO" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}