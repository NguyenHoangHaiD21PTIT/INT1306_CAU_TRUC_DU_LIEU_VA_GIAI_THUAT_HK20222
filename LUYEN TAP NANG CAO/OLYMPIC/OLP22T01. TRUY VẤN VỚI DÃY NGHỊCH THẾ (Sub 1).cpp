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
    // Ví dụ: Nghịch thế 5, 2. Ngưỡng là 3, 4: 2 để im, 5 bị ép thành 3, 4. Như vậy, cặp 5, 2 được bật khi ngưỡng = 3 = Min + 1
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
