#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, MAX = 200005;  
long long fac[MAX], ivFac[MAX];  // fac[i] là i! mod MOD, ivFac[i] là 1/i! mod MOD
int N, M, K; 
vector<pair<int, int>> block;  // Lưu các cặp tọa độ điểm bị chặn

//Luỹ thừa Modulo
long long powMod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void pre() {
    fac[0] = 1;
    for (int i = 1; i < MAX; ++i) fac[i] = fac[i - 1] * i % MOD;
    // Định lý Fermat: Nếu MOD là số nguyên tố và a không chia hết cho MOD thì nghịch đảo của a mod MOD là a^(MOD - 2) mod MOD
    ivFac[MAX - 1] = powMod(fac[MAX - 1], MOD - 2);  // Sử dụng định lý Fermat
    for (int i = MAX - 2; i >= 0; --i) ivFac[i] = ivFac[i + 1] * (i + 1) % MOD;
}

// Hàm tính tổ hợp C(n, k) = n! / [k! * (n - k)!]
long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * ivFac[k] % MOD * ivFac[n - k] % MOD;
}

int solve() {
    block.push_back({N, M});
    sort(block.begin(), block.end());  // Sắp xếp các ô bị chặn từ trái qua phải, trên xuống dưới
    int size = block.size();
    vector<long long> dp(size, 0);  // dp[i] là số cách đến ô bị chặn thứ i (index từ 0)

    // Tư duy: Bao hàm - Loại trừ
    // Bước 1: Tính số đường đi từ (1, 1) đến ô bị chặn thứ i giả sử không có ô nào bị chặn
    // Lập luận: Từ (1, 1) đến (x, y) thì: 
    // - Có tất cả x hàng. Từ hàng 1 phải xuống x - 1 hàng nữa để đến hàng cuối
    // - Có tất cả y cột. Từ cột 1 phải sang phải y - 1 cột nữa để sang cột ngoài cùng phải
    // Như vậy, Tổng số bước đi là: x - 1 + y - 1 = x + y - 2. 
    // Và với mọi cách đi thì luôn phải chọn x - 1 bước xuống và y - 1 bước sang phải --> Số cách đi chính là số cách chọn x - 1 bước xuống trong x + y - 2 bước
    // --> C(x + y - 2, x - 1)
    
    // Bước 2: Tính tư duy bao hàm - loại trừ để tính số cách đi từ (1, 1) đến (x, y) nào đó với các ô bị chặn 
    // Tư duy: Số cách đến đích không xét ô chặn (Tập tổng) - Số cách đến đích bắt buộc qua ô chặn (Không thoả) = Thoả
    /* Tập to: Số cách đi từ (1, 1) đến (x, y) ĐÃ TÍNH ở Bước 1 (Không có ô cản): C(x + y - 2, x - 1) = dp[i]
    Phần bù: Xét những điểm ảnh hưởng, cản trở trên đường đi từ (1, 1) xuống (x, y): Chính là những điểm nằm phía trên, bên trái nó. Ta gọi là các điểm j(xj, yj)
    Tập con: Số cách đi từ (1, 1) QUA Ô chặn * Số cách đi từ ô chặn đấy đến ĐÍCH
    - Công đoạn 1: Ô (1, 1) qua ô chặn (Xét cả những ô chặn đường đến ô chặn này): Đã tính ở Bước 1: dp[j]
    - Công đoạn 2: Ô (xj, yj) đến đích là (x, y) (Với điều kiện là coi như không có gì chặn): Ta suy luận như cách tính Bước 1
    Chiều dọc: Có x - xj + 1 ô. Cần xuống x - xj bước. Chiều ngang có y - yj + 1 ô, cần sang phải y - yj bước
    Vậy tổng số bước là: x - xj + y - yj bước. Cần chọn x - xj bước --> Công đoạn này có C(x - xj + y - yj, x - xj)
    Theo quy tắc nhân, ta có số cách thực hiện phần bù là: dp[j] * C(x - xj + y - yj, x - xj)
    Theo quy tắc cộng, ta cộng dồn hết tất cả những điểm thứ j ảnh hưởng đến ĐÍCH THẬT lại
    Vậy thì, theo nguyên lí bù trừ, ta có với i(x, y) là đích, j(xj, yj) là các điểm ảnh hưởng thì ta có:
            dp[i] = dp[i] - Tổng các j ảnh hưởng(dp[j] * C(x - xj + y - yj, x - xj))
    */
    for(int i = 0; i < size; ++i) {
        int x = block[i].first, y = block[i].second;
        dp[i] = C(x + y - 2, x - 1);
        for(int j = 0; j < i; ++j) {
            int xj = block[j].first, yj = block[j].second;
            if(xj <= x && yj <= y) dp[i] = (dp[i] - dp[j] * C(x - xj + y - yj, x - xj) % MOD + MOD) % MOD;
        }
    }
    return dp[size - 1];
}   

int main() {
    pre(); 
    int T;
    cin >> T; 
    while (T--) {
        cin >> N >> M >> K;
        block.clear();
        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            block.push_back({x, y});  
        }
        cout << solve() << endl;
    }
}
