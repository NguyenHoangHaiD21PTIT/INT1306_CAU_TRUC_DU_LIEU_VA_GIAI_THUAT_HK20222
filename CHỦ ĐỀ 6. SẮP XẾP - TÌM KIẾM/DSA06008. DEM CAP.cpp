/* Đếm số cặp (x, y) tự nhiên sao cho x^y > y^x*/
/* x^y > y^x khi x < y. Trừ các trường hợp sau: 
1. x = 0. Với mọi y khác 0 (y>=1), ta có x^y = 0^y = 0. y^x = y^0 = 1
2. x = 1 thì x^y = 1^y = 1, y^x = y^1 = y. Do đó để x^y > y^x thì 1>y mà y tự nhiên --> y = 0
3. x = 2, y = 3 --> x^y = 2^3 = 8; y^x = 3^2 = 9. Loại
4. x = 4, y = 2 hoặc ngược lại: x^y = y^x = 2^4 = 4^2 = 16. Loại */
#include<bits/stdc++.h>
using namespace std;

int count(int x, int y[], int n, int f[]){
    //Đếm số phần tử y thỏa mãn x^y > y^x với x cho trước, f[i] là số phần tử i
    if (x==0) return 0;//Trường hợp 1 nêu trên
    if (x==1) return f[0];//Trường hợp 2 nêu trên
    auto idx = upper_bound(y, y + n, x);//Vị trí đầu tiên của y trong mảng Y mà > x
    //-->[idx + 1;n- 1] thì đều là các số y > x --> x^y > y^x
    int pos = idx - y;
    int ans = (n-1) - pos + 1;//x có thể ghép được với các số y thỏa mãn từ pos đến n - 1
    
    /*  Ngoại lệ 1: x > y nhưng x^y>y^x khi
        a. Khi x đã >=2. y = 0 --> x^y = x^0 = 1 > y^x = 0^x = 0
                         y = 1 --> x^y = x^1 = x >=2 > y^x = 1^x = 1 
        b. Khi x = 3, y = 2 --> x^y = 3^2 = 9 > y^x = 2^3 = 8*/
    ans += (f[0] + f[1]);
    if (x == 3) ans += f[2];

    /* Ngoại lệ 2: x<y nhưng x^y vẫn <= y^x
    Khi x = 2 mà y = 3 thì x^y = 2^3 = 8, y^x = 3^2 = 9 mà 8 <9
    Khi x = 2 mà y = 4 thì x^y = 2^4 = 16, y^x = 4^2 = 16*/
    if (x == 2) ans -= (f[3] + f[4]);
    return ans;
}

int calc(int x[], int y[], int m, int n){//Hàm tính số cặp thỏa mãn trên cả 2 mảng
    int f[5] = {};
    //Đếm số phần tử 0, 1, 2, 3, 4
    for(int i = 0;i<n;i++){
        if (y[i] < 5) ++f[y[i]];
    }
    sort(y, y + n);
    int ans = 0;
    //Với mỗi x, ta xem có bao nhiêu số y thỏa mãn
    for(int i = 0;i<m;i++)  ans += count(x[i], y, n, f);
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        int x[m], y[n];
        for(int &i : x) cin >> i;
        for(int &i : y) cin >> i;
        cout << calc(x, y, m, n) << endl;
    }
}