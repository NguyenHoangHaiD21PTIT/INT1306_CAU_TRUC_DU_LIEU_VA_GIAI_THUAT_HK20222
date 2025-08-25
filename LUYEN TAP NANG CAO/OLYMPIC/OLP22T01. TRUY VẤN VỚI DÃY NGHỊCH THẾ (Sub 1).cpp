#include <bits/stdc++.h>
using namespace std;
//Sub 1:
int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    // delta[x] = Số cặp nghịch thế phát sinh khi tăng ngưỡng từ X - 1 lên X
    // Ví dụ: 5 2 3 3 0. Ban đầu, ngưỡng là 0. Tất cả bị ép xuống 0 --> 0 0 0 0 0
    // Ngưỡng là 1: 1 1 1 1 0
    // Ngưỡng là 3: 3 2 3 3 0
    // Ví dụ: Nghịch thế 5, 2. Quy tắc là không quá ngưỡng thì để nguyên, quá ngưỡng thì ép xuống bằng ngưỡng
    // Ngưỡng là 0: Cả 2 bị ép về 0, 0. Ngưỡng là 1 cũng vậy. Ngưỡng là 2 thì 5 bị ép về 2: 2, 2. 
    // Ngưỡng là 3: 2 để im, 5 bị ép thành 3. 3 > 2. Như vậy, cặp 5, 2 trở thành nghịch thế khi ngưỡng là 3 = 2 + 1
    // Ngưỡng là 4: 2 để im, 5 bị ép thành 4. 4 > 2. Đây không phải cặp nghịch thế mới nữa
    // Ngưỡng là >= 5: Cả 2 số để im. 5 > 2. Đây cũng là cặp nghịch thế cũ.
    // Như vậy, 1 cặp nghịch thế (Max, Min) chỉ được bật lên 1 lần duy nhất tại ngưỡng Min + 1. 
    // Đến ngưỡng trên 5 thì 5 được để nguyên. Do đó, nghịch thế chỉ phát sinh duy nhất 1 lần khi ngưỡng từ 2 bật lên 3
    vector<long long> delta(N + 2, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (A[i] > A[j]) {
                int b = A[j];
                if (b <= N - 2) delta[b + 1] += 1; 
            }
        }
    }
    long long run = 0;
    for (int X = 0; X <= N - 1; ++X) {
        run += delta[X];
        cout << run << "\n";
    }
}

