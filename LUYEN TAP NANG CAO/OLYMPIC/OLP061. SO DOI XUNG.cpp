#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
const int MAXN = 200000 + 5;

const int MOD  = 1e9 + 7;
const int BASE = 911'382'323; // < MOD

int N;
int a_[MAXN], p[MAXN], invp[MAXN], F[MAXN], G[MAXN];       

//1. Cập nhật a[i] += val
void bit_add(int bit[], int n, int i, int val){
    val %= MOD; if(val < 0) val += MOD;
    for(; i <= n; i += i & -i){
        int x = bit[i] + val;
        if(x >= MOD) x -= MOD;
        bit[i] = x;
    }
}

//2. Tính a[1] + a[2] + ... + a[i]
int bit_sum(const int bit[], int i){
    long long r = 0;
    for(; i > 0; i -= i & -i){
        r += bit[i];
        if(r >= MOD) r -= MOD;
    }
    return (int)r;
}

//3. Tính a[l] + a[l + 1] + ... + a[r]
int bit_range(const int bit[], int l, int r){
    int x = bit_sum(bit, r) - bit_sum(bit, l - 1);
    if(x < 0) x += MOD;
    return x;
}

//4. Tính a^e MOD
long long modpow(long long a, long long e){
    a %= MOD; if(a < 0) a += MOD;
    long long r = 1;                 
    while(e){
        if(e & 1) r = (r * a) % MOD; 
        a = (a * a) % MOD;           
        e /= 2;                     
    }
    return r;
}

// --- p[i] = BASE^i, invp[i] = BASE^{-i}
void pre1(){
    p[0] = 1;
    for(int i = 1; i <= N; i++) p[i] = (int)(1LL * p[i - 1] * BASE % MOD);
    invp[N] = (int)modpow(p[N], MOD - 2);   // Fermat: (BASE^N)^{-1}
    for(int i = N - 1; i >= 0; i--) invp[i] = (int)(1LL * invp[i + 1] * BASE % MOD);
}

// --- build 2 BIT: xuôi & ngược
void pre2(){
    // Chẳng hạn: 1234567
    // Thì tại index 3 có val = 3, chiều xuôi có trị số là 3000, chiều ngược thì trị số là 3.10^5
    // Ban đầu, BIT ở mỗi index đang lưu trị số tại index đó. Mảng BIT F lưu trị số theo chiều xuôi, G theo chiều ngược
    for(int i = 1; i <= N; i++) F[i] = G[i] = 0;
    for(int i = 1; i <= N; i++){
        int vf = (int)(1LL * a_[i] * p[i] % MOD);            // a[i] * BASE ^ i
        bit_add(F, N, i, vf);                                // Ví dụ, số 1234567, đi đến index 3 có val = 3, thì F[3] = 3000, với base 10 chẳng hạn
        int vg = (int)(1LL * a_[i] * p[N + 1 - i] % MOD);    // a[i] * BASE ^ {N + 1 - i}
        bit_add(G, N, i, vg);
    }
}

// hash xuôi/ngược của [L..R], đã chuẩn hoá mốc
inline int get_forward(int L,int R){
    return (int)(1LL * bit_range(F, L, R) * invp[L] % MOD);
    // Chẳng hạn: 3456. 3 * 10 ^ 3 + 4 * 10 ^ 4 + 5 * 10 ^ 5 + 6 * 10 ^ 6. Mục đích của ta là đưa cái val = 3 kia về trị só 0, tức nhân 10 ^ 0
    // Nhân cho BASE ^ (-L) => Chia cho 1000 --> 3 * 10 ^ 0 + 4 * 10 ^ 1 + 5 * 10 ^ 2 + 6 * 10 ^ 3 = 6543
}
inline int get_backward(int L, int R){
    return (int)(1LL * bit_range(G, L, R) * invp[N + 1 - R] % MOD);
    // Chẳng hạn: 3456. 3 * 10 ^ 5 + 4 * 10 ^ 4 + 5 * 10 ^ 3 + 6 * 10 ^ 2
    // Mục đích: Đưa trị số gắn với 6 về mốc mũ 0, mà số mũ của 6 đang là 2
    // Nhân cho BASE ^ (N - R + 1) => Chia cho 100 --> 3 * 10 ^ 3 + 4 * 10 ^ 2 + 5 * 10 ^ 1 + 6 * 10 ^ 0 = 3456
    
}

// Cập nhật điểm a[pos] = newv
/*Ví dụ: Số 1234567. Ta cần thay số 3 thành số 9. Vậy, ta phải biết: Trong mảng F tại index 3, sau đó chênh bao nhiêu. Mảng G cũng vậy
d: Độ chênh lệch: 9 - 3 = 6. Gán a[3] = 6 --> 1264567
Tại index 3, val_cũ = 3 thì số mũ trong mảng F là 10 ^ 3, giờ thành 9, như vậy, thực chất, F[3] đã tăng thêm: 6 * 10 ^ 3
3 thì số mũ trong mảng G là 10 ^ 5, giờ thành 9, như vậy, thực chất, F[3] đã tăng thêm: 6 * 10 ^ 5
*/
void point_update(int pos, int newv){
    int d = newv - a_[pos];
    a_[pos] = newv;
    int df = (int)( (1LL * d * p[pos]) % MOD );          if(df < 0) df += MOD;
    int dg = (int)( (1LL * d * p[N + 1 - pos]) % MOD );  if(dg < 0) dg += MOD;
    bit_add(F, N, pos, df);
    bit_add(G, N, pos, dg);
}

int main(){
    string S; cin >> S;
    N = (int)S.size();
    for(int i = 1; i <= N; i++) a_[i] = (S[i - 1] - '0') + 1;
    pre1(); pre2();
    int Q; cin >> Q;
    while(Q--){
        char t; cin >> t;
        if(t == 'q'){
            int L, R; cin >> L >> R;
            cout << ( (get_forward(L,R) == get_backward(L,R)) ? "YES\n": "NO\n");
        }else{
            int U; char x; cin >> U >> x;
            point_update(U, (x - '0') + 1);
        }
    }
}
/*Hướng giải: Coi như chuỗi số đề cho ở cơ số base = 10 đi, index 1 - based. Có số 1234567 chẳng hạn
1: Tính hết 10 ^ 0, 10 ^ 1, 10 ^ 2, .... Tính hết 10 ^ -1, 10 ^ -2, ... có N chữ số thì tính đến N thôi
2: Biến chuỗi xâu thành mảng số nguyên có trọng số như sau:
1234567 --> F: 1 * 10 ^ 1, 2 * 10 ^ 2, 3 * 10 ^ 3, ... , 7 * 10 ^ 7 
1234567 --> G: 1 * 10 ^ 7, 2 * 10 ^ 6, 3 * 10 ^ 5, ... , 7 * 10 ^ 4 
3: Tìm cách tính giá trị số đoạn con dựa trên trọng số đã gán. Ví dụ như cách tính 3456 như ở trên. Cái bước này mục đích là để hash không phụ thuộc vị trí
Mục đích của ta là tìm cách lưu được số vào cây BIT có trọng số, đồng thời tính được hash không theo vị trí
4: Xử lý tiếp truy vấn cập nhật: Đây là bài toán update điểm, tính tổng đoạn --> Sử dụng cây BIT
Lúc này, với 2 mảng F và G ban nãy, từ mảng lưu các giá trị rời rạc đơn lẻ, thành 2 cây BIT.
Ban đầu, mỗi cây BIT tại mỗi chỉ số lưu chính số nguyên kèm theo trọng số của nó
Ví dụ:
1234567 --> F: 1 * 10 ^ 1, 2 * 10 ^ 2, 3 * 10 ^ 3, ... , 7 * 10 ^ 7 
Cập nhật: Giả sử ta cần thay ở index 3 từ 3 thành 9
9 - 3 = 6. Nhưng đấy không phải là cái để ta update vào BIT, vì như định nghĩa ở trên, BIT ta làm có trọng số gắn với số
3 ở mảng F là 3 * 1000, như vậy, index 3 tăng lên 6000 tại mảng F. Mảng G cũng vậy
*/
